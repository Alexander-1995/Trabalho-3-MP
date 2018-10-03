//
//  pilha.c
//  
//
//  Created by Alexander André De Souza Vieira on 29/08/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "countlines.hpp"

int conta_linha(char nome_arq[Nom_Max_Arq])
{
    FILE *fp;
    int count = 0;  // Contador de linhas
    char c;  // Variável para usar o caractere lido do arquivo
    
    fp = fopen(nome_arq, "r");
    
    if (fp == NULL){     //Checa se o arquivo existe
        printf("Could not open file %s", nome_arq);
        return 0;
    }
    
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    
    fclose(fp);             //Fecha o arquivo
    printf("O arquivo %s tem %d linhas\n ", nome_arq, count);
    
    return count;
}
