#include"animais.h"


struct animais{
    char nome[N];
    char idade[N];
    char especie[N];
    char condicao[N];
    Animais* prox;
};

Animais* cria_animais(void){
    return NULL;
}

Animais* insere_animais(Animais* lista_animal,char* nome, char* idade, char* especie, char* condicao){
    Animais* novo_animal = (Animais*)malloc(sizeof(Animais));
    if(novo_animal==NULL){
        print_msg(10);
        print_msg(12);
        exit(1);
    }
    str_end(idade);
    strcpy(novo_animal->idade, idade);
    str_end(novo_animal->idade);

    str_end(nome);
    capitalizeNames(nome);
    strcpy(novo_animal->nome, nome);
    str_end(novo_animal->nome);
    
    str_end(especie);
    capitalizeNames(especie);
    strcpy(novo_animal->especie, especie);
    str_end(novo_animal->especie);
    
    str_end(condicao);
    capitalizeNames(condicao);
    strcpy(novo_animal->condicao, condicao);
    str_end(novo_animal->condicao);
    

    Animais* ant = NULL;
    Animais* temp = lista_animal;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome)))<0){
        ant = temp;
        temp = temp->prox;
    }
    if(ant ==NULL){
        novo_animal->prox = lista_animal;
        lista_animal = novo_animal;
    }
    else{
        novo_animal->prox = ant->prox;
        ant->prox = novo_animal;
    }
    return lista_animal;
}

Animais* remove_animal(Animais* lista_animal, char* nome){
    Animais* ant = NULL;
    Animais* temp = lista_animal;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome))) != 0){
        ant = temp;
        temp = temp->prox;
    }
    if(temp == NULL){
        print_msg(9);
        pressiona_enter();
        return lista_animal;
    }
    if(ant == NULL){
        lista_animal = temp->prox;
    }
    else{
        ant->prox = temp->prox;
    }
    free(temp);
    return lista_animal;
}

Animais* busca_animal(Animais* lista_animal, char* nome){
    Animais* temp = lista_animal;
    while(temp != NULL && (comparenames(string_upper(temp->nome),string_upper(nome))) != 0){
        temp = temp->prox;
    }
    if(temp == NULL){
        return NULL;
    }
    return temp;
}

int vazia_animais(Animais* lista_animal){
	return (lista_animal==NULL);
}

void libera_animais(Animais* lista_animal){
    Animais* a = lista_animal;
    Animais* temp;
    while(a != NULL){
        temp = a->prox;
        free(a);
        a = temp;
    }
}
