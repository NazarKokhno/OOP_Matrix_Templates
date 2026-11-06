#include <iostream>
#include <windows.h>

using namespace std;

template<typename T>
class Matrix
{
private:
    T **arr;
    int rows,cols;
public:
    Matrix(): arr(nullptr),rows(0),cols(0) {}

    Matrix(int r, int c) : rows(r), cols(c)
    {
        arr = new T * [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new T[cols]();
    }

    Matrix(const Matrix& other) :rows(other.rows), cols(other.cols)
    {
        arr = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = other.arr[i][j];
        }
    }

    Matrix& operator=(сonst Matrix& other)
    {
        if (this == &other)
            return *this;

        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;

        rows = other.rows;
        cols = other.cols;

        arr = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = other.arr[i][j];
        }

        return *this;
    }

    void show() const
    {
        if (arr != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    cout << arr[i][j];
                cout << endl;
            }

        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

int main()
{
    int rows = 5;
    int cols = 5;

    Matrix<int> c(rows, cols);
    c.show();
    

}