def main():
    '''
    Função principal que inicia a execução do programa de gerenciamento da clínica veterinária.

    Essa função realiza as seguintes etapas:
    1. Importa os módulos necessários: funcoes, animais e tutores.
    2. Limpa a tela do terminal.
    3. Obtém a lista de animais e a lista de tutores utilizando as funções listar_animais() e listar_tutores() dos módulos animais e tutores, respectivamente.
    4. Exibe o logo da clínica veterinária utilizando a função exibe_logo() do módulo funcoes.
    5. Exibe as opções do menu principal utilizando a função exibe_opçao() do módulo funcoes.
    6. Solicita ao usuário escolher uma opção do menu e executa a ação correspondente utilizando a função escolhe_opcao_menu() do módulo funcoes, passando as listas de animais e tutores como argumentos.

    Returns:
    None
    '''
    from pastas import funcoes, animais, tutores

    funcoes.limpa_tela()
    lista_animais = animais.listar_animais()
    lista_tutores = tutores.listar_tutores()

    funcoes.exibe_logo()
    funcoes.exibe_opçao()
    funcoes.escolhe_opcao_menu(lista_animais, lista_tutores)
    
if __name__ == '__main__':
    main()