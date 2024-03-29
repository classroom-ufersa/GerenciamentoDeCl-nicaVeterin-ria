
#include"../animais/animais.c"


typedef struct tutores Tutores;

Tutores* cria_tutores(void);

Tutores* insere_tutores(Tutores* lista_tutor, char* nome, char* contato, char* documento);

Tutores* remove_tutores(Tutores* lista_tutor, char* nome_busca);

Tutores* buscar_tutor(Tutores* lista_tutor, char* nome_busca);

void libera_tutores(Tutores* lista_tutor);

void editar_tutor_animal(Tutores* lista_tutores, Tutores* tutor_atual, Animais* animal);