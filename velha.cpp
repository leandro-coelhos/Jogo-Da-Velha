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
     return 2;
}