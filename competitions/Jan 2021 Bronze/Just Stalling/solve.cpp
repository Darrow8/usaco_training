#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>
#include <stdint.h>


using namespace std;



int factorial(int n)
{
    return n * factorial(n - 1);
}

int main(){
    int N; //number of cows and stalls
    vector<int32_t> cows; // cow heights
    vector<int32_t> stalls; // stall heights
    vector<vector<int> > cow_blocks; // stalls that a cow cannot go in
    long long count; // total number of combinations
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

    for(int i=0;i<N;i++){
            vector<int> cows_call; // array of all stalls don't work for cow[i]
            for(int j=0;j<N;j++){
                if(cows[i] >= stalls[j]){
                    //this cow does not fit
                    // cow_blocks.push_back(stalls[j]);
                    cows_call.push_back(j);
                }
            }
            cow_blocks.push_back(cows_call);
    }

    // initialize total possible count
    count = factorial(N);

    // subtract first pick
    for(int i=0;i<N;i++){
        if(!cow_blocks[i].empty()){
            // this cow has stalls it cannot get in
            int tottootall= cow_blocks[i].size()*factorial(N-1); // the total number ideally
            // deal with overlap
            // see if the removals before us have overlapped us
            for(int k=0;k<N-i;k++){
                // the cows before
                if(!cow_blocks[k].empty()){
                    /**
                     * We have 2 sets, our current cow's stalls and the previous cow's stalls
                     * stalls meaning the ones they cannot get into
                     * we need to determine if those stalls are overlapping
                    */    
                        for(int a=0;a<N-i;a++){
                            for(int b=0;b<N-i;b++){
                            
                            }
                        }


                }
            }

            for(int j=0;j<cow_blocks[i].size();i++){
                // go through the ones it cannot go to
                
            }
        }
    }


    // cout << "cows" << endl;
    // for(int cow: cows){
    //     cout << cow << endl;
    // }

    // cout << "stalls" << endl;
    // for(int stall: stalls){
    //     cout << stall << endl;
    // }









    return 0;
}