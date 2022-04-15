/*
    ��������.����� ������ ���� 3 * 3(8) ��� 4 * 4 (15).
    ����� -������� - ���������
    ��������� ���������� - ������ - ������������
    ���������� - ����� ����������� �� ���� �������� - ���������� ������������
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>



using namespace std;

/// <summary>
/// ����� ������ ��� ������ � �������� ������� ��� ���������
/// </summary>
enum UseGame {
    HUMAN = 1,
    COMPUTER
};

/// <summary>
/// ����� ������������ ��� ����� ��������� ����� � ��������
/// </summary>
enum UseUserFilltable {
    RANDOM = 1,
    USER
};

/// <summary>
/// ���������� ������ ������ ������ ��� �� ������
/// </summary>
enum Status�ell {
    CLOSE = -2,
};

/// <summary>
/// ��������� ���������� ����
/// </summary>
struct Statistic{
    // ����� ������� ����
    time_t timeStart;
    // ����� ��������� ����
    time_t timeEnd;
    // ���������� �������
    int count = 0;
};

/// <summary>
/// ������ ������������ � ������ ���� � �������� 3 �� 3 ��� 4 �� 4
/// </summary>
/// <param name="sizeMode">�������� ������ ����� �������� </param>
void inputSettingsGame(int& sizeMode) {
    // ����� ������� ���� � ��������
    int userModeGame = 0;

    // ����� ������ ���� 3 * 3 ��� 4 * 4
    cout << "�������� ����� ���� � ��������:" << endl;
    cout << "\t ����� (3 * 3) ������� 1" << endl;
    cout << "\t ����� (4 * 4) ������� 2\n\t\t";
    cin >> userModeGame;

    switch (userModeGame) {
    case 1:
        sizeMode = 3;
        break;
    case 2:
        sizeMode = 4;
        break;
    default:
        cout << "�� ����� ������������ �������" << endl;
        cout << "�� ������� �� ��� ����� ���� - 1 " << endl;
        sizeMode = 3;
    }
}

/// <summary>
/// �������������� ��������� ������ ��� ����������
/// </summary>
/// <param name="sizeMode">������ ������ ������� sizeMode �� sizeMode </param>
/// <returns> ���������� ��������� �� ��������� ��������� ������ </returns>
int** createTagsElements(int sizeMode) {
    // �������� ���������� �������
    int** tags = new int* [sizeMode] {0};

    for (int i = 0; i < sizeMode; i++) {
        *(tags + i) = new int[sizeMode] {0};
    }
    return tags;
}

/// <summary>
/// ��������� ���� ����� �������� � �������� ��� ���
/// </summary>
/// <param name="powSizeMode">������ �������</param>
/// <param name="elements">��������� �� ������</param>
/// <param name="valueUser">��� �������� ���� ���������</param>
/// <returns>True ���� ����� ������� ���</returns>
inline bool checkElements(int powSizeMode, int *elements, int valueUser) {
    // ��������� ���� �� ��� ���������� ����������� ������� 
    for (int j = 0; j < powSizeMode; j++) {
        // ��������� ���� ���� ������� ��� � ������� ��� ���
        if (*(elements + j) == valueUser) {
            // ���� ������� ��� ���� � ����� �������
            return true;
        }
    }
    return false;
}

/// <summary>
/// ��������� ���� ����� �������� � �������� ��� ���
/// </summary>
/// <param name="powSizeMode">������ �����</param>
/// <param name="elements">��������� �� ������</param>
/// <param name="valueUser">��� �������� ���� ���������</param>
/// <returns>True ���� ����� ������� ���</returns>
inline bool checkElements(int SizeMode, int** elements, int valueUser, int &indexI, int &indexJ) {
    // ��������� ���� �� ��� ���������� ���������� ������� 
    for (int i = 0; i < SizeMode; i++) {
        for (int j = 0; j < SizeMode; j++) {
            // ��������� ���� ���� ������� ��� � ������� ��� ���
            if (elements[i][j] == valueUser) {
                indexI = i;
                indexJ = j;
                // ���� ������� ��� ���� � ����� �������
                return true;
            }
        }
    }
    return false;
}


/// <summary>
/// ������� ���������� ������. ��������� ��� ������ ��� �������� ������������������� � ����������� �� ������� ����� ��������.
/// 1 ������� ��������� ��� ��������� ������� ��� ���������� �����.
/// </summary>
/// <param name="sizeMode">������ ����� sizeMode �� sizeMode</param>
/// <returns>���������� ��������� �� ���������� ������ ���������� ������� � ��������� �������</returns>
int* randValue(int sizeMode) {
    // ���������� ����������� ��� ����������� �������
    int powSizeMode = sizeMode * sizeMode;

    // ������� ������ �� ����� ��������� �����������    
    int* elements = new int[powSizeMode] {-1};

    /* �������� ������ ������ ��������������� ������� �� ��������� ���������
    �� powSizeMode ��� ����������*/
    for (int i = 0; i < powSizeMode; i++) {

        // ��������� �������� �� �������� ���������
        int valueRand = rand() % powSizeMode + 1;

        // ���� �� ����� ��������� ����� ��� ������ ���
        if (!checkElements(powSizeMode, elements, valueRand)) {
            // ���� ������ �������� ��� �� ��������� ��� � �������
            *(elements + i) = valueRand;
        }
        else {
            /* ���� ������ ������� ���� �������� �� ���������� ���
              � ������ ��� ����� �� ����� �.� �� ���������� i-1 ������� */
            i--;
        }
    };

    return elements;
};

