// Algoritmos gulosos famosos
#include "header.h"

// problema da mochila fracionária

// Estrutura para um item
struct Item{
    int profit, weight;

    // Construtor
    Item(int profit, int weight) : profit(profit), weight(weight) {} // Construtor com inicialização
};

// Função de comparação para ordenar por razão lucro/peso
bool cmp(const Item& a, const Item& b){
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;

    return r1 > r2; // Ordena em ordem decrescente de razão
}

// Função principal
double fractionalKnapsack(int W, vector<Item>& arr){
    int N = arr.size();

    // Ordena os itens por razão lucro/peso.
    std::sort(arr.begin(), arr.end(), cmp); // Usamos std::sort

    double finalvalue = 0.0; // Lucro total

    // Itera sobre os itens ordenados
    for(int i = 0; i < N; i++){

        // Se o item couber completamente na mochila
        if (arr[i].weight <= W) {
            W -= arr[i].weight; // Reduz a capacidade da mochila.
            finalvalue += arr[i].profit; // Adiciona o lucro.
        }
        // Senão
        else {
            // Adiciona uma fração do item.
            finalvalue += arr[i].profit * ((double)W / arr[i].weight);
            break; // A mochila está cheia
        }
    }

    return finalvalue; // Retorna o lucro total.
}


// Problema do troco

// Função para encontrar a menor quantidade de cédulas para o troco.
void findMin(int V){

    vector<int> denomination = {1, 2, 5, 10, 20, 50, 100, 200};

    // Ordena as cédulas em ordem crescente (necessário para o algoritmo guloso)
    std::sort(denomination.begin(), denomination.end());

    vector<int> ans; // Vetor para armazenar as cédulas do troco.

    // Itera sobre as cédulas em ordem decrescente (do maior para o menor)
    for(int i = denomination.size() - 1; i >= 0; --i){

        // Enquanto a cédula atual puder ser usada
        while(V >= denomination[i]){
            V -= denomination[i];            // Subtrai o valor da cédula do troco.
            ans.push_back(denomination[i]);  // Adiciona a cédula ao troco.
        }
    }

    for (unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}
