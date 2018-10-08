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
    FILE *fp, *fp2, *fp3;
    int count = 0, com_barra = 0, linhas_total = 0;  // Contador de linhas
    char input, input2;  // Variável para usar o caractere lido do arquivo
    
    fp = fopen(nome_arq, "r");
    fp2 = fopen(nome_arq, "r");
    
    if (fp == NULL){     //Checa se o arquivo existe
        printf("Could not open file %s", nome_arq);
        return 0;
    }
    
    // Extract characters from file and store in character c
    while (input != EOF){
        
        if (input == ' ') {      //verificacão se a linha contém somente espaços, aí não soma
        }
        
        if (input == '/') {      //verificacão se a linha contém um comentário no formato //
            fp2 = fp;
//            fp2 = fp2 +1;
            input2 = getc(fp2);
            if(input2 == '/'){
                com_barra = com_barra + 1;
            }
        }
        
        else if (input == '\n') {
//            if (charcount > 3) {
//                linecount++;
//            }
//            charcount = 0;
//        }
//        else {
//            charcount++;
//        }
            count = count + 1;
        }
        
                  input = getc(fp);
    }
    
    fclose(fp);             //Fecha o arquivo
    linhas_total = count - com_barra;
    printf("O arquivo %s tem %d linhas\n ", nome_arq, linhas_total);
    
    return linhas_total;
}


int conta_linha2(char nome_arq[Nom_Max_Arq]){
    
    FILE *fp;
    int linhas_total = 0, com_barra = 0, linhas_em_branco = 0;
    char input;  // Variável para usar o caractere lido do arquivo
    
    fp = fopen(nome_arq, "r");
    
    if (fp == NULL){     //Checa se o arquivo existe
        printf("Could not open file %s", nome_arq);
        return 0;
    }
    
    while ((input = fgetc(fp)) != EOF)
    {
        if (input  ==  '\n')
        {
            linhas_total++;
        }
        if (input  ==  '\n')
        {
            if ((input = fgetc(fp))  ==  '\n')
            {
               fseek(fp, -1, 1);
                linhas_em_branco++;
            }
        }
    }
    fseek(fp, 0, 0);
    while ((input = fgetc(fp)) != EOF)
    {
        if (input  ==  '/')
        {
            if ((input = fgetc(fp))  ==  '/')
            {
                com_barra++;
            }
        }
    }
    printf("Número total de linhas: %d\n", linhas_total);
    printf("Número total de linhas comentadas no estilo //: %d\n", com_barra);
    printf("Número total de linhas em branco: %d\n", linhas_em_branco);
    printf("Número de linhas que não estão em branco: %d\n", linhas_total-linhas_em_branco);
    return linhas_total;
}
