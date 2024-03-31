import tutores
import animais
import funcoes


def main():
    funcoes.limpa_tela()
    lista_animais = animais.listar_animais('tutores.txt')
    lista_tutores = tutores.listar_tutores('tutores.txt')

    funcoes.exibe_logo()
    funcoes.exibe_opçao()
    funcoes.escolhe_opcao_menu(lista_animais, lista_tutores)

if __name__ == '__main__':
    main()
    