/// <summary>
/// ������� ���������� ������. ��������� ��� ������ ��� �������� ������������������� � ����������� �� ������� ����� ��������.
/// 2 ������� ��������� ��� � ������.
/// </summary>
/// <param name="sizeMode">������ ����� sizeMode �� sizeMode</param>
/// <returns>���������� ��������� �� ���������� ������ ���������� ������� � ��������� �������</returns>
int* userValue(int sizeMode) {
    // ���������� ����������� ��� ����������� �������
    int powSizeMode = sizeMode * sizeMode;

    // ������� ������ �� ����� ��������� �����������    
    int* elements = new int[powSizeMode] {-1};

    // ������ � ������������ �� ����������
    cout << "������� ������������������ �� " << powSizeMode << " ����� ��� ���������� �������� �� �������� ����� ��������";
    cout << endl;

    int valueUser = 0;
    /* �������� ������ ������ ��������������� ������� c �������� � ������������ � ���������
    �� powSizeMode ��� ����������*/
    for (int i = 0; i < powSizeMode; i++) {
        // ���� ������������
        cout << "����� " << i+1 << " = ";
        cin >> valueUser;

        // ���� �� ����� ��������� ����� ��� ������ ���
        if (!checkElements(powSizeMode, elements, valueUser)) {
            // ���� ������ �������� ��� �� ��������� ��� � �������
            *(elements + i) = valueUser;
        }
            cout << "����� ����� ��� ����!" << endl;
            cout << "������� ������ �����" << endl;
            i--;
        }
    return elements;
};

/// <summary>
/// ��������� ��������� ������� ��������� ������� �� ��������� ����������� ������� 
/// </summary>
/// <param name="tags">���������� ��������� ������ </param>
/// <param name="sizeMode">������ ����� </param>
void fillTagsElements(int** tags, int sizeMode) {
    // ����� ������������ ��� ��������� ����� � ��������
    int caseUser = -1;

    // ���������� ����������� ��� ����������� �������
    int powSizeMode = sizeMode * sizeMode;

    // ����������� � ������������ ��� ����� ��������� ����� � ��������
    cout << "��������� �����" << endl;
    cout << "\t �������� ������� - �������� 1" << endl;
    cout << "\t ������ ������� - �������� 2" << endl;
    cin >> caseUser;

    // ��������� �� ���������� ��������� ������� ��� �������� ���������� ������ ������� sizeMode*sizeMode� 
    int *pElem;

    switch (caseUser)
    {
        case RANDOM:
            // ��������� �������� �������
            pElem = randValue(sizeMode);
        break;
        case USER:
            // ��������� ������ �������
            pElem = userValue(sizeMode);
        break;
        default:
            cout << "�� ����� ������������ �������" << endl;
            cout << "�� ������� �� ��� ����� ���������� - �������� " << endl;
            // ��������� �������� �������
            pElem = randValue(sizeMode);
        break;
    }

    // ������� ��� ����������� �������
    int index = 0;
    // ��������� ��������� ������
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            tags[i][j] = *(pElem + index++);
        }
    }
}

