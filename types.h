#pragma once

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

    void printMat (matrix *mat);
    line* del(line *&lines, int m);
    line* fillMatrix (int *matr);

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
                    return -1;
                }
                return 1;
            }
}