#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>   
#include <queue>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <bitset>

namespace hE{

    using namespace std;


    class Node {
        public:
            int data;  
            int index;
            int salto;  
            Node *left, *right;
            Node(int d, int i, int g) {
                data = d;
                index = i;
                salto = g;
                left = right = nullptr;
            }
            Node(Node* l, Node* r) {
                data = l->data + r->data;
                index = min(l->index, r->index); 
                left = l;
                right = r;
            }
    };


    class Compare {
        public:
            bool operator() (Node* a, Node* b) {
                if (a->data != b->data)
                    return a->data > b->data;  
                return a->index > b->index;    
            }
    };


    void preOrder(Node* root, vector<pair<string,int>> &ans, string curr) {
        if (root == nullptr) return;

        // Leaf node represents a character.
        if (root->left == nullptr && root->right == nullptr) {
            // single character case
            if (curr == "") curr = "0"; 
            
            pair<string,int> b = {curr , root->salto} ;
            ans.push_back(b);
            return;
        }

        preOrder(root->left, ans, curr + '0');
        preOrder(root->right, ans, curr + '1');
    }



    pair<vector<pair<string,int>>, Node*> huffmanCodes(vector<vector<int>> freq) {
        
        int n = freq.size();
        
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (int i = 0; i < n; i++) {
            // include index
            Node* tmp = new Node(freq[i][1], i,freq[i][0]); 
            pq.push(tmp);
        }
        if (n == 1){
            vector<pair<string, int>> a = {{"0", 0}};
            Node* b = new Node(1,1,0);
            return {a,b};
        }
        while (pq.size() >= 2) {
            
            // Left node
            Node* l = pq.top();
            pq.pop();
            
            // Right node
            Node* r = pq.top();
            pq.pop();
            
            // internal node with freq + index   
            Node* newNode = new Node(l, r); 
            pq.push(newNode);
        }

        Node* root = pq.top();
        vector<pair<string,int>> ans;
        preOrder(root, ans, "");
        return {ans,root};  //devolver vector con los saltos y sus codigos + arbol 
    }

//---------------------------------------------------------------------------------
    void merge(vector<vector<int>>& arr, int left, int mid, int right){
                            
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<vector<int>> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i][1] <= R[j][1]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<vector<int>>& arr, int left, int right){
    
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

//---------------------------------------------------------------------------------

    vector<vector<int>> cont(vector<int> arreglo){
        vector<vector<int>> salida;
        salida.push_back({0,0});    // primer valor = tamaño del salto, segundo valor = frecuencia en que aparece
        int tam = arreglo.size();
        int reco, j;
        bool cont;
        for(int i = 1; i< tam ; i++){
            reco = salida.size();
            cont = true;
            j = 0;
            while((j<reco)&&(cont)){    // revisar si el valor existe en el arreglo de frecuencias, si existe, sumar +1 a las frecuencias
                if(arreglo[i] == salida[j][0]){
                    salida[j][1] == salida[j][1] + 1;
                    cont = false;
                }
                j++;
            }
            if (!cont){ // si no existe, agregar un nuevo valor
                salida.push_back({arreglo[i],1});
            }
        }
        mergeSort(salida,0,reco);
        reverse(salida.begin(),salida.end());

        return salida;
    }


}