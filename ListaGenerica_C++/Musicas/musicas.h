#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct musica{          ///struct do TAD usado no programa.
    string nome;
    string artista;
};

musica gerarMusica(){   ///função para entrada de dados na criação de um elemento (não utilizado no momento).
    musica temp;
    cout << endl << "Digite o nome da música:" << endl;
    fflush(stdin);
    getline(cin, temp.nome);
    cout << endl << "Digite o artista da música:" << endl;
    fflush(stdin);
    getline(cin, temp.artista);
    return temp;
}

bool operator<(const musica s1, const musica s2){   ///Função com sobrecarga de operador que permite analisar
    if(s1.nome.compare(s2.nome)<0){                 ///os nomes de duas musicas de acordo com a ordem alfabética.
        return true;
    }else{
        return false;
    }
}

bool operator<=(const musica s1, const musica s2){   ///Função com sobrecarga de operador que permite analisar
    if(s1.nome.compare(s2.nome)<=0){                 ///os nomes de duas musicas de acordo com a ordem alfabética.
        return true;
    }else{
        return false;
    }
}

bool operator>(const musica s1, const musica s2){   ///Função com sobrecarga de operador que permite analisar
    if(s1.nome.compare(s2.nome)>0){                 ///os nomes de duas musicas de acordo com a ordem alfabética.
        return true;
    }else{
        return false;
    }
}

ostream& operator<<(ostream &out, const musica s){  ///Sobrecarga que permite a saída dos dados do TAD.
    out << "Nome: " << s.nome << endl;
    out << "Artista: " << s.artista << endl;
    return out;
}
