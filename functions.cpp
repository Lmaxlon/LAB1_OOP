#include <iostream>
#include <memory.h>
#include "types.h"
#include <vector>
#include <algorithm>


namespace lab1{
    line* fillMatrix (int &matr) {
        line *lines = nullptr;
        std::cout << "\nPlease get numbers of lines \n" << std::endl;
        int num = 0; //strings of matrix
        int ptr = 0;
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
                }else{
                    nulles *null= nullptr;
                    null = memaverage(num, lines);
                    std::cout << null << std::endl;
                    delaverage(null, num);
                }
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

    nulles *delaverage(nulles *&null, int m){
        int i;
        for (i = 0; i < m; i++)
            delete[] null[i].value;
        delete[] null;
        return nullptr;
    }

    void printMat (line *a, int m) {
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < a[i].n; ++j){
                std::cout << a[i].arr[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    line* modify (line *&lines, int num){
        int j, i, max;
        for (j = 0; j < num; ++j){
            max = 0;
            for (i = 0; i < lines[j].n; ++i){
                if(lines[j].arr[i] > lines[j].arr[max]) max = i;      //сохраняем максимум
            }
        }
        int del_numbers = 0;
        for (j = 0; j < num; ++j){
            for(i = max+1; i < lines[j].n; ++i){
                lines[j].arr[i] = 0.0;          //обнуляем числа после максимума
                del_numbers++;
            }
        }
        int zero_numbers = 0;
       for (j = 0; j < num; ++j){
           for (i = max+1; i < lines[j].n; ++i){
               if(lines[j].arr[lines->n-1] == 0){    //здесь под вопросом присутствие нуля!
                   lines[j].n--; //удаляем последний ноль если он остался после чистки
               if(lines[j].arr[i] == 0.0){
                   zero_numbers = zero_numbers +1;  //счетчик нулей (перед и после максимума
                   lines[j].n--;  //удаляем нулевые элементы после максимального
                   }
               }
           }
       }
       std::cout << "Removed items including zero after the maximum------->"<< zero_numbers << std::endl;
       std::cout << "Total number of items removed------->" << del_numbers << std::endl;
        return lines;
    }
//если элемент равен ноль
//заносим в новый массив
//иначе
//сохраняем индекс в обычный доп массив
    nulles* memaverage (int num, line *&lines) {
        nulles *null = nullptr;
        null = new nulles[num];
        for (int i = 0 ; i < num; ++i ){
            null[i].value = new double [null[i].count];
            for (int j = 0; j < null[i].count; ++j){
                if(lines[i].arr[j] == 0.0){
                    double index = j;
                } else if(lines[i].arr[j] != 0.0){
                    null->value = lines->arr;
                    null->count = lines->n;
                }
            }
        }
        return null;
    }
}
