#include"tutores.h"


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
