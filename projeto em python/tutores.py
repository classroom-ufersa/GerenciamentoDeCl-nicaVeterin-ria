import animais
import funcoes
import main

class Tutores:
    def __init__(self, nome, contato, documento, animais_tutor = [{}]):
        self.nome = nome
        self.contato = contato
        self.documento = documento
        self.animais_tutor = animais_tutor

    def __str__(self):
        return(f'{self.nome} | {self.contato} | {self.documento} | {self.animais_tutor}')
    

def listar_tutores():
    arquivo = open('tutores.txt', 'r')

    linhas = arquivo.readlines()
    lista_tutores = []

    for linha in linhas:
        nome, contato, documento, animais_tutor = linha.strip().split('/')
        tutor = Tutores(nome.title().strip(), contato.strip(), documento.strip(), animais_tutor.strip())
        lista_tutores.append(tutor)

    arquivo.close()

    return lista_tutores

def salva_arquivo_tutores(lista):
    arquivo = open('tutores.txt', 'w')
    lista.sort(key=lambda x: x.nome)
    for tutor in lista:
        arquivo.write(f'{tutor.nome} / {tutor.contato} / {tutor.documento} / {tutor.animais_tutor}\n')

def adiciona_tutores(lista1, lista2):
    funcoes.limpa_tela()
    funcoes.adiciona_subtitulo('Dados do novo tutor')

    nome = str(input('Informe o nome do Tutor: '))
    contato = str(input('Informe o contato do tutor: '))
    documento = str(input('Informe o documento do tutor: '))
    funcoes.limpa_tela()

    animais_tutor = []  

    while True:
        animais.mostra_lista_de_animais(lista2)
        animais_tutor_nome = input('\nInforme o nome do animal que esse tutor será responsável (ou digite "fim" para terminar): ')
        if animais_tutor_nome.lower() == 'fim':
            break  
        animais_tutor_nome = animais_tutor_nome.title()

        posicao = funcoes.busca_nome(lista2, animais_tutor_nome)

        if posicao != -1:
            tutor_animal = lista2[posicao]
            animais_tutor.append(
                {
                    'Nome': tutor_animal.nome, 
                    'Saude': tutor_animal.saude
                }
            )
        else:
            print('Animal não encontrado\n')

    tutor = Tutores(nome.title(), contato.strip(), documento.strip(), animais_tutor)
    lista1.append(tutor)

    salva_arquivo_tutores(lista1)
    funcoes.volta_ao_menu()


def mostra_lista_de_tutores(lista):
    funcoes.limpa_tela()
    lista.sort(key=lambda x: x.nome)
    for tutor in lista:
        print(f'Nome: {tutor.nome:<20} Contato: {tutor.contato:<20} Documento: {tutor.documento}')
        print('Animais:')
        for chave, animal in tutor.animais_tutor:
            print(animal)
            print(f'{chave}: {animal}')

def remove_tutor(lista):
    funcoes.limpa_tela()
    mostra_lista_de_tutores(lista)
    nome = str(input('\nInforme o nome do tutor a ser removido: '))
    nome = nome.title()

    posicao = funcoes.busca_nome(lista, nome)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_tutores(lista)
        print('\nTutor não encontrado!\n')
        nome = str(input('Informe o nome de um tutor presente na lista: '))
        nome = nome.title()
        posicao = funcoes.busca_nome(lista, nome)

    del lista[posicao]

    salva_arquivo_tutores(lista)
    funcoes.volta_ao_menu()