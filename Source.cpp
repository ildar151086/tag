/*
    Пятнашки.Выбор режима игры 3 * 3(8) или 4 * 4 (15).
    Режим -Человек - Компьютер
    Начальное размещение - ручное - компьютерное
    Статистика - время потраченное на сбор пятнашки - количество перестановок
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>



using namespace std;

enum UseGame {
    human = 1,
    computer
};

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
        return;
    }
}

int** createTagsElements(int sizeMode) {
    // Создание двумерного массива
    int** tags = new int* [sizeMode] {0};

    for (int i = 0; i < sizeMode; i++) {
        *(tags + i) = new int[sizeMode] {0};
    }
    return tags;
}

int* randValue(int sizeMode) {
    // Определяем размерность для одномерного массива
    int powSizeMode = sizeMode * sizeMode;

    // Создаем массив из чисел выбранной размернотси    
    int* elements = new int[powSizeMode];

    // Запоняем данный массив последовательно числами
    for (int i = 0; i < powSizeMode; i++) {
        int index = rand() % powSizeMode + 1;

        bool valueIn = false;
        // Проверяем если этот элемент уже в массиве или нет
        for (int j = 0; j < powSizeMode; j++) {
            if (*(elements + j) == index) {
                // Этот элемент уже есть в нашем двойном массиве
                valueIn = true;
            }
        }

        if (!valueIn) {
            // Если такого элемента нет то добавляем в массиив
            *(elements + i) = index;
        }
        else {
            // делаем шаг назад т.к не заполнилши j-1 элемент
            i--;
        }
    };

    return elements;
}

void fillTagsElements(int** tags, int sizeMode) {

    // Определяем размерность для одномерного массива
    int powSizeMode = sizeMode * sizeMode;

    // Указатель на одномерный массив размера sizeMode*sizeModeи его счетчик
    int* pElem = randValue(sizeMode);
    int index = 0;

    // Записываем нашу последовательность случайном образом в пятнашки
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            // Присваеваем его нашему двумерному массиву
            tags[i][j] = *(pElem + index++);
        }
    }
}

void showTagsElements(int** tags, int sizeMode) {
    cout << endl;

    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            cout << "\t\t" << tags[i][j] << " ";
        }
        cout << endl;
    }
}

void inputGameUse(int& gameStart) {

    // Кто играет Компьютер или -Человек
    cout << "Выбирите кто будет играть в пятнашки:" << endl;
    cout << "\tКомпьютер вариант -1 " << endl;
    cout << "\tЧеловек вариант -2 \n\t";
    // Выбор пользователя
    cin >> gameStart;

    // Обработка введенного значения
    switch (gameStart) {
    case computer:
        gameStart = computer;
        break;
    case human:
        gameStart = human;
        break;
    default:
        cout << "Вы ввели недопустимую команду" << endl;
        cout << "Мы выбрали за вас режим игры - Человек " << endl;
        gameStart = human;
        return;
    }
}

int main()
{
    srand(time(0));
    // Размер полотна пятнашки
    int sizeMode = 0;

    // Запрос пользователя о режиме игры
    inputSettingsGame(sizeMode);

    // Создание двумерного массива
    int** tags = createTagsElements(sizeMode);

    // Заполнене двумерного массива случаным или ручным способом
    fillTagsElements(tags, sizeMode);

    // Визуализация двумерного массива
    showTagsElements(tags, sizeMode);

    // Кто играет компьютер или человек
    int gameStart = -1;
    inputGameUse(gameStart);


    // Реализация логики игры 1) при Ручном 2) компьютерном подходе
    // Визуализация каждого шага игры в консоле
    // Подчет статистики и времени



    // Освобождаем выделенную память
    for (int i = 0; i < sizeMode; i++) {
        delete* (tags + i);
    }
    delete[] tags;

    return 0;
}
