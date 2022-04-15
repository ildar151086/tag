/*
    Пятнашки.Выбор режима игры 3 * 3(8) или 4 * 4 (15).
    Режим -Человек - Компьютер
    Начальное размещение - ручное - компьютерное
    Статистика - время потраченное на сбор пятнашки - количество перестановок
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>



using namespace std;

/// <summary>
/// Выбор игрока кто икрает в пятнашки Человек или Компьютер
/// </summary>
enum UseGame {
    HUMAN = 1,
    COMPUTER
};

/// <summary>
/// Выбор пользователя кто будет заполнять доску в пятнашки
/// </summary>
enum UseUserFilltable {
    RANDOM = 1,
    USER
};

/// <summary>
/// Определяем статус ячейки пустой или не пустой
/// </summary>
enum StatusСell {
    CLOSE = -2,
};

/// <summary>
/// Описываем статистику игры
/// </summary>
struct Statistic{
    // Время запуска игры
    time_t timeStart;
    // Время окончания игры
    time_t timeEnd;
    // Количество бросков
    int count = 0;
};

/// <summary>
/// Запрос пользователя а режиме игры в пятнашки 3 на 3 или 4 на 4
/// </summary>
/// <param name="sizeMode">Передаем размер доски пятнашки </param>
void inputSettingsGame(int& sizeMode) {
    // Выбор размера игры в пятнашки
    int userModeGame = 0;

    // Выбор режима игры 3 * 3 или 4 * 4
    cout << "Выбирите режим игры в пятнашки:" << endl;
    cout << "\t Режим (3 * 3) вариант 1" << endl;
    cout << "\t Режим (4 * 4) вариант 2\n\t\t";
    cin >> userModeGame;

    switch (userModeGame) {
    case 1:
        sizeMode = 3;
        break;
    case 2:
        sizeMode = 4;
        break;
    default:
        cout << "Вы ввели недопустимую команду" << endl;
        cout << "Мы выбрали за вас режим игры - 1 " << endl;
        sizeMode = 3;
    }
}

/// <summary>
/// Инициализируем двумерный массив без заполнения
/// </summary>
/// <param name="sizeMode">Задает размер массива sizeMode на sizeMode </param>
/// <returns> Возвращает указатель на созданный двумерный массив </returns>
int** createTagsElements(int sizeMode) {
    // Создание двумерного массива
    int** tags = new int* [sizeMode] {0};

    for (int i = 0; i < sizeMode; i++) {
        *(tags + i) = new int[sizeMode] {0};
    }
    return tags;
}

/// <summary>
/// Проверяет есть такое значение в масссиве или нет
/// </summary>
/// <param name="powSizeMode">Размер массива</param>
/// <param name="elements">Указатель на массив</param>
/// <param name="valueUser">Это значение надо проверить</param>
/// <returns>True если такой элемент был</returns>
inline bool checkElements(int powSizeMode, int *elements, int valueUser) {
    // Запускаем цикл по уже имеющимуся одномерному массиву 
    for (int j = 0; j < powSizeMode; j++) {
        // Проверяем если этот элемент уже в массиве или нет
        if (*(elements + j) == valueUser) {
            // Этот элемент уже есть в нашем массиве
            return true;
        }
    }
    return false;
}

/// <summary>
/// Проверяет есть такое значение в масссиве или нет
/// </summary>
/// <param name="powSizeMode">Размер доски</param>
/// <param name="elements">Указатель на массив</param>
/// <param name="valueUser">Это значение надо проверить</param>
/// <returns>True если такой элемент был</returns>
inline bool checkElements(int SizeMode, int** elements, int valueUser, int &indexI, int &indexJ) {
    // Запускаем цикл по уже имеющимуся двумерному массиву 
    for (int i = 0; i < SizeMode; i++) {
        for (int j = 0; j < SizeMode; j++) {
            // Проверяем если этот элемент уже в массиве или нет
            if (elements[i][j] == valueUser) {
                indexI = i;
                indexJ = j;
                // Этот элемент уже есть в нашем массиве
                return true;
            }
        }
    }
    return false;
}


/// <summary>
/// Создаем одномерный массив. Заполняем его нужной нам числовой последовательностью в зависимости от размера доски Пятнашек.
/// 1 вариант Заполняем его случайным образом без повторения чисел.
/// </summary>
/// <param name="sizeMode">Размер доски sizeMode на sizeMode</param>
/// <returns>Возвращаем указатель на одномерный массив заполненый числами в случайном порядке</returns>
int* randValue(int sizeMode) {
    // Определяем размерность для одномерного массива
    int powSizeMode = sizeMode * sizeMode;

    // Создаем массив из чисел выбранной размернотси    
    int* elements = new int[powSizeMode] {-1};

    /* Запоняем данный массив последовательно числами из заданного диапазона
    до powSizeMode без повторений*/
    for (int i = 0; i < powSizeMode; i++) {

        // Случайное занчение из заданого диапазона
        int valueRand = rand() % powSizeMode + 1;

        // было ли новое случайное число или небыло его
        if (!checkElements(powSizeMode, elements, valueRand)) {
            // Если такого элемента нет то добавляем его в массиив
            *(elements + i) = valueRand;
        }
        else {
            /* Если такого элемент есть вмассиве то пропускаем его
              и делаем шаг назад по циклу т.к не заполнилши i-1 элемент */
            i--;
        }
    };

    return elements;
};

