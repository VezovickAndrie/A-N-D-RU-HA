//
// Created by root on 6/25/19.
//

#ifndef UNTITLED_METHODS_H
#define UNTITLED_METHODS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

void decBinary() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int binary = 0;
    int cnt = 0;

    while (n != 0) {
        int ost = n % 2;
        for (int i = 0; i < cnt; i++) {
            ost *= 10;
        }

        binary += ost;
        cnt++;
        n /= 2;
    }

    cout << "Binary - " << binary;

    int dec = 0;
    cnt = 0;
    while (binary != 0) {
        int ost = binary % 10;
        int num = 1;
        for (int i = 0; i < cnt; i++) {
            num *= 2;
        }

        dec += num * ost;
        cnt++;
        binary /= 10;
    }

    cout << endl << "Decimal - " << dec;
}

void decOctal() {
    cout << "Enter n: ";
    int n;
    cin >> n;

    int cnt = 0;
    int oct = 0;

    while (n != 0) {
        int ost = n % 8;
        for (int i = 0; i < cnt; i++) {
            ost *= 10;
        }

        oct += ost;
        cnt++;
        n /= 8;
    }

    cout << "Octal - " << oct;
    cout << endl;

    int dec = 0;
    cnt = 0;

    while (oct != 0) {
        int ost = oct % 10;
        int num = 1;
        for (int i = 0; i < cnt; i++) {
            num *= 8;
        }

        dec += ost * num;
        cnt++;
        oct /= 10;
    }

    cout << "Decimal - " << dec;
}

void decHex() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    string hex = "";

    while (n != 0) {
        int ost = n % 16;

        if (ost > 9) {
            hex += (char) (ost + 55);
        } else {
            hex += (char) (ost + 48);
        }

        n /= 16;
    }

    reverse(hex.begin(), hex.end());

    cout << "Hexadecimal - " << hex << endl;
    int dec = 0;

    for (int i = hex.size() - 1; i >= 0; i--) {
        char ch = hex[i];
        int p = 1;
        if (ch >= 65 && ch <= 70) {
            p = (int) ch - 55;
        } else {
            p = (int) ch - 48;
        }
        int num = 1;
        for (int j = 0; j < hex.size() - i - 1; j++) {
            num *= 16;
        }

        dec += p * num;
    }

    cout << "Decimal - " << dec;
}

void move() {
    int k;
    cout << "Enter k: ";
    cin >> k;

    int *mas1 = new int[6]{0, 1, 2, 3, 4, 5};

    for (int i = 0; i < 6; i++) {
        cout << mas1[i] << " ";
    }
    int *mas2 = new int[6];

    for (int i = 0; i < 6; i++) {
        int index = (i + k) % 6;
        mas2[index] = mas1[i];
    }

    cout << endl;

    for (int i = 0; i < 6; i++) {
        cout << mas2[i] << " ";
    }

    delete[] mas1;
    delete[] mas2;
}

void matrixPower() {
    int k;
    cout << "Enter k: ";
    cin >> k;

    int **matrix1 = new int *[3];
    int *row1 = new int[3]{2, 3, 4};
    int *row2 = new int[3]{3, 1, 5};
    int *row3 = new int[3]{7, 4, 2};

    matrix1[0] = row1;
    matrix1[1] = row2;
    matrix1[2] = row3;

    int **matrix2 = new int *[3];
    for (int i = 0; i < 3; i++) {
        matrix2[i] = new int[3];
    }

    int **matrix3 = new int *[3];
    for (int i = 0; i < 3; i++) {
        matrix3[i] = new int[3];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix3[i][j] = matrix1[i][j];
        }
    }

    for (int g = 1; g < k; g++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix2[i][j] = matrix3[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int sum = 0;
                for (int h = 0; h < 3; h++) {
                    sum += matrix1[i][h] * matrix2[h][j];
                }
                matrix3[i][j] = sum;
            }
        }
    }

    cout << "Matrix in " << k << " power :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << matrix3[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < 3; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] matrix3[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] matrix3;

}

void calcMatrix() {
    int **matrix1 = new int *[4];
    int **matrix2 = new int *[4];
    int **matrix3 = new int *[4];

    for (int i = 0; i < 4; i++) {
        matrix1[i] = new int[4];
        matrix2[i] = new int[4];
        matrix3[i] = new int[4];
    }

    cout << "Enter first matrix: \n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter second matrix: \n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix2[i][j];
        }
    }

    cout << "Multiply matrix: \n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;
            for (int h = 0; h < 4; h++) {
                sum += matrix1[i][h] * matrix2[h][j];
            }

            matrix3[i][j] = sum;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << matrix3[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < 4; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] matrix3[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] matrix3;
}

void defineString() {

    ifstream in("/root/CLionProjects/untitled/in.txt");
    if(!in.is_open()) {
        cout << "Error";
    }

    string *strings = new string[5];
    int index = 0;

    while (!in.eof()) {
        getline(in, strings[index++]);
    }

    for (int i = 0; i < 5; i++) {
        string str = strings[i];

        bool k = true;
        bool z = true;
        for (int j = 0; j < str.size(); j++) {
            if (j == 0) {
                if (str[j] != '-' && (str[j] < 48 || str[j] > 57)) {
                    k = false;
                }
                if (str[j] != '_' && str[j] != '$' && !(str[j] >= 65 && str[j] <= 90) &&
                    !(str[j] >= 97 && str[j] <= 122)) {
                    z = false;
                }
            } else {
                if (str[j] < 48 || str[j] > 57) {
                    k = false;
                }
                if (str[j] != '_' && str[j] != '$' && !(str[j] >= 65 && str[j] <= 90) &&
                    !(str[j] >= 97 && str[j] <= 122) && !(str[j] >= 48 && str[j] <= 57)) {
                    z = false;
                }
            }
        }

        if (k || z) {
            if (k) {
                cout << "Number" << endl;
            } else {
                cout << "Identifier" << endl;
            }
        } else {
            cout << "None" << endl;
        }
    }

    in.close();
    delete[] strings;
}

#endif //UNTITLED_METHODS_H
