
#include"../funcoes/funcoes.c"



typedef struct animais Animais;

Animais* cria_animais(void);

Animais* insere_animais(Animais* lista_animal,char* nome, char* idade, char* especie, char* condicao);

Animais* remove_animal(Animais* lista_animal, char* nome);

Animais* busca_animal(Animais* lista_animal, char* nome);

int vazia_animais(Animais* lista_animal);

void libera_animais(Animais* lista_animal);




