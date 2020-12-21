#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int X,Y,M; // X is small pail, Y is med pail, M is one we need to reach max in
int A = 0; // A is the attempt



int main(){
    // X=1;
    // Y=1;
    // M=1;

    freopen("pails.in", "r", stdin);
    scanf("%i %i %i", &X, &Y, &M);

    int maxX = floor(M/X);
    int maxY = floor(M/Y);

    
    for(int i=0;i<maxX;i++){
        for(int j=0;j<maxY;j++){
            int R = 0;
            for(int z=0;z<i;z++){
                if(R + X <= M){
                    R = R + X;
                }else{
                    // stop
                }
            }
            for(int g=0;g<j;g++){
                if(R + Y <= M){
                    R = R + Y;
                }else{
                    // stop
                }            
            }
            A = max(A, R);
            cout << "testing between " << endl;
            cout << A << " and " << R << endl;

        }
    }

    cout << "We have a winner: " << A << endl;
    freopen("pails.out", "w", stdout);
    cout << A;

    return 0;
}