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
    REQUIRE(conta_linha(nome_arq) == 32);
    REQUIRE(conta_coment_barra(nome_arq) == 6);
    REQUIRE(conta_linha_em_branco(nome_arq) == 3);
    REQUIRE(conta_coment_barra_e_ast(nome_arq) == 7);
    REQUIRE(quant_linhas_efetivas(nome_arq) == 16);
}

TEST_CASE("Teste de Contagem de Linhas do Código Rand", "[count_lines_of_code]") {
    REQUIRE(conta_linha(nome_arq2) == 37);
    REQUIRE(conta_coment_barra(nome_arq2) == 7);
    REQUIRE(conta_linha_em_branco(nome_arq2) == 16);
    REQUIRE(conta_coment_barra_e_ast(nome_arq2) == 1);
    REQUIRE(quant_linhas_efetivas(nome_arq2) == 13);
}

