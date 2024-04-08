#include"../include/animais.h"


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

void imprimir_animal(Animais* animal){
    printf("\nNome: %s\n", animal->nome);
    printf("Espécie: %s\n", animal->especie);
    printf("Idade: %s\n", animal->idade);
    printf("Condição: %s\n", animal->condicao);
}

void editar_nome_animal(Animais* animal){
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
    printf("Nome atual: %s\n", animal->nome);
    printf("Digite o novo nome:\n");
    condicao_nome_add();
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
            printf("Informe o nome do animal\n");
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
        strcpy(animal->nome, nome);
        str_end(animal->nome);
        capitalizeNames(animal->nome);
        cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
        print_msg(22);
        pressiona_enter();
    }
}

void editar_idade_animal(Animais* animal){
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
    printf("Idade atual: %s\n", animal->idade);
    printf("Digite a nova idade:\n");
    char idade[N];
    printf(">>");
    scanf(" %[^\n]", idade);
    str_end(idade);
    if(voltar_menu(string_upper(idade)) == 1) return;
    int count_erro = 0;
    while ((verificar_condicao(idade)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(17);
            printf("Informe a idade do animal\n");
            printf(">>");
            scanf(" %[^\n]", idade);
            if(voltar_menu(string_upper(idade)) == 1) return;
            str_end(idade);
            count_erro++;
        } else {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(18);
            print_msg(21);
            pressiona_enter();
            return;
        }
    }
    if (count_erro <= 3) {
        strcpy(animal->idade, idade);
        str_end(animal->idade);
        cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
        print_msg(25);
        pressiona_enter();
    }
}

void editar_especie_animal(Animais* animal){
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
    printf("Espécie atual: %s\n", animal->especie);
    printf("Digite a nova espécie:\n");
    condicao_especie();
    char especie[N];
    printf(">>");
    scanf(" %[^\n]", especie);
    str_end(especie);
    if(voltar_menu(string_upper(especie)) == 1) return;
    int count_erro = 0;
    while ((verificar_nome(especie)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(13);
            printf("Informe a espécie do animal\n");
            condicao_especie();
            printf(">>");
            scanf(" %[^\n]", especie);
            str_end(especie);
            if(voltar_menu(string_upper(especie)) == 1) return;
            count_erro++;
        } else {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(14);
            print_msg(21);
            pressiona_enter();
            return;
        }
    }
    if (count_erro <= 3) {
        strcpy(animal->especie, especie);
        str_end(animal->especie);
        capitalizeNames(animal->especie);
        cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
        print_msg(23);
        pressiona_enter();
    }
}

void editar_condicao_animal(Animais* animal){
    cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
    printf("Condição atual: %s\n", animal->condicao);
    printf("Digite a nova condição:\n");
    condicao_condicao();
    char condicao[N];
    printf(">>");
    scanf(" %[^\n]", condicao);
    str_end(condicao);
    if(voltar_menu(string_upper(condicao)) == 1) return;
    int count_erro = 0;
    while ((verificar_condicao(condicao)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(15);
            printf("Informe a condição do animal\n");
            condicao_condicao();
            printf(">>");
            scanf(" %[^\n]", condicao);
            str_end(condicao);
            if(voltar_menu(string_upper(condicao)) == 1) return;
            count_erro++;
        } else {
            cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
            print_msg(16);
            print_msg(21);
            pressiona_enter();
            return;
        }
    }
    if (count_erro <= 3) {
        strcpy(animal->condicao, condicao);
        str_end(animal->condicao);
        capitalizeNames(animal->condicao);
        cabecalho("Editar informa\x87\xc6o de animal", "PEDROS VET");
        print_msg(24);
        pressiona_enter();
    }
}