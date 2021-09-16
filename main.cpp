#include <iostream>
#include "types.h"
#include "functions.cpp"
using namespace lab1;

int main(){
    line *arrln= nullptr;
    int num;
    arrln = fillMatrix(num);
    if (!arrln){
        std::cout << "incorrect data" << std::endl;
        return 1;
    }
    printMat(&num);
}