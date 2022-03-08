#include <iostream>
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\pilha.h"
#include "D:\Semestre [3]\Estruturas de Dados\Bibliotecas\fila.h"
#include "Bibliotecas\conteiner.h"
#include "Bibliotecas\navio.h"
#include "Bibliotecas\transportes.h"
#include "Bibliotecas\patio.h"

#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <fstream>


using namespace std;

TNavio<TElementoC> navio;
TFila<TTransportes> empilhadeirasNavio;
TFila<TTransportes> empilhadeirasCaminhao;
TPilha<TElementoC> patio;
TFila<TTransportes> caminhoes;

int main () {
    srand((unsigned)time(NULL));
    ofstream out("historico de conteiner.txt");

    int quantidadePatio = 0;
    int quantidadeNavio = 0;
    int quantidadeTotal = 0;
    int posicao = 0;    /*POSICÃO PARA ALOCAR NO PATIO*/
    int quantidadeCaminhoes = 0;

    inicializa_fila(empilhadeirasNavio);
    inicializa_fila(empilhadeirasCaminhao);
    inicializa_fila(caminhoes);

    cria_transporte(empilhadeirasNavio, 2);
    cria_transporte(empilhadeirasCaminhao, 2, 1);

    try {
        for (int i = 0; i <= 10080; i++) {
            if (insere_patio(patio, empilhadeirasNavio, quantidadePatio, posicao) == true) {
                quantidadeNavio--;
            } if (insere_caminhao(empilhadeirasCaminhao, caminhoes, quantidadePatio, quantidadeTotal) == true) {
                out << "Item [" << quantidadeTotal <<"]\n"
                    << "Produto: " << caminhoes.primeiro->conteiner->produto << endl
                    << "Origem: " << caminhoes.primeiro->conteiner->origem << endl
                    << "Destino: " << caminhoes.primeiro->conteiner->destino << endl << endl;
                delete caminhoes.primeiro->conteiner;
                delete DEQUEUE(caminhoes);
                quantidadeCaminhoes--;
            }

            contador_empilhadeira(empilhadeirasNavio, posicao);
            contador_empilhadeira(empilhadeirasCaminhao);

            if(retorna_tamanho_pilha(navio.pilhaConteiners) != 0) {
                retirar_navio(empilhadeirasNavio, navio);
            } 
            if (retorna_tamanho_pilha(patio) != 0) {
                retirar_patio(empilhadeirasCaminhao, patio);
            }
            if (((i % 360) == 0) and (i != 0)) {
                cria_navio(navio, quantidadeNavio);
            }
            
            cria_caminhao(caminhoes, quantidadeCaminhoes);
            
            system("cls");
            cout << "MINUTOS: " << i << endl
                 << "POSICAO: " << posicao << endl
                 << "QUANTIDADE NO NAVIO: " << quantidadeNavio << endl
                 << "QUANTIDADE NO PATIO: " << quantidadePatio << endl
                 << "QUANTIDADE TOTAL: " << quantidadeTotal << endl
                 << "QUANTIDADE DE CAMINHOES: " << quantidadeCaminhoes << endl;
                
        }
    out.close();
    }
    catch(const char* err) {
        cout << "ERRO: " << err << endl;
    }
    
    return 0;
}