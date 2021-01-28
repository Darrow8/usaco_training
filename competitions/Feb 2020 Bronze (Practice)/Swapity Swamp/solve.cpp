#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <array>
#include <vector>

using namespace std;

int N, K; // N is number of cows, K is number of times to swap
int A1, A2; // reversal 1
int B1, B2; // reversal 2


int main(){
    freopen("swap.in", "r", stdin);
    scanf("%d %d", &N, &K);
    scanf("%d %d", &A1, &A2);
    scanf("%d %d", &B1, &B2);
    // convert to array format
    A1--;
    B1--;
    A2--;
    B2--;


    // initialize the list
    int cowList[101] = {0};

    // list of lists
    int cowListList[K][101];
    bool stop = false;
    // for if there is a pattern
    int lengthOfPattern;
    int startOfPattern;
    for(int i=0;i<N;i++){
        cowList[i] = i+1;
    }
    freopen("swap.out", "w", stdout);
        // add first one (123456...)
        for(int j=0;j<N;j++){
            cowListList[0][j] = cowList[j];
            cout << "cowListList " << cowListList[0][j] << endl;
        }

        for(int l=1;l<K;l++){
            cout << "GOING!" << endl;
            // reverse A
            int cowList2[101] = {0};
            for(int i=0;i<=N;i++){
                cowList2[i] = cowList[i];
            }
            for(int i=A1;i<=A2;i++){
                // cout << "i is: " << i << endl;
                // cout << "(A2+(A1 - i)) is: " << (A2+(A1 - i)) << endl;
                cowList[i] = cowList2[(A2+(A1 - i))];
                
            }
            // for(int cow: cowList){
            //     if(cow != 0 ){
            //     cout << cow << endl;
            //     }
            // }
            // reverse B
            for(int i=0;i<=N;i++){
                cowList2[i] = cowList[i];
            }
            for(int i=B1;i<=B2;i++){
                // cout << "var 1: " << cowList[i] << endl;
                // cout << "var 2: " << cowList2[(B2 + 1)-i] << endl;

                cowList[i] = cowList2[(B2+(B1 - i))];
                
            }
            // for(int cow: cowList){
            //     if(cow != 0 ){
            //     cout << cow << endl;
            //     }
            // }
            // check
            // add to list
            for(int j=0;j<N;j++){
                cowListList[l][j] = cowList[j];
                cout << "cowListList " << cowListList[l][j] << endl;

            }
            for (int j=0;j<l;j++){
                bool works = true;
                for(int k=0;k<N;k++){
                    if(cowListList[j][k] != cowList[k]){
                        works = false;
                        // cout << "does not work" << endl;
                    }
                }
                if(works){
                    cout << "same one!" << endl;
                    stop = true;
                    // determine what position in the "queue" is correct by getting the "length" of the pattern
                    startOfPattern = j;
                    // lengthOfPattern = 

                }else{
                    cout << "not same" << endl;
                }
            }

            if(stop){
                break;
            }
    }
      


    for(int i=0;i<N;i++){
        // if(cow != 0 ){
        cout << cowList[i] << endl;
        // }
    }



    return 0;
}