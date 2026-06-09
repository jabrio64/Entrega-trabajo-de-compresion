#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>   

namespace gaps{
    using namespace std;
    vector<int> genGapArr(vector<int> og, int tam){     //genera los gaps entre cada valor
        vector<int> gaps;
        gaps.push_back(og[0]);
        for (int i=1; i<tam; i++){
            gaps.push_back (og[i] - og[i-1]);
        }
        return gaps;
    }

    vector<int> genSamples(vector<int> og, int tam){    //genera samples del arreglo mara facilitar la busqueda
        vector<int> samples;
        int m = ceil(log(tam)/log(3));
        int act = 0;
        int adv = floor(tam/m);
        while (act <= tam){
            samples.push_back(og[act]);
            act = act+adv;
        }
        samples.push_back(adv);     //ultimo espacio contiene el tamaño de cada salto
        return samples;
    }



}