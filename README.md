# Matrix Template Class

A C++ project implementing a template-based Matrix class with dynamic memory management and overloaded arithmetic operators.

## Features

- Template class supporting different data types
- Dynamic memory allocation using `new[]`
- Memory deallocation using `delete[]`
- Copy constructor (Deep Copy)
- Copy assignment operator
- Keyboard input
- Random matrix generation
- Matrix output
- Arithmetic operator overloading:
  - `+` — Matrix addition
  - `-` — Matrix subtraction
  - `*` — Element-wise multiplication
  - `/` — Element-wise division
- Finding the maximum element
- Finding the minimum element

## Technologies

- C++
- Object-Oriented Programming (OOP)
- Templates
- Dynamic Memory Management
- Operator Overloading

## Memory Management

The class uses dynamic two-dimensional arrays allocated with `new[]`.

Memory is properly released using `delete[]` in the destructor.

Deep copying is implemented through the copy constructor and copy assignment operator to ensure independent matrix objects.

## Example Usage

```cpp
Matrix<int> A(3, 3);
Matrix<int> B(3, 3);

A.randomFill();
B.randomFill();

Matrix<int> C = A + B;

C.show();
```

## Learning Objectives

- Understanding dynamic memory allocation
- Working with two-dimensional arrays
- Practicing class templates
- Implementing constructors and destructors
- Understanding deep copying
- Overloading arithmetic operators
- Applying OOP principles

## Purpose

This project was created as a practical exercise to improve my understanding of C++, operator overloading, constructors, destructors, dynamic memory allocation, and object-oriented programming.

