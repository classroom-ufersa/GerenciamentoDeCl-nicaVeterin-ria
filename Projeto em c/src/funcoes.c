#include"../include/funcoes.h"

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

int verificar_nome(char * nome){
    int nomeend = (int)strlen(nome);
    if(nomeend == 0){
        return 1;
    }
    int twospace = 1;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i]!=' '){
            return 1;
        }
        if(nome[i]==' '){
            if(twospace == 1){
                return 1;
            }
            else{
                twospace = 1;
            }
        }
        else{
            twospace = 0;
        }
    }
    return 0;
}

int verificar_contato(char* contato){
    int contend = (int)strlen(contato);
    if(contend != 14){
        return 1;
    }
    if(contato[0]!='(' || contato[3]!=')'){
        return 1;
    }
    if(contato[9] != '-'){
        return 1;
    }
    for(int i = 1; i <=13; i++){
        if(i != 3 && i != 9){
            if (!(contato[i] >= '0' && contato[i] <= '9')){
                return 1;
            }
        }
    }
    return 0;
}

int verificar_documento(char* documento){
    int contend = (int)strlen(documento);
    if(contend != 14){
        return 1;
    }
    if(documento[3]!='.' || documento[7]!='.'){
        return 1;
    }
    if(documento[11] != '-'){
        return 1;
    }
    for(int i = 0; i <=13; i++){
        if(i != 3 && i != 7 && i != 11){
            if (!(documento[i] >= '0' && documento[i] <= '9')){
                return 1;
            }
        }
    }
    return 0;
}

int verificar_condicao(char* condicao){
    int contend = (int)strlen(condicao);
    if(contend == 0){
        return 1;
    }
    for(int i = 0; i < contend; i++){
        if(!(isdigit(condicao[i])) && !(isalpha(condicao[i]))){
            if(condicao[i] != ' '){
                return 1;
            }
        }
    }
    return 0;
}

int verificar_opcao(char* opcao){
    if(strlen(opcao) != 1){
        return 1;
    }
    if(opcao[0] == ' '){
        return 1;
    }
    if(opcao[0] < '0' || opcao[0] > '8'){
        return 1;
    }
    return 0;
}

int verificar_opcao2(char* opcao){
    if(strlen(opcao) != 1){
        return 1;
    }
    if(opcao[0] < '0' || opcao[0] > '6'){
        return 1;
    }
    return 0;
}

void str_end(char* str){
    int strend = (int)strlen(str);
    str[strend] = '\0';
}

void capitalizeNames(char *str) {
    int capitalizeNext = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (capitalizeNext) {
                str[i] = toupper(str[i]);
                capitalizeNext = 0; 
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            capitalizeNext = 1;
        }
    }
}

