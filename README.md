# Gerenciamento de Disco

IMD0036 – SISTEMAS OPERACIONAIS
Lista de Exercícios 2 - Unidade III – 22/11/2018

# Instalação

Abra o terminal e siga as instruções:

1.`git clone https://github.com/allandemiranda/Gerenciamento-de-Disco.git`
2.`cd Gerenciamento-de-Disco/`
3.`g++ -std=c++17 ./src/*.cpp -I include -o ./bin/disco.o`

# Execução

Abra o terminal e siga as instruções:

1.`vim ./data/dados_entrada.txt`

Configure o arquivo da seguinte maneira:
* Um inteiro com a posição inicial do cabeçote
* Um inteiro n que determina o tamanho da fila de espera
* n inteiros que são a fila de espera

Quando finalizada a edição do arquivo de configuração salve e saia do Vim com o comando
`:wq`

2.`./bin/disco.o < ./data/dados_entrada.txt`