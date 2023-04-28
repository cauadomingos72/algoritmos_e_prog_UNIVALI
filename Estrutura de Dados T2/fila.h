#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <fstream>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

template <typename Tipo>
struct ElementoF{
    Tipo dado;
    ElementoF<Tipo> *proximo;
};

template <typename Tipo>
struct Fila{
    ElementoF<Tipo> *inicio;
    ElementoF<Tipo> *fim;
};

template <typename Tipo>
ElementoF<Tipo> *novoElementoF(Tipo dado){
    ElementoF<Tipo> *novo = new ElementoF<Tipo>;
    novo->dado = dado;
    novo->proximo = NULL;
}

template <typename Tipo>
bool iniciaFila(Fila<Tipo> &F){
    F.inicio = NULL;
    F.fim = NULL;
    return true;
}

template <typename Tipo>
bool Queue(Fila<Tipo> &F, Tipo dado){
    ElementoF<Tipo> *novo = novoElementoF(dado);
    if(F.fim!=NULL){
        ElementoF<Tipo> *penultimo = F.fim;
        penultimo->proximo = novo;
        F.fim = novo;
        return true;
    }else{
        F.inicio = novo;
        F.fim = novo;
        return true;
    }
}

template <typename Tipo>
Tipo DeQueue(Fila<Tipo> &F){
    if(F.inicio!=NULL){
        ElementoF<Tipo> *apagado = F.inicio;
        F.inicio = apagado->proximo;
        if(F.inicio==NULL){
            F.fim = NULL;
        }
        Tipo temp = apagado->dado;
        delete apagado;
        return temp;
    }
}

#endif // FILA_H_INCLUDED
