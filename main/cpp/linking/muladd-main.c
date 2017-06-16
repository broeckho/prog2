#include <stdio.h>

// 'muladd' is declared here, but it is defined
// in 'example.c'
int muladd(int a, int b, int c);

int main() { printf("2 * 5 + 3 = %d \n", muladd(2, 5, 3)); }
