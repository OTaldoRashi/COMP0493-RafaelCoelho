#include "header.h"

// MergeSort

// Função para juntar (merge) duas sub-listas ordenadas de um vetor.
// A primeira sub-lista é arr[left..mid] e a segunda é arr[mid+1..right].

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria vetores temporários para armazenar as sub-listas
    vector<int> L(n1), R(n2);

    // Copia os dados das sub-listas originais para os vetores temporários.
    // Usamos std::copy para otimizar.

    std::copy(arr.begin() + left, arr.begin() + left + n1, L.begin());
    std::copy(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2, R.begin());

    // Índices para percorrer as sub-listas e o vetor original.
    int i = 0, j = 0, k = left;

    // Junta as sub-listas no vetor original arr[left..right]
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes da sub-lista esquerda, se houver.
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes da sub-lista direira, se houver.
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função MergeSort recursiva.
// 'left' é o índice inicial e 'right' é o índice final da sub-lista a ser ordenada.

void mergeSort(vector<int>& arr, int left, int right){

    if(left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


// busca binaria

int buscaBinaria(vector<int> V, int chave){

    int i, j;
    int N = V.size();
    i = 0; j = N-1;

    while(j >= i){
        int meio = floor((i+j)/2.0);

        if(V[meio] == chave)
            return meio;
        
        if(V[meio] > chave){
            j = meio-1;
        }
        else{
            i = meio+1;
        }

    }

    return -1;
}


// Binary Exponentiation

long long power(long long A, long long B){
    long long res = 1;

    while (B > 0) {
        // Se B é ímpar, multiplica o resultado por A
        if (B % 2 == 1) 
            res = res * A;
        
        A = A * A;

        B = B / 2;
    }
    return res;
}

// Inversion Index

// Junta sub-vetores e conta inversões.
int countAndMerge(vector<int>& arr, int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m; // Tamanhos dos sub-vetores.
    vector<int> left(n1), right(n2); // Sub-vetores temporários.

    // Copia dados para os sub-vetores.
    for (int i = 0; i < n1; i++) 
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++) 
        right[j] = arr[m + 1 + j];

    int res = 0, i = 0, j = 0, k = l; // Inicializa contagem e índices.

    // Junta e conta inversões.
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++]; // Sem inversão
        else {
            arr[k++] = right[j++];
            res += (n1 - i); // Inversão! (right[j] < todos os left[i] restantes)
        }
    }

    // Copia os elementos restantes.
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return res; // Retorna o número de inversões encontradas.
}

// Conta inversões recursivamente.
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2; // Ponto médio.

        res += countInv(arr, l, m);         // Inversões na metade esquerda.
        res += countInv(arr, m + 1, r);     // Inversões na metade direita.
        res += countAndMerge(arr, l, m, r); // Inversões entre as metades.
    }
    return res; // Retorna o número total de inversões.
}

// Função principal para contar inversões.
int inversionCount(vector<int>& arr){
    return countInv(arr, 0, arr.size() - 1); // Inicia a contagem.
}





int main(){

    /*
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    printVector(arr);
    mergeSort(arr, 0, n - 1);
    printVector(arr);
    
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << inversionCount(arr);
    */

    return 0;
}