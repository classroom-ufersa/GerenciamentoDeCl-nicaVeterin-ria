#include"sistema.c"

int main(void){
    Tutores* lista_tutores=cria_tutores();
    lista_tutores = carregar_dados(lista_tutores);
    char opcao[N];
    do{
        menu();
        printf(">>");
        scanf(" %[^\n]",opcao);
        if(verificar_opcao(opcao) == 1){
            print_msg(1);
            pressiona_enter();
        }
        else{
            switch(opcao[0]){
            case '1':
                adicionar_tutor(lista_tutores);
                break;
            case '2':
                remover_tutor(lista_tutores);
                break;
            case '3':
                adicionar_animal(lista_tutores);
                break;
            case '4':
                remover_animal(lista_tutores);
                break;
            case '5':
                editar_animal(lista_tutores);
                break;
            case '6':
                buscar_animal(lista_tutores);
                break;
            case '7':
                listar_animais_tutor(lista_tutores);
                break;
            case '8':
                liberar_memoria(lista_tutores);
                break;
            default:
                print_msg(1);
                break;
            }
        }            
    }while(opcao[0] != '8');
    return 0;
}