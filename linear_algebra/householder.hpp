
#include <iostream>
#include "matrix.hpp"
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
T sigma(Mat<T> &mat, int index)
{
    T sum = 0;
    for (int i = 0; i < index; i++)
    {
        sum += mat.mat[index][i] * mat.mat[index][i];
    }
    return sum;
}

template <typename T>
Mat<T> vector_u(Mat<T> &mat, int index)
{
    int col = mat.col;
    Mat<T> u(1, col);
    int length = index;
    for (int i = 0; i < length; i++)
    {
        u.mat[0][i] = mat.mat[index][i];

        if (i == length - 1)
        {
            u.mat[0][i] += sqrt(sigma(mat, index));
        }
    }

    return u;
}

template <typename T>
Mat<T> get_P(Mat<T> &mat)
{
    Mat<T> u = vector_u(mat, 2);
    Mat<T> u_T = u.Transpose();
    u.show();
    u_T.show();
    T H = u.norm_2() / 2;
    Mat<T> P = mat.Identity() - (u_T * u) / H;
    P.show();
    return P;
}