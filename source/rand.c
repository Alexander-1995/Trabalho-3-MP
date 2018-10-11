//
//  rand.c
//  
//
//  Created by Alexander André De Souza Vieira on 09/10/2018.
//
// Número total de linhas: 42
// Número total de linhas comentadas no estilo 2 barras: 12
// Número total de linhas em branco: 4
// Número total de linhas comentadas no estilo barra-asterisco-asterisco-barra: 7
// Número efetivo de linhas de código: 16

#include <stdio.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){


//  oi
    int i;
  
    
    printf("Gerando 10 valores aleatorios:\n\n");
    
   
    for (i = 0; i < 10; i++){
        
        /* gerando valores aleatórios entre zero e 100 */
        
        
        
        printf("%d ", rand() % 100);
    }
    
    getch();

    return 0;


}
