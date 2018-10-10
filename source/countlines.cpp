//
//  pilha.c
//  
//
//  Created by Alexander André De Souza Vieira on 29/08/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "countlines.hpp"

int conta_linha(char nome_arq[Nom_Max_Arq]){
    
    FILE *fp;
    int linhas_total = 0, com_barra = 0, com_ast = 0, linhas_em_branco = 0;
    char input;  // Variável para armazenar o caractere lido do arquivo
    
    fp = fopen(nome_arq, "r");
    
    if (fp == NULL){     //Checa se o arquivo existe
        printf("Could not open file %s", nome_arq);
        return 0;
    }
    
    while ((input = fgetc(fp)) != EOF){
        if (input  ==  '\n'){ //Estrutura que faz uma varredura total no arquivo em busca da quantidade de linhas totais
            linhas_total++;
        }
    }
    
    fseek(fp, 0, 0);
    while ((input = fgetc(fp)) != EOF){   //Estrutura que faz a varredura do arquivo na busca e linhas em branco
        if (input  ==  '\n'){
            while (isspace(input = fgetc(fp))){
                if(input == '\n'){
                    linhas_em_branco++;
                }
            }
        }
    }
    
    fseek(fp, 0, 0);
    while ((input = fgetc(fp)) != EOF){  //Estrutura que verifica as linhas que estão comentadas no estilo //
        if (input  ==  '/'){
            if ((input = fgetc(fp))  ==  '/'){
                com_barra++;
            }
        }
    }
    
    fseek(fp, 0, 0);
    while ((input = fgetc(fp)) != EOF){    //Estrutura que procura por comentários no estilo /**/, mas que estão em linhas múltiplas
        if (input  ==  '/'){
            if ((input = fgetc(fp))  ==  '*'){
                while (((input = fgetc(fp)) != '*' and (input = fgetc(fp)) != '/')){
                    if (input  ==  '\n'){
                        printf("\n oi +1");
                        com_ast++;
                    }
                }
                if (input  ==  '*'){       //Estrutura que procura por comentários no estilo /**/, mas que estão em linhas únicas
                    if ((input = fgetc(fp))  ==  '/'){
                        com_ast++;
                    }
                }
            }
        }
    }
    
    printf("Número total de linhas: %d\n", linhas_total);
    printf("Número total de linhas comentadas no estilo //: %d\n", com_barra);
    printf("Número total de linhas em branco: %d\n", linhas_em_branco);
    printf("Número total de linhas comentadas no estilo /**/: %d\n", com_ast);
    printf("Número de linhas que não estão em branco: %d\n", linhas_total-linhas_em_branco-com_ast);
    return linhas_total;
}
