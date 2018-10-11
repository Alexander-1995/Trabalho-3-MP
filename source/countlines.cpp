// "Copyright 2018 Alexander André de Souza"
//  countlines.cpp
//
//
//  Created by Alexander André De Souza Vieira on 03/10/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "countlines.hpp"

int quant_linhas_efetivas(char nome_arq[Nom_Max_Arq]) {
    FILE *fp;
    int quant_final_linhas, linhas_total = 0;
    int com_barra = 0, com_ast = 0, linhas_em_branco = 0;
    char input;  // Variável para armazenar o caractere lido do arquivo

    fp = fopen(nome_arq, "r");

    if (fp == NULL) {     // Checa se o arquivo existe
//        printf("Could not open file %s", nome_arq);
        return 0;
    }

    linhas_total = conta_linha(nome_arq);
    linhas_em_branco = conta_linha_em_branco(nome_arq);
    com_barra = conta_coment_barra(nome_arq);
    com_ast = conta_coment_barra_e_ast(nome_arq);


//    conta_linha(fp)
//    while ((input = fgetc(fp)) != EOF){
//        if (input  ==  '\n'){
// //Estrutura que faz uma varredura total no arquivo
//    \\ em busca da quantidade de linhas totais
//            linhas_total++;
//        }
//    }



//    conta_linha_em_branco(fp);
//    fseek(fp, 0, 0);
//    while ((input = fgetc(fp)) != EOF){
//  //Estrutura que faz a varredura do arquivo na busca e linhas em branco
//        if (input  ==  '\n'){
//            while (isspace(input = fgetc(fp))){
//                if(input == '\n'){
//                    linhas_em_branco++;
//                }
//            }
//        }
//    }



//  conta_coment_barra(fp)
//    fseek(fp, 0, 0);
//    while ((input = fgetc(fp)) != EOF){
// Estrutura que verifica as linhas que estão comentadas no estilo 2 barras (//)
//        if (input  ==  '/'){
//            if ((input = fgetc(fp))  ==  '/'){
//                com_barra++;
//            }
//        }
//    }



//   conta_coment_barra_e_ast(FILE* fp)
//    fseek(fp, 0, 0);
//    while ((input = fgetc(fp)) != EOF){
// //Estrutura que procura por comentários no estilo
// barra-asterisco-asterisco-barra, mas que estão em linhas múltiplas
//        if (input  ==  '/'){
//            if ((input = fgetc(fp))  ==  '*'){
//   while (((input = fgetc(fp)) != '*' and (input = fgetc(fp)) != '/')){
//                    if (input  ==  '\n'){
//                        printf("\n oi +1");
//                        com_ast++;
//                    }
//                }
//                if (input  ==  '*'){
// //Estrutura que procura por comentários no estilo
// barra-asterisco-asterisco-barra, mas que estão em linhas únicas
//                    if ((input = fgetc(fp))  ==  '/'){
//                        com_ast++;
//                    }
//                }
//            }
//        }
//    }

    quant_final_linhas = linhas_total - linhas_em_branco - com_ast - com_barra;
    printf("\nNúmero total de linhas: %d\n", linhas_total);
    printf("Número total de linhas comentadas no estilo 2 barras: %d\n", com_barra);
    printf("Número total de linhas em branco: %d\n", linhas_em_branco);
    printf("Número total de linhas comentadas no estilo barra-asterisco-asterisco-barra: %d\n", com_ast);
    printf("Número efetivo de linhas de código: %d\n", quant_final_linhas);

    fclose(fp);

    return quant_final_linhas;
}


int conta_linha(char nome_arq[Nom_Max_Arq]) {
    int linhas_total = 0;
    char input;
    FILE *fp2;
    fp2 = fopen(nome_arq, "r");

    while ((input = fgetc(fp2)) != EOF) {
        if (input  ==  '\n') {
/* Estrutura que faz uma varredura total no arquivo
    em busca da quantidade de linhas totais*/
            linhas_total++;
        }
    }
    return linhas_total;
}

int conta_linha_em_branco(char nome_arq[Nom_Max_Arq]) {
    int linhas_em_branco = 0;
    char input;
    FILE *fp3;
    fp3 = fopen(nome_arq, "r");

    fseek(fp3, 0, 0);
    while ((input = fgetc(fp3)) != EOF) {
        // Estrutura que faz a varredura do arquivo na busca e linhas em branco
        if (input  ==  '\n') {
            while (isspace(input = fgetc(fp3))) {
                if (input == '\n') {
                    linhas_em_branco++;
                }
            }
        }
    }
    return linhas_em_branco;
}

int conta_coment_barra(char nome_arq[Nom_Max_Arq]) {
    int com_barra = 0;
    char input;
    FILE *fp4;
    fp4 = fopen(nome_arq, "r");

    fseek(fp4, 0, 0);
    while ((input = fgetc(fp4)) != EOF) {
    /* Estrutura que verifica as linhas que
       estão comentadas no estilo 2 barras*/
        if (input  ==  '/') {
            if ((input = fgetc(fp4))  ==  '/') {
                com_barra++;
            }
        }
    }
    return com_barra;
}

int conta_coment_barra_e_ast(char nome_arq[Nom_Max_Arq]) {
    int com_ast = 0;
    char input;
    FILE *fp5;
    fp5 = fopen(nome_arq, "r");

    fseek(fp5, 0, 0);
    while ((input = fgetc(fp5)) != EOF) {
        /* Estrutura que procura por comentários no estilo
         barra-asterisco-asterisco-barra, mas que estão em linhas múltiplas*/
        if (input  ==  '/') {
            if ((input = fgetc(fp5))  ==  '*') {
                while (((input = fgetc(fp5)) != '*' &&
                        (input = fgetc(fp5)) != '/')) {
                    if (input  ==  '\n') {
                        com_ast++;
                    }
                }
                if (input  ==  '*') {
                    /*Estrutura que procura por comentários no estilo
                     barra-asterisco-asterisco-barra, mas que estão em linhas únicas*/
                    if ((input = fgetc(fp5))  ==  '/') {
                        com_ast++;
                    }
                }
            }
        }
        }
    return com_ast;
}
