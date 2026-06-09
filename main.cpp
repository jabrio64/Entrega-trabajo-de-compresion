#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <cstring>
#include <math.h>   
#include "include/explicita.hpp"
#include "include/gaps.hpp"
#include "include/gapBinarySearch.hpp"
#include <bits/stdc++.h>
#include "include/leerArchivo.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){

    
    
    if (argc < 2 || argc > 4) 
        cout << "Usage: ./main <input_file> <output_file>" << endl;
    if (argc == 2 && strncmp(argv[1], "--benchmark", 11) == 0) {    // generar valores al azar
        cout << "Benchmark mode" << endl;
        cout << "args: " << argv[1] << endl;

// --------------------------------------------------------------------------------------------------------

        auto tgenerar1 = chrono::high_resolution_clock::now();

        vector<int> arreglo = gen::genArray(pow(2,25));
        int tam = arreglo.size();

        auto tgenerar2 = chrono::high_resolution_clock::now();
        
        auto tgenerar = tgenerar2 - tgenerar1;
  
// --------------------------------------------------------------------------------------------------------

        int ini = arreglo[0];   
        int hasta = arreglo.back() - ini;
        int encontrados = 0;
        int k;


        auto tbuscar1 = chrono::high_resolution_clock::now();

        for(int i = 0; i < 20000; i++){
            k = ini + rand()%hasta;
            if (binary_search(arreglo.begin(),arreglo.end(), k)){
                cout << "elemento " << k << " encontrado" << endl;
                encontrados++;
            }
            else{
                cout << "no se encontro el elemento " << k << endl;
            }
        }

        auto tbuscar2 = chrono::high_resolution_clock::now();

        auto tbuscar = tbuscar2 - tbuscar1;

// --------------------------------------------------------------------------------------------------------


        auto tgenerarGapsSamp1 = chrono::high_resolution_clock::now();

        vector<int> gaps = gaps :: genGapArr(arreglo, tam);
        vector<int> samples = gaps :: genSamples(arreglo, tam);

        auto tgenerarGapsSamp2 = chrono::high_resolution_clock::now();
        
        auto tgenerarGapsSamp = tgenerarGapsSamp2 - tgenerarGapsSamp1;

// --------------------------------------------------------------------------------------------------------

        int encontradosGaps = 0;

        auto tbuscarGap1 = chrono::high_resolution_clock::now();

        for (int j = 0; j < 500; j++){
            k = ini + rand()%hasta;
            if(gBS :: gapBinarySearch(gaps,samples, k)){
                cout << "elemento " << k << " encontrado" << endl;
                encontradosGaps++;
            }
            else{
                cout << "no se encontro el elemento " << k << endl;
            }

        }

        auto tbuscarGap2 = chrono::high_resolution_clock::now();

        auto tbuscarGap = tbuscarGap2 - tbuscarGap1;

// --------------------------------------------------------------------------------------------------------



        cout <<"Tiempo en generar el vector:" << tgenerar.count()<< " ms" << endl;
        cout <<"Tiempo en ejecutar la busqueda binaria de 20000 elementos: " << tbuscar.count() << "ms" << endl;
        cout <<"Tiemp en generar el vector de gaps y samples:" << tgenerarGapsSamp.count()<< " ms" << endl;
        cout <<"Tiempo en ejecutar la busqueda binaria con gaps y samples de 500 elementos: " << tbuscarGap.count() << "ms" << endl;

    } 
    
    if(argc == 3 && strncmp(argv[1],"-i",2) == 0){  // Trabajar con un CSV entregado por el usuario
        string ruta = argv[2];
        vector<int> aa = leer :: leerCSV(ruta);
    }

    else if (argc == 4) {
        cout << "Complete mode" << endl;
        cout <<"args: " << argv[1] << " " << argv[2] << endl;
    }


    return 0;
}
