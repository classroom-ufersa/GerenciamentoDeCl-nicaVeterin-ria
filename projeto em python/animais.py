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

def mostra_lista_de_animais(lista):
    lista.sort(key=lambda x: x.nome)
    print(f'{'Nome do animal'.ljust(20)} | {'Idade do animal'.ljust(20)} | {'Espécie do animal'.ljust(20)} | {'Saúde do animal'}' )
    for animal in lista:
        print(f'{animal.nome:<20} | {animal.idade:<20} | {animal.especie:<20} | {animal.saude}')


def adiciona_animais(lista):
    print('Dados do animal\n')
    nome = str(input('Informe o nome do animal: '))
    idade = int(input('Informe a idade do animal: '))
    especie = str(input('Informe a especie do animal: '))
    saude = str(input('Informe a saude do animal: '))

    animal = Animais(nome.title(), int(idade), especie.title(), saude.title())
    lista.append(animal)

    ordena_lista(lista)

def ordena_lista(lista):
    arquivo = open('animais.txt', 'w')
    lista.sort(key=lambda x: x.nome)
    for animal in lista:
        arquivo.write(f'{animal.nome}, {animal.idade}, {animal.especie}, {animal.saude}\n')

    arquivo.close()


lista = listar_animais()