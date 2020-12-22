#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>


using namespace std;

vector<int> unk;
array<int, 6> input;


int main(){

    // declare what we need to know 
    int a;
    int b;
    int c;
    int ab;
    int bc;
    int ca;
    int abc;

    // get cin values & sort
    cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5] >> input[6];

    for( int a : input){
        unk.push_back(a);
    }

    sort(unk.begin(), unk.end());

    // this is really a game of finding C, as A and B are the two lowest values
    a = unk[0];
    b = unk[1];
    ab = a + b;

    // now we need to determine where c is
    
    // we know that whichever one is a + b + c is the biggest

    c = unk[unk.size() -1 ] - ab;

    cout << a << " ";
    cout << b << " ";
    cout << c << endl;

    return 0;
}