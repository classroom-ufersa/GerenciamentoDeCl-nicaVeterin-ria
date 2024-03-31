import funcoes
import main
import tutores

class Animais:
    def __init__(self, nome, idade, especie, saude):
        self.nome = nome
        self.idade = idade
        self.especie = especie
        self.saude = saude

    def __str__(self):
        return(f'Nome: {self.nome} | Idade: {self.idade} | Especie: {self.especie} | Saude: {self.saude}')

def listar_animais(nome_arquivo):
    with open(nome_arquivo, 'r') as arquivo:
        linhas = arquivo.readlines()
        lista_animais = []

        for linha in linhas:
            linha = linha.strip()
            if linha.startswith('Nome:'):
                nome = linha.split('Nome: ')[1].split(" |")[0].strip()
                idade = linha.split('Idade: ')[1].split(" |")[0].strip()
                especie = linha.split('Especie: ')[1].split(" |")[0].strip()
                saude = linha.split('Saude: ')[1].strip()
                animal = Animais(nome, idade, especie, saude)
                lista_animais.append(animal)

    lista_animais.sort(key=lambda x: x.nome)
    return lista_animais

def adiciona_animal(tutores):
    from funcoes import busca_nome
    from tutores import salva_arquivo

    funcoes.exibe_subtitulo('Adicionando Animal')
    nome_animal = input('Informe o nome do animal que você deseja adicionar: ')
    idade_animal = input('Informe a idade do animal: ')
    especie_animal = input('Informe a espécie do animal: ')
    saude_animal = input('Informe a saúde do animal: ')
    print()
    nome_tutor = input('Informe o nome do tutor que você quer adicionar o animal: ')
    nome_tutor = nome_tutor.title()

    indice_tutor = busca_nome(tutores, nome_tutor)
    
    if indice_tutor != -1:
        tutor = tutores[indice_tutor]
        novo_animal = Animais(nome_animal.title(), idade_animal.title(), especie_animal.title(), saude_animal.title())
        tutor.animais_tutor.append(novo_animal)
        tutor.animais_tutor.sort(key=lambda x: x.nome)
        print(f'Animal {nome_animal} adicionado')
    else:
        while indice_tutor == -1:
            funcoes.limpa_tela()
            print(f'Tutor não encontrado')
            nome_tutor = input('Informe o nome de um tutor presente na lista: ')
            nome_tutor = nome_tutor.title()
            indice_tutor = busca_nome(tutores, nome_tutor)
    
    salva_arquivo(tutores)

def remove_animal(tutores):
    from funcoes import busca_nome
    from tutores import salva_arquivo

    funcoes.exibe_subtitulo('Removendo Animal')
    nome_tutor = input('Informe o nome do tutor que você quer remover o animal: ')
    nome_tutor = nome_tutor.title()

    indice_tutor = busca_nome(tutores, nome_tutor)

    while indice_tutor == -1:
        funcoes.limpa_tela()
        print(f'Tutor não encontrado')
        nome_tutor = input('Informe o nome de um tutor presente na lista: ')
        nome_tutor = nome_tutor.title()
        indice_tutor = busca_nome(tutores, nome_tutor)
    
    tutor = tutores[indice_tutor]
    
    nome_animal = input('Informe o nome do animal que você deseja remover: ')
    nome_animal = nome_animal.title()
    indice_animal = busca_nome(tutor.animais_tutor, nome_animal)

    while indice_animal == -1:
        funcoes.limpa_tela()
        print(f'Animal não encontrado nesse tutor')
        nome_animal = input('Informe o nome de um animal que pertence a esse tutor: ')
        nome_animal = nome_animal.title()
        indice_animal = busca_nome(tutor.animais_tutor, nome_animal)

    tutor.animais_tutor.pop(indice_animal)
    print(f'Animal {nome_animal} removido')
            
    salva_arquivo(tutores)

