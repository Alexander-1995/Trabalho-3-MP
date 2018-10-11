//  fibonacci.c
//
//  Created by Alexander André De Souza Vieira on 03/10/2018.
//
//
// Número total de linhas: 38
// Número total de linhas comentadas no estilo 2 barras: 11
// Número total de linhas em branco: 4
// Número total de linhas comentadas no estilo barra-asterisco-asterisco-barra: 7
// Número efetivo de linhas de código: 16

#include <stdio.h>

/* Fibonacci series program in C language */
#include <stdio.h>

int main(){
    int n =0;, first = 0, second = 1, next, c;

/*
printf("Enter the number of terms\n");
scanf("%d", &n);
printf("Hello world!");
printf("First %d terms of Fibonacci series are:\n", n);
*/
    for (c = 0; c < n; c++){
        if (c <= 1){
            next = c;
        }else{
            next = first + second;
            first = second;
            second = next;
        }
//        printf("%d\n", next);
        printf("oi");
    }
    return 0;
}
