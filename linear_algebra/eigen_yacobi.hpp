

#include <iostream>
#include "matrix.hpp"
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
Mat<T> get_jacobi_mat(int n, int p, int q, T c, T s);
template <typename T>
Mat<T> transpose(Mat<T> &mat);

template <typename T>
struct yacobi_return
{
    Mat<T> yacobi;
    Mat<T> ans;
};

template <typename T>
struct yacobi_return<T> yacobi_transform(Mat<T> &mat, int p, int q);

template <typename T>
struct yacobi_return<T> eigen_yacobi(Mat<T> &mat)
{

    int row = mat.row;
    int col = mat.col;

    Mat<double> yac(row, col);

    for (int i = 0; i < row; i++)
    {
        yac.mat[i][i] = 1;
    }

    for (int loop = 0; loop < 10; loop++)
    {
        for (int i = 0; i < row - 1; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                struct yacobi_return<double> y_r = yacobi_transform<double>(mat, i, j);
                mat = y_r.ans;
                yac = yac * y_r.yacobi;
            }
        }
    }

    struct yacobi_return<double> y_r =
    {
        yac, mat
    };

    return y_r;
}

template <typename T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

template <typename T>
struct yacobi_return<T> yacobi_transform(Mat<T> &mat, int p, int q)
{
    T a_pp = mat.mat[p][p];
    T a_qq = mat.mat[q][q];
    T a_pq = mat.mat[p][q];

    T theta = (a_qq - a_pp) / (2 * a_pq);
    T t = sgn<T>(theta) / (abs(theta) + sqrt(pow(theta, 2) + 1));

    T c = 1 / sqrt(pow(t, 2) + 1);
    T s = t * c;

    Mat<T> yacobi = get_jacobi_mat<T>(mat.col, p, q, c, s);
    Mat<T> yacobi_T = transpose(yacobi);

    Mat<T> A = yacobi_T * mat * yacobi;

    struct yacobi_return<double> y_r =
    {
        yacobi, A
    };

    return y_r;
}

template <typename T>
Mat<T> transpose(Mat<T> &mat)
{
    int n = mat.col;
    Mat<T> new_mat(n, n);

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            new_mat.mat[j][i] = mat.mat[i][j];
        }
    }

    return new_mat;
}

template <typename T>
Mat<T> get_jacobi_mat(int n, int p, int q, T c, T s)
{
    Mat<T> mat(n, n);
    for (int i = 0; i < n; i++)
    {
        mat.mat[i][i] = 1;
    }

    mat.mat[p][p] = c;
    mat.mat[q][q] = c;
    mat.mat[q][p] = -s;
    mat.mat[p][q] = s;

    return mat;
}
