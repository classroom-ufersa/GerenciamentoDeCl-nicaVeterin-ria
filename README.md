# Clínica veterinária
- Esse repositório tem como objetivo desenvolver um projeto de gerenciamento de uma clínica veterinária, feito nas linguagens C e python. 
***

## Desenvolvedores
>[Pedro Lucas](https://github.com/Pelluca)
>
>[Pedro Andrade](https://github.com/pehandrade)
***

# Tabela de conteúdo
> [Introdução](#introdução)
> 
> [Problemática](#problemática)
> 
> [Desenvolvimento](#desenvolvimento)
>
> [Organização Repositório](#organização-repositório)
>
> [Compilação e Execução](#compilação-e-execução)
***

# Introdução 
O sistema em questão, permite que o usuário seja capaz de gerenciar uma clínica veterinária de forma fácil e dinâmica. Podendo cadastrar e editar informações dos tutores e animais.
***

# Problemática
Projetar um sistema na Linguagem C para gerenciamemto de uma clínica Veterinária. O sistema precisará manicuplar tutores e animais.
***

# Desenvolvimento
O código desenvolvido nas linguagens Python e C, ambas apresentam as sequintes funcionalidas:
- `Gerenciamento de tutores:` Adiciona, remove e lista os tutores e seus animais cadastrados em um arquivo.txt
- `Gerenciamento de animais:` Adiciona e remove animais, busca animais pelo nome, além de editar as informações de um animal

## Menu
As sequintes opçãoes estão presentes no nosso menu:
- `Adiciona Tutores:` Cria um novo tutor na lista;
- `Remove tutor:` Remove um tutor da lista;
- `Adiciona Animal:` Adiciona animal a um tutor presente na lista;
- `Remove Animal:` Remove um animal da lista;
- `Editar informação de um animal:` Edita algum atributo pertecente a um animal;
- `Busca animal por nome:` Busca algum animal presente na lista pelo nome;
- `Listar tutores e seus animais:` Mostra a lista de tutores e seus respectivos animais;
- `Sair:` finaliza o programa.
***

# Organização Repositório
``` 
📁 Gerenciamento_de_Clinica_Veterinaria
│
└───Projeto em c
        │
        ├──Files
            │
            └───arquivo.txt
        ├──include
            │
            └───animais.h
            └───funcoes.h
            └───sistema.h
            └───tutores.h
        ├──src
            │
            └───animais.c
            └───funcoes.c
            └───main.c
            └───sistema.c
            └───tutores.c
│
└───projeto em python
        │
        ├──__pycache__
            │
            └───main.cpython-312.pyc
        ├──arquivo
            │
            └───tutores.txt
        ├──pasta
            │
            └───__pycache__
            └───__init__.py
            └───animais.py
            └───funcoes.py
            └───tutores.py
        ├──main.py
│
└───.gitignore
│
└───README.md
```
***
# Compilação e Execução
Para instalar e executar este projeto, siga estas etapas:
- Clone o repositório do GitHub:
```bash
    git clone https://github.com/classroom-ufersa/Gerenciamento_de_Clinica_Veterinaria.git
````

- Execução em C
````c
    cd .\Projeto em c\bin\
    gcc ..\src\main.c -o main
    .\main.exe
````

- Execução em Python
````python
    cd .\projeto em pyhon\
    python main.py
````
