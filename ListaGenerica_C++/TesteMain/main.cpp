#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include "listaEncadeada.h"
#include "listaDuplamenteEncadeada.h"
#include "listaGenerica.h"

using namespace std;

void testeListaGen(){
    cout << "Lista Estática" << endl;
    cout << "Testes das inserções" << endl;
    listaGen <int, 5> comeco;
    iniciaListaGen(comeco);
    insereFimListaGen(comeco, 4);
    insereFimListaGen(comeco, 2);
    insereFimListaGen(comeco, 1);
    insereInicioListaGen(comeco, 5);
    inserePosicaoListaGen(comeco, 3, 3);
    for(int i=0; i<comeco.tamanho; i++){
        cout << comeco.elementos[i].dado << endl;
    }
    cout << "Teste do bubblesort" << endl;
    bubblesortG(comeco);
    for(int i=0; i<comeco.tamanho; i++){
        cout << comeco.elementos[i].dado << endl;
    }
    cout << "Testes das remoções" << endl;
    removePosicaoListaGen(comeco, 3);
    removeInicioListaGen(comeco);
    removeFimListaGen(comeco);
    for(int i=0; i<comeco.tamanho; i++){
        cout << comeco.elementos[i].dado << endl;
    }
}

void testeListaEnc(){
    cout << "Lista Encadeada" << endl;
    cout << "Testes das inserções" << endl;
    listaEnc <int> comeco;
    iniciaListaEnc(comeco);
    insereFimListaEnc(comeco, 4);
    insereFimListaEnc(comeco, 2);
    insereFimListaEnc(comeco, 1);
    insereInicioListaEnc(comeco, 5);
    inserePosicaoListaEnc(comeco, 3, 3);
    elementoEnc <int> *aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Teste do bubblesort" << endl;
    bubblesortS(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Testes das remoções" << endl;
    removePosicaoListaEnc(comeco, 3);
    removeInicioListaEnc(comeco);
    removeFimListaEnc(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
}

void testeListaDEnc(){
    cout << "Lista Duplamente Encadeada" << endl;
    cout << "Testes das inserções" << endl;
    listaDEnc <int> comeco;
    iniciaListaDEnc(comeco);
    insereFimListaDEnc(comeco, 4);
    insereFimListaDEnc(comeco, 2);
    insereFimListaDEnc(comeco, 1);
    insereInicioListaDEnc(comeco, 5);
    inserePosicaoListaDEncCI(comeco, 3, 3);
    elementoDEnc <int> *aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Teste do bubblesort" << endl;
    bubblesortD(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Testes das remoções" << endl;
    removePosicaoListaDEncSI(comeco, 3);
    removeInicioListaDEnc(comeco);
    removeFimListaDEnc(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    testeListaGen();
    testeListaEnc();
    testeListaDEnc();
    return 0;
}
