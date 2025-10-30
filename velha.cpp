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
          if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1) {
               return 1;
          }
          //Vertical
          if (tabuleiro[0][i] == 1 && tabuleiro[1][i] == 1 && tabuleiro[2][i] == 1) {
               return 1;
          }
     }
     //Diagonal
     if ((tabuleiro[0][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][2] == 1)||(tabuleiro[0][2] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][0] == 1)) {
          return 1;
     }
     return 0;
}