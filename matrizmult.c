/* Este programa implementa la multiplicación de dos matrices
 * Autor: XXX
 * Fecha: XXX
 * Espacio académico: Sofwatre para Hardware
 * Version: 1.0
 */

#include<stdio.h>

// ========================================================= //
// == Prototipos (signatures) de las funciones utilizadas == //
// ========================================================= //
double prodPunto(double*, double*, int);
void prodMatrizV1(double*, double*, double*, int, int, int);
void prodMatrizV2(double*, double*, double*, int, int, int);
void resetearMatriz(double*, int, int);
void llenarMatriz(double*, int, int, char);
void escribirMatriz(double*, int, int, char);
// ======================= //
// == Función principal == //
// ======================= //
int main() {
    int f1 = 0, f2 = 0, c1 = 0, c2 = 0;
    printf("Digite las dimensoines de la matriz 1:\n");
    printf("Filas: ");
    scanf("%d", &f1);
    printf("Columnas: ");
    scanf("%d", &c1);

    printf("Digite las dimensoines de la matrizi  2:\n");
    printf("Filas: ");
    scanf("%d", &f2);
    printf("Columnas: ");
    scanf("%d", &c2);
    
    if(c1 != f2) {
        printf("ERROR!, dimensiones incompatibles\n");
        return 0;
    }

    double A[f1][c1], B[f2][c2], C[f1][c2];
    double *pA = &A[0][0];
    double *pB = &B[0][0];
    double *pC = &C[0][0];
    
    printf("Ingrese los valores de la matriz A\n");
    llenarMatriz(pA, f1, c1, 'A');
    printf("Ingrese los valores de la matriz B\n");
    llenarMatriz(pB, f2, c2, 'B');
    // Muestra las matrices capturadas
    escribirMatriz(pA, f1, c1, 'A');
    escribirMatriz(pB, f2, c2, 'B');

    // Calula el producto matricial
    prodMatrizV2(pA, pB, pC, f1, c1, c2);

    printf("El resultado del producto es:\n");
    escribirMatriz(pC, f1, c2, 'C');
    
    return 0;
}
// ============================================ //
// == Definición de las funciones utilizadas == //
// ============================================ //
//
// ------------------- //
// -- Llenar matriz -- //
// ------------------- //
void llenarMatriz(double *pA, int f, int c, char nombre) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j ++) {
            printf("%c[%d][%d] = ", nombre, i + 1, j + 1);
            double temp = 0;
            scanf("%lf", &temp);
            *(pA + c*i + j) = temp;
        }
    }
}
// ------------------- //
// -- Llenar matriz -- //
// ------------------- //
void resetearMatriz(double *pA, int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j ++) {
            *(pA + c*i + j) = 0.0;
        }
    }
}

// --------------------- //
// -- Escribir matriz -- // <-- Mostrar en pantalla
// --------------------- //
void escribirMatriz(double *pA, int f, int c, char nombre) {
    printf("%c = \n", nombre);
    for(int i = 0; i < f; i++) {
        printf("|\t");
        for(int j = 0; j < c; j ++) {
            printf("%lf\t", *(pA + c*i + j));
        }
        printf("|\n");
    }
}
// ------------------------ //
// -- Producto Matricial -- //
// ------------------------ //
void prodMatrizV2(double *pA, double *pB, double *pC, int f1, int c1, int c2) {
    resetearMatriz(pC, f1, c2);
    for(int i = 0; i < f1; i++) {
        for(int j = 0; j < c2; j++) {
            double temp = 0.0;
            for(int k = 0; k < c1; k++) {
                // Testigo
//                printf("(A[%d][%d])%lf * (B[%d][%d])%lf = (C[%d][%d])%lf\n", i,k,*(pA + c1*i + k), 
//                    k,j,*(pB + c1*k + j), 
//                    i,j,(*(pA + c1*i + k)) * (*(pB + c1*k + j))); 
                //
                temp += (*(pA + c1*i + k)) * (*(pB + c1*k + j));
                //temp += A[c1*i + k] * B[j + c1*k];
            }
            *(pC + c2*i + j) = temp;
        }
    }
}