/// <summary>
/// Создаем одномерный массив. Заполняем его нужной нам числовой последовательностью в зависимости от размера доски Пятнашек.
/// 2 вариант Заполняем его в ручную.
/// </summary>
/// <param name="sizeMode">Размер доски sizeMode на sizeMode</param>
/// <returns>Возвращаем указатель на одномерный массив заполненый числами в случайном порядке</returns>
int* userValue(int sizeMode) {
    // Определяем размерность для одномерного массива
    int powSizeMode = sizeMode * sizeMode;

    // Создаем массив из чисел выбранной размернотси    
    int* elements = new int[powSizeMode] {-1};

    // Запрос у пользователя на заполнение
    cout << "Введите последовательность из " << powSizeMode << " чисел без повторения которыми мы заполним доску Пятнашек";
    cout << endl;

    int valueUser = 0;
    /* Запоняем данный массив последовательно числами c запросом у пользователя с проверкой
    до powSizeMode без повторений*/
    for (int i = 0; i < powSizeMode; i++) {
        // Ввод пользователя
        cout << "Число " << i+1 << " = ";
        cin >> valueUser;

        // было ли новое случайное число или небыло уже
        if (!checkElements(powSizeMode, elements, valueUser)) {
            // Если такого элемента нет то добавляем его в массиив
            *(elements + i) = valueUser;
        }
            cout << "Такое число уже есть!" << endl;
            cout << "Введите другое число" << endl;
            i--;
        }
    return elements;
};

/// <summary>
/// Заполняем двумерный массиив случаными числами из созданого одномерного массива 
/// </summary>
/// <param name="tags">Заполненый двумерный массив </param>
/// <param name="sizeMode">Размер доски </param>
void fillTagsElements(int** tags, int sizeMode) {
    // Выбор пользователя как заполнить доску в пятнашки
    int caseUser = -1;

    // Определяем размерность для одномерного массива
    int powSizeMode = sizeMode * sizeMode;

    // Запрашиваем у пользователя как будем заполнять доску в пятнашке
    cout << "Заполнить доску" << endl;
    cout << "\t случаным образом - напишите 1" << endl;
    cout << "\t ручным образом - напишите 2" << endl;
    cin >> caseUser;

    // Указатель на заполненый случаными числами без повторов одномерный массив размера sizeMode*sizeModeи 
    int *pElem;

    switch (caseUser)
    {
        case RANDOM:
            // Заполняем случаным образом
            pElem = randValue(sizeMode);
        break;
        case USER:
            // Заполняем ручным образом
            pElem = userValue(sizeMode);
        break;
        default:
            cout << "Вы ввели недопустимую команду" << endl;
            cout << "Мы выбрали за вас режим заполнения - Случаный " << endl;
            // Заполняем случаным образом
            pElem = randValue(sizeMode);
        break;
    }

    // счетчик для одномерного массива
    int index = 0;
    // Заполняем двумерный массив
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            tags[i][j] = *(pElem + index++);
        }
    }
}

