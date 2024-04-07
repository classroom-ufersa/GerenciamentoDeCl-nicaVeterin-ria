def main():
    from pastas import funcoes, animais, tutores

    funcoes.limpa_tela()
    lista_animais = animais.listar_animais()
    lista_tutores = tutores.listar_tutores()

    funcoes.exibe_logo()
    funcoes.exibe_opçao()
    funcoes.escolhe_opcao_menu(lista_animais, lista_tutores)
    
if __name__ == '__main__':
    main()