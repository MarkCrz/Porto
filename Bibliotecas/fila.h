#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;


template <class T>
struct TFila {
    T* primeiro;
};

template <class T>
void inicializa_fila (TFila<T> &fila) {
    fila.primeiro = NULL;
}

//=========================================================================================================================================================
template <class T>
void QUEUE (TFila<T> &fila, T* novo) {
    if (fila.primeiro == NULL) {
        fila.primeiro = novo;
    } else {
        T* nav = fila.primeiro;
        while (nav->proximo != NULL) {
            nav = nav->proximo;
        }
        nav->proximo = novo;
    }
}

//=========================================================================================================================================================
template <class T>
T* DEQUEUE (TFila<T> &fila) {
    if (fila.primeiro == NULL) {
        throw "Stack Underflow!";
    } else {
        T* excluir = fila.primeiro;
        fila.primeiro = fila.primeiro->proximo;
        return excluir;
    }
}

//=========================================================================================================================================================
template <class T>
int retorna_tamanho_fila(TFila<T> fila) {
    int contador = 0;
    for (T* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        contador++;
    }
    return contador;
}

template <class T>
bool pertence_fila (TFila<T> fila, T* info) {
    for (T* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        if (nav == info) {
            return true;
        }
    }
    return false;
}

template <class T>
int retorna_indice_fila (TFila<T> fila, T* info) {
    if (pertence_fila(fila, info) == true) {
        int i = 0;
        for (T* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
            if (nav == info) {
                return i;
            }
            i++;
        }
    } else {
        throw "O dado nao pertence a fila";
    }
}

//=========================================================================================================================================================
template <class T>
void imprime_fila (TFila<T> fila) {
    cout << "IMPRIMINDO FILA!!!" << endl;
    cout << "COMECA EM: " << fila.primeiro << endl;
    int i = 0;
    for (T* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        cout << "Item [" << i++ << "]: " << "&: " << nav << " - proximo: " << nav->proximo << endl;
    }
}



#endif //FILA_H