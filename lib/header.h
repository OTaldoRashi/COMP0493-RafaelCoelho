#ifndef HEADER_H
#define HEADER_H

#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

// IO Cases
int readFirstLine();
void readCaseA();
void readCaseB();
void readCaseC();
void readCaseD();
void readCaseE();
void readCaseF();
void readCaseG();

// Geometry
class Ponto;
class Reta;
double distPontos(Ponto A, Ponto B);
double distPontoReta(Ponto P, Reta R);

// linearSorting
vector<int> countSort(vector<int>& inputArray);
void bucketSort(vector<float>& arr);
void radixsort(vector<int>& V);

// greedy
struct Item;
double fractionalKnapsack(int W, vector<Item>& arr);
void findMin(int V);

// div and conquer
void mergeSort(vector<int>& arr, int left, int right);
int buscaBinaria(vector<int> V, int chave);
long long power(long long A, long long B);
int inversionCount(vector<int>& arr);




#endif