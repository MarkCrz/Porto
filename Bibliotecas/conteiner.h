#ifndef CONTEINER_H
#define CONTEINER_H

#include <iostream>

using namespace std;


struct TElementoC {
    string produto;
    string origem;
    string destino;
    TElementoC* proximo;
};

//=========================================================================================================================================================
//DEFINE AS INFORMAÇÕES
TElementoC* cria_conteiner () {
    TElementoC* novo = new TElementoC;
    int number = ((rand() % 4) + 1);
    novo->proximo = NULL;

    switch (number) {
        case 1:
            novo->produto = "Carro";
            break;
        case 2:
            novo->produto = "Alimento";
            break;
        case 3:
            novo->produto = "Materia-Prima";
            break;
        case 4:
            novo->produto = "Medicamento";
            break;
    }

    number = ((rand() % 4) + 5);
    switch (number) {
        case 5:
            novo->origem = "EUA";
            break;
        case 6:
            novo->origem = "Inglaterra";
            break;
        case 7:
            novo->origem = "Japao";
            break;
        case 8:
            novo->origem = "China";
            break;
    }

    number = ((rand() % 4) + 9);
    switch (number) {
        case 9:
            novo->destino = "Sao Paulo";
            break;
        case 10:
            novo->destino = "Itajai";
            break;
        case 11:
            novo->destino = "Belo Horizonte";
            break;
        case 12:
            novo->destino = "Curitiba";
            break;
    }

    return novo;
}


//=========================================================================================================================================================
//IMPRIME O CONTEINER
template <class T>
void imprime_conteiner (T conteiner) {
    cout << "IMPRIMINDO CONTEINER!!!" << endl;
    cout << "COMECA EM: " << conteiner.topo << endl;
    int i = 0;
    for (TElementoC* nav = conteiner.topo; nav != NULL; nav = nav->proximo) {
        cout << "Item [" << i++ << "]: " << endl
                                         << "Produto: " << nav->produto << endl
                                         << "Origem: " << nav->origem << endl
                                         << "Destino: " << nav->destino << endl
                                         << "&: " << nav << " - Proximo: " << nav->proximo << endl;
    }
}


#endif //CONTEINER_H