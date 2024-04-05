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

/**
 * @brief Exibe um cabeçalho na tela.
 * 
 * Esta função limpa a tela, exibe um cabeçalho formatado
 * com o nome da página e o título fornecidos como parâmetros.
 * 
 * @param pagina O nome da página a ser exibido no cabeçalho.
 * @param titulo O título a ser exibido no cabeçalho.
 */
void cabecalho(char *pagina, char *titulo);

/**
 * @brief Exibe um menu na tela.
 * 
 * Esta função limpa a tela, exibe um menu com opções numéricas
 * para várias operações relacionadas a tutores e animais.
 * 
 * As opções do menu são:
 * 1 - Adicionar tutor
 * 2 - Remover tutor
 * 3 - Adicionar animal
 * 4 - Remover animal
 * 5 - Editar informações de animal
 * 6 - Buscar animal por nome
 * 7 - Listar tutores e seus animais
 * 8 - Sair
 */
void menu(void);

/**
 * @brief Verifica se um nome é válido.
 * 
 * Esta função recebe um nome como parâmetro e verifica se ele é válido.
 * Um nome é considerado válido se contiver apenas letras do alfabeto
 * e espaços em branco. Não são permitidos espaços consecutivos e o nome
 * não pode estar vazio.
 * 
 * @param nome O nome a ser verificado.
 * @return Retorna 0 se o nome for válido, caso contrário, retorna 1.
 */
int verificar_nome(char * nome);

/**
 * @brief Verifica se um contato é válido.
 * 
 * Esta função recebe um contato como parâmetro e verifica se ele é válido.
 * Um contato é considerado válido se contiver apenas números e tiver 11 dígitos.
 * 
 * @param contato O contato a ser verificado.
 * @return Retorna 0 se o contato for válido, caso contrário, retorna 1.
 */
int verificar_contato(char* contato);

/**
 * @brief Verifica se um documento é válido.
 * 
 * Esta função recebe um documento como parâmetro e verifica se ele é válido.
 * Um documento é considerado válido se contiver apenas números e tiver 11 dígitos.
 * 
 * @param documento O documento a ser verificado.
 * @return Retorna 0 se o documento for válido, caso contrário, retorna 1.
 */
int verificar_documento(char* documento);

/**
 * @brief Verifica se uma espécie é válida.
 * 
 * Esta função recebe uma espécie como parâmetro e verifica se ela é válida.
 * Uma espécie é considerada válida se contiver apenas letras do alfabeto
 * e espaços em branco. Não são permitidos espaços consecutivos e a espécie
 * não pode estar vazia.
 * 
 * @param especie A espécie a ser verificada.
 * @return Retorna 0 se a espécie for válida, caso contrário, retorna 1.
 */
int verificar_condicao(char* condicao);

/**
 * @brief Verifica se uma opção é válida.
 * 
 * Esta função recebe uma opção como parâmetro e verifica se ela é válida.
 * Uma opção é considerada válida se for um número inteiro entre 1 e 8.
 * 
 * @param opcao A opção a ser verificada.
 * @return Retorna 0 se a opção for válida, caso contrário, retorna 1.
 */
int verificar_opcao(char* opcao);

/**
 * @brief Verifica se uma opção é válida.
 * 
 * Esta função recebe uma opção como parâmetro e verifica se ela é válida.
 * Uma opção é considerada válida se for um número inteiro entre 1 e 6.
 * 
 * @param opcao A opção a ser verificada.
 * @return Retorna 0 se a opção for válida, caso contrário, retorna 1.
 */
int verificar_opcao2(char* opcao);

/**
 * @brief Adiciona o caractere nulo ao final de uma string.
 * 
 * Esta função recebe uma string como parâmetro e adiciona o caractere
 * nulo (`'\0'`) ao final da string, indicando o seu término.
 * 
 * @param str A string à qual o caractere nulo será adicionado.
 */
void str_end(char* str);

