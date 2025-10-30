#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.h"

TEST_CASE("Tem como parâmetro a matriz 3x3 inteiros."){
     int tabuleiro[3][3] = {
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0}
     };
     REQUIRE(validaFormatoTabuleiro(tabuleiro) == true);
}

TEST_CASE("Está fora do formato 3x3."){
     int tabuleiro[3][3] = {
          {0, 0},
          {0, 0},
          {0, 0}
     };
     REQUIRE(validaFormatoTabuleiro(tabuleiro) == false);
}