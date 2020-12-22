#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>    // std::find
#include <vector>       // std::vector
using namespace std;

int N,K; // K is num of practice sessions and N is num of cows

int fact(int n){
    int f =1;
    for(int i=1; i<=n;i++){
        f *= (i);
    }
    return f;
}

int comb(int n, int r){
    return fact(n)/(fact(r)*fact(n-r));
}


int main(){

    freopen("gymnastics.in", "r", stdin);
    scanf("%d %d", &K, &N);
    int scores[K][N];
    int comps = comb(N,2); // the number of comparisons

    /**
     * array of ones that are "still good", going from 
     * a-b, a-c, a-d
     * b-c, b-d
     * c-d
    */
    char stillGood[N][N]; // we are kinda just using a triangle of this


    for(int i = 0; i<N; i++){
        for(int j =0; j<K; j++){
            scanf("%d", &scores[i][j]);

            cout << scores[i][j];
        }
        cout << endl;
    }

    // for each match
    for(int k =0; k<K; k++){
        // for each assignment of a number
        for (int i = 1; i <= N; i++){
            cout <<"i is: "<< i << endl;
            cout <<"N-i is: "<< N-i << endl;
            // compare on the basis of how many comparisons
            for (int j = 0; j < N-i; j++){
                int cow_x = find(scores[0][0],scores[0][N-1],i);
                int cow_y = find(scores[0][0],scores[0][N-1],);

            //     char currentGymnast = stillGood[i][j];
            // int fp = find(scores[0],scores[0][N-1],i+1);
            //     for()

                // if(scores[k][i] > scores[k][j] && currentGymnast == 'G'){
                    
                // }else if(scores[k][i] < scores[k][j] && currentGymnast == 'L'){
                    
                // }else if(scores[k][i] > scores[k][j] && currentGymnast == 'G'){
                    
                // }

            }


                


            }
    }


    return 0;
}