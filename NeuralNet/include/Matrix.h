#ifndef _MATRIX_
#define _MATRIX_

#include "Matrix.h"

namespace BorisNetAi
{
    class Matrix
    {
        public:
            Matrix(int rows, int columns);

            ~Matrix();

            void MUL(Matrix& a, Matrix& b);

            void HADAMARD(Matrix& a);

            void ADD(Matrix& a);

            void SUB(Matrix& a);
            
            float& operator()(int row, int col) { return m_data [row + col * row]; }

        private:
        
            float* m_data;
        
            int m_rows, m_columns, m_total;

    };
}

#endif // _matrix_