#include <iostream>
#include "types.h"
#include "functions.cpp"
using namespace lab1;

int main(){
    line *arrln= nullptr;
    int num;
    arrln = fillMatrix(num);
    if (!arrln){
        std::cout << "ERROR: I can't see your data in a matrix, please don't complete a process or put only numbers" << std::endl;
        return 1;
    }
    line *arrln2= nullptr;
    arrln2 = new line[num];
    modify(arrln2, num);

    std::cout << "Sourced matrix:" << std::endl;
    printMat(arrln, num);
    std::cout << "New matrix:" << std::endl;
    printMat(arrln2, num);
    del(arrln, num);
    delete[] arrln2;
    arrln2 = nullptr;
}