#include <iostream>

using namespace std;

#ifndef HMat
#define HMat

template <typename T>
class Mat
{
  private:
    bool delete_flag;

  public:
    T **mat;
    int row;
    int col;
    Mat(int row, int col)
    {

        this->row = row;
        this->col = col;
        mat = new T *[row];
        for (int i = 0; i < row; ++i)
            mat[i] = new T[col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    Mat(const Mat &a_mat)
    {
        this->row = a_mat.row;
        this->col = a_mat.col;
        mat = new T *[row];
        for (int i = 0; i < row; ++i)
            mat[i] = new T[col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = a_mat.mat[i][j];
            }
        }
    }
    ~Mat()
    {

        for (int i = 0; i < this->row; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    Mat operator+(Mat const &obj)
    {
        Mat res(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] + obj.mat[i][j];
            }
        }

        return res;
    }

    void operator=(Mat const &obj)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = obj.mat[i][j];
            }
        }
    }

    Mat operator-(Mat const &obj)
    {
        Mat res(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] - obj.mat[i][j];
            }
        }

        return res;
    }

    Mat operator*(T scala)
    {
        Mat res(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] * scala;
            }
        }

        return res;
    }

    Mat operator/(T scala)
    {
        Mat res(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] / scala;
            }
        }

        return res;
    }

    Mat operator*(Mat const &obj)
    {
        int row = this->row;
        int col = obj.col;
        int inner = this->col;

        assert(obj.row == this->col && "dimention mismatch");

        Mat res(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                T sum = 0;
                for (int k = 0; k < inner; k++)
                {
                    sum += mat[i][k] * obj.mat[k][j];
                }
                res.mat[i][j] = sum;
            }
        }

        return res;
    }

    Mat<T> Identity()
    {
        Mat<T> identity(row, col);
        for (int i = 0; i < row; i++)
        {
            identity.mat[i][i] = 1;
        }

        return identity;
    }

    Mat<T> Transpose()
    {
        Mat<T> mat_T(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat_T.mat[j][i] = mat[i][j];
            }
        }

        return mat_T;
    }

    T norm_2()
    {
        T sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += mat[i][j] * mat[i][j];
            }
        }

        return sum;
    }

    void show()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }
    }
};

#endif