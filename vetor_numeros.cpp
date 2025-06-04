#include <iostream>
#include <vector>
#include <string>      // incluído para std::string, embora não usado diretamente em globais/structs aqui
#include <limits>      // para std::numeric_limits
#include <algorithm>   // para std::find, std::swap, std::binary_search, std::lower_bound
#include <cctype>      // para toupper
#include <cstdlib>     // para system("cls")

// variáveis globais
int op;                         // armazena a escolha do usuário no menu
std::vector<int> vet;           // vetor para armazenar inteiros
const size_t tam_MAX = 50;      // tamanho máximo do vetor (usando const para compatibilidade com C++98)


bool verificarSeVetorEstaOrdenado(const std::vector<int>& v); // declaração para substituto do std::is_sorted

// exibe a contagem atual de elementos no vetor.
void MostrarContagem() {
    std::cout << "\n------------------------------------\n";
    std::cout << "Total de elementos no vetor: " << vet.size() << "/" << tam_MAX << std::endl;
    std::cout << "------------------------------------\n";
}

// exibe o menu principal do programa.
void MostrarMenu() {
    system("cls"); // limpa o console (específico para windows)
    std::cout << "===========================================\n";
    std::cout << "                 PROGRAMA                 \n";
    std::cout << "===========================================\n";
    std::cout << "[1] ADICIONAR\n"
              << "[2] BUSCAR\n"
              << "[3] ORDENAR\n"
              << "[4] REMOVER\n"
              << "[5] EXIBIR VETOR\n"
              << "[0] SAIR\n";
    std::cout << "===========================================\n";
    MostrarContagem();
    std::cout << "OPCAO: ";
}

// pausa a execução e aguarda o usuário pressionar enter.
// assume que o buffer de entrada está relativamente limpo antes desta chamada.
void espera() {
    std::cout << "\nPressione ENTER para continuar...";
    // consome o restante da linha atual, efetivamente aguardando o enter.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// adiciona números ao vetor com base nas faixas especificadas
void Add() {
    char continuar;
    do {
        system("cls");
        std::cout << "===========================================\n";
        std::cout << "             ADICIONAR NUMEROS            \n";
        std::cout << "===========================================\n";

        if (vet.size() >= tam_MAX) {
            std::cout << "Vetor ja esta lotado.\n";
            MostrarContagem();
            espera();
            return; // sai da função Add se o vetor estiver cheio
        }

        int num_ad_i;
        std::cout << "Digite o numero a adicionar: ";
        std::cin >> num_ad_i;
        // limpar o buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // verifica se o número está dentro das faixas permitidas.
        bool determinado =
            (num_ad_i >= 1 && num_ad_i <= 20) ||
            (num_ad_i >= 50 && num_ad_i <= 60) ||
            (num_ad_i >= 100 && num_ad_i <= 120);

        if (!determinado) {
            std::cout << "Nao e possivel adicionar nessa faixa.\n";
            MostrarContagem();
        } else {
            // verifica se o número já existe
            std::vector<int>::iterator it = std::find(vet.begin(), vet.end(), num_ad_i);
            if (it != vet.end()) {
                std::cout << "Numero ja presente no vetor!\n";
                MostrarContagem();
            } else {
                vet.push_back(num_ad_i);
                std::cout << "Numero " << num_ad_i << " adicionado com sucesso!\n";
                MostrarContagem();
            }
        }

        // pergunta se o usuário quer adicionar outro número.
        if (vet.size() < tam_MAX) {
            std::cout << "\nDeseja continuar adicionando? (S/N): ";
            std::cin >> continuar;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Vetor atingiu a capacidade maxima.\n";
            espera();
            break; // sai do loop pois o vetor está cheio
        }
    } while (toupper(continuar) == 'S' && vet.size() < tam_MAX);
}

// ordena o vetor usando o algoritmo bubble sort.
void BubbleSort(std::vector<int> &v) {
    int n = static_cast<int>(v.size()); // converte para int para os limites do loop
    bool trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break; //se nenhum par de elementos foi trocado, o vetor está ordenado.
    }
}