/// <summary>
/// Выводим на экран двумерный массив 
/// </summary>
/// <param name="tags">Указатель на двумерный массив</param>
/// <param name="sizeMode">Размер доски в пятнашки</param>
void showTagsElements(int** tags, int sizeMode) {
    cout << endl;
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            // Отображение в зависимости от статуса ячейки
            switch (tags[i][j])
            {
                case CLOSE:
                    cout << "\t\t" << "|ZERO|" << " ";
                break;
            default:
                cout << "\t\t  " << tags[i][j] << "   ";
                break;
            }
            
        }
        cout << endl;
    }
}

/// <summary>
/// Запрашиваем у пользователя кто играет. 1 Компьюьетер. 2 Человек.
/// </summary>
/// <param name="gameStart">Возврашаем выбор пользователя</param>
void inputGameUse(int& gameStart) {

    // Запрашиваем Кто играет Компьютер или Человек
    cout << "Выбирите кто будет играть в пятнашки:" << endl;
    cout << "\tЧеловек вариант -1 " << endl;
    cout << "\tКомпьютер вариант -2 \n\t";
    // Выбор пользователя
    cin >> gameStart;

    // Обработка введенного значения
    switch (gameStart) {
    case COMPUTER:
        gameStart = COMPUTER;
        break;
    case HUMAN:
        gameStart = HUMAN;
        break;
    default:
        cout << "Вы ввели недопустимую команду" << endl;
        cout << "Мы выбрали за вас режим игры - Человек " << endl;
        gameStart = HUMAN;
        return;
    }
}

/// <summary>
/// Обнуляем самое минимальное число в двумерном массиве. "Пустая ячейка" для пятнашки
/// </summary>
/// <param name="tags">Двумерный массив</param>
/// <param name="sizeMode">Размер доски</param>
void nullTags(int **tags, int sizeMode) {
    // Будим хранить минимальное число и его индекс
    int min = tags[0][0];
    int indexI = 0;
    int indexJ = 0;
    
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            if (min > tags[i][j]) {
                min = tags[i][j];
                indexI = i;
                indexJ = j;
            }
        }
    }
    // Делаем найденные элемент "свободным"
    tags[indexI][indexJ] = CLOSE;

}

