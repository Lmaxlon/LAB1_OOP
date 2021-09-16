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
    std::cout << "Matrix:" << std::endl;
    printMat(arrln, num);
    del(arrln, num);
}