#ifndef TRANSPORTES_H
#define TRANSPORTES_H

#include <iostream>

using namespace std;

struct TTransportes {
    int tempo;
    int carregando;
    TElementoC* conteiner;
    TTransportes* proximo;
};

/*FUNÇÕES GERAIS--------------------------------------------------------------------------------------------------------------------------------------------*/
//COLOCA O TRANSPORTE NO MODO INICIAL
void inicializa_transporte (TTransportes* transportes, int diferente = 0) {
    transportes->carregando = 0;
    transportes->tempo = 0;
    transportes->conteiner = NULL;
    transportes->proximo = NULL;
    if (diferente == 1) { //UTILIZADO PARA CRIAR A EMPILHADEIRA QUE RETIRA DO PATIO E COLOCA NO CAMINHÃO
        transportes->carregando = 3;
    }
}

//CRIA A LISTA DE TRANSPORTE COM OS VALORES INICIAIS
template <class T>
void cria_transporte(TFila<T> &fila, int quantidade = 1, int diferente = 0) {
    for(int i = 0; i < quantidade; i++) {
        TTransportes* novo = new TTransportes;
        inicializa_transporte(novo, diferente);
        QUEUE(fila, novo);
    }
}

//IMPRIME O TRANSPORTE PASSADO POR PARAMETRO
template <class T>
void imprime_transportes(TFila<T> fila) {
    int i = 1;
    for (T* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        cout << "Item[" << i << "]" << endl
             << "Endereco: " << nav << endl
             << "Carregando: " << nav->carregando << endl
             << "Tempo: "   << nav->tempo << endl
             << "Conteiner: " << nav->conteiner << endl
             << "Proximo: " << nav->proximo << endl << endl;
        i++;
    }
}


/*FUNÇÕES EMPILHADEIRA-------------------------------------------------------------------------------------------------------------------------------------*/
//CONTA O TEMPO NECESSÁRIO PARA QUE A EMPILHADEIRA FAÇA SUA FUNÇÃO E TAMBÉM DEFINE O TEMPO DEPEDENDO DA POSICAO QUE ESTA A ALOCAÇÃO NO PATIO
template <class T>
void contador_empilhadeira(TFila<T> &fila, int posicao = 0) {
    for (TTransportes* nav = fila.primeiro; nav != NULL; nav = nav->proximo) {
        if (nav->carregando != 0) {
            if (nav->tempo != 0) {
                nav->tempo--;
            }
            if((nav->carregando == 1) and (nav->tempo == 0)) {
                nav->carregando = 2;
                switch (posicao) {
                    case 0:
                        nav->tempo = 1;
                        break;
                    case 1:
                        nav->tempo = 2;
                        break;
                    case 2:
                        nav->tempo = 3;
                        break;
                    case 3:
                        nav->tempo = 4;
                        break;
                    case 4:
                        nav->tempo = 5;
                        break;
                }
            }
        }
    }
}


/*FUNÇÕES CAMINHÃO-------------------------------------------------------------------------------------------------------------------------------------*/
//CRIA O CAMINHÃO COM A MÉDIA DE 3 POR MINUTO
template <class T>
void cria_caminhao(TFila<T> &fila, int &qtdCaminhoes){
    int numeroCaminhao = ((rand() % 100) + 1);
    if (numeroCaminhao <= 80) {
        cria_transporte(fila, 3);
        qtdCaminhoes = qtdCaminhoes + 3;
    } else if ((numeroCaminhao > 80) and (numeroCaminhao <= 85)) {
        cria_transporte(fila, 1);
        qtdCaminhoes = qtdCaminhoes + 1;
    } else if ((numeroCaminhao > 85) and (numeroCaminhao <= 90)) {
        cria_transporte(fila, 2);
        qtdCaminhoes = qtdCaminhoes + 2;
    } else if ((numeroCaminhao > 90) and (numeroCaminhao <= 95)) {
        cria_transporte(fila, 4);
        qtdCaminhoes = qtdCaminhoes + 4;
    } else {
        cria_transporte(fila, 5);
        qtdCaminhoes = qtdCaminhoes + 5;
    }
}

//RETIRA O CONTEINER DA EMPILHADEIRA E COLOCA NO CAMINHÃO
template <class T>
bool insere_caminhao(TFila<T> &fila, TFila<T> &fila2, int &qtdPatio, int &qtdTotal) {
    for(TTransportes* navEmp = fila.primeiro; navEmp != NULL; navEmp = navEmp->proximo) {
        if((navEmp->carregando == 4) and (navEmp->tempo == 0)) {
            fila2.primeiro->conteiner = navEmp->conteiner;
            navEmp->carregando = 3;
            navEmp->conteiner = NULL;
            qtdPatio--;
            qtdTotal++;
            return true;
        }
    }
    return false;
}


#endif //TRANSPORTES_H