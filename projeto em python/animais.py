import funcoes
import tutores
import main

class Animais:
    def __init__(self, nome, idade, especie, saude):
        self.nome = nome
        self.idade = idade
        self.especie = especie
        self.saude = saude

    def __str__(self):
        print(f'{self.nome} | {self.idade} | {self.especie} | {self.saude}')

def listar_animais():
    arquivo = open('animais.txt', 'r')

    linhas = arquivo.readlines()
    lista_animais = []

    for linha in linhas:
        nome, idade, especie, saude = linha.strip().split(',')
        animal = Animais(nome.title(), int(idade), especie.title(), saude.title())
        lista_animais.append(animal)
        
    arquivo.close()

    return lista_animais


def adiciona_animais(lista):
    print('Dados do animal\n')
    nome = str(input('Informe o nome do animal: '))
    idade = int(input('Informe a idade do animal: '))
    especie = str(input('Informe a especie do animal: '))
    saude = str(input('Informe a saude do animal: '))

    animal = Animais(nome.title(), int(idade), especie.title(), saude.title())
    lista.append(animal)

    salva_arquivo_animais(lista)

def salva_arquivo_animais(lista):
    arquivo = open('animais.txt', 'w')
    lista.sort(key=lambda x: x.nome)
    for animal in lista:
        arquivo.write(f'{animal.nome}, {animal.idade}, {animal.especie}, {animal.saude}\n')

    arquivo.close()

def mostra_lista_de_animais(lista):
    lista.sort(key=lambda x: x.nome)
    print(f'{'Nome do animal'.ljust(20)} | {'Idade do animal'.ljust(20)} | {'Espécie do animal'.ljust(20)} | {'Saúde do animal'}' )
    for animal in lista:
        print(f'{animal.nome:<20} | {animal.idade:<20} | {animal.especie:<20} | {animal.saude}')

def remove_animal(lista):
    mostra_lista_de_animais(lista)
    nome = str(input('Informe o nome do animal a ser removido: '))
    nome = nome.title()

    posicao = funcoes.busca_nome(lista, nome)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_animais(lista)
        print('\nAnimal não encontrado!\n')
        nome = str(input('Informe o nome de um animal presente na lista: '))
        posicao = funcoes.busca_nome(lista, nome)

    del lista[posicao]
    
    salva_arquivo_animais(lista)

def editar_animal(lista):
    mostra_lista_de_animais(lista)
    animal = input('Informe o nome do animal que deseja editar: ')
    animal.title()

    posicao = funcoes.busca_nome(lista, animal)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_animais(lista)
        print('Animal não encontrado\n')
        animal = str(input('Informe o nome de um animal presente na lista: '))
        posicao = funcoes.busca_nome(lista, animal)

    funcoes.menu_editar_animal()
    escolhe_opcao_editar(lista, posicao)

def escolhe_opcao_editar(lista ,posicao):
    try:
        opcao_escolhida = int(input('Escolha uma opcão: '))

        if opcao_escolhida == 1:
            novo_nome = str(input('Informe o novo nome do animal'))
            novo_nome= novo_nome.title()
            lista[posicao].nome = novo_nome
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 2:
            nova_idade = int(input('Informe a nova idade do animal: '))
            lista[posicao].idade = nova_idade
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 3:
            nova_especie = str(input('Informe o nova espécie do animal: '))
            nova_especie = nova_especie.title()
            lista[posicao].especie = nova_especie
        elif opcao_escolhida == 4:
            nova_saude = str(input('Informe o novo estado de saúde do animal: '))
            nova_saude = nova_saude.title()
            lista[posicao].saude = nova_saude
        elif opcao_escolhida == 5:
            main.main()

    except:
        funcoes.opcao_invalida()


    





