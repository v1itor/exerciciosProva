#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#define NUMERO 10;

void exercicio1(){
        int nivel;
        printf("\n\nBem vindo! Por favor, insira a dificuldade:\n\n1 - Fácil\n2 - Médio\n3 - Difícil\n\n");
        scanf("%d", &nivel);
        fflush(stdin);
        parametrizar(nivel);
}

void start(int resposta, int max_tentativas){
    int tentativa;
    printf("%d", resposta);
    for (int i=0; i<max_tentativas; i++){
        printf("\n-> Tentativa %d de %d\n", i+1, max_tentativas);
        printf("\ttentativa um número: ");
        scanf("%d", &tentativa);
        fflush(stdin);

        if (tentativa == resposta) {
            printf("\n\nParabéns! Você acertou o número secreto na %dª tentativa!\n\n", i+1);
            break;
        }
        else if (tentativa < resposta) {
            printf("\nSua tentativa foi menor que o número secreto!\n\n");
        }
        else {
            printf("\nSua tentativa foi maior que o número secreto!\n\n");
        }
    }
    if (tentativa != resposta) {
        printf("\n\nVocê perdeu!\nO número secreto era: %d\n\n", resposta);
    }
}

void parametrizar(int nivel){
    int resposta, max_tentativas;
    srand(time(NULL));
    switch (nivel) {
        case 1:
            resposta = rand() % 10;
            max_tentativas = 5;
            start(resposta, max_tentativas);
            break;
        case 2:
            resposta = rand() % 50;
            max_tentativas = 4;
            start(resposta, max_tentativas);
            break;
        case 3:
            resposta = rand() % 100;
            max_tentativas = 3;
            start(resposta, max_tentativas);
            break;
        default:
            exercicio1();
            break;
    }
}

void exercicio2(){
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    for(i =0; i<3; i++){
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] *= 3;
        }
    }
    for(i =0; i<3; i++){
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void count_str(char* dest){
    printf("\n\nA quantidade de caracteres na string que voce inseriu e de %d\n\n", strlen(dest));
}

void substituiStr(char* source, char* dest){
    char result[200];
    strcpy(result, source);
    strncat( result, dest, strlen(dest));
    printf("\n\nNosso conjunto inicial e \"%s\", somaremos os 10 primeiros caracteres a \"%s\" e obteremos o conjunto \"%s\"", source, dest, result);
}

void intToStrParse(char* str){
    int i;
    if (strchr(str, '-')){
        char *result = str+1;
        i = atoi(result);
        i = i-(2*i);
    }else{
        i= atoi(str);
    }
    printf("\n\n%d", i*2);
}

void exercicio3() {
    char source[20] = "ola mundo!";
    char dest[200] = "meu nome e vitor";
    printf("\n\nDigite o que deseja somar no \"Ola mundo\": ");
    gets(dest);
    count_str(dest);
    substituiStr(source, dest);
    char number[5];
    printf("\n\nInsira um numero de ate 5 digitos que sera multiplicado por 2: ");
    gets(number);
    intToStrParse(number);
    return 0;
}

void exercicio4(){
    char nome[50] = {"olá mundo"};

    printf("Digite seu nome: ");
    getchar();
    fgets(nome, 50, stdin);

    printf("Seu nome é %s\n\n", nome);

    return 0;
}

void selecionaExercicios(){
    int exercicioSelecionado;
    printf("Bem vindo!\n\nSelecione o exercicio que deseja rodar:\n\n1 - Acerte um número!\n2 - Multiplique uma raiz por um escalar\n3 - Manipulação de strings\n4 - Mostrar string\nDigite o exercício desejado: ");
    scanf("%d", &exercicioSelecionado);
    fflush(stdin);
    switch (exercicioSelecionado)
    {
    case 1:
        exercicio1();
        break;
    case 2:
        exercicio2();
        break;
    case 3:
        exercicio3();
        break;
    case 4:
        exercicio4();
        break;
    default:
        printf("\n\nExercício inválido, selecione novamente!\n");
        selecionaExercicios();
        break;
    }
}

int main (void)
{
    setlocale(LC_ALL, "Portuguese");
    printf("Bem Vindo!");
    selecionaExercicios();
}