// Alunos: Cauã Domingos, Pedro  Kons, Paulo Martino
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename Tipo>
struct elementoEnc{     //Cria uma estrutura onde estara armazenado um dado e um apontamento para um próximo elemento que possa estar na lista
    Tipo dado;      //Onde será armazenado um dado genérico
    elementoEnc <Tipo> *proximo;    //Apoontamento para um próximo elemento da lista   
};

template <typename Tipo>
struct listaEnc{    //Atribui variáveis que definem o início da lista
    elementoEnc <Tipo> *inicio; //Cria um ponteiro onde será armazenado o endereço do começo da lista
};

template <typename Tipo>
bool iniciaListaEnc(listaEnc<Tipo> &lEnc){  //Inicializa a lista, atribuindo um valor nulo ao inicio dela (visto que não deve possuir nenhum lixo de memória na mesma)
    lEnc.inicio = NULL; //Atribui o endereço do inicio como nulo
    return true;    //Retorna que foi executada a função
}

template <typename Tipo>
int retornaTamanhoListaEnc(listaEnc<Tipo> &lEnc){   //Retorna o tamanho total da lista
    if(lEnc.inicio != NULL){    //Verifica se o inicio está apontando para algum endereço não nulo
        int i=1;
        elementoEnc <Tipo> *nav = lEnc.inicio; //Cria um ponteiro para ajudar a navegar pela lista
        while(nav!=NULL){   //Faz a verificação até que o endereço atribuido no nav seja nulo, indicando que é o fim da lista
            nav = nav->proximo; //Caso o endereço do nav não for nulo, ele passa para um próximo elemento da lista
            i++;    //Adiciona 1 ao contador do tamanho da lista
        }
        return i;   //Retorna o tamanho total da lista
    }else{
        return 0;   //É visto através do "if" que o endereço é nulo, sendo assim a lista está vazia
    }
}

template <typename Tipo>
elementoEnc<Tipo> *novoElemento(Tipo dado){     //Criação de um novo elemento que será inserido na lista
    elementoEnc <Tipo> *novo = new elementoEnc<Tipo>;      //Atribui um endereço a esse ponteiro
    novo->dado = dado;      //Inseri o dado dentro do novo elemento
    novo->proximo = NULL;   //Atribui um valor de nulo ao próximo endereço deste elemento
};

template <typename Tipo>
bool insereFimListaEnc(listaEnc<Tipo> &lEnc, Tipo dado){    //Função que irá inserir um novo elemento no fim da lista
    elementoEnc <Tipo> *nav = lEnc.inicio;  //Cria um ponteiro para ajudar a navegar pela lista
    if(lEnc.inicio != NULL){    //Verifica se o inicio está apontando para algum endereço não nulo
        while(nav->proximo!=NULL){    //Um laço de repetição que irá percorrer até o fim da lista, se o próximo do endereço do "nav" for nulo, isso indica que "nav" é o último elemento da lista
            nav = nav->proximo;    //Caso o próximo elemento atribuido no "nav" não for nulo, ele passa para o próximo elemento desse elemento
        }
        elementoEnc <Tipo> *novo = novoElemento(dado);   //Cria um ponteiro que está armazenando o elemento que será inserido
        novo->proximo = nav->proximo;   //O endereço próximo do novo elemento receberá o endereço do próximo elemento (que é nulo)  
        nav->proximo = novo;    //O endereço do proxímo elemento do nav (que se encontra nulo), receberá o endereço do novo elemento
        return true;
    }else{  //Caso o endereço seja nulo, ele estará inserindo um primeiro elemento a essa lista
        elementoEnc<Tipo> *novo = novoElemento(dado);   //Cria um ponteiro que está armazenando o elemento que será inserido
        novo->proximo = NULL;   //Atribui o valor do proxímo elemento como nulo, indicando o fim da lista
        lEnc.inicio = novo;     //O endereço deste novo elemento será apontado pelo início da lista
        return true;    //Retorna que foi executada a função
    }
}

template <typename Tipo>
bool removeFimListaEnc(listaEnc<Tipo> &lEnc){   //Função que remove o elemento final de uma lista
    if(lEnc.inicio != NULL){    
        elementoEnc <Tipo> *nav = lEnc.inicio;
        if(nav->proximo != NULL){
            elementoEnc <Tipo> *aux = lEnc.inicio;
            nav = nav->proximo;
            while(nav->proximo!=NULL){
                aux = nav;
                nav = nav->proximo;
            }
            aux->proximo = NULL;
            delete nav;
            return true;
        }else{
            lEnc.inicio = NULL;
            delete nav;
            return true;
        }
    }else{
        return false;
    }
}

template <typename Tipo>
bool insereInicioListaEnc(listaEnc<Tipo> &lEnc, Tipo dado){
    elementoEnc<Tipo> *novo = novoElemento(dado);
    novo->proximo = lEnc.inicio;
    lEnc.inicio = novo;
    return true;
}

template <typename Tipo>
bool removeInicioListaEnc(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        elementoEnc <Tipo> *aux = lEnc.inicio;
        lEnc.inicio = aux->proximo;
        delete aux;
        return true;
    }else{
        return false;
    }
}

template <typename Tipo>
bool inserePosicaoListaEnc(listaEnc<Tipo> &lEnc, Tipo dado, int posicao){
    elementoEnc<Tipo> *novo = novoElemento(dado);
    if(posicao == 1){
        novo->proximo = lEnc.inicio;
        lEnc.inicio = novo;
        return true;
    }else{
        elementoEnc <Tipo> *nav = lEnc.inicio;
        for(int i=2; i<posicao && nav!=NULL; i++){
            nav = nav->proximo;
        }
        if(nav != NULL){
            novo->proximo = nav->proximo;
            nav->proximo = novo;
            return true;
        }else{
            return false;
        }
    }
    return false;
}

template <typename Tipo>
bool removePosicaoListaEnc(listaEnc<Tipo> &lEnc, int posicao){
    if(lEnc.inicio != NULL && posicao > 0){
        elementoEnc <Tipo> *aux = lEnc.inicio;
        elementoEnc <Tipo> *nav = aux->proximo;
        if(posicao == 1){
            lEnc.inicio = nav;
            delete aux;
            return true;
        }else{
            for(int i=2; i<posicao && nav!=NULL; i++){
                aux = nav;
                nav = nav->proximo;
            }
            aux->proximo = nav->proximo;
            delete nav;
            return true;
        }
    }else{
        return false;
    }
}

template <typename Tipo>
void bubblesortS(listaEnc<Tipo> &lEnc){
    if(lEnc.inicio != NULL){
        Tipo temp;
        elementoEnc <Tipo> *nav = lEnc.inicio;
        elementoEnc <Tipo> *aux = nav->proximo;
        while(aux!=NULL){
            if(aux->dado < nav->dado){
                temp = aux->dado;
                aux->dado = nav->dado;
                nav->dado = temp;
                nav = lEnc.inicio;
                aux = nav->proximo;
            }else{
                aux = aux->proximo;
                nav = nav->proximo;
            }
        }
    }
}
///Pela necessidade de navegar em ambas as direções, o quicksort não será implementado nesta biblioteca
