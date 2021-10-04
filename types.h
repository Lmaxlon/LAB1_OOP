#pragma once
#include <chrono>
#include <thread>
namespace lab1{

    typedef struct line{
        int n; //количество элементов строки
        double *arr;//массив элементов
    } line;

    typedef struct nulles{
        int count;
        double *value;
    } nulles;

/*    typedef struct matrix{
        int numLines; //количество строк матрицы
        line *arrln; //массив строк
    } matrix;*/

    /*---------------types of functions---------------*/

    void printMat (line *a, int m);
    line* del(line *&lines, int m);
    line* fillMatrix (int &matr);
    line* modify (line *&lines, int num);
    nulles* memaverage (int num, line *&lines);
    nulles *delaverage(nulles *&null, int m);

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
                } else if (prm == 0.0){
                    return 2;
                }
                return 1;
            }
}