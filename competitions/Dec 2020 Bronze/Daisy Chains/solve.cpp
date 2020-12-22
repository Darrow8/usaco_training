#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>


using namespace std;

int N, photoCount; // number of flowers is N, number of photos with an average flower is photoCount
vector<int> flowers;

vector<int> getPartOfArr(int start, int end, vector<int> arr){
    vector<int> vec;
    for(int a=0;a<arr.size();a++){
        if(a >= start && a <= end){
            vec.push_back(arr[a]);
        }
    }

    return vec;
}

bool averagePropHas(vector<int> arr){
    bool hasProp = false;
    float total = 0;
    for(int a=0;a<arr.size();a++){
        total += arr[a];
    }
    float avg = total/arr.size();
    // cout << "total is " << total << endl;
    // cout << "arr.size() is " << arr.size() << endl;
    // cout << "avg is " << avg << endl;
    // cout << (total/arr.size()) << endl;

    for(int a=0;a<arr.size();a++){
        if(arr[a] == avg){
            hasProp = true;
            
            // cout << "has avg! " << arr[a] << " " << avg << endl;
        }
    }


    return hasProp;
}


int main(){

    // load in content
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        flowers.push_back(input);
    }

    // we need to figure out how many "photos we can take"

    // firstly we can take an individual photo for each flower

    photoCount += N;

    // next we need to get all possible combinations and then see if they average out correctly
    vector<vector<int> > possiblePhoto;

    // for each flower
    for(int i=0;i<N;i++){
        // for each possible combination
        // cout << "flower " << i << endl;
        for(int j=(N - (i+1));j>0;j--){
            // cout << "j is " << j << endl;
            // put into array 
            vector<int> pushBackArr; 
            pushBackArr = getPartOfArr(i,j+i,flowers);
            // for(int a: pushBackArr){
            //     cout << a << ", ";
            // }
            // cout << endl;
            possiblePhoto.push_back(pushBackArr);
        }

    }

    // test each combination and determine if has average property
    for(vector<int> indArr : possiblePhoto){
        // for(int a : indArr){
        //     cout << a << ", ";

        // }
        // cout << endl;
        if(averagePropHas(indArr)){
            photoCount++;
        }
    }

    cout << photoCount << endl;


}