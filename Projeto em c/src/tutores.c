#include"../include/tutores.h"


struct tutores{
    char nome[N];
    char contato[N];
    char documento[N];
    Animais* lista_animais;
    Tutores* prox;
};


Tutores* cria_tutores(void){
    return NULL;
}


Tutores* insere_tutores(Tutores* lista_tutor, char* nome, char* contato, char* documento){
    Tutores* novo_tutor = (Tutores*)malloc(sizeof(Tutores));
    if(novo_tutor==NULL){
        print_msg(10);
        print_msg(12);
        exit(1);
    }
    str_end(nome);
    capitalizeNames(nome);
    strcpy(novo_tutor->nome, nome);
    str_end(novo_tutor->nome);

    str_end(contato);
    strcpy(novo_tutor->contato, contato);
    str_end(novo_tutor->contato);

    str_end(documento);
    strcpy(novo_tutor->documento, documento); 
    str_end(novo_tutor->documento);

    Animais* lista_animal = cria_animais();
    novo_tutor->lista_animais = lista_animal;
    Tutores* ant = NULL;
    Tutores* temp = lista_tutor;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome)))<0){
        ant = temp;
        temp = temp->prox;
    }
    
    if(ant ==NULL){
        novo_tutor->prox = lista_tutor;
        lista_tutor = novo_tutor;
    }
    else{
        novo_tutor->prox = ant->prox;
        ant->prox = novo_tutor;
    }
    return lista_tutor;
}

Tutores* remove_tutores(Tutores* lista_tutor, char* nome_busca){
    Tutores* ant = NULL;
    Tutores* temp = lista_tutor;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome_busca))) != 0){
        ant = temp;
        temp = temp->prox;
    }
    if(temp == NULL){
        print_msg(8);
        pressiona_enter();
        return lista_tutor;
    }
    if(ant == NULL){
        lista_tutor = temp->prox;
    }
    else{
        ant->prox = temp->prox;
    }
    libera_tutores(temp);
    return lista_tutor;
}

Tutores* buscar_tutor(Tutores* lista_tutor, char* nome_busca){
    Tutores* temp = lista_tutor;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome_busca)))<0){
        temp = temp->prox;
    }
    if(temp == NULL || (comparenames(string_upper(temp->nome),string_upper(nome_busca)))>0){
        return NULL;
    }
    return temp;
}

void libera_tutores(Tutores* lista_tutor){
    Tutores* a = lista_tutor;
    Tutores* temp;
    while(a != NULL){
        temp = a->prox;
        libera_animais(a->lista_animais);
        free(a);
        a = temp;
    }
}

void editar_tutor_animal(Tutores *lista_tutores, Tutores *tutor_atual, Animais *animal){
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
    printf("Tutor atual: %s\n", tutor_atual->nome);
    printf("Digite o nome do novo tutor:\n");
    condicao_nome_busca();
    char nome[N];
    printf(">>");
    scanf(" %[^\n]", nome);
    str_end(nome);
    if(voltar_menu(string_upper(nome)) == 1) return;
    int count_erro = 0;
    while ((verificar_nome(nome)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do tutor\n");
            condicao_nome_add();
            printf(">>");
            scanf(" %[^\n]", nome);
            str_end(nome);
            if(voltar_menu(string_upper(nome)) == 1) return;
            count_erro++;
        } else {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(5);
            print_msg(21);
            pressiona_enter();
            return;
        }
    }
    if (count_erro <= 3) {
        Tutores* tutor_novo = cria_tutores();
        tutor_novo = buscar_tutor(lista_tutores, nome);
        if (tutor_novo == NULL) {
            cabecalho("Remover animal", "PEDROS VET");
            print_msg(8);
            print_msg(21);
            pressiona_enter();
            return;
        }
        tutor_novo->lista_animais = insere_animais(tutor_novo->lista_animais, animal->nome, animal->especie, animal->idade, animal->condicao);
        tutor_atual->lista_animais = remove_animal(tutor_atual->lista_animais, animal->nome);
        cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
        print_msg(26);
        pressiona_enter();
    }
}