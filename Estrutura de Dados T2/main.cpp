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

bool addGNormal(gnormal Normal, int nome, int tempo){
    if(Normal.primeiroN==NULL)
        return false;
    guiches *atual = Normal.primeiroN;
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
    novo.socio = false;
    Queue(atual->gfila, novo);
    atual->total++;
    return true;
}

bool addGSocios(gsocios Socios ,int nome, int tempo){
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

void preencherGNormal(int Carga, gnormal Normal){
    for(int i=1; i<=Carga; i++){
        if((i%20) < 10 && (i%20) >= 0)
            addGNormal(Normal, i, 3);
        if((i%20) < 16 && (i%20) > 9)
            addGNormal(Normal, i, 2);
        if((i%20) < 20 && (i%20) > 15)
            addGNormal(Normal, i, 1);
    }
}

void preencherGSocios(int Carga, gsocios Socios){
    for(int i=1; i<=Carga; i++){
        if((i%20) < 17 && (i%20) >= 0)
            addGSocios(Socios, i, 1);
        if((i%20) < 20 && (i%20) > 16)
            addGSocios(Socios, i, 2);
    }
}

ostream& operator<<(ostream& os, const Torcedor& aux) {
    if(aux.socio==false)
        os << aux.nome;
    else
        os << aux.nome << "S";
    return os;
}

ostream& operator<<(ostream& os, const Fila<Torcedor>& f) {
    ElementoF<Torcedor> *nav = f.inicio;
    while(nav!=NULL){
        os << " " << nav->dado << " ";
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
    menu(qtdGuicheSocio, qtdGuicheNormal, qtdCarga, qtdProcura, qtdTempo);
    for(int i=qtdGuicheNormal; i>0; i--){
        guiches *novo = novoGuiche(i);
        novo->proximo = Normal.primeiroN;
        Normal.primeiroN = novo;
    }
    for(int i=qtdGuicheSocio; i>0; i--){
        guiches *novo = novoGuiche(i);
        novo->proximo = Socios.primeiroS;
        Socios.primeiroS = novo;
    }
    preencherGSocios(qtdCarga/20, Socios);
    preencherGNormal(qtdCarga-qtdCarga/20, Normal);
    for(int i=qtdTempo; i>0; i--){
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
        }
        nav = Normal.primeiroN;
        while(nav!=NULL){
            if(nav->gfila.inicio!=NULL){
                if(nav->gfila.inicio->dado.tempo==0)
                    DeQueue(nav->gfila);
                else
                    nav->gfila.inicio->dado.tempo--;
            }
            nav = nav->proximo;
        }
        nav = Socios.primeiroS;
        while(nav!=NULL){
            if(nav->gfila.inicio!=NULL){
                if(nav->gfila.inicio->dado.tempo==0)
                    DeQueue(nav->gfila);
                else
                    nav->gfila.inicio->dado.tempo--;
            }
            nav = nav->proximo;
        }
        system("pause");
        system("cls");
    }
    cout << "Simulação Encerrada." << endl;
    return 0;
}
/* balanceamento de procentagem: 1-((1+x)/x%)*/
