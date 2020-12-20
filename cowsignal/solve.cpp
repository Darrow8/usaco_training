#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>


using namespace std;

int M, N, K; // M is rows, N is columns


int main(){
    freopen("cowsignal.in", "r", stdin);

    scanf("%d %d %d \n", &M, &N, &K);


    char msg[M][N];
    char newmsg[M*K][N*K];


    // * take in
    for(int i=0;i<M+1;i++){
        for(int j=0;j<N+1;j++){
            scanf("%c",&msg[i][j]);
        }
    }

            cout << "OK" << endl;

    // * put out
    for(int i=0;i<M*K;i++){
        for(int j=0;j<N*K;j++){
                newmsg[i][j] = *"a";
        }
    }


    // // * ?expand
    for(int i=0;i<M+1;i++){
        for(int j=0;j<N;j++){
            for(int r=0;r<K;r++){
                for(int g=0;g<K;g++){
                    newmsg[i*K+r][j*K+g] = msg[i][j];
                    cout << "row:" << i << endl;
                    cout << "column:" << j << endl;
                    cout << "secrow:" << i+r << endl;
                    cout << "seccolumn:" << j+g << endl;
                    cout << "msg: " << msg[i][j] << endl;
                    cout << "newmsg: " << newmsg[i+r][j+g] << endl;

                }
            }
        }
    }


    freopen("cowsignal.out", "w", stdout);

    //* output
    for(int i=0;i<M*K;i++){
        for(int j=0;j<N*K;j++){
            printf("%c",newmsg[i][j]);
        }
        printf("%s","\n");
    }





}