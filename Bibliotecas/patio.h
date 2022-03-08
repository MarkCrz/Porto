#ifndef PATIO_H
#define PATIO_H

#include <iostream>
#include "transportes.h"

using namespace std;

//RETIRA O CONTEINER DA EMPILHADEIRA E COLOCA NO PATIO DO PORTO
template <class T, class T2>
bool insere_patio (TPilha<T> &pilha, TFila<T2> &fila, int &quantidadePatio, int &posicao) {
    if (quantidadePatio <= 2500) {
        for (TTransportes* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
            if ((nav->carregando == 2) and (nav->tempo == 0)) {
                PUSH(pilha, nav->conteiner);

                nav->carregando = 0;
                nav->conteiner = NULL;

                quantidadePatio++;
                if(quantidadePatio <= 500) {
                    posicao = 0;
                } else if ((quantidadePatio > 500) and (quantidadePatio <= 1000)) {
                    posicao = 1;
                } else if ((quantidadePatio > 1000) and (quantidadePatio <= 1500)) {
                    posicao = 2;
                } else if ((quantidadePatio > 1500) and (quantidadePatio <= 2000)) {
                    posicao = 3;
                } else {
                    posicao = 4;
                }
                return true;
            }
        }
        return false;
    } else {
        throw "Stack Overflow!";
    }
}

//RETIRA O CONTEINER DO PATIO E COLOCA NA EMPILHADEIRA
template <class T, class T2>
bool retirar_patio(TFila<T> &fila, TPilha<T2> &pilha) {
    for (TTransportes* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        if(nav->carregando == 3) {
            nav->conteiner = POP(pilha);
            nav->conteiner->proximo = NULL;
            nav->tempo = 2;
            nav->carregando = 4;
            return true;
        }
    }
    return false;
}

#endif //PATIO_H