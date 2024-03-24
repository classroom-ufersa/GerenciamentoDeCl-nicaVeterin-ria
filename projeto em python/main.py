import tutores
import animais
import funcoes


def main():
    lista1 = tutores.listar_tutores()
    lista2 = animais.listar_animais()

    tutores.adiciona_tutores(lista1, lista2)




if __name__ == '__main__':
    main()