#include "matrix_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

// Функція зчитує матрицю з файлу
// Формат файлу:
// n m
// елементи матриці по рядках
void get_matrix(string filename, double matrix[][MAX_SIZE], int &n, int &m) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        n = 0;
        m = 0;
        return;
    }

    fin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> matrix[i][j];
        }
    }

    fin.close();
}

// Функція записує матрицю та результат у файл
void show_matrix(string filename, const double matrix[][MAX_SIZE], int n, int m, double result) {
    ofstream fout(filename);

    if (!fout.is_open()) {
        cout << "Помилка створення файлу " << filename << endl;
        return;
    }

    fout << "Матриця:\n";
    fout << n << " " << m << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << matrix[i][j] << "\t";
        }
        fout << endl;
    }

    fout << "\nМінімальний серед максимальних елементів стовпців = "
         << result << endl;

    fout.close();
}

// Функція знаходить мінімальний серед максимальних елементів стовпців
double minOfColumnMaximums(const double matrix[][MAX_SIZE], int n, int m) {
    // Беремо максимум першого стовпця
    double minAmongMax;
    double maxInColumn = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (matrix[i][0] > maxInColumn) {
            maxInColumn = matrix[i][0];
        }
    }

    minAmongMax = maxInColumn;

    // Обходимо інші стовпці
    for (int j = 1; j < m; j++) {
        maxInColumn = matrix[0][j];

        for (int i = 1; i < n; i++) {
            if (matrix[i][j] > maxInColumn) {
                maxInColumn = matrix[i][j];
            }
        }

        if (maxInColumn < minAmongMax) {
            minAmongMax = maxInColumn;
        }
    }

    return minAmongMax;
}

// Виведення матриці в консоль
void printMatrixToConsole(const double matrix[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}