/// <summary>
/// ������� �� ����� ��������� ������ 
/// </summary>
/// <param name="tags">��������� �� ��������� ������</param>
/// <param name="sizeMode">������ ����� � ��������</param>
void showTagsElements(int** tags, int sizeMode) {
    cout << endl;
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            // ����������� � ����������� �� ������� ������
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
/// ����������� � ������������ ��� ������. 1 �����������. 2 �������.
/// </summary>
/// <param name="gameStart">���������� ����� ������������</param>
void inputGameUse(int& gameStart) {

    // ����������� ��� ������ ��������� ��� �������
    cout << "�������� ��� ����� ������ � ��������:" << endl;
    cout << "\t������� ������� -1 " << endl;
    cout << "\t��������� ������� -2 \n\t";
    // ����� ������������
    cin >> gameStart;

    // ��������� ���������� ��������
    switch (gameStart) {
    case COMPUTER:
        gameStart = COMPUTER;
        break;
    case HUMAN:
        gameStart = HUMAN;
        break;
    default:
        cout << "�� ����� ������������ �������" << endl;
        cout << "�� ������� �� ��� ����� ���� - ������� " << endl;
        gameStart = HUMAN;
        return;
    }
}

/// <summary>
/// �������� ����� ����������� ����� � ��������� �������. "������ ������" ��� ��������
/// </summary>
/// <param name="tags">��������� ������</param>
/// <param name="sizeMode">������ �����</param>
void nullTags(int **tags, int sizeMode) {
    // ����� ������� ����������� ����� � ��� ������
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
    // ������ ��������� ������� "���������"
    tags[indexI][indexJ] = CLOSE;

}

/// <summary>
/// ��������� ����� ������ ����� ���� ����� � ��������� ������
/// </summary>
/// <param name="tags">����� �������� � ���� ���������� �������</param>
/// <param name="indexI">������ ��������� ����� �� ������</param>
/// <param name="indexJ">������ ��������� ����� �� �������</param>
/// <param name="sizeMode">������ ������</param>
/// <param name="indexIZero">������ ������� ���� �� ������</param>
/// <param name="indexJZero">������ ������� ���� �� �������</param>
/// <returns></returns>
bool chekZero(int ** tags, int indexI, int indexJ, int sizeMode, int &indexIZero, int &indexJZero) {
    
    // ���������� �������� ������� � ��������� ������ ������� ���������� ��������� 
    int stepUP      = indexI - 1;
    int stepDown    = indexI + 1;
    int stepLeft    = indexJ - 1;
    int stepRight   = indexJ + 1;

    // ��������� �� ����� �� ������� �������
    stepUP    = (stepUP < 0) ? -1               : stepUP;
    stepDown  = (stepDown >= sizeMode) ? -1     : stepDown;
    stepLeft  = (stepLeft < 0) ? -1             : stepLeft;
    stepRight = (stepRight >= sizeMode) ? -1    : stepRight;

    // ��������� �� ������� ������ ������ �����
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
/// ������ ������� ��� �������� ����������� �������
/// </summary>
/// <param name="tags">���������� �������</param>
/// <param name="indexI">������ ����� �� ������</param>
/// <param name="indexJ">������ ����� �� �������</param>
/// <param name="indexIZero">������ ������ ������ �� ������</param>
/// <param name="indexJZero">������ ������ ������ �� �������</param>
void swap(int **tags, int indexI, int indexJ, int indexIZero, int indexJZero) {
    int temp = tags[indexI][indexJ];
    tags[indexI][indexJ] = CLOSE;
    tags[indexIZero][indexJZero] = temp;
}

/// <summary>
/// ��������� ������� ���� � ���������
/// </summary>
/// <param name="tags">���� �������� ��� ���������� ������</param>
/// <param name="sizeMode">������ �����</param>
void prossesGameForHuman(int **tags, int sizeMode, Statistic &statictic) {
    // ����� ������� ���� �� ���������� ���������� ��� ��� ��� ��������� ����
    bool gameEnd = false;

    // ����� ��������� ������������� ������� ���������� �������� � ������ �������
    int valueNumder = -1;

    // ������� ������������ ����� � ������� ������� ���� ������������
    int indexJ = -1;
    int indexI = -1;

    // ������� ��� ����� ������� ������� ������ ������
    int indexIZero = -1;
    int indexJZero = -1;


    cout << "...................���� �����������......................" << endl;
    cout << "�� ������ ������ ������ ����� � ������� ���������� �������� ������� � ������ ����" << endl;

    // �������� �����
    statictic.timeStart = time(0);
    
    // ��������� ���� ���� �� ���� ����������� ������� ��� �� ������� ����� "-1"
    while (!gameEnd) {
        // ������������ ���� ���� ��������
        showTagsElements(tags, sizeMode);

        // ������ ����
        cout << "��� ���:\t";
        cin >> valueNumder;

        // ��������� �� ����� �� ���� ������������ -1 ��� ������ �� ���������
        if (valueNumder == -1) {
            gameEnd = true;
            cout << "����� �� ���������" << endl;
            break;
        }

        // ��������� ���� ����� ����� ������ �� ����
        if (!checkElements(sizeMode, tags, valueNumder, indexI, indexJ)) {
            cout << "������ ����� ��� �� ����� " << endl;
            cout << "������� ����� �����" << endl;
            continue;
        }
    
        if (!chekZero(tags, indexI, indexJ, sizeMode, indexIZero, indexJZero)) {
            cout << "������ ������ �� ���������� �� �������� ����� " << endl;
            cout << "������� ����� �����" << endl;
            continue;
        }

        // ������ ������� ������ ������ � �������� �����
        swap(tags, indexI, indexJ, indexIZero, indexJZero);

        statictic.count++;

        // �������� �������� ����������
    }

    // ����������� �����
    statictic.timeEnd = time(0);

}

void prossesGameForCompiuter(int** tags, int sizeMode, Statistic& statictic) {
    // ����� ������� ���� �� ���������� ���������� ��� ��� ��� ��������� ����
    bool gameEnd = false;

    // ����� ��������� ����������� ������� ���������� �������� � ������ �������
    int valueNumder = -1;

    // ������� ������������ ����� � ������� ������� ���� ��
    int indexJ = -1;
    int indexI = -1;

    // ������� ��� ����� ������� ������� ������ ������
    int indexIZero = -1;
    int indexJZero = -1;


    cout << "...................���� �����������......................" << endl;
    cout << "�� ������ ������ ������ ����� � ������� ���������� �������� ������� � ������ ����" << endl;

    // �������� �����
    statictic.timeStart = time(0);

    // ��������� ���� ���� �� ���� ����������� ������� ��� �� ������� ����� "-1"
    while (!gameEnd) {
        // ������������ ���� ���� ��������
        showTagsElements(tags, sizeMode);

        // ������ ����
        cout << "��� ���:\t";
        cin >> valueNumder;

        // ��������� �� ����� �� ���� ������������ -1 ��� ������ �� ���������
        if (valueNumder == -1) {
            gameEnd = true;
            cout << "����� �� ���������" << endl;
            break;
        }

        // ��������� ���� ����� ����� ������ �� ����
        if (!checkElements(sizeMode, tags, valueNumder, indexI, indexJ)) {
            cout << "������ ����� ��� �� ����� " << endl;
            cout << "������� ����� �����" << endl;
            continue;
        }

        if (!chekZero(tags, indexI, indexJ, sizeMode, indexIZero, indexJZero)) {
            cout << "������ ������ �� ���������� �� �������� ����� " << endl;
            cout << "������� ����� �����" << endl;
            continue;
        }

        // ������ ������� ������ ������ � �������� �����
        swap(tags, indexI, indexJ, indexIZero, indexJZero);

        statictic.count++;

        // �������� �������� ����������
    }

    // ����������� �����
    statictic.timeEnd = time(0);
}

/// <summary>
/// ����� ����. ������
/// </summary>
/// <param name="statictic">��������� �� ���� ������� </param>
void showStatistic(Statistic statictic) {
    cout << "������������ ����\t " << (statictic.timeEnd - statictic.timeStart) << " ���." << endl;
    cout << "���������� �������\t" << statictic.count <<endl;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    // ���������� ���� ������
    Statistic statictic;

    // ������ ������� ��������
    int sizeMode = 0;

    // ������ ������������ � ������ ����
    inputSettingsGame(sizeMode);

    // �������� ���������� ������� � ������� ����� ������� ��� ����� ��� ����
    int** tags = createTagsElements(sizeMode);

    // ��������� ���������� ������� �������� ��� ������ ��������
    fillTagsElements(tags, sizeMode);

    // ������������ ���������� �������
    showTagsElements(tags, sizeMode);

    // ��� ������ ��������� ��� �������
    int gameStart = -1;
    inputGameUse(gameStart);

    // �������� ������������ �������� �� ��������� � ��������� ������� ��� �������� ������ ������
    nullTags(tags, sizeMode);

    // ������������ ���������� �������
    showTagsElements(tags, sizeMode);
    
    // ������� ������� ����� �����
    system("cls");

    // ���������� ������ ���� 1) ��� ������ 2) ������������ �������
    switch (gameStart) {
        case COMPUTER:
            prossesGameForCompiuter(tags, sizeMode, statictic);
        break;
        case HUMAN:
            prossesGameForHuman(tags, sizeMode, statictic);
        break;
    }

    // ����� �����c����
    showStatistic(statictic);

    // ����������� ���������� ������ ��� ������������ ������
    for (int i = 0; i < sizeMode; i++) {
        delete* (tags + i);
    }
    delete[] tags;

    return 0;
}
