#pragma once
#include <chrono>
#include <thread>
namespace lab1{

    typedef struct line{
        int n; //количество элементов строки
        double *arr;//массив элементов
    } line;

/*    typedef struct matrix{
        int numLines; //количество строк матрицы
        line *arrln; //массив строк
    } matrix;*/


    /*---------------functions of compares---------------*/

    inline int getmax (double a, double b){
        return a > b;
    }

    inline int getmin (double a, double b){
        return a < b;
    }

    /*---------------types of functions---------------*/

    void printMat (line *a, int m);
    line* del(line *&lines, int m);
    line* fillMatrix (int *matr);
    double minormax(double a[], int m, int (*f)(double, double));

    /**
 * @brief Template of function "get numbers"
 *
 * @param prm
 * @return int -1 false, 1 true
 */

    template <class T>
            int getNum(T &prm){
                std::cin >> prm;
                if(!std::cin.good()){
                    std::cout << "The diagnostic program called!" << std::endl;
                    for (int i = 0; i < 29; ++i){
                        std::cout << "-" << std::flush ;
                        std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    }
                    return -1;
                }
                return 1;
            }
}