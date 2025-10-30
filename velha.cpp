#include "velha.h"
#include <vector>

bool validaFormatoTabuleiro(std::vector<std::vector<int>> tabuleiro) {
     if(tabuleiro.size() != 3) {
          return false;
     }
     for(int i = 0; i < 3; i++){
          if(tabuleiro[i].size() != 3) {
               return false;
          }
     }
     return true;
}

int verificaVencedor(std::vector<std::vector<int>> tabuleiro) {
     for(int i = 0; i < 3; i++){
          //Horizontal
          if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0]) {
               return tabuleiro[i][0];
          }
          //Vertical
          if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i]) {
               return tabuleiro[0][i];
          }
     }
     //Diagonal
     if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
          return tabuleiro[0][0];
     }
     if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
          return tabuleiro[0][2];
     }
     return 0;
}