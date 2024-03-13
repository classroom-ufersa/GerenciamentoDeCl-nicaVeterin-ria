#include"Animais.h"
#define N 81 /* Número máximo caracteres */

struct animais{
    int idade;
    char especie[N];
    char condicao[N];
}

int Contagem_animais(FILE *arquivo){
    int numero_animais = 0;
    char linha[100];

    while (fgets(linha, 100, arquivo) != NULL) { 
        numero_animais++;
    }
    return numero_animais;
}