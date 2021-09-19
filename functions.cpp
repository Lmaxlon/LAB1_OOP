#include <iostream>
#include "types.h"

namespace lab1{
    line* fillMatrix (int &matr) {
        line *lines = nullptr;
        std::cout << "\nPlease put numbers of lines \n" << std::endl;
        int num = 0; //strings of matrix
        if (getNum(num) < 0 ) {              //!!!!
            std::cout << "\nYou put an EOF or a WRONG DATA in the program, exit... \n" << std::endl;
            return nullptr;
        } while (num < 0);
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
                std::cout << "Enter number of items in line #" << (i + 1) << " --> ";
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
                if (getNum(lines[i].arr[j]) < 0){
                    std::cout << "\nYou put an EOF or a WRONG DATA in the program, exit... \n" << std::endl;
                    del (lines, i+1);
                    return nullptr;
                }
                lines[i].arr[j] = num; //!!!
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