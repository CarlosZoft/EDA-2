# Nome: João Victor de Oliveira Matos
# Matrícula: 17/0013987

## Exercicio T1

A estabilidade de um algoritmo de ordenação se refera a capacidade do algoritimo de preservar a posição relativa de elementos com mesmo valor de chave de ordenação. Exemplo ordenar um vetor de alunos por sua nota usando o Insertion Sort em que o vetor esteja dessa forma:

    Aluno 1 | 10
    Aluno 2 | 8
    Aluno 3 | 7
    Aluno 4 | 6
    Aluno 5 | 8
    Aluno 6 | 9

Após a ordenação:

    Aluno 4 | 6
    Aluno 3 | 7
    Aluno 2 | 8
    Aluno 5 | 8
    Aluno 6 | 9
    Aluno 1 | 10

Os alunos 2 e 5 mantiver sua posições relativas um com o outro apos a ordenação.


## Exercicio T2

Usando o vetor V = [5,3,4,8,12,2,9] ddepois de rodar a função sep esse vetor fica V = [5,3,4,2,12,8,9]. Não deu certo pois o a função retornou o indice 4, nesse indice esta o valor 12, a esquerda dele todos os valores são menores que ele, porém a direita dele deveriam estar valores maiores e não foi o que ocorreu.
Se trocarmos o return i por return i-1 também nao funcionaria.
