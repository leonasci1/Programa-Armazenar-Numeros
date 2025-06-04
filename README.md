# Programa-Armazenar-Numeros
README: Programa de Manipulação de Vetor de Inteiros
Este programa em C++ permite ao usuário gerenciar uma lista (vetor) de números inteiros, oferecendo funcionalidades básicas de adição, busca, ordenação, remoção e exibição dos elementos. O programa foi desenvolvido com foco na compatibilidade com compiladores C++ mais antigos (padrão C++98/03).

Funcionalidades Principais
Adicionar Números:

Permite inserir números inteiros no vetor.
A adição é restrita a faixas de valores específicas: [1-20], [50-60] e [100-120].
Impede a adição de números duplicados.
Verifica se o vetor atingiu sua capacidade máxima (definida como 50 elementos).
Buscar Números:

O usuário pode procurar por um número específico no vetor.
São oferecidos dois métodos de busca:
Pesquisa Sequencial: Percorre o vetor elemento por elemento.
Pesquisa Binária: Método mais eficiente que requer que o vetor esteja ordenado. Se o vetor não estiver ordenado, o programa oferece a opção de ordená-lo antes de realizar a busca.
Ordenar Vetor:

Permite ordenar os elementos do vetor em ordem crescente.
O usuário pode escolher entre dois algoritmos de ordenação:
BubbleSort
Insertion Sort
O programa informa se o vetor já se encontra ordenado.
Remover Números:

Possibilita a remoção de elementos do vetor.
A remoção pode ser feita de duas formas:
Por Valor: O usuário digita o número que deseja remover.
Por Posição: O usuário digita o índice (posição) do elemento a ser removido.
Exibir Vetor:

Mostra todos os números atualmente armazenados no vetor, junto com a contagem de elementos e a capacidade máxima.
Estrutura do Código e Implementação
Linguagem: C++ (com foco na compatibilidade C++98/03).
Estrutura de Dados: std::vector<int> da biblioteca padrão do C++ é utilizado para armazenar os números, oferecendo flexibilidade no tamanho (embora limitado a tam_MAX na lógica de adição).
Interface: Menu textual interativo para facilitar a navegação e seleção das funcionalidades pelo usuário.
Compatibilidade:
Funções como std::is_sorted (C++11) foram substituídas por implementações manuais (verificarSeVetorEstaOrdenado) para garantir a compatibilidade.
O uso de constexpr foi substituído por const.
Iteradores auto foram explicitados com std::vector<int>::iterator.
Validação de Entrada: Implementada para diversas entradas do usuário, visando maior robustez do programa.
Modularização: O código é organizado em funções para cada funcionalidade principal, melhorando a legibilidade e manutenção.
Como Compilar e Executar
Compilação:
Utilize um compilador C++ (como g++ ou o compilador embutido no Dev-C++).
Não são necessárias flags especiais de C++11 ou posteriores, pois o código foi adaptado.
Exemplo com g++: g++ nome_do_arquivo.cpp -o nome_do_executavel
Execução:
Após a compilação bem-sucedida, execute o arquivo gerado.
Exemplo: ./nome_do_executavel (Linux/macOS) ou nome_do_executavel.exe (Windows).
O programa apresentará um menu com as opções disponíveis para o usuário interagir.
