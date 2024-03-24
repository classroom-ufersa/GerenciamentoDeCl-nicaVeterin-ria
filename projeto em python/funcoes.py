import os
import main
import animais
import tutores

def exibe_logo():
    print('''
        ██████╗░███████╗██████╗░██████╗░░█████╗░░██████╗     ██╗░░░██╗███████╗████████╗
        ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝     ██║░░░██║██╔════╝╚══██╔══╝
        ██████╔╝█████╗░░██║░░██║██████╔╝██║░░██║╚█████╗░     ╚██╗░██╔╝█████╗░░░░░██║░░░
        ██╔═══╝░██╔══╝░░██║░░██║██╔══██╗██║░░██║░╚═══██╗     ░╚████╔╝░██╔══╝░░░░░██║░░░
        ██║░░░░░███████╗██████╔╝██║░░██║╚█████╔╝██████╔╝     ░░╚██╔╝░░███████╗░░░██║░░░
        ╚═╝░░░░░╚══════╝╚═════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░     ░░░╚═╝░░░╚══════╝░░░╚═╝░░░
          ''')

def exibe_opçao():
    print('1. Adiciona tutor')
    print('2. Remover tutor')
    print('3. Adiciona animal')
    print('4. Remover animal')
    print('5. Editar informação de animal')
    print('6. Buscar animal por nome')
    print('7. Listar tutores e seu animais')
    print('8. Sair')

def escolhe_opcao_menu(lista_animais, lista_tutores):
    try:
        opcao_escolhida = int(input('\nEscolha uma opção: '))

        if opcao_escolhida == 1:
            tutores.adiciona_tutores(lista_tutores, lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 2:
            tutores.remove_tutor(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 3:
            animais.adiciona_animais(lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 4:
            animais.remove_animal(lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 5:
            animais.editar_animal(lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 6:
            animais.busca_animal(lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 7:
            tutores.mostra_lista_de_tutores(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 8:
            finalizar_programa()
        else:
            opcao_invalida()

    except:
        opcao_invalida()
    

def adiciona_subtitulo(texto):
    limpa_tela()
    linha = '=' * (len(texto))
    print(linha)
    print(texto)
    print(linha)
    print()


def volta_ao_menu():
    input('\nPrecione ENTER para voltar ao menu')
    main.main()

def opcao_invalida():
    print('Opção inválida!\n')
    volta_ao_menu()

def busca_nome(lista, nome):
    inicio = 0
    fim = len(lista) - 1

    while inicio <= fim:
        meio = (inicio + fim) // 2
        if lista[meio].nome == nome:
            return meio
        elif lista[meio].nome < nome:
            inicio = meio + 1
        else:
            fim = meio - 1
    
    return -1

def limpa_tela():
    os.system('cls')

def finalizar_programa():
    limpa_tela()
    print('Saindo...')



