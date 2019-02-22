#include <iostream>
#include "matrix.hpp"
using namespace std;

template <typename T>
void gaussian_elimination(Mat<T> &mat, Mat<T> &b)
{
    assert(b.col == 1);
    assert(b.row == mat.row);

    for (int i = 0; i < mat.row; i++)
    {
        T a_ii = mat.mat[i][i];
        for (int j = i + 1; j < mat.row; j++)
        {
            double a_ji = mat.mat[j][i];
            for (int k = i; k < mat.col; k++)
            {
                mat.mat[j][k] = mat.mat[j][k] - mat.mat[i][k] * a_ji / a_ii;
            }
            b.mat[j][0] = b.mat[j][0] - b.mat[i][0] * a_ji / a_ii;
        }
    }
}

template <typename T>
void back_substitution(Mat<T> &mat, Mat<T> &b)
{
    for (int i = mat.row - 1; i >= 0; i--)
    {
        T substi = 0;
        for (int j = mat.row - 1; j > i; j--)
        {
            substi += mat.mat[i][j] * b.mat[j][0];
        }

        b.mat[i][0] = (b.mat[i][0] - substi) / mat.mat[i][i];
    }
}
