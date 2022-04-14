/*
    ��������.����� ������ ���� 3 * 3(8) ��� 4 * 4 (15).
    ����� -������� - ���������
    ��������� ���������� - ������ - ������������
    ���������� - ����� ����������� �� ���� �������� - ���������� ������������
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
        return;
    }
}

int** createTagsElements(int sizeMode) {
    // �������� ���������� �������
    int** tags = new int* [sizeMode] {0};

    for (int i = 0; i < sizeMode; i++) {
        *(tags + i) = new int[sizeMode] {0};
    }
    return tags;
}

int* randValue(int sizeMode) {
    // ���������� ����������� ��� ����������� �������
    int powSizeMode = sizeMode * sizeMode;

    // ������� ������ �� ����� ��������� �����������    
    int* elements = new int[powSizeMode];

    // �������� ������ ������ ��������������� �������
    for (int i = 0; i < powSizeMode; i++) {
        int index = rand() % powSizeMode + 1;

        bool valueIn = false;
        // ��������� ���� ���� ������� ��� � ������� ��� ���
        for (int j = 0; j < powSizeMode; j++) {
            if (*(elements + j) == index) {
                // ���� ������� ��� ���� � ����� ������� �������
                valueIn = true;
            }
        }

        if (!valueIn) {
            // ���� ������ �������� ��� �� ��������� � �������
            *(elements + i) = index;
        }
        else {
            // ������ ��� ����� �.� �� ���������� j-1 �������
            i--;
        }
    };

    return elements;
}

void fillTagsElements(int** tags, int sizeMode) {

    // ���������� ����������� ��� ����������� �������
    int powSizeMode = sizeMode * sizeMode;

    // ��������� �� ���������� ������ ������� sizeMode*sizeMode� ��� �������
    int* pElem = randValue(sizeMode);
    int index = 0;

    // ���������� ���� ������������������ ��������� ������� � ��������
    for (int i = 0; i < sizeMode; i++) {
        for (int j = 0; j < sizeMode; j++) {
            // ����������� ��� ������ ���������� �������
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

    // ��� ������ ��������� ��� -�������
    cout << "�������� ��� ����� ������ � ��������:" << endl;
    cout << "\t��������� ������� -1 " << endl;
    cout << "\t������� ������� -2 \n\t";
    // ����� ������������
    cin >> gameStart;

    // ��������� ���������� ��������
    switch (gameStart) {
    case computer:
        gameStart = computer;
        break;
    case human:
        gameStart = human;
        break;
    default:
        cout << "�� ����� ������������ �������" << endl;
        cout << "�� ������� �� ��� ����� ���� - ������� " << endl;
        gameStart = human;
        return;
    }
}

int main()
{
    srand(time(0));
    // ������ ������� ��������
    int sizeMode = 0;

    // ������ ������������ � ������ ����
    inputSettingsGame(sizeMode);

    // �������� ���������� �������
    int** tags = createTagsElements(sizeMode);

    // ��������� ���������� ������� �������� ��� ������ ��������
    fillTagsElements(tags, sizeMode);

    // ������������ ���������� �������
    showTagsElements(tags, sizeMode);

    // ��� ������ ��������� ��� �������
    int gameStart = -1;
    inputGameUse(gameStart);


    // ���������� ������ ���� 1) ��� ������ 2) ������������ �������
    // ������������ ������� ���� ���� � �������
    // ������ ���������� � �������



    // ����������� ���������� ������
    for (int i = 0; i < sizeMode; i++) {
        delete* (tags + i);
    }
    delete[] tags;

    return 0;
}
