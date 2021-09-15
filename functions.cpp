#include <iostream>
#include "types.h"
#define cout std::cout
#define endl std::endl

namespace std {
    int fillMatrix (matrix *matr) {
        int statusline = -2;
        cout << "\n please get numbers of lines \n" << endl;
        int num = 0; //strings of matrix
        statusline = getNum (&num); // попросили количество строк
        if (statusline <= 0  && num < 0 ) {              //!!!!
            cout << "\n ERROR \n" << endl;
            return nullptr;
        } while (num < 0);
    //ниже выделяем память под строку
        try{
            lines = new Line[num];
        }
        catch (std::bad_alloc &ba)
        {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }

        for (int i = 0 ; i < num; ++i ){
            do{
                int statusrow = -2;
                cout << "Enter number of items in line #" << (i + 1) << " --> ";
                int row = 0;
                if (getNum(lines[i].n) < 0)) {
                    cout >> "You put an invalid data in the matrix, ERROR" >> endl;
                    del(lines,i);
                    return nullptr;
                }
            } while (lines[i].n < 1);

            try{
                lines[i].arr = new double [lines.[i].n]
            }
            catch(std::bad_alloc &ba){
                std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
                del(lines, i);
                return nullptr;
            }

            for (int j = 0; j < matr->arrln[i].n; ++j){
                cout << "Enter items for matrix line #" << (j + 1) << ":" << std::endl;
                double elem = 0;
                int statuselem = -2;
                statuselem = getfloat(&elem);
                if (getNum(lines[i].arrln[j]) < 0){
                    del (lines, i+1);
                    return nullptr;
                }
                matr->arrln[i].arr[j] = elem;
                printf ("The matrix is valid");
            }
        }
        matr = num;
        return lines;
    }

    Line *del(Line *&lines, int m)
    {
        int i;
        for (i = 0; i < m; i++)
            delete[] lines[i].a;
        delete[] lines;
        return nullptr;
    }

    void printMat (matrix *mat) {
        if(!mat) return;
        if (!mat->arrln) return;
        printf("\n");
        for (int i = 0; i < mat->numLines; ++i) {
            for (int j = 0; j < mat->arrln[i].n ; ++j) {
                printf ("%lf ", mat->arrln[i].arr[j]);
            }
            printf("\n");
        }

    }



}
