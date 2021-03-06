//// "Copyright 2018 Alexander André de Souza"
//  testa_countlines.c
//
//
//  Created by Alexander André De Souza Vieira on 03/10/2018.
//
#define CATCH_CONFIG_MAIN
// This tells Catch to provide a main() - only do this in one cpp file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "countlines.hpp"
#include "catch.hpp" /*!Inclusão da biblioteca catch.hpp para poder realizar os testes.*/

char nome_arq[Nom_Max_Arq] = "fibonacci.c";
char nome_arq2[Nom_Max_Arq] = "rand.c";
char nome_arq3[Nom_Max_Arq] = "printasc.c";
char nome_arq4[Nom_Max_Arq] = "CalculaSoma.c";

// //Teste utilizado inicialmente
// int main(void)
// {
//    int x;
//    char nome_arq[Nom_Max_Arq] = "fibonacci.c";
//
//    x = conta_linha(nome_arq);
//    printf("\n\n\n%d\n",x);
//        return 0;
// }

TEST_CASE("Teste de Contagem de Linhas do Código Fibonacci", "[count_lines_of_code]") {
    REQUIRE(conta_linha(nome_arq) == 38);
    REQUIRE(conta_coment_barra(nome_arq) == 11);
    REQUIRE(conta_linha_em_branco(nome_arq) == 4);
    REQUIRE(conta_coment_barra_e_ast(nome_arq) == 7);
    REQUIRE(quant_linhas_efetivas(nome_arq) == 16);
}

TEST_CASE("Teste de Contagem de Linhas do Código Rand", "[count_lines_of_code]") {
    REQUIRE(conta_linha(nome_arq2) == 42);
    REQUIRE(conta_coment_barra(nome_arq2) == 12);
    REQUIRE(conta_linha_em_branco(nome_arq2) == 16);
    REQUIRE(conta_coment_barra_e_ast(nome_arq2) == 1);
    REQUIRE(quant_linhas_efetivas(nome_arq2) == 13);
}

TEST_CASE("Teste de Contagem de Linhas do Código Printa ASC", "[count_lines_of_code]") {
    REQUIRE(conta_linha(nome_arq3) == 29);
    REQUIRE(conta_coment_barra(nome_arq3) == 14);
    REQUIRE(conta_linha_em_branco(nome_arq3) == 4);
    REQUIRE(conta_coment_barra_e_ast(nome_arq3) == 1);
    REQUIRE(quant_linhas_efetivas(nome_arq3) == 10);
}

TEST_CASE("Teste de Contagem de Linhas do Código Calcula Soma", "[count_lines_of_code]") {
    REQUIRE(conta_linha(nome_arq4) == 31);
    REQUIRE(conta_coment_barra(nome_arq4) == 12);
    REQUIRE(conta_linha_em_branco(nome_arq4) == 6);
    REQUIRE(conta_coment_barra_e_ast(nome_arq4) == 0);
    REQUIRE(quant_linhas_efetivas(nome_arq4) == 13);
}
