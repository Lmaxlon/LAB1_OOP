namespace std{
    typedef struct line{
        int n; //количество элементов строки
        double *arr;//массив элементов
    } line;

    typedef struct matrix{
        int numLines; //количество строк матрицы
        line *arrln; //массив строк
    } matrix;

    /**
 * @brief Template of function "get numbers"
 *
 * @param prm
 * @return int -1 false, 1 true
 */

    template <class T>
            int getNum(T &prm){
                cin >> prm;
                if(!cin.good()){
                    cout << "You put an invalid data or EOF" << endl;
                    return -1;
                }
                return 1;
            }

            /*---------------functions of compares---------------*/

            inline int getmax (double a, double b){
                return a > b;
            }

            inline int getmin (double a, double b){
                return a < b;
            }

            /*---------------types of functions---------------*/

            void printMat (matrix *mat);
            Line *del(Line *&lines, int m);
            int fillMatrix (matrix *matr);
        }