// ordena o vetor usando o algoritmo insertion sort.
void InsertionSort(std::vector<int> &v) {
    int n = static_cast<int>(v.size()); // converte para int para os limites do loop
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        // move os elementos de v[0..i-1] que são maiores que a chave
        // para uma posição à frente da sua posição atual.
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// função auxiliar para verificar se um vetor está ordenado.

bool verificarSeVetorEstaOrdenado(const std::vector<int>& v) {
    if (v.size() < 2) {
        return true; // vetor vazio ou com um único elemento é considerado ordenado.
    }
    for (size_t i = 0; i < v.size() - 1; ++i) {
        if (v[i] > v[i + 1]) {
            return false; // encontrou um par fora de ordem.
        }
    }
    return true; // todos os elementos estão em ordem não decrescente
}

// permite ao usuário ordenar o vetor usando um mét
void Ordenar() {
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "               ORDENAR VETOR               \n";
    std::cout << "===========================================\n";

    if (vet.empty()) {
        std::cout << "Vetor vazio. Nao ha nada para ordenar.\n";
        espera();
        return;
    }

    if (verificarSeVetorEstaOrdenado(vet)) {
        std::cout << "O vetor ja esta ordenado.\n";
        espera();
        return;
    }

    int metodo;
    std::cout << "Escolha o metodo de ordenacao:\n"
              << "[1] BubbleSort\n"
              << "[2] Insertion Sort\n"

              << "Opcao: ";
    std::cin >> metodo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (metodo == 1) {
        BubbleSort(vet);
        std::cout << "Vetor ordenado com BubbleSort.\n";
    } else if (metodo == 2) {
        InsertionSort(vet);
        std::cout << "Vetor ordenado com Insertion Sort.\n";
    } else {
        std::cout << "Opcao invalida. Ordenacao cancelada.\n";
    }
    espera();
}

// permite ao usuário buscar um valor no vetor
int Buscar() {
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "                BUSCAR VALOR               \n";
    std::cout << "===========================================\n";

    if (vet.empty()) {
        std::cout << "Vetor vazio. Nao ha numeros para buscar.\n";
        espera();
        return 0;
    }

    int tipo;
    std::cout << "Escolha o tipo de pesquisa:\n"
              << "[1] Pesquisa Sequencial\n"
              << "[2] Pesquisa Binaria\n"
              << "Opcao: ";
    std::cin >> tipo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int idBUSCA;
    std::cout << "Digite o valor para busca: ";
    std::cin >> idBUSCA;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipo == 1) { // busca sequencial
        bool encontrado = false;
        for (size_t i = 0; i < vet.size(); i++) {
            if (vet[i] == idBUSCA) {
                std::cout << "Valor " << idBUSCA << " encontrado na posicao " << i << ".\n";
                encontrado = true;
                break; // valor encontrado, não é necessário continuar o loop.
            }
        }
        if (!encontrado) {
            std::cout << "Valor nao encontrado.\n";
        }
    } else if (tipo == 2) { // busca binária

        if (!verificarSeVetorEstaOrdenado(vet)) {
            std::cout << "Para a pesquisa binaria, o vetor precisa estar ordenado.\n"
                      << "Deseja ordenar o vetor agora? (S/N): ";
            char resp;
            std::cin >> resp;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(resp) == 'S') {
                Ordenar(); // chama a função Ordenar principal que escolhe metodo

                if (!verificarSeVetorEstaOrdenado(vet)) { // verifica se a ordenação foi bem sucedida ou cancelada
                    std::cout << "Vetor nao foi ordenado. Pesquisa binaria cancelada.\n";
                    espera();
                    return 0;
                }
            } else {
                std::cout << "Pesquisa binaria cancelada.\n";
                espera();
                return 0;
            }
        }
        // realiza busca binária se o vetor estiver ordenado.
        if (std::binary_search(vet.begin(), vet.end(), idBUSCA)) {

            std::vector<int>::iterator it = std::lower_bound(vet.begin(), vet.end(), idBUSCA);
            int pos = static_cast<int>(it - vet.begin()); // calcula o índice a partir do iterador.
            std::cout << "Valor " << idBUSCA << " encontrado na posicao " << pos << ".\n";
        } else {
            std::cout << "Valor nao encontrado.\n";
        }
    } else {
        std::cout << "Opcao de pesquisa invalida.\n";
    }
    espera();
    return 0;
}

