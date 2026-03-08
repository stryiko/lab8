#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>

using namespace std;

const int MAX_SIZE = 100;

// Функція зчитування одновимірного масиву та числа K з файлу
void get_mas(string filename, int arr[], int &n, int &k);

// Функція запису одновимірного масиву у файл
void show_mas(string filename, const int arr[], int n);

// Функція вставки нульового елемента після K-го
void insertZeroAfterK(int arr[], int &n, int k);

// Виведення масиву в консоль
void printArrayToConsole(const int arr[], int n);

// Зчитування символьного масиву з файлу
void get_char_array(string filename, char arr[], int &n);

// Запис символьного масиву у файл
void show_char_array(string filename, const char arr[], int n);

// Бульбашкове сортування за зростанням
void bubbleSortAscending(char arr[], int n);

// Виведення символьного масиву в консоль
void printCharArrayToConsole(const char arr[], int n);

#endif