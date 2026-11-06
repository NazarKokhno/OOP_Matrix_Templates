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
    Matrix(const Matrix& other);
    ~Matrix();
    void show() const;
    void fill();
    void randomFill(); 
    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    
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
Matrix<T>::Matrix(const Matrix& other) :rows(other.rows), cols(other.cols)
{
    arr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new T[cols];
        for (int j = 0; j < cols; j++)
            arr[i][j] = other.arr[i][j];
    }
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

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
    if (this == &other)
        return *this;


    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

 
    rows = other.rows;
    cols = other.cols;

    if (other.arr == nullptr)
    {
        arr = nullptr;
    }
    else
    {
        arr = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = other.arr[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T>Matrix<T>::operator+(const Matrix& other) const
{
    if (arr == nullptr || other.arr == nullptr)
    {
        cout << "Matrix is not initialized" << endl;
        return Matrix();
    }

    if (rows != other.rows || cols != other.cols)
    {
        cout << "Matrix size do not match" << endl;
        return Matrix();

    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.arr[i][j] = arr[i][j] + other.arr[i][j];

    return result;
}

int main()
{
    srand(time(0));

    int rows = 5;
    int cols = 5;

    Matrix<int> c1(rows, cols);
    c1.randomFill();
    c1.show();
    cout << endl;
    Matrix<int> c2(rows, cols);
    c2.randomFill();
    c2.show();
    cout << endl;

    Matrix<int> c3;
    c3 = c1 + c2;
    c3.show();
    
}