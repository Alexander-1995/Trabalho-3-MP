//  fibonacci.c
//
//  Created by Alexander André De Souza Vieira on 03/10/2018.
//
//
#include <stdio.h>

/* Fibonacci series program in C language */
#include <stdio.h>

int main(){
    int n, first = 0, second = 1, next, c;

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
