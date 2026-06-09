#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>   



namespace gen{
    using namespace std;
    vector <int> genArray(int n){
        cout<< "inicio" << endl;
        vector <int> arre;
        arre.push_back(rand()%100000);
        for (int i = 1; i<n; i++){
            arre.push_back(arre[i-1] + rand()%50000);   
        }
        return arre;
    }

}

