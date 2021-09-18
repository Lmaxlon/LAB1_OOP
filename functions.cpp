#include <iostream>
#include "types.h"

namespace lab1{
    line* fillMatrix (int &matr) {
        line *lines = nullptr; // Ȕș
        //      int statusline = -2;
        std::cout << "\nPlease get numbers of lines \n" << std::endl;
        int num = 0; //strings of matrix
        //        statusline = getNum (&num); // попросили количество строк
        if (/*statusline <= 0  && */getNum(num) < 0 ) {              //!!!!
            std::cout << "\nYou put an EOF or a WRONG DATA in the program, exit... \n" << std::endl;
            return nullptr;
        } while (num < 0);
        //ниже выделяем память под строку
        try{
            lines = new line[num];
        }
        catch (std::bad_alloc &ba)
        {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }

        for (int i = 0 ; i < num; ++i ){
            do{
                //              int statusrow = -2;
                std::cout << "Enter number of items in line #" << (i + 1) << " --> ";
                //              int row = 0;
                if (getNum(lines[i].n) < 0) {
                    std::cout << "\nYou put an EOF or a WRONG DATA in the program, exit... \n" << std::endl;
                    del(lines,i);
                    return nullptr;
                }
            } while (lines[i].n < 1);

            try{
                lines[i].arr = new double [lines[i].n];
            }
            catch(std::bad_alloc &ba){
                std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
                del(lines, i);
                return nullptr;
            }

            for (int j = 0; j < lines[i].n; ++j){
                std::cout << "Enter items for matrix line #" << (j + 1) << ":" << std::endl;
                //              double elem = 0;
                //              int statuselem = -2;
                //              statuselem = getNum(&elem);
                if (getNum(lines[i].arr[j]) < 0){
                    std::cout << "\nYou put an EOF or a WRONG DATA in the program, exit... \n" << std::endl;
                    del (lines, i+1);
                    return nullptr;
                }
                //                matr->arrln[i].arr[j] = elem;
                //                printf ("The matrix is valid");
            }
        }
        matr = num;
        return lines;
    }

    line *del(line *&lines, int m)
    {
        int i;
        for (i = 0; i < m; i++)
            delete[] lines[i].arr;
        delete[] lines;
        return nullptr;
    }

    void printMat (line *a, int m) {
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < a[i].n; ++j)
                std::cout << a[i].arr[j] << " ";
            std::cout << std::endl;
        }
    }

    line* modify (line *&lines, int num){
        lines = new line[num];
        int j, i, max, min;
        for (j = 0; j < num; ++j)
        {
            min = 0;
            max = 0;
            for (i = 0; i < lines[j].n; ++i)
            {
                if(lines[j].arr[i] > lines[j].arr[max]) max = i;
                if(lines[j].arr[i] < lines[j].arr[min]) min = i;
            }
            int tmp;
            tmp = lines[j].arr[min];
            lines[j].arr[min] = lines[j].arr[max];
            lines[j].arr[max] = tmp;
        }
        return lines;
    }
}