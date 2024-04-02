//Villavicencio, Josh Dane; Yu, Steven Aaron - S15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t clock_start, clock_end, asmClock_start, asmClock_end;
extern void daxpy_asm(double a, double* x, double* y, double* z, int n);

//Performs a * x[] + y[] function
void daxpy_c(int n, double a, double x[], double y[], double z[]) {
    double running_time = 0.0;
    //By this time, the clocks start to tell time as well
    clock_start = clock();

    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }

    clock_end = clock();

    printf("First 10 X values: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f \n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9]);
    printf("First 10 Y values: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f \n", y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9]);
    printf("First 10 results: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f \n", z[0], z[1], z[2], z[3], z[4], z[5], z[6], z[7], z[8], z[9]);
    running_time = ((double)(clock_end - clock_start)) / CLOCKS_PER_SEC;
    printf("Running Time to Process in C: %f sec.\n\n", running_time);

    
}

void call_asm(int n, double a, double* x, double* y, double* z) {
    double runningAsm_time = 0.0;
    //By this time, the clocks start to tell time as well
    asmClock_start = clock();

    daxpy_asm(a, x, y, z, n);

    asmClock_end = clock();

    printf("First 10 results: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f \n", z[0], z[1], z[2], z[3], z[4], z[5], z[6], z[7], z[8], z[9]);
    runningAsm_time = ((double)(clock_end - clock_start)) / CLOCKS_PER_SEC;
    printf("Running Time to Process in ASM: %f sec.\n\n", runningAsm_time);

    
}

void randomize_vals(double* vals, int n) {
    srand(time(NULL)); //Helps with randomizing values
    for (int i = 0; i < n; i++) {
        vals[i] = (double)rand() / 1000;
    }
}



int main() {

    double a = 2.0; //In this example, we will have our a as 2.0 for all, regardless of number of n's
    //Running Time for C

        //Our first time processing is n = 2^20
        int n = 1048576;
        double* x = (double*)malloc(n * sizeof(double)); 
        double* y = (double*)malloc(n * sizeof(double)); 
        double* z = (double*)malloc(n * sizeof(double)); 
        double* z_asm = (double*)malloc(n * sizeof(double));
        randomize_vals(x, n);
        randomize_vals(y, n);
        printf("Let's say that the value of n is 2^20\n");
        daxpy_c(n, a, x, y, z);
        call_asm(n, a, x, y, z_asm);


        //Next, we have n = 2^24
        n = 16777216;
        x = (double*)malloc(n * sizeof(double));
        y = (double*)malloc(n * sizeof(double));
        z = (double*)malloc(n * sizeof(double)); 
        z_asm = (double*)malloc(n * sizeof(double));
        randomize_vals(x, n);
        randomize_vals(y, n);
        printf("Let's say that the value of n is 2^24\n");
        daxpy_c(n, a, x, y, z); 
        call_asm(n, a, x, y, z_asm);

        //Lastly, n = 2^27 since my code cannot support 2^28, 2^29 and 2^30; all answers are stored in 2 decimal places 
        n = 134217728;
        x = (double*)malloc(n * sizeof(double)); 
        y = (double*)malloc(n * sizeof(double)); 
        z = (double*)malloc(n * sizeof(double));
        z_asm = (double*)malloc(n * sizeof(double));
        randomize_vals(x, n);
        randomize_vals(y, n);
        printf("Let's say that the value of n is 2^27\n");
        daxpy_c(n, a, x, y, z);
        call_asm(n, a, x, y, z_asm);
    

    return 0;
}
