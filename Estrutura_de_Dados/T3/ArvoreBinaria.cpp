#include <iostream>
using namespace std;

#include <string>

struct No {
    string VxO;
    int prior;
    No* esquerda;
    No* direita;
};

struct Tarv{
    No* raiz;
};

bool VNum(char C){
    if((C >= '0')&&(C <= '9')){
        return true;
    }
    else{
        return false;
    }
}

int Prioridade(char C){
    if(C == ' ')
        return 0;
    else
    {
        if(C=='+' || C=='-')
            return 2;
        if(C=='/' || C=='*')
            return 4;
        if(C=='(' || C==')')
            return 6;
        else
            return 1;
    }
}

string getNumber(string exp){
    string aux;
    for(int i=0;i<exp.size();i++){
        if(VNum(exp[i])){
            aux+=exp[i];
        }else{
            break;
        }
    }
    return aux;
}

No* MontarArv(string exp, No *Pai) {
    int prioridadeAtual = 0;
    int posOp = -1;
    int contP = 0;
    //int valor = 0;
    int aux = 0;

    for (int i = exp.size()-1; i >=0 ; i--) {
        cout<<endl<<exp[i]<<endl;
        if (exp[i] == ')') {
            contP++;
        } else if (exp[i] == '(') {
            contP--;
        } else if ((exp[i] == '+' || exp[i] == '-') && contP == 0) {
            if(Pai!=NULL){
                cout<<"exp[i]: "<<exp[i]<<endl;
//                if(Prioridade(Pai->VxO)==4){
//                    aux = 1;
//                }
            }
            posOp = i;
            break;
        } else if ((exp[i] == '*' || exp[i] == '/') && contP == 0) {

            posOp = i;
            break;
        }
    }
    cout<<"Aux: "<<aux<<endl;
    if (posOp != -1) {
        No* no = new No;
        no->VxO = exp[posOp];
        no->prior = prioridadeAtual;
        no->esquerda = MontarArv(exp.substr(0, posOp),no);
        if(aux==1){
            cout<<"Direita-Pai: "<<Pai->direita->VxO;
            cout<<"Esquerda-Pai: "<<Pai->esquerda->VxO;
            no->direita = Pai;
            aux=0;
        }else{
             no->direita = MontarArv(exp.substr(posOp + 1),no);
        }

//        no->esquerda = MontarArv(exp.substr(0, posOp),no);
//        no->direita = MontarArv(exp.substr(posOp + 1),no);
        return no;
    }
    else if (exp[0] == '(' && exp[exp.size() - 1] == ')' && contP == 0) {
        return MontarArv(exp.substr(1, exp.size() - 2),NULL);
    } else {
        No* no = new No;
        no->VxO = getNumber(exp);
        no->prior = 0;
        no->esquerda = NULL;
        no->direita = NULL;
        return no;
    }
}

int Calculo(No* raiz) {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return stoi(raiz->VxO); // Converter o string numérico para um valor inteiro
    }
    int resultadoEsquerda = Calculo(raiz->esquerda);
    int resultadoDireita = Calculo(raiz->direita);

    if (raiz->VxO == "+") {
        return resultadoEsquerda + resultadoDireita;
    } else if (raiz->VxO == "-") {
        return resultadoEsquerda - resultadoDireita;
    } else if (raiz->VxO == "*") {
        return resultadoEsquerda * resultadoDireita;
    } else if (raiz->VxO == "/") {
        return resultadoEsquerda / resultadoDireita;
    }
    return 0; // Operador inválido
}

double pow(double a, double b){

    double result;

    result = a;

    for(int cont = 1; cont < b; cont++){
        result = result * a;
    }

    return result;
}

int altura(No *raiz) { // Ta correto
    if (raiz == NULL){
        return 0;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if (alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

int qtd_coluna(int h) {
    if (h == 1)
        return 1;
    return qtd_coluna(h - 1) + qtd_coluna(h - 1) + 1;
}

void mostraArv(string **M, No *raiz, int coluna, int linha, int altura) {
    if (raiz == NULL){
        return;
    }
    M[linha][coluna] = raiz->VxO;
    mostraArv(M, raiz->esquerda, coluna - pow(2, altura - 2), linha + 1, altura - 1);
    mostraArv(M, raiz->direita, coluna + pow(2, altura - 2), linha + 1, altura - 1);
}

void mostrar(Tarv arv) {
    int h = altura(arv.raiz)+1;
    int coluna = qtd_coluna(h);
    string **M = new string*[h];
    for (int i = 0; i < h; i++) {
        M[i] = new string[coluna];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < coluna; j++) {
            M[i][j] = "0";
        }
    }

    mostraArv(M, arv.raiz, coluna / 2, 0, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < coluna; j++) {
            if (M[i][j] == "0"){
                cout << " " << " ";
            }
            else{
                cout << M[i][j] << " ";
            }
        }
        cout << endl << endl;
    }
}

int main() {
    string exp;
    cout<<"\nDigite a expressao: ";
    getline(cin,exp);
    cout<<exp;
    for(int i=0;i<exp.size();i++){
        if(exp[i]==' '){
            exp.erase(i,1);
            i--;
        }
    }
    No* teste = NULL;
    Tarv arvore;
    arvore.raiz = MontarArv(exp,teste);
    int resultado = Calculo(arvore.raiz);
    mostrar(arvore);
    cout << "Resultado: " << resultado << endl;
    return 0;
}
