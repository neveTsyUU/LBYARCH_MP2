#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Prototype for the assembly function
extern void daxpy_asm(int n, double A, const double *X, const double *Y, double *Z);

void daxpy_c(int n, double A, const double *X, const double *Y, double *Z) {
    for(int i = 0; i < n; ++i) {
        Z[i] = A * X[i] + Y[i];
    }
}

// Function to initialize vectors with random values
void init_vectors(double *X, double *Y, int n, double *A) {
    *A = 2.0; // Example scalar
    for(int i = 0; i < n; ++i) {
        X[i] = (double)rand() / RAND_MAX * 10;
        Y[i] = (double)rand() / RAND_MAX * 10;
    }
}

// Main program to demonstrate and time the kernels
int main() {
    int n = 1 << 20; // Example size, adjust as necessary
    double *X = malloc(n * sizeof(double));
    double *Y = malloc(n * sizeof(double));
    double *Z_c = malloc(n * sizeof(double));
    double *Z_asm = malloc(n * sizeof(double));
    double A;

    srand(time(NULL));
    init_vectors(X, Y, n, &A);

    // Time and call the C version
    clock_t start_c = clock();
    daxpy_c(n, A, X, Y, Z_c);
    clock_t end_c = clock();
    double time_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;

    // Time and call the assembly version
    clock_t start_asm = clock();
    daxpy_asm(n, A, X, Y, Z_asm); // Implement this in assembly
    clock_t end_asm = clock();
    double time_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;

    // Output and analysis
    printf("Time C: %f\nTime ASM: %f\n", time_c, time_asm);

    // Free allocated memory
    free(X);
    free(Y);
    free(Z_c);
    free(Z_asm);

    return 0;
}