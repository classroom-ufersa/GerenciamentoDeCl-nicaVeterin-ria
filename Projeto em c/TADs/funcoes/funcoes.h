
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <conio.h>
#define TXT_red "\x1b[31m"
#define TXT_green "\x1b[32m"
#define TXT_yellow "\x1b[33m"
#define TXT_whitered "\x1b[41m"
#define TXT_reset "\x1b[0m"
#define N 81

void cabecalho(char *pagina, char *titulo);

void menu(void);

int verificar_nome(char * nome);

int verificar_contato(char* contato);

int verificar_documento(char* documento);

int verificar_condicao(char* condicao);

int verificar_opcao(char* opcao);

int verificar_opcao2(char* opcao);

void str_end(char* str);

void capitalizeNames(char *str);

char *string_upper(char *str);

int comparenames(char* str1, char* str2);

void print_msg(int cod_msg);

void condicao_nome_add(void);

void condicao_nome_busca(void);

void condicao_contato(void);

void condicao_documento(void);

void condicao_especie(void);

void condicao_condicao();

void pedros_vet();

void limpa_tela(void);

void pressiona_enter();
