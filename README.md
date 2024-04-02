# LBYARCH_MP2
Programming project number 2 for LBYARCH Year 2023-2024 made by Josh Dane Villavicencio and Steven Aaron Yu of section S15.


## Project Specification Overview
The specification mentioned that this project should contain a C kernel and an ASM kernel performing this function DAXPY (A*X+Y).

It is also noted that SIMD registers and scalar functions are to be used as inputs, otherwise a grade of 0 will be given. 

Through this process:

Z[i] = A * X[i] + Y[i]

It is noted that:
Scalar variable A is a double-precision float and vectors X, Y, Z are also double-precision floats. 

The output is vector Z where the first 10 results are shown. 

NOTE: All results for the different runs may be different since random numbers are set as the variables instead. 


## Process of Running and Testing

At first, the program is ran once in C and in Assembly to see if the computations with different vectors are done right. 
The average time is gathered by performing 30 runs separately and manually getting the average of all the runs. This is done for the C and ASM versions.

Two separate runs are also gathered. These two runs are the debugged code and the compiling without debugging code. 

DISCLAIMER: Please do not make a function / for loop that makes the machine compute for it 30 times, it will make your CPU performance reach 97% since it will compute for the function 180 times (90 computations for C and 90 for ASM with each computing for 2^20, 2^24, and 2^27), so I did not push through with that method. 


## Average Running Time 

All of these have been run 30 times and the average time was gathered. 

C and ASM Average Time without Debugging:
|  TEST  |  C AVERAGE TIME  |  ASSEMBLY AVERAGE TIME  | 
| ------------- | ------------- | ------------- |
|  2^20  |  0.002633 seconds  |  0.000833 seconds  |
|  2^24  |  0.043700 seconds  |  0.012100 seconds  |
|  2^29  |  1.422933 seconds  |  0.392833 seconds  |




