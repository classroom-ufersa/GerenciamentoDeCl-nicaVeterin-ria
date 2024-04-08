class Tutores:
    def __init__(self, nome, contato, documento, animais_tutor=None):
        '''
        Inicializa um objeto Tutores com as informaçãoes fornecidas

        Atributos:
        nome (str): O nome do tutor.
        contato (str): O contato do tutor (telefone, e-mail, etc.).
        documento (str): O documento de identificação do tutor.
        animais_tutor (list): Uma lista de animais que o tutor possui. Pode ser uma lista vazia se o tutor não tiver animais.
        '''
        self.nome = nome
        self.contato = contato
        self.documento = documento
        if animais_tutor is None:
            self.animais_tutor = []
        else:
            self.animais_tutor = animais_tutor

    def __str__(self):
        '''
        Retorna uma representação em string do objeto Tutores.

        Retorna:
        str: Uma string contendo as informações do tutor e seus animais.
        '''
        animais_str = "\n\t".join(str(animal) for animal in self.animais_tutor)
        return f'Tutor | Nome: {self.nome} | Contato: {self.contato} | Documento: {self.documento}\n\tAnimais do Tutor:\n\t{animais_str}'
    
def listar_tutores():
    '''
    Carrega os dados dos tutores e seus animais a partir de um arquivo de texto e retorna uma lista de objetos Tutores.

    Retorna:
    list: Uma lista de objetos Tutores, contendo informações sobre os tutores e seus animais.
    '''
    from pastas.animais import Animais
    tutores = []

    with open(r'C:\Users\peluc\OneDrive\Área de Trabalho\Gerenciamento_de_Clinica_Veterinaria\projeto em python\arquivo\tutores.txt', 'r') as arquivo:
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
    '''
    Cria um novo tutor e adiciona à lista de tutores.

    Esta função solicita informações sobre o tutor e os animais que ele possui, e então cria um novo objeto Tutores
    com essas informações e o adiciona à lista de tutores fornecida.

    Args:
    tutores (list): Uma lista de objetos Tutores existentes.

    Returns:
    None
    '''
    from pastas.animais import Animais
    from pastas.funcoes import exibe_subtitulo, limpa_tela

    exibe_subtitulo('Adicionando Tutor')
    nome = input("Nome do tutor: ")
    contato = input("Contato do tutor: ")
    documento = input("Documento do tutor: ")
    print()

    animais = []
    while True:
        exibe_subtitulo('Adicionando o(s) Animal(ais) do Tutor')
        nome_animal = input('Informe o nome do animal que você deseja adicionar: ')
        idade_animal = input('Informe a idade do animal: ')
        especie_animal = input('Informe a espécie do animal: ')
        saude_animal = input('Informe a saúde do animal: ')

        animal = Animais(nome_animal.title(), idade_animal.title(), especie_animal.title(), saude_animal.title())
        animais.append(animal)
        animais.sort(key=lambda x: x.nome)

        limpa_tela()
        print('Deseja adicionar outro animal?\n')
        para = input('Digite (S) para continuar ou Digite (N) para sair: ')
        para = para.upper()
        if para == 'S':
            continue
        elif para == 'N':
            break
        else:
            while para != 'S' and para != 'N':
                limpa_tela()
                print('Ops! parece que você digitou errado\n')
                para = input('Digite (S) para adicinar outro animal ou Digite (N) para sair: ')
                para = para.upper()

    novo_tutor = Tutores(nome.title(), contato, documento, animais)
    tutores.append(novo_tutor)
    tutores.sort(key=lambda x: x.nome)
    salva_arquivo(tutores)

def remove_tutor(tutores):
    '''
    Remove um tutor da clínica veterinária.

    Esta função permite ao usuário especificar o nome de um tutor a ser removido. Se o tutor for encontrado na lista de
    tutores fornecida, ele será removido. Caso contrário, uma mensagem informando que o tutor não foi encontrado será exibida.

    Args:
    tutores (list): Uma lista de objetos Tutores representando os tutores na clínica.

    Returns:
    None
    '''
    from pastas.funcoes import busca_nome, exibe_subtitulo

    exibe_subtitulo('Removendo um Tutor da Clínica')
    nome_tutor = input('Informe o nome do tutor que você deseja remover: ')
    nome_tutor = nome_tutor.title()
    indice_tutor = busca_nome(tutores, nome_tutor)

    while indice_tutor == -1:
        exibe_subtitulo('Tutor não encontrado!')
        nome_tutor = input('Informe o nome de um tutor presente na lista: ')
        nome_tutor = nome_tutor.title()
        indice_tutor = busca_nome(tutores, nome_tutor)

    tutores.pop(indice_tutor)
    print(f'\nO tutor {nome_tutor} foi removido com sucesso!')
    salva_arquivo(tutores)


def salva_arquivo(tutores):
    '''
    Salva os dados dos tutores em um arquivo de texto.

    Esta função recebe uma lista de objetos Tutores e escreve suas representações de string
    no arquivo de texto 'tutores.txt', separando cada tutor por duas linhas em branco.

    Args:
    tutores (list): Uma lista de objetos Tutores.

    Returns:
    None
    '''
    with open(r'C:\Users\peluc\OneDrive\Área de Trabalho\Gerenciamento_de_Clinica_Veterinaria\projeto em python\arquivo\tutores.txt', 'w') as arquivo:
        for tutor in tutores:
            arquivo.write(str(tutor) + '\n\n')

def mostra_arquivo():
    '''
    Exibe o conteúdo do arquivo 'tutores.txt' na saída padrão.

    Esta função abre o arquivo 'tutores.txt' em modo de leitura e exibe seu conteúdo linha por linha,
    removendo espaços em branco no início e no final de cada linha.

    Args:
    None

    Returns:
    None
    '''
    from pastas.funcoes import exibe_subtitulo

    exibe_subtitulo('Lista de Tutores Cadastrados')
    with open(r'C:\Users\peluc\OneDrive\Área de Trabalho\Gerenciamento_de_Clinica_Veterinaria\projeto em python\arquivo\tutores.txt', 'r') as arquivo:
        for linha in arquivo:
            print(linha.strip())