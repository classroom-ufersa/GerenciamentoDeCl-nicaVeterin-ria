import os
import animais
import funcoes

class Tutores:
    def __init__(self, nome, contato, documento, animais_tutor):
        self.nome = nome
        self.contato = contato
        self.documento = documento
        self.animais_tutor = animais_tutor

    def __str__(self):
        print(f'{self.nome} | {self.contato} | {self.documento} | {self.animais_tutor}')

def listar_tutores():
    arquivo = open('tutores.txt', 'r')

    linhas = arquivo.readlines()
    lista_tutores = []

    for linha in linhas:
        nome, contato, documento, animais_tutor = linha.strip().split(',')
        tutor = Tutores(nome.title(), int(contato), int(documento), (animais_tutor.title()))
        lista_tutores.append(tutor)

    arquivo.close()

    return lista_tutores

def ordena_lista_tutores(lista):
    arquivo = open('tutores.txt', 'w')
    lista.sort(key=lambda x: x.nome)
    for tutor in lista:
        arquivo.write(f'{tutor.nome}, {tutor.contato}, {tutor.documento}, {tutor.animais_tutor}\n')

def adiciona_tutores(lista1, lista2):
    lista2 = animais.listar_animais()

    print('Dados do novo tutor')
    nome = str(input('Informe o nome do Tutor: '))
    contato = int(input('Informe o contato do tutor: '))
    documento = int(input('informe o documento do tutor'))
    os.system('cls')

    animais.mostra_lista_de_animais(lista2)
    animais_tutor = str(input('\n\nInforme o nome do animal que esse tutor será responsável: '))

    #adicionar buscar_animal depois

    tutor = Tutores(nome.title(), int(contato), int(documento), animais_tutor.title())
    lista1.append(tutor)

    ordena_lista_tutores(lista1)

    
