#include "array_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

// Функція зчитує масив і число K з файлу
// Формат файлу:
// n
// елементи масиву
// k
void get_mas(string filename, int arr[], int &n, int &k) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        n = 0;
        k = 0;
        return;
    }

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin >> k;

    fin.close();
}

// Функція записує масив у файл
void show_mas(string filename, const int arr[], int n) {
    ofstream fout(filename);

    if (!fout.is_open()) {
        cout << "Помилка створення файлу " << filename << endl;
        return;
    }

    fout << "Результуючий масив:\n";
    fout << n << endl;

    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }

    fout << endl;
    fout.close();
}

// Функція вставляє 0 після K-го елемента
void insertZeroAfterK(int arr[], int &n, int k) {
    // Перевірка коректності K
    if (k < 1 || k > n || n >= MAX_SIZE) {
        cout << "Некоректне значення K або масив переповнений.\n";
        return;
    }

    // Зсуваємо елементи вправо, починаючи з кінця
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }

    // Вставляємо 0 після K-го елемента
    arr[k] = 0;
    n++;
}

// Виведення масиву в консоль
void printArrayToConsole(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція зчитування символьного масиву з файлу
// Формат файлу:
// n
// символи через пробіл
void get_char_array(string filename, char arr[], int &n) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        n = 0;
        return;
    }

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();
}

// Функція запису символьного масиву у файл
void show_char_array(string filename, const char arr[], int n) {
    ofstream fout(filename);

    if (!fout.is_open()) {
        cout << "Помилка створення файлу " << filename << endl;
        return;
    }

    fout << "Відсортований символьний масив:\n";
    fout << n << endl;

    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }

    fout << endl;
    fout.close();
}

// Бульбашкове сортування за зростанням
void bubbleSortAscending(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Виведення символьного масиву в консоль
void printCharArrayToConsole(const char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}