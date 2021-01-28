#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>

using namespace std;

int main(){
    string cowphabet;
    string heard;
    int iterations = 1;
    vector<int> vals;
    cin >> cowphabet;
    cin >> heard;

    for(int i=0;i<heard.length();i++){
        vals.push_back(cowphabet.find(heard[i]));
        // cout << vals[i] << endl;     

    }

    for(int i=0;i<heard.length();i++){
        // cout << vals[i] << endl;     

        if(i > 0){
            if(vals[i] <= vals[i-1]){
                // cout << vals[i] << endl;
                iterations++;
            }      
        }   
    }
    //     if(i > 0){
    //         // if this letter is later in the alphabet than the previous  
    //         cout << vals[i] << endl;     
    //         // cout << "====="<< endl;     
    //         // cout << vals[i] << endl;     
    //         // cout << vals[i-1] << endl;          
    //         // cout << "====="<< endl;     
    //         // if(vals[i] >= vals[i-1]){
    //         //     iterations++;
    //         // }
    //     }
    // }
    cout << iterations << endl;


    return 0;
}