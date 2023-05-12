///Alunos: Cauã Domingos e Paulo Martino Hermans
#include <iostream>
#include <locale.h>
#include <windows.h>
#include "fila.h"

using namespace std;

struct Torcedor
{
  int nome;
  int tempo;
  bool socio;
};

struct guiches{    ///Criação do tipo Guichê
    int num;    ///Variável que descreve o numero referente ao guichê
    int total;    ///Variável que indica o total de pessoas aguardando atendimento
    Fila<Torcedor> gfila;    ///Englobamento da fila de espera do guichê
    guiches *proximo;    ///Ponteiro para o guichê ao lado
};

struct gnormal{
    guiches *primeiroN;    ///Criação de uma lista de guichês normais
};

struct gsocios{
    guiches *primeiroS;    ///Criação de uma lista de guichês para sócios
};

guiches *novoGuiche(int num){    ///Função para criação de um novo guichê
    guiches *novoG = new guiches;    ///Declaração de guichê
    novoG->num = num;    ///Atribuição do numero referente
    novoG->total = 0;    ///Inicialização do guichê com zero na espera
    iniciaFila(novoG->gfila);    ///Inicialização da fila do guichê
    novoG->proximo = NULL;   ///Preparação do ponteiro
}

bool iniciaGNormal(gnormal &g){    ///Inicialização da lista de guichês normais
    g.primeiroN = NULL;
    return true;
}

bool iniciaGSocios(gsocios &g){    ///Inicialização da lista de guichês para sócios
    g.primeiroS = NULL;
    return true;
}

void menu(int &GS, int &GN, int &C, int &P, int &T) ///Função de seleção das opções da simulação
{
    system("cls");
    cout<<"Qtd. de guichês sócio-torcedor: "<<endl;
    cin >> GS;
    cout<<"Qtd. de guichês normais: "<<endl;
    cin >> GN;
    cout<<"Qtd. de pessoas na carga inicial: "<<endl;
    cin >> C;
    cout<<"Qtd. de pessoas procurando fila a cada unidade de tempo: "<<endl;
    cin >> P;
    cout<<"Qtd. de tempo da simulação: "<<endl;
    cin >> T;
    system("cls");
}

bool addGNormal(gnormal Normal, int nome, int tempo){  ///Função para adicionar um torcedor á fila do guichê
    if(Normal.primeiroN==NULL)    ///verifica a existência de ao menos um guichê
        return false;
    guiches *atual = Normal.primeiroN;    
    if(atual->proximo!=NULL){    ///caso haja mais de um guichê, o desvio é acionado para criação de um navegador de guiches
        guiches *nav = atual->proximo;   
        while(nav!=NULL){
            if(nav->total<atual->total){    ///após a criação do navegador, ele deve comparar os guichês até achar o que contém a menor fila
                atual = nav;
            }
            nav = nav->proximo;
        }
    }
    Torcedor novo;
    novo.nome = nome;
    novo.tempo = tempo;
    novo.socio = false;
    Queue(atual->gfila, novo);    ///o torcedor é declarado com os dados passados por parametro e adicionado ou guichê selecionado anteriormente
    atual->total++;
    return true;
}

bool addGSocios(gsocios Socios ,int nome, int tempo){    ///função similar a anterior, utilizando como parametro os guichês para sócios
    if(Socios.primeiroS==NULL)
        return false;
    guiches *atual = Socios.primeiroS;
    if(atual->proximo!=NULL){
        guiches *nav = atual->proximo;
        while(nav!=NULL){
            if(nav->total<atual->total){
                atual = nav;
            }
            nav = nav->proximo;
        }
    }
    Torcedor novo;
    novo.nome = nome;
    novo.tempo = tempo;
    novo.socio = true;
    Queue(atual->gfila, novo);
    atual->total++;
    return true;
}

void preencherGNormal(int Carga, gnormal Normal){    ///Esta função deve atribuir a carga inicial aos guichês
    for(int i=1; i<=Carga; i++){
        if((i%20) < 10 && (i%20) >= 0)   ///os seguintes desvios enviam os parametros do torcedor a serr criado de forma não aleatória.
            addGNormal(Normal, i, 3);
        if((i%20) < 16 && (i%20) > 9)
            addGNormal(Normal, i, 2);
        if((i%20) < 20 && (i%20) > 15)
            addGNormal(Normal, i, 1);
    }
}

