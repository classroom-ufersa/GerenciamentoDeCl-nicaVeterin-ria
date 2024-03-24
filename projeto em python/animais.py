import funcoes
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
        animal = Animais(nome.title().strip(), int(idade), especie.title().strip(), saude.title().strip())
        lista_animais.append(animal)
        
    arquivo.close()

    return lista_animais


def adiciona_animais(lista):
    funcoes.limpa_tela()
    funcoes.adiciona_subtitulo('Dados do novo animal')

    nome = str(input('Informe o nome do animal: '))
    idade = int(input('Informe a idade do animal: '))
    especie = str(input('Informe a especie do animal: '))
    saude = str(input('Informe a saude do animal: '))

    animal = Animais(nome.title().strip(), int(idade), especie.title().strip(), saude.title().strip())
    lista.append(animal)

    salva_arquivo_animais(lista)
    funcoes.volta_ao_menu()

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
    funcoes.limpa_tela()
    mostra_lista_de_animais(lista)
    nome = str(input('\nInforme o nome do animal a ser removido: '))
    nome = nome.title()

    posicao = funcoes.busca_nome(lista, nome)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_animais(lista)
        print('\nAnimal não encontrado!\n')
        nome = str(input('Informe o nome de um animal presente na lista: '))
        nome = nome.title()
        posicao = funcoes.busca_nome(lista, nome)

    del lista[posicao]
    
    salva_arquivo_animais(lista)

def editar_animal(lista):
    funcoes.limpa_tela()
    mostra_lista_de_animais(lista)
    animal = input('\nInforme o nome do animal que deseja editar: ')
    animal = animal.title()

    posicao = funcoes.busca_nome(lista, animal)

    while posicao == -1:
        funcoes.limpa_tela()
        mostra_lista_de_animais(lista)
        print('\nAnimal não encontrado\n')
        animal = str(input('Informe o nome de um animal presente na lista: '))
        animal = animal.title()
        posicao = funcoes.busca_nome(lista, animal)

    menu_editar_animal()
    escolhe_opcao_editar(lista, posicao)

def escolhe_opcao_editar(lista ,posicao):
    try:
        opcao_escolhida = int(input('\nEscolha uma opcão: '))

        if opcao_escolhida == 1:
            funcoes.adiciona_subtitulo('Novo nome')
            novo_nome = str(input('Informe o novo nome do animal: '))
            novo_nome= novo_nome.title()
            lista[posicao].nome = novo_nome
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 2:
            funcoes.adiciona_subtitulo('Nova idade')
            nova_idade = int(input('Informe a nova idade do animal: '))
            lista[posicao].idade = nova_idade
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 3:
            funcoes.adiciona_subtitulo('Novo especie')
            nova_especie = str(input('Informe o nova espécie do animal: '))
            nova_especie = nova_especie.title()
            lista[posicao].especie = nova_especie
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 4:
            funcoes.adiciona_subtitulo('Novo estado de saúde')
            nova_saude = str(input('Informe o novo estado de saúde do animal: '))
            nova_saude = nova_saude.title()
            lista[posicao].saude = nova_saude
            salva_arquivo_animais(lista)
        elif opcao_escolhida == 5:
            main.main()
        else:
            funcoes.opcao_invalida()

    except:
        funcoes.opcao_invalida()

def menu_editar_animal():
    funcoes.adiciona_subtitulo('Qual informção você deseja editar?')
    print('1. Nome')
    print('2. Idade')
    print('3. Espécie')
    print('4. Saúde')
    print('5. Sair')

def busca_animal(lista):
    funcoes.limpa_tela()
    nome = str(input('Informe o nome do animal: '))
    nome = nome.title()

    posicao = funcoes.busca_nome(lista, nome)

    if posicao != -1:
        animal_escolhido = lista[posicao]
        lista.sort(key=lambda x: x.nome)
        print(f'{'Nome do animal'.ljust(20)} | {'Idade do animal'.ljust(20)} | {'Espécie do animal'.ljust(20)} | {'Saúde do animal'}' )
        print(f'{animal_escolhido.nome:<20} | {animal_escolhido.idade:<20} | {animal_escolhido.especie:<20} | {animal_escolhido.saude:<20}')
    else:
        funcoes.limpa_tela()
        print('Esse animal não está presente na lista!')