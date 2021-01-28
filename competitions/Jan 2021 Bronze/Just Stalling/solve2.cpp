#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>
#include <stdint.h>


using namespace std;



int main(){


    int N; //number of cows and stalls
    vector<int> cows; // cow heights
    vector<int> stalls; // stall heights
    vector<vector<int> > all_combs;
    // long long count = 0; // total number of combinations
    int c=0;
    cin >> N;
    for(int i=0;i<N;i++){
        int val;
        cin >> val;
        cows.push_back(val);
    }
    for(int i=0;i<N;i++){
        int val;
        cin >> val;
        stalls.push_back(val);
    }



    // sort(cows.begin(),cows.end());

    do {
        bool works = true;
        for(int j=0;j<cows.size();j++){
            // cout << cow;
                // cout << stall;
                if(cows[j] > stalls[j]){
                    // cout << "does not work" << endl;
                    works = false;
                }
        }
        // cout << endl;
        if(works){
            c++;
        }
    } while ( next_permutation(cows.begin(),cows.end()));


    // int times =0;
    // while(times < N){
    //     times++;
    //     next_permutation(cows.begin(),cows.end());
    //     bool works = true;
    //     for(int j=0;j<cows.size();j++){
    //         // cout << cow;
    //             // cout << stall;
    //             if(cows[j] > stalls[j]){
    //                 // cout << "does not work" << endl;
    //                 works = false;
    //             }
    //     }
    //     // cout << endl;
    //     if(works){
    //         count++;
    //     }
    // }

    cout << c << endl;

    // for(int i=0;i<N!;i++){

    //     // for(int j=0;j<N;j++){
            

    //     // }
    // }



    return 0;
}