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

    /*---------------types of functions---------------*/

    void printMat (line *a, int m);
    line* del(line *&lines, int m);
    line* fillMatrix (int &matr);
    line* modify (line *&lines, int num);
    line* zeromemory (line *&lines, int num);

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

 /*           template <class T>
            double memory(T &lines, T &num){
                //----новое выделение памяти для копирования в новый массив без чисел после максимума----//
                line *newlines = nullptr;
                int newnum = 0;
                newnum = num;
                try{
                    newlines = new line[newnum];
                }
                catch (std::bad_alloc &ba)
                {
                    return lines;
                }

                for (int j = 0; j < num; ++j){
                    try{
                        newlines[j].arr = new double [newlines[j].n];
                    }
                    catch(std::bad_alloc &ba){
                        del(newlines, j);
                        return lines;
                    }
                    for (int i = 0; j < newlines[j].n; ++i){
                        newlines[j].arr[i] = lines[j].arr[i];
                        double a = newlines[j].arr[i];
                        return a;
                    }
                }
                //^---новое выделение памяти для копирования в новый массив без чисел после максимума---^//
               return newlines;
            }*/
}