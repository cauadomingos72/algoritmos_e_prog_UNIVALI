//Alunos: Cauã Domingos, Paulo Martino Hermans, Thyago Magalhães do Nascimento e Vinícius Henrique Ribeiro.
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15
#define TAM 5
using namespace std;

bool menu()  //Cria um menu ao abrir o jogo.
{
    int opcao;
    cout << " ____ ___ _  _  ____  ___  " << endl;
    cout << "| __ )_ _|  | |/ ___|/ _  " << endl;
    cout << "|  _  | ||  | | |  _| | | |" << endl;
    cout << "| |_) | || |  | |_| | |_| |" << endl;
    cout << "|____/___|_| _| ____| ___/ " << endl;
    cout << endl;
    cout << "1 - Jogar\n2 - Fechar o jogo" << endl;
    cin >> opcao;
    if(opcao!=1)
    return false;
    else
    return true;
}

bool verif(int cartela[][TAM],int temp)
{
    for(int i=0;i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            if(cartela[i][j]==temp) //Verifica se o valor gerado na variável "temp" já está inserido na cartela.
            return true; //Retorna "true" caso o valor no "temp" já esteja na cartela.
        }
    }
    return false; //Retorna "false" caso o valor no "temp" não esteja na cartela.
}

string preencher(int cartela[TAM][TAM])
{
    int temp;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            temp = 1+i*15+(rand()%15); //Valor gerado de maneira controlada de acordo com a linha, seguindo uma ordem de 15 em 15.
            while(verif(cartela,temp)) //Laço que garante que não insira um valor repetido na cartela.
            {
                temp = 1+i*15+(rand()%15);
            }
            cartela[i][j]=temp;
        }
    }
    string nome;
    cout << "De um nome para a cartela:";
    cin >> nome;
    return nome;
}

void bubblesort (int cartela[TAM][TAM]){  //Função de ordenação crescente para cada linha da cartela.
    int cond=1, temp=0;
    for(int i=TAM-1; (i>=1) && (cond==1); i--){
    cond=0;
        for(int j=0; j<TAM;j++){
            for(int k=0; k<i; k++){
                if(cartela[j][k+1]<cartela[j][k]){  //Condição que confere a ordem crescente da linha da matriz.
                  temp=cartela[j][k];
                  cartela[j][k]=0;
                  cartela[j][k]=cartela[j][k+1];
                  cartela[j][k+1]=temp;  //Caso esteja fora de ordem, os valores são trocados de posição com o uso de uma variável temporaria.
                  cond=1;
                }
            }
        }
    }
}

int sorteio(bool zero)
{
    srand((unsigned) time(NULL));
    static int numerosParaSortear[76] = {0};  //Variável estática para armazenamento dos valores durante todas as execuções da função.
    int n;
    bool mantemWhile = true;
    do
    {
        n = rand()%75+1;

        if (numerosParaSortear[n] == 0)  //Lógica que mantém o laço rodando até que um valor novo seja obtido.
        {
            numerosParaSortear[n] = n;
            mantemWhile = false;
        }

    } while (mantemWhile);
    if(zero==true)
    for(int i=0; i<77; i++)  //Laço e lógica que zeram a variável ao reiniciar o jogo.
    numerosParaSortear[i]=0;
    return n;
}

void clrscr(){
  system("cls");
}

void textcolor (int forecolor, int backcolor) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void exibir(int cartela[TAM][TAM], string nome, int vet[TAM*15])  //Função para exibição das cartelas, dos números marcados e dos nomes.
{
    cout << "Cartela de " << nome << endl;  //Exibição do nome da cartela.
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            bool igual=false;
            for(int k=1; k<TAM*15; k++)
            {
                if(vet[k]!=0)  //Lógica para marcação de números sorteados.
                {
                    if(cartela[i][j]==vet[k])
                    igual=true;
                }
                else
                k=TAM*15;
            }
            if(igual==false)  //Condição de número não marcado.
            {
                textcolor (BRIGHTWHITE, BLACK);
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";  //Lógica para organização dos caracteres, adicionando um 0 na casa da dezena dos números menores que 10.
                else
                cout << cartela[i][j] << " ";
            }
            else if(igual==true) //Condição de número marcado.
            {
                textcolor (LIGHTRED, BLACK);
                if (cartela[i][j]<10)
                cout << "0" << cartela[i][j] << " ";
                else
                cout << cartela[i][j] << " ";
                textcolor (BRIGHTWHITE, BLACK);
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool bingo(int mat[TAM][TAM], int vet[TAM*15])  //Função para condição de vitória.
{
    int cont=0;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            for(int k=0; k<TAM*15; k++)
            {
                if(mat[i][j]==vet[k])  //Compara os valores e armazena o numero de números iguais.
                cont++;
            }
        }
    }
    if(cont==25)  //Caso a cartela esteja com os 25 números marcados, ela vence.
    return true;
    else
    return false;
}