def edita_animal(tutores):
    from tutores import salva_arquivo
    from funcoes import busca_nome

    funcoes.exibe_subtitulo('Editando Animal')
    nome_tutor = input('Informe o nome do tutor que possui o animal que você deseja editar: ')
    nome_tutor = nome_tutor.title()
    
    indice_tutor = busca_nome(tutores, nome_tutor)

    while indice_tutor == -1:
        funcoes.limpa_tela()
        print(f'Tutor não encontrado')
        nome_tutor = input('Informe o nome de um tutor presente na lista: ')
        nome_tutor = nome_tutor.title()
        indice_tutor = busca_nome(tutores, nome_tutor)
    
    tutor = tutores[indice_tutor]
    
    nome_animal = input('Informe o nome do animal que você deseja editar: ')
    nome_animal= nome_animal.title()
    indice_animal = busca_nome(tutor.animais_tutor, nome_animal)

    while indice_animal == -1:
        funcoes.limpa_tela()
        print(f'Animal não encontrado nesse tutor')
        nome_animal = input('Informe o nome de um animal que pertence a esse tutor: ')
        nome_animal = nome_animal.title()
        indice_animal = busca_nome(tutor.animais_tutor, nome_animal)

    animal = tutor.animais_tutor[indice_animal]
    escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
    salva_arquivo(tutores)

def escolhe_opcao_editar(tutores, animal, tutor, indice_animal):
    try:
        menu_editar_animal()
        opcao_escolhida = int(input('\nEscolha uma opcão: '))
        if opcao_escolhida == 1:
            funcoes.exibe_subtitulo('Novo nome')
            novo_nome = str(input('Informe o novo nome do animal: '))
            novo_nome= novo_nome.title()
            animal.nome = novo_nome
            escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
        elif opcao_escolhida == 2:
            funcoes.exibe_subtitulo('Nova idade')
            nova_idade = int(input('Informe a nova idade do animal: '))
            animal.idade = nova_idade
            escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
        elif opcao_escolhida == 3:
            funcoes.exibe_subtitulo('Novo especie')
            nova_especie = str(input('Informe o nova espécie do animal: '))
            nova_especie = nova_especie.title()
            animal.especie = nova_especie
            escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
        elif opcao_escolhida == 4:
            funcoes.exibe_subtitulo('Novo estado de saúde')
            nova_saude = str(input('Informe o novo estado de saúde do animal: '))
            nova_saude = nova_saude.title()
            animal.saude = nova_saude
            escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
        elif opcao_escolhida == 5:
            funcoes.exibe_subtitulo('Trocando Tutor')
            troca_animal(tutores, tutor, indice_animal)
            escolhe_opcao_editar(tutores, animal, tutor, indice_animal)
        elif opcao_escolhida == 6:
            main.main()
        else:
            funcoes.opcao_invalida()
    except:
        funcoes.opcao_invalida()

def troca_animal(tutores, tutor_atual, indice_animal):
    from funcoes import busca_nome
    from tutores import salva_arquivo

    novo_tutor = input('Informe o nome do novo tutor do animal: ')
    novo_tutor = novo_tutor.title()
    indice_novo_tutor = busca_nome(tutores, novo_tutor)
    while indice_novo_tutor == -1:
        funcoes.limpa_tela()
        print(f'Tutor não encontrado')
        nome_tutor = input('Informe o nome de um tutor presente na lista: ')
        nome_tutor = nome_tutor.title()
        indice_novo_tutor = busca_nome(tutores, nome_tutor)

    animal = tutor_atual.animais_tutor.pop(indice_animal)
    novo_tutor = tutores[indice_novo_tutor]
    novo_tutor.animais_tutor.append(animal)
    novo_tutor.animais_tutor.sort(key=lambda x: x.nome)
    salva_arquivo(tutores)

def busca_animal(lista_animais):
    from funcoes import busca_nome

    funcoes.exibe_subtitulo('Buscando Animal')
    nome = input('Informe o nome do animal: ')
    nome = nome.title()

    indice_animal = busca_nome(lista_animais, nome)

    if indice_animal != -1:
        animal_escolhido = lista_animais[indice_animal]
        lista_animais.sort(key=lambda x: x.nome)
        print(f'{'Nome do animal'.ljust(20)} | {'Idade do animal'.ljust(20)} | {'Espécie do animal'.ljust(20)} | {'Saúde do animal'}' )
        print(f'{animal_escolhido.nome:<20} | {animal_escolhido.idade:<20} | {animal_escolhido.especie:<20} | {animal_escolhido.saude:<20}')
    else:
        print('Esse animal não está presente na lista!')
    
def menu_editar_animal():
    funcoes.exibe_subtitulo('Qual informção você deseja editar?')
    print('1. Nome')
    print('2. Idade')
    print('3. Espécie')
    print('4. Saúde')
    print('5. Troca tutor')
    print('6. Sair')