#include"../src/tutores.c"

/**
 * @brief Adiciona um novo tutor à lista de tutores.
 * 
 * Esta função permite ao usuário adicionar um novo tutor à lista de tutores.
 * O nome, contato e documento do tutor são solicitados ao usuário, verificados
 * quanto à validade, e então o tutor é adicionado à lista.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void adicionar_tutor(Tutores* lista_tutores);

/**
 * @brief Remove um tutor da lista de tutores.
 * 
 * Esta função permite ao usuário remover um tutor da lista de tutores.
 * O nome do tutor a ser removido é solicitado ao usuário, verificado
 * quanto à validade, e então, se um tutor com tal nome for encontrado o 
 * tutor é removido da lista, caso contrário, uma mensagem de erro é exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void remover_tutor(Tutores* lista_tutores);

/**
 * @brief Adiciona um novo animal à lista de um tutor.
 * 
 * Esta função permite ao usuário adicionar um novo animal à lista de animais de um tutor.
 * O nome do tutor é solicitado ao usuário para identificar a lista à qual o animal será adicionado.
 * Em seguida, o nome, idade, espécie e condição do animal são solicitados e verificados quanto à validade.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void adicionar_animal(Tutores* lista_tutores);

/**
 * @brief Remove um animal da lista de um tutor.
 * 
 * Esta função permite ao usuário remover um animal da lista de animais de um tutor.
 * O nome do tutor é solicitado ao usuário para identificar a lista à qual o animal pertence.
 * Em seguida, o nome do animal a ser removido é solicitado ao usuário, verificado
 * quanto à validade, e então, se um animal com tal nome for encontrado o 
 * animal é removido da lista, caso contrário, uma mensagem de erro é exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void remover_animal(Tutores* lista_tutores);

/**
 * @brief Edita as informações de um animal na lista de um tutor.
 * 
 * Esta função permite ao usuário editar as informações de um animal na lista de animais de um tutor.
 * O nome do tutor é solicitado ao usuário para identificar a lista à qual o animal pertence.
 * Em seguida, o nome do animal a ser editado é solicitado ao usuário, verificado
 * quanto à validade, e então, se um animal com tal nome for encontrado, o usuário pode editar
 * as informações do animal, caso contrário, uma mensagem de erro é exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void editar_animal(Tutores* lista_tutores);

/**
 * @brief Busca um animal na lista de tutores.
 * 
 * Esta função permite ao usuário buscar um animal na lista de tutores.
 * O nome do animal a ser buscado é solicitado ao usuário, verificado
 * quanto à validade, e então, se um animal com tal nome for encontrado, as informações
 * do animal são exibidas, caso contrário, uma mensagem de erro é exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void buscar_animal(Tutores* lista_tutores);

/**
 * @brief Lista os tutores e seus animais cadastrados.
 * 
 * Esta função exibe na tela os tutores cadastrados juntamente com os animais associados a cada um deles.
 * Se não houver nenhum tutor cadastrado ou nenhum animal associado a um tutor, uma mensagem de erro é exibida.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void listar_animais_tutor(Tutores* lista_tutores);

/**
 * @brief Libera a memória alocada para a lista de tutores.
 * 
 * Esta função libera a memória alocada para a lista de tutores, incluindo todos os animais associados.
 * Além disso, realiza algumas operações de limpeza na tela e exibe uma mensagem de conclusão.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void liberar_memoria(Tutores* lista_tutores);

/**
 * @brief Carrega dados de um arquivo e inicializa a lista de tutores.
 * 
 * Esta função carrega dados de um arquivo de texto e inicializa a lista de tutores
 * a partir desses dados. Os dados devem estar formatados de acordo com as especificações
 * do programa, onde cada linha contém informações sobre um tutor ou um animal associado a um tutor.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 * @return Ponteiro para a lista de tutores atualizada com os dados carregados do arquivo.
 */
Tutores* carregar_dados(Tutores* lista_tutores);

/**
 * @brief Escreve os dados da lista de tutores em um arquivo.
 * 
 * Esta função escreve os dados da lista de tutores em um arquivo de texto.
 * Os dados são formatados de acordo com as especificações do programa, onde cada linha
 * contém informações sobre um tutor ou um animal associado a um tutor.
 * 
 * @param lista_tutores Ponteiro para a lista de tutores.
 */
void escrever_dados(Tutores* lista_tutores);