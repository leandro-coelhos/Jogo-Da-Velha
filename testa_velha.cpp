#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.h"
#include <vector>

TEST_CASE("Tem como parâmetro a matriz 3x3 inteiros."){
     std::vector<std::vector<int>> tabuleiro = {
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0},
     };
     REQUIRE(validaFormatoTabuleiro(tabuleiro) == true);
}

TEST_CASE("Está fora do formato 3x3."){
    std::vector<std::vector<int>> tabuleiro = {
        {0, 0},
        {0, 0},
        {0, 0},
     };
     REQUIRE(validaFormatoTabuleiro(tabuleiro) == false);
}