// permite ao usuário remover elementos do vetor por valor ou posição.
void Remover() {
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "              REMOVER VALOR                \n";
    std::cout << "===========================================\n";

    if (vet.empty()) {
        std::cout << "Vetor vazio. Nao ha nada para remover.\n";
        MostrarContagem();
        espera();
        return;
    }

    std::cout << "Conteudo atual do vetor:\n";
    for (size_t i = 0; i < vet.size(); i++) {
        std::cout << "[" << i << "] = " << vet[i] << "\n";
    }
    MostrarContagem();

    int opcao;
    std::cout << "\nEscolha como deseja remover:\n"
              << "[1] Remover por valor\n"
              << "[2] Remover por posicao\n"
              << "Opcao: ";
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcao == 1) { // remover por valor
        int valor;
        std::cout << "Digite o valor a ser removido: ";
        std::cin >> valor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        std::vector<int>::iterator it = std::find(vet.begin(), vet.end(), valor);
        if (it != vet.end()) {
            vet.erase(it); // apaga o elemento encontrado.
            std::cout << "Valor " << valor << " removido com sucesso!\n";
        } else {
            std::cout << "Valor nao encontrado no vetor.\n";
        }
    } else if (opcao == 2) { // remover por posição
        int posicao;
        // garante que vet.size() - 1 não seja negativo se o vetor estiver vazio
        std::cout << "Digite a posicao a ser removida (0 a " << (vet.empty() ? 0 : vet.size() - 1) << "): ";
        std::cin >> posicao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // valida a posição.
        if (posicao >= 0 && posicao < static_cast<int>(vet.size())) {
            int valor_removido = vet[static_cast<size_t>(posicao)]; // acessa o elemento antes de apagar
            vet.erase(vet.begin() + posicao); // apaga o elemento na posição dada.
            std::cout << "Valor " << valor_removido << " na posicao " << posicao << " removido com sucesso!\n";
        } else {
            std::cout << "Posicao invalida.\n";
        }
    } else {
        std::cout << "Opcao invalida!\n";
    }
    MostrarContagem();
    espera();
}

// exibe todos os elementos atualmente no vetor.
void ExibirVetor() {
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "               EXIBIR VETOR                \n";
    std::cout << "===========================================\n";
    if (vet.empty()) {
        std::cout << "Vetor vazio.\n";
    } else {
        std::cout << "Conteudo atual do vetor:\n";
        for (size_t i = 0; i < vet.size(); i++) {
            std::cout << "[" << i << "] = " << vet[i] << "\n";
        }
    }
    MostrarContagem(); // exibe a contagem ao mostrar o vetor
    espera();
}

// função principal
int main() {


    do {
        MostrarMenu();
        std::cin >> op;

        // validação básica de entrada para a escolha do menu.
        if (std::cin.fail()) {
            std::cin.clear(); // limpa o buffer de erro.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida.
            std::cout << "Entrada invalida! Por favor, digite um numero para a opcao.\n";
            espera();
            op = -1;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o newline após entrada válida de inteiro.


        switch (op) {
            case 1: Add(); break;
            case 2: Buscar(); break;
            case 3: Ordenar(); break;
            case 4: Remover(); break;
            case 5: ExibirVetor(); break;
            case 0:
                system("cls");
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida!\n";
                espera();
        }
    } while (op != 0);

    return 0; //
}