#include "Matrix.h"

#include <malloc.h>

namespace BorisNetAi
{
    
    Matrix::Matrix(int rows, int columns) : m_rows{rows}, m_columns{columns}
    {
        m_total = rows * columns;
        m_data = (float*)_aligned_malloc(sizeof(float) * m_total, 64);
    }
    
    Matrix::~Matrix()
    {
        _aligned_free(m_data);
    }

    void Matrix::MUL(Matrix& a, Matrix& b)
    {
        if (a.m_columns != b.m_rows)
            throw "Columns of matrix A must be equal rows of matrix B";
        
        if (this == &a || this == &b)
            throw "destination matrix must be distinct from matrices A and B";

        const auto SHARED_DIMENSION = a.m_columns;
        for (auto r = 0; r < a.m_rows; ++r)
        {
            for (auto c = 0; c < a.m_rows; ++c)
            {
                float total = 0.0f;
                for (auto d = 0; d < SHARED_DIMENSION; ++d)
                {
                    total += a(r,d) * b(d, c);
                }

                this->operator()(r, c) = total; 
            }
        }
    }

    void Matrix::HADAMARD(Matrix& a)
    {
        if (m_rows != a.m_rows || m_columns != a.m_columns)
            throw "Matrices have to have same dimmension to ";

        for (auto i = 0; i < a.m_total; ++i)
        {
            m_data[i] *= a.m_data[i];
        }
    }

    void Matrix::ADD(Matrix& a)
    {
        if (m_rows != a.m_rows || m_columns != a.m_columns)
            throw "Matrices have to have same dimmension to ADD";

        for (auto i = 0; i < a.m_total; ++i)
        {
            m_data[i] += a.m_data[i];
        }
    }

     void Matrix::SUB(Matrix& a)
    {
        if (m_rows != a.m_rows || m_columns != a.m_columns)
            throw "Matrices have to have same dimmension to ADD";

        for (auto i = 0; i < a.m_total; ++i)
        {
            m_data[i] -= a.m_data[i];
        }
    }

}