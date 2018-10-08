//
//  testa_countlines.c
//  
//
//  Created by Alexander André De Souza Vieira on 03/20/2018.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp" /*!Inclusão da biblioteca catch.hpp para poder realizar os testes.*/
#include <stdio.h>
#include <stdlib.h>
#include "countlines.hpp"

char nome_arq[Nom_Max_Arq] = "fibonacci.c";

TEST_CASE( "Teste de Contagem de Linhas do Código", "[count_lines_of_code]" ) {
    REQUIRE(conta_linha2(nome_arq) == 31 );

}

////Teste utilizado anteriormente
//int main(void)
//{
//    int x;
//    char nome_arq[Nom_Max_Arq] = "fibonacci.c";
//
//    x = conta_linha(nome_arq);
//    printf("\n\n\n%d\n",x);
//        return 0;
//}
