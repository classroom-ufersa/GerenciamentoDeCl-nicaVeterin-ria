#include"../src/funcoes.c"

/**
 * @struct Animais
 * @brief Estrutura para representar uma lista de animais.
 */
typedef struct animais Animais;

/**
 * @brief Cria uma lista de animais vazia.
 * 
 * Esta função aloca memória para uma lista de animais vazia
 * e a inicializa. Retorna um ponteiro para a lista de animais.
 * 
 * @return Um ponteiro para a lista de animais criada com o valor NULL.
 */
Animais* cria_animais(void);

/**
 * @brief Insere um novo animal na lista de animais.
 * 
 * Esta função recebe uma lista de animais, o nome, a idade, a espécie e a condição de um animal,
 * e insere um novo nó na lista de animais com essas informações. Retorna um ponteiro para a lista
 * de animais atualizada.
 * 
 * @param lista_animal Um ponteiro para a lista de animais.
 * @param nome O nome do animal a ser inserido.
 * @param idade A idade do animal a ser inserido.
 * @param especie A espécie do animal a ser inserido.
 * @param condicao A condição do animal a ser inserido.
 * 
 * @return Um ponteiro para a lista de animais atualizada, ou NULL se a memória não puder ser alocada.
 */
Animais* insere_animais(Animais* lista_animal,char* nome, char* idade, char* especie, char* condicao);

/**
 * @brief Remove um animal da lista de animais.
 * 
 * Esta função recebe uma lista de animais e o nome de um animal a ser removido.
 * Ela remove o nó correspondente da lista de animais e retorna um ponteiro para a lista
 * de animais atualizada.
 * 
 * @param lista_animal Um ponteiro para a lista de animais.
 * @param nome O nome do animal a ser removido.
 * 
 * @return Um ponteiro para a lista de animais atualizada.
 */
Animais* remove_animal(Animais* lista_animal, char* nome);

/**
 * @brief Busca um animal na lista de animais.
 * 
 * Esta função recebe uma lista de animais e o nome de um animal a ser buscado.
 * Ela percorre a lista de animais e retorna um ponteiro para o nó correspondente
 * ao animal buscado, ou NULL se o animal não for encontrado.
 * 
 * @param lista_animal Um ponteiro para a lista de animais.
 * @param nome O nome do animal a ser buscado.
 * 
 * @return Um ponteiro para o nó correspondente ao animal buscado, ou NULL se o animal não for encontrado.
 */
Animais* busca_animal(Animais* lista_animal, char* nome);

/**
 * @brief Verifica se a lista de animais está vazia.
 * 
 * Esta função recebe uma lista de animais e verifica se ela está vazia.
 * Retorna 1 se a lista estiver vazia, ou 0 caso contrário.
 * 
 * @param lista_animal Um ponteiro para a lista de animais.
 * 
 * @return 1 se a lista de animais estiver vazia, ou 0 caso contrário.
 */
int vazia_animais(Animais* lista_animal);

/**
 * @brief Libera a memória alocada para a lista de animais.
 * 
 * Esta função recebe uma lista de animais e libera a memória alocada para ela.
 * 
 * @param lista_animal Um ponteiro para a lista de animais.
 */
void libera_animais(Animais* lista_animal);

/**
 * @brief Imprime as informações de um animal.
 * 
 * Esta função recebe um ponteiro para um nó de animal e imprime as informações
 * do animal correspondente.
 * 
 * @param animal Um ponteiro para um nó de animal.
 */
void imprimir_animal(Animais* animal);

/**
 * @brief Edita o nome de um animal.
 * 
 * Esta função recebe um ponteiro para um nó de animal e permite editar o nome
 * do animal correspondente.
 * 
 * @param animal Um ponteiro para um nó de animal.
 */
void editar_nome_animal(Animais* animal);

/**
 * @brief Edita a idade de um animal.
 * 
 * Esta função recebe um ponteiro para um nó de animal e permite editar a idade
 * do animal correspondente.
 * 
 * @param animal Um ponteiro para um nó de animal.
 */
void editar_idade_animal(Animais* animal);

/**
 * @brief Edita a espécie de um animal.
 * 
 * Esta função recebe um ponteiro para um nó de animal e permite editar a espécie
 * do animal correspondente.
 * 
 * @param animal Um ponteiro para um nó de animal.
 */
void editar_especie_animal(Animais* animal);

/**
 * @brief Edita a condição de um animal.
 * 
 * Esta função recebe um ponteiro para um nó de animal e permite editar a condição
 * do animal correspondente.
 * 
 * @param animal Um ponteiro para um nó de animal.
 */
void editar_condicao_animal(Animais* animal);