def exibe_logo():
    '''
    Exibe o logo da clínica veterinária.

    Returns:
    None
    '''
    print('''
        ██████╗░███████╗██████╗░██████╗░░█████╗░░██████╗     ██╗░░░██╗███████╗████████╗
        ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝     ██║░░░██║██╔════╝╚══██╔══╝
        ██████╔╝█████╗░░██║░░██║██████╔╝██║░░██║╚█████╗░     ╚██╗░██╔╝█████╗░░░░░██║░░░
        ██╔═══╝░██╔══╝░░██║░░██║██╔══██╗██║░░██║░╚═══██╗     ░╚████╔╝░██╔══╝░░░░░██║░░░
        ██║░░░░░███████╗██████╔╝██║░░██║╚█████╔╝██████╔╝     ░░╚██╔╝░░███████╗░░░██║░░░
        ╚═╝░░░░░╚══════╝╚═════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░     ░░░╚═╝░░░╚══════╝░░░╚═╝░░░
          ''')

def exibe_opçao():
    '''
    Exibe as opções do menu principal.

    Returns:
    None
    '''
    print('1. Adiciona tutor')
    print('2. Remover tutor')
    print('3. Adiciona animal')
    print('4. Remover animal')
    print('5. Editar informação de animal')
    print('6. Buscar animal por nome')
    print('7. Listar tutores e seu animais')
    print('8. Sair')

def escolhe_opcao_menu(lista_animais, lista_tutores):
    '''
    Solicita ao usuário escolher uma opção do menu e executa a ação correspondente.

    Args:
    lista_animais (list): Uma lista de objetos Animais representando os animais.
    lista_tutores (list): Uma lista de objetos Tutores representando os tutores.

    Returns:
    None
    '''
    from pastas.animais import adiciona_animal, remove_animal, edita_animal, busca_animal
    from pastas.tutores import criar_tutor, remove_tutor, mostra_arquivo

    try:
        opcao_escolhida = int(input('\nEscolha uma opção: '))

        if opcao_escolhida == 1:
            criar_tutor(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 2:
            remove_tutor(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 3:
            adiciona_animal(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 4:
            remove_animal(lista_tutores)
            volta_ao_menu()
        elif opcao_escolhida == 5:
            edita_animal(lista_tutores)
        elif opcao_escolhida == 6:
            busca_animal(lista_animais)
            volta_ao_menu()
        elif opcao_escolhida == 7:
            mostra_arquivo()
            volta_ao_menu()
        elif opcao_escolhida == 8:
            finalizar_programa()
        else:
            opcao_invalida()

    except:
        opcao_invalida()
    

def exibe_subtitulo(texto):
    '''
    Exibe um subtítulo com base no texto fornecido.

    Args:
    texto (str): O texto do subtítulo.

    Returns:
    None
    '''
    limpa_tela()
    linha = '=' * (len(texto))
    print(linha)
    print(texto)
    print(linha)
    print()


def volta_ao_menu():
    '''
    Retorna ao menu principal após o usuário pressionar a tecla ENTER.

    Returns:
    None
    '''
    from main import main

    input('\nPrecione ENTER para voltar ao menu')
    main()

def opcao_invalida():
    '''
    Exibe uma mensagem de opção inválida.

    Returns:
    None
    '''
    print('Opção inválida!\n')
    volta_ao_menu()

def busca_nome(lista, nome):
    '''
    Realiza uma busca binária pelo nome na lista fornecida.

    Args:
    lista (list): Uma lista ordenada de objetos.
    nome (str): O nome a ser procurado na lista.

    Returns:
    int: O índice do item na lista se encontrado, caso contrário, -1.
    '''
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
    '''
    Limpa a tela do terminal.

    Returns:
    None
    '''
    import os
    if os.name == 'nt': 
        os.system('cls')
    else:
        os.system('clear')

def finalizar_programa():
    '''
    Finaliza a execução do programa.

    Returns:
    None
    '''
    limpa_tela()
    print('Saindo...')