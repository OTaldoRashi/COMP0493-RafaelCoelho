#include <iostream>
#include <sstream>

// Caso 1:
//  a) The number of test cases is given in the first line of the input.

int readFirstLine(){
    int N;
    std::cin >> N;
    return N;
}

void readCaseA(){
    int casos = readFirstLine();

    for(int i=0; i<casos; i++){ // lê e executa N vezes
        int A, B;
        std::cin >> A >> B;

        std::cout << (A+B) << '\n';
    }

}

//  b) The multiple test cases are terminated by special values (usually zeroes).

void readCaseB(){
    int A, B;

    while((std::cin >> A >> B) && (A || B)){ // lê enquanto A e B são diferentes de zero

        std::cout << (A+B) << '\n';
    }

}

//  c) The multiple test cases are terminated by the EOF (end-of-file) signal.

void readCaseC(){
    int A, B;

    while(std::cin >> A >> B){ // lê enquanto há input ou !EOF

        std::cout << (A+B) << '\n';
    }

}

// Caso 2: Case Numbers and Blank Line

//  d) “Case [NUMBER]: [ANSWER]” followed by a blank line for each test case.

void readCaseD(){
    int A, B;
    int C = 0;

    while(std::cin >> A >> B){ // lê enquanto há input ou !EOF
        // contamos os casos

        std::cout << "Caso " << ++C << ": " << (A+B) << "\n\n";
    }

}

//  e)  Print blank lines only between test cases. If we use the approach above,
//      we will end up with an extra new line at the end of our output,
//      producing unnecessary ‘Presentation Error’ (PE) verdict.

void readCaseE(){
    int A, B;
    int C = 0;

    while(std::cin >> A >> B){ // lê enquanto há input ou !EOF
        // contamos os casos
        if(C > 0) std::cout << '\n';

        std::cout << "Caso " << ++C << ": " << (A+B) << '\n';
    }

}


// Caso 3: Variable Number of Inputs

//       For each test case (each input line), we are
//       now given an integer k (k ≥ 1), followed by k integers.

// ex:  1 1 
//      2 3 4
//      3 8 1 1

void readCaseF(){
    int k;

    while(std::cin >> k){ // lê k numeros a seguir
        int ans = 0, v;

        while(k--){
            std::cin >> v;
            ans += v;
        }

        std::cout << ans << '\n';
    }

}

// The input routine can be a little bit more problematic if we are not given the convenient
// integer k at the beginning of each test case/line. To perform the same task, assuming k >= 1
// and two integers in the same line are separated by exactly one space, we now need to read
// in pairs of an integer and a character and detect the end-of-line signal (EOLN).


void readCaseG(){

    std::string line;

    while(std::getline(std::cin, line)) { // le a linha toda
        std::stringstream ss(line); // cria uma 'stream'

        int ans = 0, v;
        //char dummy;

        while(ss >> v) { 
            ans += v;
            //ss >> dummy;
        }

        std::cout << ans << '\n';
    }
}


int main(){

    //readCaseA();
    //readCaseB();
    //readCaseC();
    //readCaseD();
    //readCaseE();
    //readCaseF();
    readCaseG();

    return 0;
}
