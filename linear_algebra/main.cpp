#include <iostream>
#include "matrix.hpp"
#include "gaussian_elimination.hpp"
#include "eigen_yacobi.hpp"
#include "householder.hpp"

using namespace std;

int main()
{
    Mat<double> mat(3, 3);
    // Mat<double> yac(3, 3);

    // for (int i = 0; i < 3; i++)
    // {
    //     yac.mat[i][i] = 1;
    // }

    // double init[3][3] = {
    //     {2, 4, 6},
    //     {1, 5, 9},
    //     {2, 1, 3}};

    double init[3][3] = {
        {2, 4, 6},
        {4, 5, 9},
        {6, 9, 3}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat.mat[i][j] = init[i][j];
        }
    }

    Mat<double> p = get_P(mat);

    Mat<double> A_1 = p * mat * p;
    A_1.show();

    // Mat<double> b(3, 1);

    // double init2[3][1] = {
    //     {4},
    //     {2},
    //     {7}};

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 1; j++)
    //     {
    //         b.mat[i][j] = init2[i][j];
    //     }
    // }

    // struct yacobi_return<double> y_r = eigen_yacobi<double>(mat);

    // y_r.ans.show();

    // y_r.yacobi.show();

    return 0;
}