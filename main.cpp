#include <iostream>
#include <windows.h>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // -------------------- Завдання 1 --------------------
    cout << "========== Завдання 1: Одновимірний масив ==========\n";

    int arr[MAX_SIZE];
    int n = 0;
    int k = 0;

    // Зчитування масиву з файлу
    get_mas("array_in_102.txt", arr, n, k);

    cout << "Початковий масив:\n";
    printArrayToConsole(arr, n);

    // Обробка масиву: після K-го елемента вставити 0
    insertZeroAfterK(arr, n, k);

    cout << "Результат після вставки 0 після " << k << "-го елемента:\n";
    printArrayToConsole(arr, n);

    // Запис результату у файл
    show_mas("array_out_102.txt", arr, n);

    // -------------------- Завдання 2 --------------------
    cout << "\n========== Завдання 2: Двовимірний масив ==========\n";

    double matrix[MAX_SIZE][MAX_SIZE];
    int m = 0;

    // Зчитування матриці з файлу
    get_matrix("matrix_in_28.txt", matrix, n, m);

    cout << "Початкова матриця:\n";
    printMatrixToConsole(matrix, n, m);

    // Обчислення мінімального серед максимальних елементів стовпців
    double result = minOfColumnMaximums(matrix, n, m);

    cout << "Мінімальний серед максимальних елементів стовпців = "
         << result << endl;

    // Запис результату у файл
    show_matrix("matrix_out_28.txt", matrix, n, m, result);

    // -------------------- Завдання 3 --------------------
    cout << "\n========== Завдання 3: Сортування ==========\n";

    char symbols[MAX_SIZE];
    int sizeSymbols = 0;

    // Зчитування символів з файлу
    get_char_array("sort_in_19.txt", symbols, sizeSymbols);

    cout << "Початковий символьний масив:\n";
    printCharArrayToConsole(symbols, sizeSymbols);

    // Бульбашкове сортування за зростанням
    bubbleSortAscending(symbols, sizeSymbols);

    cout << "Відсортований масив:\n";
    printCharArrayToConsole(symbols, sizeSymbols);

    // Запис у файл
    show_char_array("sort_out_19.txt", symbols, sizeSymbols);

    cout << "\nУсі завдання виконано. Результати записані у файли.\n";

    return 0;
}