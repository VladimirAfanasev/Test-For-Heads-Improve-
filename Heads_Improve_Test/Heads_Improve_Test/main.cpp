//
//  main.cpp
//  Heads_Improve_Test
//
//  Created by Владимир Афанасьев on 21.02.2021.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> GenAndSort(int n){
    
    vector<vector<int>> VectorOfVectors;

    vector<int> Sizes(n);
    
    int flag=0;
    for(int i = 0;i<n;i++){
        Sizes [i]=rand()%100;
        for(int j = 0;j<i;j++){
            if (Sizes[j]==Sizes[i]) flag=flag+1;
        }
    }
    while (flag>0){
        //Устранение одинаковых размеров
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;i++){
                if (Sizes[i]==Sizes[j]) {
                    Sizes[i]=rand()%100;
                    flag=flag-1;
                }
            }
        }
        //Проверка на наличие новых одинаковых размеров
        for(int i = 0;i<n;i++){
            Sizes [i]=rand();
            for(int j = 0;j<i;j++){
                if (Sizes[i]==Sizes[j]) flag=flag+1;
            }
        }
    }
    
    vector<int> CurVector;
    for(int i = 0;i<n;i++){
        for (int j=0;j < Sizes[i];j++){
            CurVector.push_back(rand());
        }
        if (i%2==0) {
            sort(CurVector.begin(),CurVector.end());
        }
        else{
            sort(CurVector.begin(),CurVector.end(),greater<int>());
            
        }
        VectorOfVectors.push_back(CurVector);
    }
   
        
    return VectorOfVectors;
}



int main(){
    
    vector<vector<int>>Vec = GenAndSort(10);
    
    return 0;
}
