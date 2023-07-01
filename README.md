<h1 align="center">Trabalho_A2_ED</h1>
<p align="center"><strong>Trabalho para a Avaliação 2 de Estruturas de Dados da FGV EMAp - 2023.1</strong></p>

<h2>Informações e objetivos</h2>

O Objetivo do trabalho é construir um explorador de árvores. Ele dispõe das seguintes funções:
01. O programa deve oferecer um menu ASCII para o usuário com as opções de uso
02. Todas as operações devem indicar o tempo de processamento utilizado após finalização
03. Uma das opções deve ser a construção de uma árvore binária de busca a partir de um arquivo texto
04. Uma das opções deve ser a construção de uma árvore binária de busca a partir de dados digitados pelo usuário
05. Uma das opções deve informar da altura da árvore
06. Uma das opções deve informar o tamanho da árvore
07. Uma das opções deve ser a inserção de um elemento fornecido pelo usuário
08. Uma das opções deve ser a remoção de um elemento fornecido pelo usuário
09. Uma das opções deve ser a busca do endereço de memória de um elemento fornecido pelo usuário
10. Uma das opções deve informar se a árvore é completa
11. Uma das opções deve informar se a árvore é perfeita
12. Uma das opções deve exibir a árvore utilizando BFS - elabore uma implementação eficiente
13. Uma das opções deve converter a árvore em uma lista e ordenar com Bubble Sort
14. Uma das opções deve converter a árvore em uma lista e ordenar com Selection Sort
15. Uma das opções deve converter a árvore em uma lista e ordenar com Insertion Sort
16. Uma das opções deve converter a árvore em uma lista e ordenar com Shell Sort
17. Extra: Representação gráfica da ordenação

<h2>Instalação</h2>

Faça na pasta onde o repositório ficará:

1. git clone https://github.com/MaxJockesi/Trabalho_A2_ED.git

<h3>Linux</h3>

1. sudo apt install libsdl2-dev pkg-config

2. g++ tree_functions.cpp border_functions.cpp tree_operations.cpp sorting_algorithms.cpp main.cpp -o "main.exe" $(pkg-config --cflags --libs sdl2)

3. ./main.exe

<h3>Windows</h3>

1. g++ -Isrc/include -Lsrc/lib -o main tree_functions.cpp border_functions.cpp tree_operations.cpp sorting_algorithms.cpp  main.cpp -lmingw32 -lSDL2main -lSDL2

<h2>Integrantes</h2>

- Cleyton Vinicius Prado dos Santos
- Jean Fernando Horn
- Max Jockesi Barbosa Soares
- Pablo Andrade Carvalho Barros

<h2>Agradecimentos especiais</h2>

- Professor <a href="https://emap.fgv.br/professores/rafael-de-pinho" target="_blank">Rafael de Pinho</a>
- Monitor <a href="https://github.com/wellington36" target="_blank">Wellington José Leite da Silva</a>
- Monitor <a href="https://github.com/barrafas" target="_blank">Tiago Barradas</a>
