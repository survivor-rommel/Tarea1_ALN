#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
void allocMatrix(double ***matrix, int fil, int col);
void deallocMatrix(double **matrix, int fil );
void leerDatos( double **A, int fil, int col, double B[] );
void gaussEliminacion( double **A, int fil, int col, double v[] );
void intercambiarFilas( double **A, int col, int k, int max );
void imprimirMatriz( double **A, int fil, int col, double v[] );
void imprimirSolucion( double v[], int fil );

int main()
{

    int fil, col;
    printf( "\nNumero de variables: " );
    scanf( "%d", &fil );
    col = fil;



    double** A = NULL;
    allocMatrix(&A, fil, col);

    double B[fil];
    leerDatos( A, fil, col, B );

    imprimirMatriz( A, fil, col, B );

    gaussEliminacion( A, fil, col, B );

    deallocMatrix( A, fil );

    return 0;
}
void allocMatrix(double ***matrix, int fil, int col )
{
    *matrix = (double **)malloc(sizeof(double *) * fil);

    for( int i = 0; i < col; i++){

        *(*matrix + i) = (double *)malloc(sizeof(double) * col);

    }

}
void deallocMatrix(double **matrix, int fil )
{
    int i = 0;

    for(i = 0; i < fil; i++){
        free(matrix[i]);

    }
    free(matrix);
}
void leerDatos( double **A, int fil, int col, double B[] )
{
    printf( "\nIntroduzca coeficientes de la ecuacion dada:\n" );

    for( int i = 0; i < fil; i++ ){
        printf( "\nFila %d:\n", i + 1 );
        for( int j = 0; j < col; j++ ) {
            printf( "Columna %d: ", j + 1 );
            scanf( "%lf", &A[i][j] );
        }
    }
    printf( "\nIntroduzca la igualdad de la ecuacion dada:\n" );
    for( int i = 0; i < fil; i++ ){
        printf( "Fila %d: ", i + 1 );
        scanf( "%lf", &B[i] );
    }
}

void gaussEliminacion( double **A, int fil, int col, double B[] )
{
    int max;
    int N = fil;
    double factor, temp;
    for( int k = 0; k < N; k++ ){

        max = k;
        for( int i = k + 1; i < N; i++ )
            if( abs( A[i][k] ) > abs( A[max][k] ) )
                max = i;
        intercambiarFilas( A, col, k, max );
        temp = B[k];
        B[k] = B[max];
        B[max] = temp;

        for( int i = k + 1; i < N; i++ ) {
            factor = A[i][k] / A[k][k];
            B[i] -= factor * B[k];
            for( int j = k; j < N; j++ )
                A[i][j] -= factor * A[k][j];
        }
    }
    imprimirMatriz( A, fil, col, B );
    double solucion[fil];
    double suma;
    for( int i = 0; i < fil; i++ )

        solucion[i] = 0.00;
    for( int i = N - 1; i >= 0; i-- ){
        suma = 0.0;
        for( int j = i + 1; j < N; j++ )
            suma += A[i][j] * solucion[j];
        solucion[i] = (B[i] - suma) / A[i][i];
    }
    imprimirSolucion( solucion, fil );
}
void intercambiarFilas( double **M, int col, int k, int max )
{
    double temp[col];
    for( int i = k; i < col; i++ ) {
        temp[i] = M[k][i];
        M[k][i] = M[max][i];
        M[max][i] = temp[i];
    }
}
void imprimirMatriz( double **M, int fil, int col, double v[] )
{
    printf( "\nMatriz:\n" );
    for( int i = 0; i < fil; i++ ){

        for( int j = 0; j < col; j++ ){

            printf( "%.3lf ", M[i][j] );
        }

        printf( "| %.3lf\n", v[i] );
    }
    printf( "\n" );

}

void imprimirSolucion( double v[], int fil )
{
    printf( "\nSolucion: " );
    for( int i = 0; i < fil; i++ )

        printf( "\nX%d: %.3lf", i + 1, v[i] );
    printf( "\n" );

}
