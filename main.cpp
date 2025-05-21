#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

// armazenar dados do aluno
struct Aluno {
    int matricula;
    std::string nome;
    float media;
    bool aprovado;
};

// tamanho do vetor
const int TAMANHO_VETOR = 50;

Aluno alunos[TAMANHO_VETOR];
int quantidadeAlunos = 0;      // quantidade de alunos

void AdicionarAluno() {
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "                 PROGRAMA                 \n";
    std::cout << "===========================================\n";

    if (quantidadeAlunos >= TAMANHO_VETOR) {
        std::cout << "Quantidade máxima alcançada!\n";
        return;
    }

    // variáveis temporárias para entrada
    int matricula;
    std::string nome;
    float media;

    // ler nome (inclui espaços)
    std::cout << "Digite o nome do aluno: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nome);

    // ler matrícula
    std::cout << "Digite a matricula do aluno: ";
    std::cin >> matricula;

    // ler média
    std::cout << "Digite a media do aluno: ";
    std::cin >> media;

    // preencher o registro no vetor
    alunos[quantidadeAlunos].matricula = matricula;
    alunos[quantidadeAlunos].nome      = nome;
    alunos[quantidadeAlunos].media     = media;
    alunos[quantidadeAlunos].aprovado  = (media >= 7.0f);

    quantidadeAlunos++;
    std::cout << "Aluno adicionado com sucesso!\n";
}

// stubs para eliminar erro de link edição
void Buscar() {
    system("cls");
    std::cout << "[BUSCAR] Função ainda não implementada.\n";
}

void Ordenar() {
    system("cls");
    std::cout << "[ORDENAR] Função ainda não implementada.\n";
}

void Remover() {
    system("cls");
    std::cout << "[REMOVER] Função ainda não implementada.\n";
}

void ExibirVetor() {
    system("cls");
    std::cout << "[EXIBIR VETOR] Função ainda não implementada.\n";
}

// Função para mostrar o menu
void MostrarMenu(){
    system("cls");
    std::cout << "===========================================\n";
    std::cout << "                 PROGRAMA                 \n";
    std::cout << "===========================================\n";
    std::cout << "[1] ADICIONAR ALUNO\n"
              << "[2] BUSCAR\n"
              << "[3] ORDENAR\n"
              << "[4] REMOVER\n"
              << "[5] EXIBIR VETOR\n"
              << "[0] SAIR\n";
    std::cout << "===========================================\n";
    std::cout << "OPCAO: ";
}

int main() {
    int opc;
    do {
        MostrarMenu();
        std::cin >> opc;
        switch (opc) {
            case 1: AdicionarAluno();   break;
            case 2: Buscar();           break;
            case 3: Ordenar();          break;
            case 4: Remover();          break;
            case 5: ExibirVetor();      break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opcao invalida!\n";
        }
        std::cout << "Pressione ENTER para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    } while (opc != 0);

    return 0;
}
