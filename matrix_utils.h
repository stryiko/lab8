#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <string>

using namespace std;

const int MAX_SIZE = 100;

// Зчитування матриці з файлу
void get_matrix(string filename, double matrix[][MAX_SIZE], int &n, int &m);

// Запис результатів у файл
void show_matrix(string filename, const double matrix[][MAX_SIZE], int n, int m, double result);

// Знаходження мінімального серед максимальних елементів стовпців
double minOfColumnMaximums(const double matrix[][MAX_SIZE], int n, int m);

// Виведення матриці в консоль
void printMatrixToConsole(const double matrix[][MAX_SIZE], int n, int m);

#endif