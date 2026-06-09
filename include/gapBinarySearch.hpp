#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>   

namespace gBS{
    using namespace std;

    bool gapBinarySearch(vector<int> gaps, vector<int> samples, int k){
        int adv = samples.back();
        int low = 0;
        int high = samples.size() - 2;
        int mid;
        while (low < high) {
            mid = low + ((high - low) / 2);
            if(samples[mid]==k){
                return true;
            }
            if (samples[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        int value = samples[mid];
        int pos = mid*adv;
        int lim;
        if(k>value){
            lim = pos + adv;
            while (!(value>k)){
                pos++;
                value = value + gaps[pos];
                if(value == k){
                    return true;
                }
            }
        }
        else{
            lim = pos- adv;
            while (!(value<k)){
                pos--;
                value = value - gaps[pos];
                if(value == k){
                    return true;
                }
            }
        }
        return false;
    }

}