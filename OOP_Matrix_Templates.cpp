#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
class Matrix
{
private:
    T** arr;
    int rows, cols;
public:
    Matrix() : arr(nullptr), rows(0), cols(0) {};
    Matrix(int r, int c);
    ~Matrix();
    void show() const;
    void fill();
    void randomFill();

};

template<typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c)
{
    arr = new T * [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new T[cols]();
}

template<typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

template<typename T>
void Matrix<T>::show() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

template<typename T>
void Matrix<T>::fill()
{
    if (arr != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "[" << i << "]" << "[" << j << "]: ";
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Matrix is not initialized!" << endl;
    }

}

template<typename T>
void Matrix<T>::randomFill()
{
    if (arr != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = rand() % 100 + 1;
            }
        }
    }
    else
    {
        cout << "Matrix is not initialized!" << endl;
    }
}



int main()
{
    srand(time(0));
    
    int rows = 5;
    int cols = 5;

    Matrix<int> c(rows, cols);
    c.show();
    c.randomFill();
    c.show();
}