void preencherGSocios(int Carga, gsocios Socios){   ///função similar a anterior, utilizando como parametro os guichês para sócios
    for(int i=1; i<=Carga; i++){
        if((i%20) < 17 && (i%20) >= 0)
            addGSocios(Socios, i, 1);
        if((i%20) < 20 && (i%20) > 16)
            addGSocios(Socios, i, 2);
    }
}

ostream& operator<<(ostream& os, const Torcedor& aux) {   ///sobrecarga que torna possível a exibição do tipo torcedor
    if(aux.socio==false)
        os << aux.nome <<" (" << aux.tempo << ") ";
    else
        os << aux.nome << " (" << aux.tempo << ") " <<"S";
    return os;
}

ostream& operator<<(ostream& os, const Fila<Torcedor>& f) {   ///sobrecarga que viajará toda uma fila para exibição de todos os elementos
    ElementoF<Torcedor> *nav = f.inicio;
    while(nav!=NULL){
        os << nav->dado << "\t ";
        nav = nav->proximo;
    }
    return os;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo; 
    gnormal Normal;                                                      
    iniciaGNormal(Normal);
    gsocios Socios;
    iniciaGSocios(Socios);
    menu(qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo);   ///Nos primeiros passos há toda a criação dos elementos necessários para a simulação
    for(int i=qtdGuicheNormal; i>0; i--){
        guiches *novo = novoGuiche(i);
        novo->proximo = Normal.primeiroN;
        Normal.primeiroN = novo;
    }
    for(int i=qtdGuicheSocio; i>0; i--){    ///ambos os dois primeiros laços de repetição preenchem o atendimento com o número digitado de guichês
        guiches *novo = novoGuiche(i);
        novo->proximo = Socios.primeiroS;
        Socios.primeiroS = novo;
    }
    preencherGSocios(qtdCarga/20, Socios);
    preencherGNormal(qtdCarga-qtdCarga/20, Normal);   ///ocorre o preenchimento dos guichês criados
    int atendidos = 0;    ///inteiro que contará o total de torcedores atendidos
    for(int i=qtdTempo; i>0; i--){    ///laço que irá manter a simulação até o final do período definido
        guiches *nav = Normal.primeiroN;
        for(int i=qtdGuicheNormal; i>0; i--){
            cout << "Guichê normal número " << nav->num << endl;
            if(nav->gfila.inicio!=NULL)
                cout << nav->gfila << endl;
            else
                cout << endl;
            nav = nav->proximo;
        }
        nav = Socios.primeiroS;
        for(int i=qtdGuicheSocio; i>0; i--){
            cout << "Guichê para sócios número " << nav->num << endl;   
            if(nav->gfila.inicio!=NULL)
                cout << nav->gfila << endl;
            else
                cout << endl;
            nav = nav->proximo;
        }                            ///os dois laços anteriores exibem os guichês com seus nomes, tipos e filas
        nav = Normal.primeiroN;
        while(nav!=NULL){
            if(nav->gfila.inicio!=NULL){
                if(nav->gfila.inicio->dado.tempo==0){
                    DeQueue(nav->gfila);
                    atendidos++;
                }else
                    nav->gfila.inicio->dado.tempo--;
            }
            nav = nav->proximo;
        }
        nav = Socios.primeiroS;
        while(nav!=NULL){
            if(nav->gfila.inicio!=NULL){
                if(nav->gfila.inicio->dado.tempo==0){
                    DeQueue(nav->gfila);
                    atendidos++;
                }else
                    nav->gfila.inicio->dado.tempo--;
            }
            nav = nav->proximo;
        }                  ///os dois laços anteriores reduzem o tempo que o primeiro torcedor já esperou e o removem do guichê quando seu atendimento está completo
        if(qtdProcura>0){
            for(int i=1; i<=qtdProcura; i++){      ///laço que adiciona o numero de torcedores que procuram um guichê a cada unidade de tempo
                addGNormal(Normal, i+qtdCarga, 3);
            }
            qtdCarga+=qtdProcura;
        }
        system("pause");
        system("cls");
    }
    cout << "Simulação Encerrada." << endl;
    cout << atendidos << " torcedores foram atendidos com sucesso." << endl;   ///há a exibição dos dados da simulação e uma mensagem de encerramento do programa
    cout << "Média de atendimentos por guichê: " << atendidos/(qtdGuicheNormal+qtdGuicheSocio);
    return 0;
}
