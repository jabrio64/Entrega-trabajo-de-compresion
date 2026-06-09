
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <fstream>   
#include <sstream>
#include <utility> 
#include <stdexcept> 

namespace leer{
    using namespace std;

    vector<int> leerCSV (string direccion){
        vector<pair<string,vector<int>>> result;
        fstream fin(direccion);
        

        if(!fin.is_open()) throw std::runtime_error("Archivo no pudo ser abierto");

        string linea, nombCol;
        int val;

        if (fin.good()){    
            getline(fin, linea);
            stringstream ss(linea);

            while(getline(ss, nombCol,',')){
                result.push_back({nombCol,vector<int>{}});
            }

        }

        while (getline(fin,linea)){
            stringstream ss(linea);
            int colIdx = 0;
            while (ss >> val){
                result.at(colIdx).second.push_back(val);
                if(ss.peek() == ',') ss.ignore();
                colIdx++;
            }
        }
        fin.close();

        vector <int> a;
        cout << "--------------"<<endl;
        for (int i = 0; i < result.size(); i++){
            for (int j = 0; j < result[i].second.size(); j++){
                
                cout << result[i].second[j] << " , ";
            }
            cout << endl;
        }

        return a;
    }


    
}