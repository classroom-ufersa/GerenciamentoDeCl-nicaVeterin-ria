#include"../tutores/tutores.c"

void cabecalho(char *pagina, char *titulo);

void menu(void);

void adicionar_tutor(Tutores* lista_tutores);

void remover_tutor(Tutores* lista_tutores);

void adicionar_animal(Tutores* lista_tutores);

void remover_animal(Tutores* lista_tutores);

void buscar_animal(Tutores* lista_tutores);

void listar_animais_tutor(Tutores* lista_tutores);

Tutores* carregar_dados(Tutores* lista_tutores);

void escrever_dados(Tutores* lista_tutores);