char *string_upper(char *str){
    int i;
    for (i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

int comparenames(char* str1, char* str2){
    /* Função que faz a comparação entre a string 1 e a string
       2 a partir do seu tamanho
    */
    return strncmp(str1, str2, strlen(str2));
}

void menu_editar_animal(){
    printf("\n\n");
    printf("1 - Editar nome\n");
    printf("2 - Editar esp%ccie\n",130);
    printf("3 - Editar condi%c%co\n",135,198);
    printf("4 - Editar idade\n");
    printf("5 - Editar tutor\n");
    printf("6 - Voltar\n");
}

int voltar_menu(char* str){
    if(strcmp(str, "VOLTAR") == 0){
        print_msg(21);
        pressiona_enter();
        return 1;
    }
    return 0;
}

void limpa_tela(){
    #ifdef _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #elif __linux__
        system("clear");
    #endif
}

void pressiona_enter(){
    printf("\nPressione ENTER para continuar.");
    while (getchar() != '\n');
    getchar();
}

void print_msg(int cod_msg){
    // mensagem limpa:
    if(cod_msg == 0) printf("\n\n");

    // alerta de formato: 
    else if(cod_msg == 1) printf(TXT_yellow"\nInsira uma op%c%co v%clida.\n"TXT_reset,135, 198, 160);
    else if(cod_msg == 2) printf(TXT_yellow"\nInforme um nome v%clido.\n"TXT_reset,160);
    else if(cod_msg == 3) printf(TXT_yellow"\nInforme um contato v%clido.\n"TXT_reset,160);
    else if(cod_msg == 4) printf(TXT_yellow"\nInforme um documento v%clido.\n"TXT_reset,160);
    else if(cod_msg == 5) printf(TXT_red"\nNome inv%clido.\n"TXT_reset,160);
    else if(cod_msg == 6) printf(TXT_red"\nContato inv%clido.\n"TXT_reset,160);
    else if(cod_msg == 7) printf(TXT_red"\nDocumento inv%clido.\n"TXT_reset,160);
    else if(cod_msg == 8) printf(TXT_yellow"\nTutor n%co encontrado\n"TXT_reset,198);
    else if(cod_msg == 9) printf(TXT_yellow"\nAnimal n%co encontrado\n"TXT_reset,198);
    else if(cod_msg == 10) printf(TXT_red"\nErro de aloca%c%co de mem%cria\n\n"TXT_reset,135,198,162);
    else if(cod_msg == 11) printf(TXT_red"\nFalha na abertura do arquivo\n\n"TXT_reset);
    else if(cod_msg == 12) printf(TXT_whitered"\nENCERRANDO PROGRAMA"TXT_reset);
    else if(cod_msg == 13) printf(TXT_yellow"\nInforme uma esp%ccie v%clida.\n"TXT_reset,130,160);
    else if(cod_msg == 14) printf(TXT_red"\nEsp%ccie inv%clida.\n"TXT_reset,130,160);
    else if(cod_msg == 15) printf(TXT_yellow"\nInforme uma condi%c%co v%clida.\n"TXT_reset,135,198,160);
    else if(cod_msg == 16) printf(TXT_red"\nCondi%c%co inv%clida.\n"TXT_reset,135,198,160);
    else if(cod_msg == 17) printf(TXT_yellow"\nInforme uma idade v%clida.\n"TXT_reset,160);
    else if(cod_msg == 18) printf(TXT_red"\nIdade inv%clida.\n"TXT_reset,160);
    else if(cod_msg == 19) printf(TXT_yellow"\nLista vazia.\n"TXT_reset);
    else if(cod_msg == 20) printf(TXT_red"\nOp%c%co inv%clida.\n"TXT_reset,135, 198, 160);
    else if(cod_msg == 21) printf(TXT_red"\nVoltando ao menu principal\n"TXT_reset);
    else if(cod_msg == 22) printf(TXT_green"\nNome alterado com sucesso\n"TXT_reset);
    else if(cod_msg == 23) printf(TXT_green"\nEsp%ccie alterada com sucesso\n"TXT_reset,130);
    else if(cod_msg == 24) printf(TXT_green"\nCondi%c%co alterada com sucesso\n"TXT_reset,135,198);
    else if(cod_msg == 25) printf(TXT_green"\nIdade alterada com sucesso\n"TXT_reset);
    else if(cod_msg == 26) printf(TXT_green"\nTutor alterado com sucesso\n"TXT_reset);
}

void condicao_nome_add(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -Informe o nome completo.          %c\n",186,186);
    printf("%c -N%co come%car com espa%co.           %c\n",186,198,135,135,186);
    printf("%c -N%co possuir n%cmeros.              %c\n",186,198,163,186);
    printf("%c -N%co possuir caracteres inv%clidos. %c\n",186,198,160,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void condicao_nome_busca(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -N%co come%car com espa%co.           %c\n",186,198,135,135,186);
    printf("%c -N%co possuir n%cmeros.              %c\n",186,198,163,186);
    printf("%c -N%co possuir caracteres inv%clidos. %c\n",186,198,160,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void condicao_contato(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -Formato do contato:               %c\n",186,186);
    printf("%c          (xx)xxxxx-xxxx            %c\n",186,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void condicao_documento(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -Formato do documento:             %c\n",186,186);
    printf("%c          xxx.xxx.xxx-xx            %c\n",186,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void condicao_especie(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -Informe uma especie existente     %c\n",186,186);
    printf("%c -N%co come%car com espa%co.           %c\n",186,198,135,135,186);
    printf("%c -N%co possuir n%cmeros.              %c\n",186,198,163,186);
    printf("%c -N%co possuir caracteres inv%clidos. %c\n",186,198,160,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void condicao_condicao(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c -N%co come%car com espa%co.           %c\n",186,198,135,135,186);
    printf("%c -N%co possuir caracteres inv%clidos. %c\n",186,198,160,186);
    printf("%c -Digite VOLTAR para voltar ao menu.%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void pedros_vet(){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,187,176,219,219,219,219,219,219,219,187,219,219,219,219,219,219,187,176,219,219,219,219,219,219,187,176,176,219,219,219,219,219,187,176,176,219,219,219,219,219,219,187,219,219,187,176,176,176,219,219,187,219,219,219,219,219,219,219,187,219,219,219,219,219,219,219,219,187);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,201,205,205,219,219,187,219,219,201,205,205,205,205,188,219,219,201,205,205,219,219,187,219,219,201,205,205,219,219,187,219,219,201,205,205,219,219,187,219,219,201,205,205,205,205,188,219,219,186,176,176,176,219,219,186,219,219,201,205,205,205,205,188,200,205,205,219,219,201,205,205,188);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,201,188,219,219,219,219,219,187,176,176,219,219,186,176,176,219,219,186,219,219,219,219,219,219,201,188,219,219,186,176,176,219,219,186,200,219,219,219,219,219,187,176,200,219,219,187,176,219,219,201,188,219,219,219,219,219,187,176,176,176,176,176,219,219,186,176,176,176);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,201,205,205,205,188,176,219,219,201,205,205,188,176,176,219,219,186,176,176,219,219,186,219,219,201,205,205,219,219,187,219,219,186,176,176,219,219,186,176,200,205,205,205,219,219,187,176,200,219,219,219,219,201,188,176,219,219,201,205,205,188,176,176,176,176,176,219,219,186,176,176,176);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,186,176,176,176,176,176,219,219,219,219,219,219,219,187,219,219,219,219,219,219,201,188,219,219,186,176,176,219,219,186,200,219,219,219,219,219,201,188,219,219,219,219,219,219,201,188,176,176,200,219,219,201,188,176,176,219,219,219,219,219,219,219,187,176,176,176,219,219,186,176,176,176);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,188,176,176,176,176,176,200,205,205,205,205,205,205,188,200,205,205,205,205,205,188,176,200,205,188,176,176,200,205,188,176,200,205,205,205,205,188,176,200,205,205,205,205,205,188,176,176,176,176,200,205,188,176,176,176,200,205,205,205,205,205,205,188,176,176,176,200,205,188,176,176,176);
}