bool menufim(string name)  //Um novo menu para repetição ou encerramento do jogo.
{
    clrscr();
    cout << "A cartela de " << name << " venceu!";
    cout << endl;
    cout << "1 - Jogar Novamente\n2 - Fechar o jogo" << endl;
    int opcao;
    cin >> opcao;
    if(opcao!=1)
    return false;
    else
    return true;
}

void marcados(int sorteados[TAM*15])
{
    for(int j=1; j<TAM*15; j++)  //Laço que percorre o vetor.
    {
        if(sorteados[j]!=0)  //Lógica que determina o fim da exibição do vetor se baseado em valores diferentes de zero.
        {
            if (sorteados[j]<10)
            cout << "0" << sorteados[j] << " ";
            else
            cout << sorteados[j] << " ";
        }
        else
        j=TAM*15;  //Caso o resto do vetor esteja vazio, esta linha encerra o laço.
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    bool game = menu();  //Variável usada durante todo o programa e serve para fazer o jogo continuar rodando até que seja fechado.
    textcolor(15,0);  //Função usada para alterar a cor dos caracteres a serem apresentados.
    if (game==true)  //Lógica de continuação ou encerramento do jogo.
    do
    {
        bool zerar=true;  //Variável que apaga os números sorteados na execução anterior do programa ou determina a gravação dos mesmos no main.
        sorteio(zerar);  //Função que sorteia números aleatórios de 1 a 75. Utiliza uma variável estática que necessita de uma variável no main para ser zerada.
        zerar=false;
        int sorteados[TAM*15]{0};  //Vetor que armazena os números sorteados.
        clrscr();  //Função que apaga todos os caracteres exibidos no programa
        int cartela1[TAM][TAM]{0};  //Matrizes para as cartélas.
        int cartela2[TAM][TAM]{0};
        int cartela3[TAM][TAM]{0};
        int cartela4[TAM][TAM]{0};
        int cartela5[TAM][TAM]{0};
        string nome1 = preencher(cartela1);  //Variáveis para os nomes e função que determina os números e o nome a ser escolhido.
        string nome2 = preencher(cartela2);
        string nome3 = preencher(cartela3);
        string nome4 = preencher(cartela4);
        string nome5 = preencher(cartela5);
        bubblesort(cartela1);  //Função para ordenação dos valores.
        bubblesort(cartela2);
        bubblesort(cartela3);
        bubblesort(cartela4);
        bubblesort(cartela5);
        for (int i=0; i<75; i++){  //Laço de repetição para as jogadas.
            clrscr();
            if(i!=0)
            sorteados[i] = sorteio(zerar);  //Após o valor da variável ser trocado depois da última execução, a função passará a armazenar valores no vetor.
            exibir(cartela1,nome1,sorteados);  //Função que exibe o nome e os números da cartela na tela .
            exibir(cartela2,nome2,sorteados);
            exibir(cartela3,nome3,sorteados);
            exibir(cartela4,nome4,sorteados);
            exibir(cartela5,nome5,sorteados);
            marcados(sorteados);  //Função que exibe os números já sorteados.
            getch();  //Comando que exige uma digitação para a continuação do programa.
            if(bingo(cartela1, sorteados)==true)  //Função e lógica para determinar o vencedor.
            {
            system("pause");
            game = menufim(nome1); //Função que mostra a cartela vencedora e as opções de continuação ou encerramento.
            break;
            }
            if(bingo(cartela2, sorteados)==true)
            {
            system("pause");
            game = menufim(nome2);
            break;
            }
            if(bingo(cartela3, sorteados)==true)
            {
            system("pause");
            game = menufim(nome3);
            break;
            }
            if(bingo(cartela4, sorteados)==true)
            {
            system("pause");
            game = menufim(nome4);
            break;
            }
            if(bingo(cartela5, sorteados)==true)
            {
            system("pause");
            game = menufim(nome5);
            break;
            }
        }
    }while(game==true);  //Lógica que garante a continuação do jogo.
    return 0;
}
