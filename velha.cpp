#include "velha.h"
#include <iostream>
#include <vector>
#include <cstdlib> 

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
     int x = 0;
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
               x = tabuleiro[i][0];
          }
          //Vertical
          if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i]) {
               x = tabuleiro[0][i];
          }
     }
     //Diagonal
     if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
          x = tabuleiro[0][0];
     }
     if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
          x = tabuleiro[0][2];
     }
     int c = 0;
     int c1 = 0;
     int c2 = 0;
     for(int i: n){
          if(i != 0) {
               c++;
          }
          if(i == 1) c1++;
          if(i == 2) c2++;
     }
     if(c >= 5) {
          if(c1 > 5 || c2 > 5 || abs(c1 - c2) >= 2) {
               return -2; // Impossível
          }
          return x; //  Vitorioso ou empate
     }
     else {
          return -1; // Jogo em andamento
     }
}