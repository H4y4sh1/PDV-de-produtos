#include <iostream>
#include <string>

struct Produto {
    std::string nome;
    double preco;
    int quantidade;
};

double calcularTotal(const Produto produtos[], int numProdutos) {
    double total = 0.0;
    
    for (int i = 0; i < numProdutos; i++) {
        total += produtos[i].preco * produtos[i].quantidade;
    }
    
    return total;
}

int main() {
    const int maxProdutos = 100;
    Produto produtos[maxProdutos];
    int numProdutos = 0;

    while (true) {
        // Registro de produtos
        std::cout << "Nome do produto (ou 'sair' para encerrar): ";
        std::string nomeProduto;
        std::cin >> nomeProduto;

        if (nomeProduto == "sair") {
            break;
        }

        produtos[numProdutos].nome = nomeProduto;

        std::cout << "Preco do produto: ";
        std::cin >> produtos[numProdutos].preco;

        std::cout << "Quantidade: ";
        std::cin >> produtos[numProdutos].quantidade;

        numProdutos++;
    }

    // Calcula o total da compra
    double total = calcularTotal(produtos, numProdutos);

    // Exibe o recibo
    std::cout << "\nRecibo:\n";
    for (int i = 0; i < numProdutos; i++) {
        std::cout << produtos[i].nome << " - Preco: " << produtos[i].preco << " - Quantidade: " << produtos[i].quantidade << "\n";
    }

    std::cout << "Total: " << total << "\n";

    return 0;
}
