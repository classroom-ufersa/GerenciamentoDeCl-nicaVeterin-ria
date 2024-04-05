#include"../src/animais.c"

/**
 * @struct Tutores
 * @brief Estrutura para representar uma lista de tutores.
 */
typedef struct tutores Tutores;

/**
 * @brief Cria uma lista de tutores vazia.
 * 
 * Esta função aloca memória para uma lista de tutores vazia
 * e a inicializa. Retorna um ponteiro para a lista de tutores.
 * 
 * @return Um ponteiro para a lista de tutores criada com o valor NULL.
 */
Tutores* cria_tutores(void);

/**
 * @brief Insere um novo tutor na lista de tutores.
 * 
 * Esta função recebe uma lista de tutores, o nome, o contato e o documento de um tutor,
 * e insere um novo nó na lista de tutores com essas informações. Retorna um ponteiro para a lista
 * de tutores atualizada.
 * 
 * @param lista_tutor Um ponteiro para a lista de tutores.
 * @param nome O nome do tutor a ser inserido.
 * @param contato O contato do tutor a ser inserido.
 * @param documento O documento do tutor a ser inserido.
 * 
 * @return Um ponteiro para a lista de tutores atualizada, ou NULL se a memória não puder ser alocada.
 */
Tutores* insere_tutores(Tutores* lista_tutor, char* nome, char* contato, char* documento);

/**
 * @brief Remove um tutor da lista de tutores.
 * 
 * Esta função recebe uma lista de tutores e o nome de um tutor a ser removido.
 * Ela remove o nó correspondente da lista de tutores e retorna um ponteiro para a lista
 * de tutores atualizada.
 * 
 * @param lista_tutor Um ponteiro para a lista de tutores.
 * @param nome O nome do tutor a ser removido.
 * 
 * @return Um ponteiro para a lista de tutores atualizada.
 */
Tutores* remove_tutores(Tutores* lista_tutor, char* nome_busca);

/**
 * @brief Busca um tutor na lista de tutores.
 * 
 * Esta função recebe uma lista de tutores e o nome de um tutor a ser buscado.
 * Ela percorre a lista de tutores e retorna um ponteiro para o nó correspondente
 * ao tutor buscado, ou NULL se o tutor não for encontrado.
 * 
 * @param lista_tutor Um ponteiro para a lista de tutores.
 * @param nome O nome do tutor a ser buscado.
 * 
 * @return Um ponteiro para o nó correspondente ao tutor buscado, ou NULL se o tutor não for encontrado.
 */
Tutores* buscar_tutor(Tutores* lista_tutor, char* nome_busca);

/**
 * @brief Libera a memória alocada para a lista de tutores.
 * 
 * Esta função recebe uma lista de tutores e libera a memória alocada
 * para cada nó da lista.
 * 
 * @param lista_tutor Um ponteiro para a lista de tutores.
 */
void libera_tutores(Tutores* lista_tutor);

/**
 * @brief Edita a posição de um animal entre turores.
 * 
 * Esta função permite editar o tutor associado a um animal.
 * Ela solicita o nome do novo tutor e atualiza as informações do animal 
 * na lista de animais do novo tutor e o remove da lista de animais do tutor atual.
 * Se o novo tutor não existir, uma mensagem de erro será exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de todos os tutores.
 * @param tutor_atual Ponteiro para o tutor atual do animal.
 * @param animal Ponteiro para o animal cujo tutor será editado.
 */
void editar_tutor_animal(Tutores* lista_tutores, Tutores* tutor_atual, Animais* animal);