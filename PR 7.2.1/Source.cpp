// Lab_7_2_1.cpp
// Обухова Віктора
// Лабораторна робота No 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            R[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << R[i][j];
        cout << endl;
    }
    cout << endl;
}

void SearchMin(int** R, const int rowCount, const int colCount, int* arr)
{
    int min, x = 0;

    for (int i = 0; i < rowCount; i++)
    {
        min = R[i][0];
        for (int j = 1; j < colCount; j++)
        {
            if (R[i][j] < min)
                min = R[i][j];
        }
        arr[x] = min;
        x++;
    }

}
int SearchMax(int* arr, const int rowCount)
{
    int max = arr[0];

    for (int i = 1; i < rowCount; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int main()
{
    srand((unsigned)time(NULL));

    //Діапазон значень елементів матриці
    int Low = 5;
    int  High = 35;

    int  rowCount = 5; // Кількість рядків
    int  colCount = 5; // Кількість стовпців


    int** R = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    Create(R, rowCount, colCount, Low, High);
    Print(R, rowCount, colCount);
    cout << endl;

    int* arr = new int[rowCount];

    SearchMin(R, rowCount, colCount, arr);
    int Max = SearchMax(arr, rowCount);

    cout << setw(4) << "Max of Min = " << Max << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}