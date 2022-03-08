#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

template <class T>
struct TPilha {
    T* topo;
};

template <class T>
void inicializa_pilha (TPilha<T> &pilha) {
    pilha.topo = NULL;
}

//INSERIR ELEMENTO=========================================================================================================================================================
template <class T>
void PUSH(TPilha<T> &pilha, T* info) {
    if (pilha.topo == NULL) {
        pilha.topo = info;
    } else {
        info->proximo = pilha.topo;
        pilha.topo = info;
    }
}

//REMOVER ELEMENTO=========================================================================================================================================================
template <class T>
T* POP(TPilha<T> &pilha) {
    if (pilha.topo == NULL) {
        throw "Stack Underflow";
    } else {
        T* excluir = pilha.topo;
        pilha.topo = pilha.topo->proximo;
        return excluir;
    }
}

//TAMANHO / PERTENCE / INDICE=========================================================================================================================================================
template <class T>
int retorna_tamanho_pilha(TPilha<T> pilha) {
    int contador = 0;
    for (T* nav = pilha.topo; nav != NULL; nav = nav->proximo) {
        contador++;
    }
    return contador;
}

template <class T>
bool pertence_pilha (TPilha<T> pilha, T* info) {
    for (T* nav = pilha.topo; nav != NULL; nav = nav->proximo) {
        if (nav == info) {
            return true;
        }
    }
    return false;
}

template <class T>
int retorna_indice_pilha (TPilha<T> pilha, T* info) {
    if (pertence_pilha(pilha, info) == true) {
        int i = 0;
        for (T* nav = pilha.topo; nav != NULL; nav = nav->proximo) {
            if (nav == info) {
                return i;
            }
            i++;
        }
    } else {
        throw "O dado nao pertence a pilha";
    }
}

//IMPRESSÃO DAS POSIÇÕES=========================================================================================================================================================
template <class T>
void imprime_pilha (TPilha<T> pilha) {
    cout << "IMPRIMINDO PILHA!!!" << endl;
    cout << "COMECA EM: " << pilha.topo << endl;
    int i = 0;
    for (T* nav = pilha.topo; nav != NULL; nav = nav->proximo) {
        cout << "Item [" << i++ << "]: " << " - &: " << nav << " - proximo: " << nav->proximo << endl;
    }
}

#endif // PILHA_H