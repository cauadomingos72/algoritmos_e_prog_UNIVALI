#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include "listaEncadeada.h"
#include "listaDuplamenteEncadeada.h"
#include "listaGenerica.h"
#include "musicas.h"

using namespace std;

void testeMusicaEstatica(){                 ///Os seguintes 3 procedimentos foram criados para a realização de um algoritmo similar
    cout << "Lista Estática" << endl;       ///entre as 3 listas, todos resolvem os mesmos problemas com as mesmas variáveis em questão.
    cout << "Testes das inserções" << endl;
    listaGen <musica, 5> lista;             ///Neste procedimento, será testada uma lista estática genérica, ela contará com um vetor de
    iniciaListaGen(lista);                  ///5 posições e estará recebendo a struct da biblioteca "musicas.h" como parametro.
    musica temp;
    temp.artista = "vazio";
    temp.nome = "d";
    insereFimListaGen(lista, temp);         ///A seguinte ordem de inserções tem o mesmo propósito nas 3 listas, colocar cada um dos métodos
    temp.nome = "b";                        ///no seu pior caso possível, por exemplo, nesse caso, é esperado que o "insereFim" e o
    insereFimListaGen(lista, temp);         ///"inserePosicao" tenham que mover diversas variáveis antes de sua conclusão, o que trará mais
    temp.nome = "a";                        ///clareza sobre o quanto se é gasto com cada implementção.
    insereFimListaGen(lista, temp);
    temp.nome = "e";
    insereInicioListaGen(lista, temp);
    temp.nome = "c";
    inserePosicaoListaGen(lista, temp, 3);
    for(int i=0; i<lista.tamanho; i++){     ///Aqui são exibidos todos os elementos em sua atual ordem;
        cout << lista.elementos[i].dado << endl;
    }
    cout << "Teste das ordenações" << endl;
    bubblesortG(lista);
    //quicksortG(comeco, 0, comeco.tamanho-1);
    for(int i=0; i<lista.tamanho; i++){
        cout << lista.elementos[i].dado << endl;
    }
    /*
        Ao contrário dos próximos dos procedimentos, na lista estática, a implementação das ordenações foi feita, porém ela não funciona com
    o TAD utilizado, no PDF, será constado o número de operações utilizando variáveis do tipo int.
    */
    cout << "Testes das remoções" << endl;
    removeFimListaGen(lista);
    removePosicaoListaGen(lista, 3);        ///Aqui são testadas a remoções e também são pensadas de modo a criar um péssimo caso para o programa,
    removeInicioListaGen(lista);            ///uma vez que o acesso deve começar pelo fim da lista.
    for(int i=0; i<lista.tamanho; i++){
        cout << lista.elementos[i].dado << endl;    ///Última exibição.
    }
}

/*     ///Este procedimento inicialmente não faria parte do trabalho, mas será salvo para demsontração do uso das ordenações sem o TAD de musicas.
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
    cout << "Teste das ordenações" << endl;
    bubblesortG(comeco);
    //quicksortG(comeco, 0, comeco.tamanho-1);
    for(int i=0; i<comeco.tamanho; i++){
        cout << comeco.elementos[i].dado << endl;
    }
    cout << "Testes das remoções" << endl;
    removeFimListaGen(comeco);
    removePosicaoListaGen(comeco, 3);
    removeInicioListaGen(comeco);
    for(int i=0; i<comeco.tamanho; i++){
        cout << comeco.elementos[i].dado << endl;
    }
}*/


void testeMusicaSEncadeada(){               ///Para este e para o próximo procedimento, o algoritmo e lógica são identicos ao anterior, a única
    cout << "Lista Encadeada" << endl;      ///mudança significativa é a implementação do tipo de lista.
    cout << "Testes das inserções" << endl;
    listaEnc <musica> comeco;
    iniciaListaEnc(comeco);
    musica temp;
    temp.artista = "vazio";
    temp.nome = "d";
    insereFimListaEnc(comeco, temp);
    temp.nome = "b";
    insereFimListaEnc(comeco, temp);
    temp.nome = "a";
    insereFimListaEnc(comeco, temp);
    temp.nome = "e";
    insereInicioListaEnc(comeco, temp);
    temp.nome = "c";
    inserePosicaoListaEnc(comeco, temp, 3);
    elementoEnc <musica> *aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Teste das ordenações" << endl;  ///Além de testar as inserções, a ordem dos fatores inseridos também criam o pior caso possível para
    bubblesortS(comeco);                     ///o método de ordenação, uma vez que são pensados para ficarem na ordem inversa da qual se deseja.
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Testes das remoções" << endl;
    removeFimListaEnc(comeco);
    removePosicaoListaEnc(comeco, 3);
    removeInicioListaEnc(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
}

void testeMusicaDEncadeada(){               ///Terceiro e último teste com 5 variáveis no pior caso para cada algoritmo.
    cout << "Lista Duplamente Encadeada" << endl;
    cout << "Testes das inserções" << endl;
    listaDEnc <musica> comeco;
    iniciaListaDEnc(comeco);
    musica temp;
    temp.artista = "vazio";
    temp.nome = "d";
    insereFimListaDEnc(comeco, temp);
    temp.nome = "b";
    insereFimListaDEnc(comeco, temp);
    temp.nome = "a";
    insereFimListaDEnc(comeco, temp);
    temp.nome = "e";
    insereInicioListaDEnc(comeco, temp);
    temp.nome = "c";
    inserePosicaoListaDEncCI(comeco, temp, 3);  ///No caso da lista duplamente encadeada, foi implementada uma lógica para a
    elementoDEnc <musica> *aux = comeco.inicio; ///analise da posição requerida, desejando averiguar se tal posição estará
    while(aux!=NULL){                           ///mais próxima do fim ou do início da lista, quando o procedimento contem
        cout << aux->dado << endl;              ///as letras "CI - com índice" no fim do nome, significa que o indice será
        aux = aux->proximo;                     ///verificado, já "SI - sem índice" não o utiliza.
    }
    cout << "Teste das ordenações" << endl;
    //bubblesortD(comeco);
    quicksortD(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "Testes das remoções" << endl;
    removeFimListaDEnc(comeco);
    removePosicaoListaDEncSI(comeco, 3);
    removeInicioListaDEnc(comeco);
    aux = comeco.inicio;
    while(aux!=NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
}

int main()                          ///Cada procedimento foi testado um a um por execução, para executar um dos testes, apenas se destacou
{                                   ///as demais chamadas com "//".
    setlocale(LC_ALL, "Portuguese");
    //testeListaGen();
    //testeMusicaEstatica();
    testeMusicaSEncadeada();        ///Por se avaliar apenas as características de cada biblioteca de lista, não se viu necessidade da criação
    //testeMusicaDEncadeada();        ///de uma interface completa para a atual implementação, embora já exista um suporte nas bibliotecas para
    return 0;                       ///tais implementações no futuro.
}
