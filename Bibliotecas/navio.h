#ifndef NAVIO_H
#define NAVIO_H

#include <iostream>
#include "transportes.h"

using namespace std;

template <class T>
struct TNavio {
    string nomeNavio;
    string capitao;
    TPilha<T> pilhaConteiners;
};

//=========================================================================================================================================================
//DEFINE NOMES
template <class T>
void define_nomes (TNavio<T> &navio) {
    int number = ((rand() % 4) + 1);

    switch (number) {
        case 1:
            navio.nomeNavio = "Oro Jackson";
            navio.capitao = "Gol D. Roger";
            break;
        case 2:
            navio.nomeNavio = "Moby Dick";
            navio.capitao = "Edward Newgate";
            break;
        case 3:
            navio.nomeNavio = "Thousand Sunny";
            navio.capitao = "Monkey D. Luffy";
            break;
        case 4:
            navio.nomeNavio = "Red Force";
            navio.capitao = "Shanks";
            break;
    }
}

//=========================================================================================================================================================
//RESETA NAVIO
template <class T>
void reseta_navio(TNavio<T> &navio) {
    navio.capitao = "";
    navio.nomeNavio = "";
}

//=========================================================================================================================================================
//CRIA O NAVIO, DEFINE OS DADOS DENTRO DO NAVIO
template <class T>
void cria_navio (TNavio<T> &navio, int &qtdNavio) {
    TElementoC* conteiner = new TElementoC;

    inicializa_pilha(navio.pilhaConteiners);
    define_nomes(navio);
    for (int i = 0; i < 200; i++) {
        conteiner = cria_conteiner();
        PUSH(navio.pilhaConteiners, conteiner);
        qtdNavio++;
    }
}

//=========================================================================================================================================================
//REMOVE O CONTEINER DO NAVIO E COLOCA NA EMPILHADEIRA
template <class T, class T2>
void retirar_navio(TFila<T> &fila, TNavio<T2> &navio) {
    for (TTransportes* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        if(nav->carregando == 0) {
            nav->conteiner = POP(navio.pilhaConteiners);
            nav->conteiner->proximo = NULL;
            nav->carregando = 1;
            nav->tempo = 1;
        }
    }
}

//=========================================================================================================================================================
//IMPRIME O NAVIO
template <class T>
void imprime_navio(TNavio<T> navio) {
    cout << "IMPRIMINDO NAVIO!!!" << endl;
    cout << "Nome do Navio: " << navio.nomeNavio << endl
         << "Nome do Capitao: " << navio.capitao << endl;
    imprime_conteiner(navio.pilhaConteiners);
}
#endif //NAVIO_H