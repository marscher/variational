#include <stdlib.h>
#include <stdio.h>

/** Subtracts given row vector from each row of the matrix X

@param X : (M, N) array
@param row : (N) array
@param M : int
@param N : int

*/
void _subtract_row_double(double* X, double* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X[ro + j] -= row[j];
                }
        }
}

/** see above */
void _subtract_row_float(float* X, float* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X[ro + j] -= row[j];
                }
        }
}

void _subtract_row_double_copy(double* X0, double* X, double* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X0[ro + j] = X[ro + j] - row[j];
                }
        }
}

void _subtract_row_float_copy(float* X0, float* X, float* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X0[ro + j] = X[ro + j] - row[j];
                }
        }
}


int* _bool_to_list(int* b, int N, int nnz)
{
        int i;
        int k=0;
        int* list = (int*)malloc(nnz*sizeof(int));
        for (i=0; i<N; i++)
                if (b[i] == 1)
                        list[k++] = i;
        return (list);
}

/** Checks each column whether it is constant in the rows or not

@param cols : (N) result array that will be filled with 0 (column constant) or 1 (column variable)
@param X : (M, N) array
@param M : int
@param N : int

*/
void _nonconstant_cols_char(int* cols, char* X, int M, int N)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                                cols[j] = 1;
                }
        }
}

/** see above */
void _nonconstant_cols_int(int* cols, int* X, int M, int N)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                                cols[j] = 1;
                }
        }
}

/** see above */
void _nonconstant_cols_long(int* cols, long* X, int M, int N)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                                cols[j] = 1;
                }
        }
}

/** see above */
void _nonconstant_cols_float(int* cols, float* X, int M, int N)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                                cols[j] = 1;
                }
        }
}

/** see above */
void _nonconstant_cols_double(int* cols, double* X, int M, int N)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                                cols[j] = 1;
                }
        }
}

/** Checks each column whether it is approximately constant in the rows or not

@param cols : (N) result array that will be filled with 0 (column constant) or 1 (column variable)
@param X : (M, N) array
@param M : number of rows
@param N : number of columns
@param tol : maximum difference of any row to the first row to be still considered equal.

*/
void _nonconstant_cols_float_approx(int* cols, float* X, int M, int N, float tol)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        double diff;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        diff = X[j] - X[ro+j];
                        if (diff > tol || -diff > tol)
                                cols[j] = 1;
                }
        }
}

/** see above */
void _nonconstant_cols_double_approx(int* cols, double* X, int M, int N, double tol)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        double diff;

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        diff = X[j] - X[ro+j];
                        if (diff > tol || -diff > tol)
                                cols[j] = 1;
                }
        }
}