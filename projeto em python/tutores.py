import funcoes
import main

class Tutores:
    def __init__(self, nome, contato, documento, animais_tutor=None):
        self.nome = nome
        self.contato = contato
        self.documento = documento
        if animais_tutor is None:
            self.animais_tutor = []
        else:
            self.animais_tutor = animais_tutor

    def __str__(self):
        animais_str = "\n\t".join(str(animal) for animal in self.animais_tutor)
        return f'Tutor | Nome: {self.nome} | Contato: {self.contato} | Documento: {self.documento}\n\tAnimais do Tutor:\n\t{animais_str}'
    
def listar_tutores(nome_arquivo):
    from animais import Animais
    tutores = []

    with open(nome_arquivo, 'r') as arquivo:
        nome = None
        contato = None
        documento = None
        animais_tutor = []
        for linha in arquivo:
            linha = linha.strip()
            if linha.startswith("Tutor"):
                if nome and contato and documento:
                    tutores.append(Tutores(nome, contato, documento, animais_tutor))
                nome, contato, documento = linha.split(" | ")[1:]
                nome = nome.split(":")[1].strip()
                contato = contato.split(":")[1].strip()
                documento = documento.split(":")[1].strip()
                animais_tutor = []
            elif linha.startswith("Nome:"):
                nome_animal = linha.split("Nome: ")[1].split(" |")[0].strip()
                idade = linha.split("Idade: ")[1].split(" |")[0].strip()
                especie = linha.split("Especie: ")[1].split(" |")[0].strip()
                saude = linha.split("Saude: ")[1].strip()
                animal = Animais(nome_animal, idade, especie, saude)
                animais_tutor.append(animal)
        if nome and contato and documento:
            tutores.append(Tutores(nome, contato, documento, animais_tutor))

    tutores.sort(key=lambda x: x.nome)
    return tutores

def criar_tutor(tutores):
    from animais import Animais

    funcoes.exibe_subtitulo('Adicionando Tutor')
    nome = input("Nome do tutor: ")
    contato = input("Contato do tutor: ")
    documento = input("Documento do tutor: ")
    print()

    animais = []
    while True:
        funcoes.exibe_subtitulo('Adicionando o(s) Animal(ais) do Tutor')
        nome_animal = input('Informe o nome do animal que você deseja adicionar: ')
        idade_animal = input('Informe a idade do animal: ')
        especie_animal = input('Informe a espécie do animal: ')
        saude_animal = input('Informe a saúde do animal: ')

        animal = Animais(nome_animal.title(), idade_animal.title(), especie_animal.title(), saude_animal.title())
        animais.append(animal)
        animais.sort(key=lambda x: x.nome)

        funcoes.limpa_tela()
        print('Deseja adicionar outro animal?\n')
        para = input('Digite (S) para continuar ou Digite (N) para sair: ')
        para = para.upper()
        if para == 'S':
            continue
        elif para == 'N':
            break
        else:
            while para != 'S' and para != 'N':
                funcoes.limpa_tela()
                print('Ops! parece que você digitou errado\n')
                para = input('Digite (S) para continuar ou Digite (N) para sair: ')
                para = para.upper()

    novo_tutor = Tutores(nome.title(), contato.title(), documento.title(), animais)
    tutores.append(novo_tutor)
    tutores.sort(key=lambda x: x.nome)

    salva_arquivo(tutores)

def remove_tutor(tutores):
    from funcoes import busca_nome

    funcoes.exibe_subtitulo('Removendo um Tutor da Clínica')
    nome_tutor = input('Informe o nome do tutor que você deseja remover: ')
    nome_tutor = nome_tutor.title()
    indice_tutor = busca_nome(tutores, nome_tutor)

    if indice_tutor != -1:
        tutores.pop(indice_tutor)
        print(f'O tutor {nome_tutor} foi removido com sucesso!')
        salva_arquivo(tutores)
    else:
        print('Tutor não encontrado')

def salva_arquivo(tutores):
    with open('tutores.txt', 'w') as arquivo:
        for tutor in tutores:
            arquivo.write(str(tutor) + '\n\n')

def mostra_arquivo():
    funcoes.exibe_subtitulo('Lista de Tutores Cadastrados')
    with open("tutores.txt", "r") as arquivo:
        for linha in arquivo:
            print(linha.strip())