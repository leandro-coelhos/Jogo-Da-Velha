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

TEST_CASE("X vence na linha."){
    std::vector<std::vector<int>> tabuleiro = {
        {1, 1, 1},
        {0, 2, 0},
        {2, 0, 0},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 1);
}

TEST_CASE("X vence na diagonal."){
    std::vector<std::vector<int>> tabuleiro = {
        {2, 0, 1},
        {0, 1, 0},
        {1, 0, 2},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 1);
}

TEST_CASE("X vence na coluna."){
    std::vector<std::vector<int>> tabuleiro = {
        {2, 1, 0},
        {0, 1, 2},
        {0, 1, 0},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 1);
}

TEST_CASE("O vence na linha."){
    std::vector<std::vector<int>> tabuleiro = {
        {2, 2, 2},
        {0, 1, 0},
        {1, 0, 1},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 2);
}

TEST_CASE("O vence na coluna."){
    std::vector<std::vector<int>> tabuleiro = {
        {1, 2, 0},
        {0, 2, 1},
        {1, 2, 0},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 2);
}

TEST_CASE("O vence na diagonal."){
    std::vector<std::vector<int>> tabuleiro = {
        {2, 1, 0},
        {1, 2, 1},
        {0, 0, 2},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 2);
}

TEST_CASE("Empate."){
    std::vector<std::vector<int>> tabuleiro = {
        {1, 2, 1},
        {2, 2, 1},
        {1, 1, 2},
     };
     REQUIRE(verificaVencedor(tabuleiro) == 0);
}

TEST_CASE("Indefinido"){
    std::vector<std::vector<int>> tabuleiro = {
        {1, 0, 2},
        {0, 1, 0},
        {0, 0, 0},
     };
     REQUIRE(verificaVencedor(tabuleiro) == -1);
}

TEST_CASE("Impossível"){
    std::vector<std::vector<int>> tabuleiro = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
     };
     REQUIRE(verificaVencedor(tabuleiro) == -2);
}