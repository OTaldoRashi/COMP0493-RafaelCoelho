// algoritmos de ordenação O(n)
#include "header.h"


// CoutingSort

vector<int> countSort(vector<int>& inputArray){

    int N = inputArray.size();

    // Encontra o valor máximo
    int maiorValor = 0;
    for (int valor : inputArray) {
        maiorValor = max(maiorValor, valor);
    }

    // Cria o vetor de contagem (countArray)
    vector<int> countArray(maiorValor + 1, 0);

    // Contagem de ocorrências.
    for (int valor : inputArray) {
        countArray[valor]++;
    }

    // Calcula a soma acumulada (prefix sum).
    for (int i = 1; i <= maiorValor; ++i) {
        countArray[i] += countArray[i - 1];
    }

    // Cria o vetor de saída (outputArray)
    vector<int> outputArray(N);

    // Constrói o vetor ordenado (estável)
    for (int i = N - 1; i >= 0; --i) {
        int valor = inputArray[i];
        outputArray[countArray[valor] - 1] = valor;
        countArray[valor]--;
    }

    return outputArray;
}


// BucketSort


// Insertion sort para ordenar os buckets.
void insertionSort(vector<float>& bucket){

    for(unsigned int i = 1; i < bucket.size(); ++i){
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

// Função Bucket Sort.
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Cria n buckets vazios (vetores)
    std::vector<std::vector<float>> buckets(n); // vector de vectors

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Calcula o índice do bucket.

        // Garante que o índice não ultrapasse os limites
        if (bucketIndex >= n)
            bucketIndex = n - 1;
        
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Ordena cada bucket individualmente
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]); // Ordena cada bucket (insertion garante estabilidade)
    }

    // Concatena os buckets de volta no vetor original.
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(float valor : buckets[i]){
            arr[index++] = valor; // Preenche o vetor original.
        }
    }
}

// RadixSort

// Função para obter o valor máximo em um vetor.
int getMax(const vector<int>& V) { // Recebe um const vector
    int mx = V[0];

    for(size_t i = 1; i < V.size(); ++i){ // Usamos size_t para o índice
        if(V[i] > mx)
            mx = V[i];

    }
    return mx;
}

// Função countSort
void countSort(vector<int>& V, int exp){
    int n = V.size();

    // Vetor de saída
    vector<int> output(n);
    vector<int> count(10, 0); // Inicializado com zeros.

    // Contagem de ocorrências.
    for(int i = 0; i < n; i++){
        count[(V[i] / exp) % 10]++;
    }

    // Ajusta count[] para indicar as posições.
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Constrói o vetor de saída.
    for(int i = n - 1; i >= 0; i--){
        output[count[(V[i] / exp) % 10] - 1] = V[i];
        count[(V[i] / exp) % 10]--;
    }

    // Copia o vetor de saída de volta para V.
    for(int i = 0; i < n; i++) {
        V[i] = output[i]; // Copia o vetor ordenado de volta para V
    }
}

// Função Radix Sort
void radixsort(vector<int>& V){

    // Encontra o valor máximo para saber o número de dígitos.
    int m = getMax(V);

    // Aplica o counting sort para cada dígito.
    for(int exp = 1; m / exp > 0; exp *= 10){
        countSort(V, exp);
    }
}

