import os
import main
import animais
import tutores

def exibe_logo():
    print('''
        ██████╗░███████╗██████╗░██████╗░░█████╗░░██████╗
        ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝
        ██████╔╝█████╗░░██║░░██║██████╔╝██║░░██║╚█████╗░
        ██╔═══╝░██╔══╝░░██║░░██║██╔══██╗██║░░██║░╚═══██╗
        ██║░░░░░███████╗██████╔╝██║░░██║╚█████╔╝██████╔╝
        ╚═╝░░░░░╚══════╝╚═════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░
        
        ██╗░░░██╗███████╗████████╗
        ██║░░░██║██╔════╝╚══██╔══╝
        ╚██╗░██╔╝█████╗░░░░░██║░░░
        ░╚████╔╝░██╔══╝░░░░░██║░░░
        ░░╚██╔╝░░███████╗░░░██║░░░
        ░░░╚═╝░░░╚══════╝░░░╚═╝░░░
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

def adiciona_subtitulo(texto):
    limpa_tela()
    linha = '*' * (len(texto))
    print(linha)
    print(texto)
    print(linha)
    print()

def volta_ao_menu():
    input('\nDigite uma tecla para voltar ao menu')
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

def menu_editar_animal():
    adiciona_subtitulo('Qual informção você deseja editar?')
    print('1. Nome')
    print('2. Idade')
    print('3. Espécie')
    print('4. Saúde')
    print('5. Sair')