/// <summary>
/// Проверяем чтобы пустая ячека была рядом с выбранном числом
/// </summary>
/// <param name="tags">Доска пятнашки в виде двумерного массива</param>
/// <param name="indexI">Индекс заданного числа по строке</param>
/// <param name="indexJ">Индекс заданного числа по столбцу</param>
/// <param name="sizeMode">Размер дроски</param>
/// <param name="indexIZero">Индекс пустого поля по строке</param>
/// <param name="indexJZero">Индекс пустого поля по столбцу</param>
/// <returns></returns>
bool chekZero(int ** tags, int indexI, int indexJ, int sizeMode, int &indexIZero, int &indexJZero) {
    
    // Определяем соседние позиции с выбранным числом которые необходимо првоерить 
    int stepUP      = indexI - 1;
    int stepDown    = indexI + 1;
    int stepLeft    = indexJ - 1;
    int stepRight   = indexJ + 1;

    // Проверяем на выход за границу массива
    stepUP    = (stepUP < 0) ? -1               : stepUP;
    stepDown  = (stepDown >= sizeMode) ? -1     : stepDown;
    stepLeft  = (stepLeft < 0) ? -1             : stepLeft;
    stepRight = (stepRight >= sizeMode) ? -1    : stepRight;

    // проверяем на наличие пустой ячейки рядом
    if (stepUP != -1) {
        if (tags[stepUP][indexJ] == CLOSE) {
            indexIZero = stepUP;
            indexJZero = indexJ;
            return true;
        }
    }
    if (stepDown != -1) {
        if (tags[stepDown][indexJ] == CLOSE) {
            indexIZero = stepDown;
            indexJZero = indexJ;
            return true;
        }
    }
    if (stepLeft != -1) {
        if (tags[indexI][stepLeft] == CLOSE) {
            indexIZero = indexI;
            indexJZero = stepLeft;
            return true;
        }
    }
    if (stepRight != -1) {
        if (tags[indexI][stepRight] == CLOSE) {
            indexIZero = indexI;
            indexJZero = stepRight;
            return true;
        }
    }
    return false; 
}

/// <summary>
/// Меняем местами два элемента двухмерного массива
/// </summary>
/// <param name="tags">Двухмерный масссив</param>
/// <param name="indexI">Индекс числа по строке</param>
/// <param name="indexJ">Индекс числа по столбцу</param>
/// <param name="indexIZero">Индекс пустой ячейки по строке</param>
/// <param name="indexJZero">Индекс пустой ячейки по столбцу</param>
void swap(int **tags, int indexI, int indexJ, int indexIZero, int indexJZero) {
    int temp = tags[indexI][indexJ];
    tags[indexI][indexJ] = CLOSE;
    tags[indexIZero][indexJZero] = temp;
}

/// <summary>
/// Запускаем процесс игры с человеком
/// </summary>
/// <param name="tags">Поле Пятнашек как двухмерный массив</param>
/// <param name="sizeMode">Размер доски</param>
void prossesGameForHuman(int **tags, int sizeMode, Statistic &statictic) {
    // Будет следить была ли выиграшная комбинация или нет для остановки игры
    bool gameEnd = false;

    // Число введенные пользователем которые необходимо поменять с пустой ячейкой
    int valueNumder = -1;

    // Индексы расположения числа в массиве который ввел пользователь
    int indexJ = -1;
    int indexI = -1;

    // Индексы где будем хранить позицию пустой ячейки
    int indexIZero = -1;
    int indexJZero = -1;


    cout << "...................Игра начинаеться......................" << endl;
    cout << "Вы должны будите ввести цифру с которую необходимо поменять местами с пустым поле" << endl;

    // Начинаем отчет
    statictic.timeStart = time(0);
    
    // Запускаем цикл пока не бдет правильного решения или не введите цифру "-1"
    while (!gameEnd) {
        // Визуализация поля игры Пятнашки
        showTagsElements(tags, sizeMode);

        // Запрос хода
        cout << "Ваш ход:\t";
        cin >> valueNumder;

        // Проверяем не букву ли ввел пользователь -1 для выхода из программы
        if (valueNumder == -1) {
            gameEnd = true;
            cout << "Выход из программы" << endl;
            break;
        }

        // Проверяем если такое число вообще на поле
        if (!checkElements(sizeMode, tags, valueNumder, indexI, indexJ)) {
            cout << "Такого числа нет на доске " << endl;
            cout << "Введите новое число" << endl;
            continue;
        }
    
        if (!chekZero(tags, indexI, indexJ, sizeMode, indexIZero, indexJZero)) {
            cout << "Пустая ячейка не находиться на соседних полях " << endl;
            cout << "Введите новое число" << endl;
            continue;
        }

        // Меняем местами пустую ячейку и заданное число
        swap(tags, indexI, indexJ, indexIZero, indexJZero);

        statictic.count++;

        // Проверка победной комбинации
    }

    // заканчиваем отчет
    statictic.timeEnd = time(0);

}

