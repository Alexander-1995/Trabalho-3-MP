//
//  countlines.h
//  
//
//  Created by Alexander André De Souza Vieira on 03/10/2018.
//

#ifndef countlines_h
#define countlines_h
#define Nom_Max_Arq 80

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "catch.hpp"  /*!Inclusão da biblioteca catch.hpp para poder realizar os testes.*/

#endif /* countlines_h */

int quant_linhas_efetivas(char nome_arq[Nom_Max_Arq]);
int conta_linha(FILE*);
int conta_linha_em_branco(FILE*);
int conta_coment_barra(FILE*);
int conta_coment_barra_e_ast(FILE*);

