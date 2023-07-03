#include <iostream>
using namespace std;
#include <string>
#include <windows.h>
struct No {
    string VxO;
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

bool VOp(char C){
    if((C == '+') || (C == '-') || (C == '*') || (C == '/'))
        return true;
    else
        return false;
}

bool VParenteses(char C){
    if((C == '(') || (C == ')')){
        return true;
    }
    else{
        return false;
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

No* MontarArv(string exp) {
    int posOp = -1,contP = 0;

    for (int i = exp.size()-1; i >=0 ; i--) {
        cout<<endl<<exp[i]<<endl;
        if (exp[i] == ')') {
            contP++;
        } else if (exp[i] == '(') {
            contP--;
        } else if ((exp[i] == '+' || exp[i] == '-') && contP == 0) {
            posOp = i;
            break;
        } else if ((exp[i] == '*' || exp[i] == '/') && contP == 0) {
            posOp = i;
            break;
        }
    }
    if (posOp != -1) {
        No* no = new No;
        no->VxO = exp[posOp];
        no->esquerda = MontarArv(exp.substr(0, posOp));
        no->direita = MontarArv(exp.substr(posOp + 1));
        return no;
    }
    else if (exp[0] == '(' && exp[exp.size() - 1] == ')' && contP == 0) {
        return MontarArv(exp.substr(1, exp.size() - 2));
    } else {
        No* no = new No;
        no->VxO = getNumber(exp);
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

bool verificar(string exp){
    for(int i=0;i<exp.size();i++){
        if(exp[i]==' '){
            exp.erase(i,1);
            i--;
        }
    }
    int contAbre=0,contFecha=0;
    for(int i=0;i<exp.size();i++){
        cout<<exp[i]<<endl;
        if(!VOp(exp[i]) && !VNum(exp[i]) && !VParenteses(exp[i])){
            return false;
        }
    }
    if(exp.size()==1 && !VNum(exp[0])){
        return false;
    }
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='('){
            contAbre++;
        }
        if(exp[i]==')'){
            contFecha++;
        }
    }
    if(contAbre!=contFecha){
        return false;
    }
    for(int i=0;i<exp.size()-1;i++){
        if(VOp(exp[i])==true && VOp(exp[i+1]==true && (exp[i]!='(' || exp[i]!=')' || exp[i+1]!='(' || exp[i+1]!=')'))){
            return false;
        }
    }
    if(VOp(exp[0])==true || VOp(exp[exp.size()-1])==true){
        return false;
    }

    return true;
}

void menu(int &op){
    cout<<endl;
    cout<<endl;
    cout<<"\t\tÁRVORE BINÁRIA DE EXPRESSÃO"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"1 - Inserir Expressão"<<endl;
    cout<<"2 - Exibir Expressão"<<endl;
    cout<<"3 - Exibir Resultado"<<endl;
    cout<<"4 - Exibir em Forma de Grafo"<<endl;
    cout<<"5 - Encerrar"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cin>>op;
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    int op;
    string expressao;
    Tarv arvore = {};

    do{
        menu(op); //Função menu, onde estará a interface do usuário no console
        switch(op) //A função menu retorna o opção, a qual é armazenada um valor, e será direcionada para a função desejada
        {
          case 1:
            system("cls"); //Limpa a interface do usuário
            cout<<"Digite uma expressão:"<<endl;
            cin>>expressao; //O usuário digita a expressão no qual deseja que seja calculada
            arvore = {}; //Anula a variável árvore por uma possível outra expressão a qual queira estar realizando depois
            if(!verificar(expressao)){
                cout<<"Expressão errada";
                break;
            }
            arvore.raiz = MontarArv(expressao); //Chama a função que estará armazenando e reorganizando a expressão digitada pelo usuário
            system("cls"); //Limpa a interface do usuário
          break;
          case 2:
            system("cls"); //Limpa a interface do usuário
            cout<<endl;
            for(int i=0; i < expressao.size(); i++){ //Um laço de repetição que irá percorrer toda a expressão digitada, exibindo a mesma
                cout<<expressao[i]<<" ";
              }
            cout<<endl;
          break;
          case 3:
            system("cls"); //Limpa a interface do usuário
            cout<<endl;
            cout<<"Resultado: "<<Calculo(arvore.raiz)<<endl; //Exibe o resultado retornado pela função cálculo
          break;
          case 4:
            system("cls"); //Limpa a interface do usuário
            cout<<endl;
            mostrar(arvore); //Função que exibe a expressão da forma que está contida na árvore em grafo
            cout<<endl;
          break;
          case 5: //Encerra o programa
          break;
          default:
          system("cls");
            cout<<"Opção Inválida";
        }
    } while(op != 5);
}
