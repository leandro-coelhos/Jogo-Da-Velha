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
     std::vector<int> n;
     for(int i = 0; i < 3; i++){
          if(tabuleiro[i][0] != 0) {
               n.push_back(tabuleiro[i][0]);
          }
          if(tabuleiro[i][1] != 0) {
               n.push_back(tabuleiro[i][1]);
          }
          if(tabuleiro[i][2] != 0) {
               n.push_back(tabuleiro[i][2]);
          }
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
     int c = 0;
     for(int i: n){
          if(i != 0) {
               c++;
          }
     }
     if(c >= 5) {
          return 0; // Empate
     }
     else {
          return -1; // Jogo em andamento
     }
}