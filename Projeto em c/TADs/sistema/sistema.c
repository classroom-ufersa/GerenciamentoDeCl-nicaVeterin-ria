#include"sistema.h"

void cabecalho(char *pagina, char* titulo){
    limpa_tela();
    printf("==========================================================================================\n");
    printf("\t\t\t%s\t\t\t%s\n", pagina, titulo);
    printf("==========================================================================================\n\n");
}

void menu(void){
    limpa_tela();
    pedros_vet();
    printf("1 - Adicionar tutor\n");
    printf("2 - Remover tutor\n");
    printf("3 - Adicionar animal\n");
    printf("4 - Remover animal\n");
    printf("5 - Editar informa%c%co de animal\n",135, 198);
    printf("6 - Buscar animal por nome\n");
    printf("7 - Listar tutores e seus animais\n");
    printf("8 - Sair\n");
}

void adicionar_tutor(Tutores* lista_tutores){
    char nome[N];
    cabecalho("Adicionar tutor", "PEDROS VET");
    printf("Informe o nome do tutor\n");
    condicao_nome_add();
    printf(">>");
    scanf(" %[^\n]",nome);
    str_end(nome);
    int count_erro = 0;
    while((verificar_nome(nome))==1 && count_erro <= 3){
        if(count_erro<3){
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do tutor\n");
            condicao_nome_add();
            printf(">>");
            scanf(" %[^\n]",nome);
            str_end(nome);
            count_erro++;
        }
        else{
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char contato[N];
    cabecalho("Adicionar tutor", "PEDROS VET");
    printf("Informe o contato do tutor\n");
    condicao_contato();
    printf(">>");
    scanf(" %[^\n]",contato);
    str_end(contato);
    count_erro = 0;
    while((verificar_contato(contato)) == 1 && count_erro <= 3){
        if(count_erro<3){
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(3);
            printf("Informe o contato do tutor\n");
            condicao_contato();
            printf(">>");
            scanf(" %[^\n]",contato);
            str_end(contato);
            count_erro++;
        }
        else{
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(6);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char documento[N];
    cabecalho("Adicionar tutor", "PEDROS VET");
    printf("Informe o documento do tutor\n");
    condicao_documento();
    printf(">>");
    scanf(" %[^\n]",documento);
    str_end(documento);
    count_erro = 0;
    while((verificar_documento(documento)) == 1 && count_erro <= 3){
        if(count_erro<3){
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(4);
            printf("Informe o documento do tutor\n");
            condicao_documento();
            printf(">>");
            scanf(" %[^\n]",documento);
            str_end(documento);
            count_erro++;
        }
        else{
            cabecalho("Adicionar tutor", "PEDROS VET");
            print_msg(7);
            pressiona_enter();
            return lista_tutores;
        }
    }
    lista_tutores = insere_tutores(lista_tutores,nome,contato,documento);
    escrever_dados(lista_tutores);
}

void remover_tutor(Tutores* lista_tutores){
    char nome_busca[N];
    cabecalho("Remover tutor", "PEDROS VET");
    printf("Informe o nome do tutor que ser%c removido\n",160);
    condicao_nome_busca();
    printf(">>");
    scanf(" %[^\n]", nome_busca);
    str_end(nome_busca);
    int count_erro = 0;
    while((verificar_nome(nome_busca))==1 && count_erro <= 3){
        if(count_erro<3){
            cabecalho("Remover tutor", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do tutor que ser%c removido\n",160);
            condicao_nome_busca();
            printf(">>");
            scanf(" %[^\n]",nome_busca);
            str_end(nome_busca);
            count_erro++;
        }
        else{
            cabecalho("Remover tutor", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    lista_tutores = remove_tutores(lista_tutores,nome_busca);
    escrever_dados(lista_tutores);
}

void adicionar_animal(Tutores* lista_tutores) { 
    char nome_tutor[N];
    cabecalho("Adicionar animal", "PEDROS VET");
    printf("Informe o nome do tutor\n");
    condicao_nome_busca();
    printf(">>");
    scanf(" %[^\n]", nome_tutor);
    str_end(nome_tutor);
    int count_erro = 0;
    while ((verificar_nome(nome_tutor)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do tutor\n");
            condicao_nome_busca();
            printf(">>");
            scanf(" %[^\n]", nome_tutor);
            str_end(nome_tutor);
            count_erro++;
        } else {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(5);
            pressiona_enter(); 
            return lista_tutores;
        }
    }
    Tutores* tutor = buscar_tutor(lista_tutores, nome_tutor);
    if (tutor == NULL) {
        cabecalho("Adicionar animal", "PEDROS VET");
        print_msg(8);
        pressiona_enter();
        return lista_tutores;
    }
    char nome_animal[N];
    cabecalho("Adicionar animal", "PEDROS VET");
    printf("Informe o nome do animal\n");
    condicao_nome_add();
    printf(">>");
    scanf(" %[^\n]", nome_animal);
    str_end(nome_animal);
    count_erro = 0;
    while ((verificar_nome(nome_animal)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do animal\n");
            condicao_nome_add();
            printf(">>");
            scanf(" %[^\n]", nome_animal);
            str_end(nome_animal);
            count_erro++;
        } else {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char idade[N];
    cabecalho("Adicionar animal", "PEDROS VET");
    printf("Informe a idade do animal\n");
    printf(">>");
    scanf(" %[^\n]", idade);
    str_end(idade);
    count_erro = 0;
    while ((verificar_condicao(idade)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(17);
            printf("Informe a idade do animal\n");
            printf(">>");
            scanf(" %[^\n]", idade);
            str_end(idade);
            count_erro++;
        } else {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(18);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char especie[N];
    cabecalho("Adicionar animal", "PEDROS VET");
    printf("Informe a espécie do animal\n");
    condicao_especie();
    printf(">>");
    scanf(" %[^\n]", especie);
    str_end(especie);
    count_erro = 0;
    while ((verificar_nome(especie)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(13);
            printf("Informe a espécie do animal\n");
            condicao_especie();
            printf(">>");
            scanf(" %[^\n]", especie);
            str_end(especie);
            count_erro++;
        } else {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(14);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char condicao[N];
    cabecalho("Adicionar animal", "PEDROS VET");
    printf("Informe a condi%c%co do animal\n",135,198);
    condicao_condicao();
    printf(">>");
    scanf(" %[^\n]", condicao);
    str_end(condicao);
    count_erro = 0;
    while ((verificar_condicao(condicao)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(15);
            printf("Informe a condi%c%co do animal\n",135,198);
            condicao_condicao();
            printf(">>");
            scanf(" %[^\n]", condicao);
            str_end(condicao);
            count_erro++;
        } else {
            cabecalho("Adicionar animal", "PEDROS VET");
            print_msg(16);
            pressiona_enter();
            return lista_tutores;
        }
    }
    tutor->lista_animais = insere_animais(tutor->lista_animais, nome_animal, idade, especie, condicao);
    escrever_dados(lista_tutores);
}

void remover_animal(Tutores* lista_tutores){
    char nome_tutor[N];
    cabecalho("Remover animal", "PEDROS VET");
    printf("Informe o nome do tutor\n");
    condicao_nome_busca();
    printf(">>");
    scanf(" %[^\n]", nome_tutor);
    str_end(nome_tutor);
    int count_erro = 0;
    while ((verificar_nome(nome_tutor)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Remover animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do tutor\n");
            condicao_nome_busca();
            printf(">>");
            scanf(" %[^\n]", nome_tutor);
            str_end(nome_tutor);
            count_erro++;
        } else {
            cabecalho("Remover animal", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    char nome_animal[N];
    cabecalho("Remover animal", "PEDROS VET");
    printf("Informe o nome do animal\n");
    condicao_nome_busca();
    printf(">>");
    scanf(" %[^\n]", nome_animal);
    str_end(nome_animal);
    count_erro = 0;
    while ((verificar_nome(nome_animal)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Remover animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do animal\n");
            condicao_nome_busca();
            printf(">>");
            scanf(" %[^\n]", nome_animal);
            str_end(nome_animal);
            count_erro++;
        } else {
            cabecalho("Remover animal", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    Tutores* tutor = buscar_tutor(lista_tutores, nome_tutor);
    if (tutor == NULL) {
        cabecalho("Remover animal", "PEDROS VET");
        print_msg(8);
        pressiona_enter();
        return lista_tutores;
    }
    tutor->lista_animais = remove_animal(tutor->lista_animais, nome_animal);
    escrever_dados(lista_tutores);
}

void buscar_animal(Tutores* lista_tutores){
    char nome_animal[N];
    cabecalho("Buscar animal", "PEDROS VET");
    printf("Informe o nome do animal\n");
    condicao_nome_busca();
    printf(">>");
    scanf(" %[^\n]", nome_animal);
    str_end(nome_animal);
    int count_erro = 0;
    while ((verificar_nome(nome_animal)) == 1 && count_erro <= 3) {
        if (count_erro < 3) {
            cabecalho("Buscar animal", "PEDROS VET");
            print_msg(2);
            printf("Informe o nome do animal\n");
            condicao_nome_busca();
            printf(">>");
            scanf(" %[^\n]", nome_animal);
            str_end(nome_animal);
            count_erro++;
        } else {
            cabecalho("Buscar animal", "PEDROS VET");
            print_msg(5);
            pressiona_enter();
            return lista_tutores;
        }
    }
    Tutores* temp1 = lista_tutores;
    Animais* temp2;
    if (temp1 == NULL) {
        cabecalho("Buscar animal", "PEDROS VET");
        print_msg(19);
        pressiona_enter();
    }
    else {
        while(temp1 != NULL){
            temp2 = gnimal(temp1->lista_animais, nome_animal);
            if(temp2 != NULL){
                printf("Nome do tutor: %s\n",temp1->nome);
                printf("Nome: %s\n",temp2->nome);
                printf("Idade: %s\n",temp2->idade);
                printf("Esp%ccie: %s\n",130,temp2->especie);
                printf("Condi%c%co: %s\n",135,198,temp2->condicao);
                pressiona_enter();
                return;
            }
            temp1 = temp1->prox;
        }
        if (temp1 == NULL) {
            cabecalho("Buscar animal", "PEDROS VET");
            print_msg(9);
            pressiona_enter();
        }
    }
}

void listar_animais_tutor(Tutores* lista_tutores){
    cabecalho("Listar tutores e seus animais", "PEDROS VET");
    if(lista_tutores == NULL){
        print_msg(19);
        pressiona_enter();
    }
    else{
        Tutores* temp = lista_tutores;
        while(temp != NULL){
            printf("Nome: %s\n",temp->nome);
            printf("Contato: %s\n",temp->contato);
            printf("Documento: %s",temp->documento);
            if(temp->lista_animais == NULL){
                printf("Nenhum animal cadastrado\n\n");
            }
            else{
                printf("Animais:\n");
                Animais* temp_animal = temp->lista_animais;
                while(temp_animal != NULL){
                    printf("Nome: %s\n",temp_animal->nome);
                    printf("Idade: %s\n",temp_animal->idade);
                    printf("Esp%ccie: %s\n",130,temp_animal->especie);
                    printf("Condi%c%co: %s\n",135,198,temp_animal->condicao);
                    temp_animal = temp_animal->prox;
                }
            }
            temp = temp->prox;
        }
        pressiona_enter();
    }
}

Tutores* carregar_dados(Tutores* lista_tutores){
    FILE * arquivo = fopen("arquivo.txt","r");
    if(arquivo == NULL){
        arquivo = fopen("arquivo.txt","w");
        if(arquivo == NULL){
            print_msg(11);
            print_msg(12);
            exit(1);
        }
        else{
            fclose(arquivo);
            return cria_tutores();
        }
    }
    else{
        char linha[N],comeco[N],st1[N],st2[N],st3[N],st4[N],ultimo_tutor[N];
        while(fgets(linha, 81, arquivo) != NULL){
            sscanf(linha,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]",comeco,st1,st2,st3,st4);
            if(comparenames(comeco,"Tutor:") == 0){
                lista_tutores = insere_tutores(lista_tutores,st1,st2,st3);
                strcpy(ultimo_tutor,st1);
                str_end(ultimo_tutor);      
            }
            else{
                Tutores* tutor = buscar_tutor(lista_tutores, ultimo_tutor);
                if (tutor == NULL) {
                    cabecalho("Adicionar animal", "PEDROS VET");
                    print_msg(8);
                    pressiona_enter();
                    return lista_tutores;
                }
                tutor->lista_animais = insere_animais(tutor->lista_animais, st1,st2,st3,st4);
            }
        }
        return lista_tutores;
    }
}

void escrever_dados(Tutores* lista_tutores){
    FILE * arquivo = fopen("arquivo.txt","w");
    if(arquivo == NULL){
        print_msg(11);
        print_msg(12);
        exit(1);
    }
    else{
        Tutores* temp = lista_tutores;
        while(temp != NULL){
            fprintf(arquivo,"Tutor:\t%s\t%s\t%s",temp->nome,temp->contato,temp->documento);
            Animais* temp_animal = temp->lista_animais;
            while(temp_animal != NULL){
                fprintf(arquivo,"Animal:\t%s\t%s\t%s\t%s",temp_animal->nome,temp_animal->idade,temp_animal->especie,temp_animal->condicao);
                temp_animal = temp_animal->prox;
            }
            temp = temp->prox;
        }
        fclose(arquivo);
    }
}