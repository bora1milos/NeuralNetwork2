#ifndef _MATRIX_
#define _MATRIX_

#include "Matrix.h"

namespace BorisNetAi
{
    class Matrix
    {
        public:
            Matrix(int rows, int columns) : m_rows{rows}, m_columnts{columns}
            {
                m_total = rows * columns;
                data = (double*)_aligned_malloc(sizeof(double) * total, 64);
            }

            ~Matrix()
            {
                _aligned_free(data);
            }
        
        private:
            double* m_data;
            int m_rows, m_columnts, m_total;



    };
}

#endif // _matrix_