void prossesGameForCompiuter(int** tags, int sizeMode, Statistic& statictic) {
    // Будет следить была ли выиграшная комбинация или нет для остановки игры
    bool gameEnd = false;

    // Число введенные компьютером которые необходимо поменять с пустой ячейкой
    int valueNumder = -1;

    // Индексы расположения числа в массиве который ввел ПК
    int indexJ = -1;
    int indexI = -1;

    // Индексы где будем хранить позицию пустой ячейки
    int indexIZero = -1;
    int indexJZero = -1;


    cout << "...................Игра начинаеться......................" << endl;
    cout << "Вы должны будите ввести цифру с которую необходимо поменять местами с пустым поле" << endl;

    // Начинаем отчет
    statictic.timeStart = time(0);

    // Запускаем цикл пока не бдет правильного решения или не введите цифру "-1"
    while (!gameEnd) {
        // Визуализация поля игры Пятнашки
        showTagsElements(tags, sizeMode);

        // Запрос хода
        cout << "Ваш ход:\t";
        cin >> valueNumder;

        // Проверяем не букву ли ввел пользователь -1 для выхода из программы
        if (valueNumder == -1) {
            gameEnd = true;
            cout << "Выход из программы" << endl;
            break;
        }

        // Проверяем если такое число вообще на поле
        if (!checkElements(sizeMode, tags, valueNumder, indexI, indexJ)) {
            cout << "Такого числа нет на доске " << endl;
            cout << "Введите новое число" << endl;
            continue;
        }

        if (!chekZero(tags, indexI, indexJ, sizeMode, indexIZero, indexJZero)) {
            cout << "Пустая ячейка не находиться на соседних полях " << endl;
            cout << "Введите новое число" << endl;
            continue;
        }

        // Меняем местами пустую ячейку и заданное число
        swap(tags, indexI, indexJ, indexIZero, indexJZero);

        statictic.count++;

        // Проверка победной комбинации
    }

    // заканчиваем отчет
    statictic.timeEnd = time(0);
}

/// <summary>
/// Показ стат. данных
/// </summary>
/// <param name="statictic">Структура со стат данными </param>
void showStatistic(Statistic statictic) {
    cout << "Длительность игры\t " << (statictic.timeEnd - statictic.timeStart) << " сек." << endl;
    cout << "Количество бросков\t" << statictic.count <<endl;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    // Записываем стат данные
    Statistic statictic;

    // Размер полотна пятнашки
    int sizeMode = 0;

    // Запрос пользователя о режиме игры
    inputSettingsGame(sizeMode);

    // Создание двумерного массива в котором будем хранить все числа для игры
    int** tags = createTagsElements(sizeMode);

    // Заполнене двумерного массива случаным или ручным способом
    fillTagsElements(tags, sizeMode);

    // Визуализация двумерного массива
    showTagsElements(tags, sizeMode);

    // Кто играет компьютер или человек
    int gameStart = -1;
    inputGameUse(gameStart);

    // Удаление минимального значения из элементов в двумерном массиве для создание пустой ячейки
    nullTags(tags, sizeMode);

    // Визуализация двумерного массива
    showTagsElements(tags, sizeMode);
    
    // Очистка консоли перед игрой
    system("cls");

    // Реализация логики игры 1) при Ручном 2) компьютерном подходе
    switch (gameStart) {
        case COMPUTER:
            prossesGameForCompiuter(tags, sizeMode, statictic);
        break;
        case HUMAN:
            prossesGameForHuman(tags, sizeMode, statictic);
        break;
    }

    // Вывод статиcтики
    showStatistic(statictic);

    // Освобождаем выделенную память под динамический массив
    for (int i = 0; i < sizeMode; i++) {
        delete* (tags + i);
    }
    delete[] tags;

    return 0;
}
