[/*
Objetivo: 
Criar em memória uma representação para cada uma das 52 cartas de um baralho (x 2 baralhos) para serem utilizadas em um jogo de Buraco.
O programa dever� "distribuir" aleatoriamente as cartas (11 cartas para cada um dos 4 jogadores participantes). 
Encerra a proposta com a apresenta��o das "m�os" de cada jogador.
Nota��o para a identifica��o da carta:

N-99-B = Onde:
N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> N�mero da carta (01-�s / 13-Rei)
B  -> Baralho (1 ou 2)
Exemplo: 4-10-2  ->  10 de espada do baralho 2
baralho[n][c]
n = 0..1
c = 0..51
baralho[0][1] = "1021"
baralho[0][2] = "1031"
baralho[0][0] = "1011"
.
.
baralho[0][12] = "1131"
baralho[0][13] = "2011"
.
.
baralho[0][51] = "4131"
.
baralho[1][0] = "1012"
.
.
.
.
baralho[1][51] = "4132"
mao[j][c]
j = 0..3
c = 0..10

mao[0][0] = "1012"
mao[1][0] = "1011"

*/
#include <iostream>
#include <iomanip>
#include <cstdlib> // para a função rand(), da qual criará um valor aleatório.
#include <ctime>   // para inicializar a semente de geração de números aleatórios
using namespace std;

// Função para inicializar o baralho
void inicializarBaralho(string baralho[][52]) {
    for(int b = 0; b < 2; b++) {
        for(int n = 0; n < 4; n++) {
            for(int c = 0; c < 13; c++) {
                baralho[b][n * 13 + c] = to_string(n + 1) + ((c + 1 < 10) ? "0" : "") + to_string(c + 1) + to_string(b + 1);
            }
        }
    }
}

// Função para mostrar o baralho
void mostrarBaralho(string baralho[][52]) {
    for(int b = 0; b < 2; b++) {
        for(int c = 0; c < 52; c++) {
            cout << baralho[b][c] << "  ";
        }
        cout << endl;
    }
}

void distribuirBaralho(string baralho[][52], string maos[][11]){
    for(int j = 0; j < 4; j++) {
        for(int c = 0; c < 11; c++) {
            // Escolher uma carta aleatória que ainda não foi distribuída
            int indice_carta;
            do {
                indice_carta = rand() % 52;
            } while (baralho[indice_carta / 52][indice_carta % 52] == "");

            // Atribuir a carta selecionada à mão atual
            maos[j][c] = baralho[indice_carta / 52][indice_carta % 52];

            // Remover a carta do baralho, marcando-a como usada
            baralho[indice_carta / 52][indice_carta % 52] = "";
        }
    }
}
void mostrarMaos(string maos[][11]) {
    for (int j = 0; j < 4; j++) {
        cout << "Mão " << j + 1 << ":" << endl;
        for (int c = 0; c < 11; c++) {
            cout << maos[j][c] << " ";
        }
        cout << endl;
    }
}




int main(int argc, char** argv) {
    srand(time(0)); // Inicializar a semente de geração de números aleatórios

    string baralho[2][52];
    string maos[4][11];
    inicializarBaralho(baralho);

    mostrarBaralho(baralho);
    distribuirBaralho(baralho, maos);
    mostrarMaos(maos);

    return 0;
}