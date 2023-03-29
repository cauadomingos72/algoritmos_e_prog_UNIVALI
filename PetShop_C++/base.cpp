#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class carro{
    private:
        vector<int>id_carro;
        vector<string> modelo;
        vector<string>cor;
        vector<int>tamanho;
        vector<int>preco;

    public:

/////////////////////////////////////////////////////////////
///ADICIONANDO A LISTA

    void addModelo(string m) {
        modelo.push_back(m);
    }

    void addCor(string c) {
        cor.push_back(c);
    }

    void addTamanho(int t) {
        tamanho.push_back(t);
    }

    void addPreco(int p) {
        preco.push_back(p);
    }

    void addId(int &d) {
        id_carro.push_back(d);
        d++;
    }

/////////////////////////////////////////////////////////////////////////////
///PRINT

    void printId() {
        cout<<"Id:\t\t";
        for (int i = 0; i < id_carro.size(); i++) {
            cout << id_carro[i] << "\t";
        }
        cout << endl;
    }

    void printModelo() {
        cout<<"Modelo:\t\t";
        for (int i = 0; i < modelo.size(); i++) {
            cout << modelo[i] << "\t";
        }
        cout << endl;
    }

    void printCor() {
        cout<<"Cor:\t\t";
        for (int i = 0; i < cor.size(); i++) {
            cout << cor[i] << "\t";
        }
        cout << endl;
    }

    void printTamanho() {
        cout<<"Assentos:\t";
        for (int i = 0; i < tamanho.size(); i++) {
            cout << tamanho[i] << "\t";
        }
        cout << endl;
    }

    void printPreco() {
        cout<<"Preco:\t\t";
        for (int i = 0; i < preco.size(); i++) {
            cout << preco[i] << "\t";
        }
        cout << endl;
    }

    void sizeModelo(int var){
        var=modelo.size();
        cout<<"Var:"<<var;
    }

    void pesquisarModelo(string var_string,int var){
        for(int i = 0 ; i < var; i++){
            if(modelo[i]==var_string){
                //imprimir_carro(id_carro,modelo,cor,tamanho,preco);
            }
        }
    }
};

class Dados{
    string nome;
    int documento;
};

void imprimir_carro(carro id_carro,carro modelo,carro cor,carro tamanho,carro preco){
    id_carro.printId();
    modelo.printModelo();
    cor.printCor();
    tamanho.printTamanho();
    preco.printPreco();
}

void pesquisa(carro id_carro,carro modelo,carro cor,carro tamanho,carro preco){
    int pes,var;
    system("cls");
    cout<<endl<<endl<<"Deseja Pesquisar por: "<<endl<<endl;
    cout<<"1- Modelo\n2- Cor\n3- Número de Assentos\n4- Preco Máximo"<<endl;
    cin>>pes;
    int var_int;
    string var_string;
    system("cls");
    switch(pes){
    case 1:
        cout<<endl<<endl<<"Digite o nome do modelo que deseja ver: ";
        cin>>var_string;
        modelo.sizeModelo(var);
        modelo.pesquisarModelo(var_string,var);
        break;
    case 2:
        cout<<endl<<endl<<"Digite o nome da cor que deseja ver: ";
        cin>>var_string;
        break;
    case 3:
        cout<<endl<<endl<<"Digite o número de assentos do carro que deseja ver: ";
        cin>>var_int;
        break;
    case 4:
        cout<<endl<<endl<<"Digite o preço máximo que deseja ver: ";
        cin>>var_int;
        break;
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    int tam=0;

    carro id_carro,modelo,cor,tamanho,preco;
    int menu,select,t,p,d=1;
    string m,c;
    do{
        system("cls");
        cout<<endl<<"\t\tMenu"<<endl<<endl<<"Digite 1 para acessar o menu para Funcionários e 2 para o Cliente: ";
        cin>>menu;
        system("cls");
        switch(menu)
        {
        case 1:
            tam++;
            cout<<endl<<"\tMenu Funcionário";
            cout<<endl<<endl<<"Digite as informações do carro para registrá-lo: "<<endl<<endl;
            cout<<"Modelo: ";
            cin>>m;
            modelo.addModelo(m);
            cout<<endl<<"Cor: ";
            cin>>c;
            cor.addCor(c);
            cout<<endl<<"Número de Assentos: ";
            cin>>t;
            tamanho.addTamanho(t);
            cout<<endl<<"Preço por dia: ";
            cin>>p;
            preco.addPreco(p);
            id_carro.addId(d);
            break;
        case 2:
            cout<<endl<<"\tMenu Cliente";
            cout<<endl<<endl<<"Digite um dos números abaixo para ver se as opções de carros disponíveis: ";
            cout<<endl<<endl<<"1- Imprimir todos os carros\n2- Pesquisar por categoria"<<endl;
            cin>>select;
            switch(select){
            case 1:
                cout<<endl<<endl;
                imprimir_carro(id_carro,modelo,cor,tamanho,preco);
                system("pause>nul");
                break;
            case 2:
                pesquisa(id_carro,modelo,cor,tamanho,preco);
                system("pause>nul");
                break;
            }
            break;
        }
    }while(menu!=3);
    return 0;
    }
