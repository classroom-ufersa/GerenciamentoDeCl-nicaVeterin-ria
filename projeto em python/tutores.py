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

def salva_arquivo_tutores(lista):
    arquivo = open('tutores.txt', 'w')
    lista.sort(key=lambda x: x.nome)
    for tutor in lista:
        arquivo.write(f'{tutor.nome}, {tutor.contato}, {tutor.documento}, {tutor.animais_tutor}\n')

def adiciona_tutores(lista1, lista2):
    print('Dados do novo tutor')
    nome = str(input('Informe o nome do Tutor: '))
    contato = int(input('Informe o contato do tutor: '))
    documento = int(input('Informe o documento do tutor: '))
    funcoes.limpa_tela()

    animais.mostra_lista_de_animais(lista2)
    animais_tutor = str(input('\n\nInforme o nome do animal que esse tutor será responsável: '))
    animais_tutor = animais_tutor.title()

    posicao = funcoes.busca_nome(lista2, animais_tutor)

    while posicao == -1:
        funcoes.limpa_tela()
        animais.mostra_lista_de_animais(lista2)
        print('Animal não encontrado\n')
        animais_tutor = str(input('Informe o nome de um animal presente na lista: '))
        posicao = funcoes.busca_nome(lista2, animais_tutor)

    tutor = Tutores(nome.title(), int(contato), int(documento), animais_tutor.title())
    lista1.append(tutor)

    salva_arquivo_tutores(lista1)

def mostra_lista_de_tutores(lista):
    lista.sort(key=lambda x: x.nome)
    print(f'{'Nome do tutor'.ljust(20)} | {'Contato do tutor'.ljust(20)} | {'Documento do tutor'.ljust(20)} | {'Animal responsável pelo tutor'}' )
    for tutor in lista:
        print(f'{tutor.nome:<20} | {tutor.contato:<20} | {tutor.documento:<20} | {tutor.animais_tutor}')

def remove_tutor(lista):
    mostra_lista_de_tutores(lista)
    nome = str(input('Informe o nome do tutor a ser removido: '))
    nome = nome.title()

    posicao = funcoes.busca_nome(lista, nome)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_tutores(lista)
        print('\nTutor não encontrado!\n')
        nome = str(input('Informe o nome de um tutor presente na lista: '))
        posicao = funcoes.busca_nome(lista, nome)

    del lista[posicao]

    salva_arquivo_tutores(lista)



    