/**
 * @brief Capitaliza nomes em uma string.
 * 
 * Esta função recebe uma string como parâmetro e capitaliza os nomes nela contidos.
 * Assume-se que os nomes estão separados por espaços e que as letras que compõem os
 * nomes devem ser maiúsculas no início e minúsculas nos demais caracteres.
 * 
 * @param str A string contendo os nomes a serem capitalizados.
 */
void capitalizeNames(char *str);

/**
 * @brief Converte uma string para letras maiúsculas.
 * 
 * Esta função recebe uma string como parâmetro e converte todas as letras
 * minúsculas contidas nela para maiúsculas.
 * 
 * @param str A string a ser convertida.
 * @return A string convertida para letras maiúsculas.
 */
char *string_upper(char *str);

/**
 * @brief Compara duas strings.
 * 
 * Esta função recebe duas strings como parâmetro e compara seus conteúdos.
 * Retorna 0 se as strings forem iguais, um valor negativo se a primeira string
 * for menor que a segunda e um valor positivo se a primeira string for maior
 * que a segunda.
 * 
 * @param str1 A primeira string a ser comparada.
 * @param str2 A segunda string a ser comparada.
 * @return 0 se as strings forem iguais, um valor negativo se a primeira string for menor que a segunda e um valor positivo se a primeira string for maior que a segunda.
 */
int comparenames(char* str1, char* str2);

/**
 * @brief Exibe um menu de edição de animal na tela.
 * 
 * Esta função exibe um menu com opções numéricas para edição de informações
 * de um animal. As opções do menu são:
 * 1 - Editar nome
 * 2 - Editar idade
 * 3 - Editar espécie
 * 4 - Editar condição
 * 5 - Voltar
 */
void menu_editar_animal();

/**
 * @brief Exibe uma mensagem na tela.
 * 
 * Esta função recebe um código de mensagem como parâmetro e exibe
 * uma mensagem correspondente ao código na tela.
 * 
 * @param cod_msg O código da mensagem a ser exibida.
 */
void print_msg(int cod_msg);

/**
 * @brief Exibe condições para adição de nome.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao adicionar um nome. As condições incluem:
 * - Informar o nome completo.
 * - Não começar com espaços.
 * - Não possuir números.
 * - Não possuir caracteres inválidos.
 */
void condicao_nome_add(void);

/**
 * @brief Exibe condições para busca de nome.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao buscar um nome. As condições incluem:
 * - Não começar com espaços.
 * - Não possuir números.
 * - Não possuir caracteres inválidos.
 */
void condicao_nome_busca(void);

/**
 * @brief Exibe condições para adição de contato.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao adicionar um contato. As condições incluem:
 * - Seguir o formato (xx) xxxxx-xxxx.
 */
void condicao_contato(void);

/**
 * @brief Exibe condições para adição de documento.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao adicionar um documento. As condições incluem:
 * - Seguir o formato xxx.xxx.xxx-xx.
 */
void condicao_documento(void);

/**
 * @brief Exibe condições para adição de espécie.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao adicionar uma espécie. As condições incluem:
 * - Informar uma espécie existente.
 * - Não começar com espaços.
 * - Não possuir números.
 * - Não possuir caracteres inválidos.
 */
void condicao_especie(void);

/**
 * @brief Exibe condições para adição de condição.
 * 
 * Esta função imprime na tela as condições que devem ser seguidas
 * ao adicionar uma condição. As condições incluem:
 * - Não começar com espaços.
 * - Não possuir caracteres inválidos.
 */
void condicao_condicao();

/**
 * @brief Exibe uma representação visual de uma placa.
 * 
 * Esta função imprime na tela uma representação visual de uma placa,
 * formada por caracteres ASCII, para fins decorativos.
 */
void pedros_vet();

/**
 * @brief Limpa a tela.
 * 
 * Esta função limpa a tela do terminal.
 */
void limpa_tela(void);

/**
 * @brief Pausa a execução do programa.
 * 
 * Esta função pausa a execução do programa até que o usuário pressione
 * a tecla Enter.
 */
void pressiona_enter();
