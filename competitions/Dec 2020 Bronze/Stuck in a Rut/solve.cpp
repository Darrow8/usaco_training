#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>



using namespace std;

int N; // num of cows

// direction to go
// enum Direction {North = 'N', East = 'E'};

// class for cow
class Cow{
    public:
        int x; // x pos
        int y; // y pos
        char direction; // direction
        string tilesEaten = "0"; // number of tiles eaten
};
vector<Cow> allCows;


// int runTurn(){

//     return 0;
// }

vector<vector<int> > sortCol(vector<vector<int> > arr){
    vector<vector<int> > newvec;
    bool good = false;
    while(good == false){
            for(int i =0; i< arr.size(); i++){
                vector<int> smallV = arr[i];
                for(int j =0; j< arr.size(); j++){
                    if(smallV >= arr[j] && j != 0){
                        smallV = arr[j];
                    }
                }
                newvec.push_back(smallV);
            }
            if(newvec.size() == arr.size()){
                good = true;
            }
    }
    if(good){
        return newvec;
    }
}


int main(){
    
    // get num of cows and put into array
    cin >> N;
    for(int i=0;i<N;i++){
        Cow newCow;
        cin >> newCow.direction >> newCow.x >> newCow.y;
        allCows.push_back(newCow);
    }

    // determine collisions
    for(Cow focusCow: allCows){
        vector<vector<int> > ourCollisions;
        if(focusCow.direction == 'N'){
            // facing north, check if cow is in front/has eaten in front
            for(Cow otherCow: allCows){
                if(otherCow.direction == 'E' && otherCow.x < focusCow.x && otherCow.y > focusCow.y){
                    // collision will *probably* happen
                    /**
                     * first val is focusCow x
                     * second is otherCow y
                     * third is focusCowLength
                     * fourth is otherCowLength
                    */
                    vector<int> collision;
                    collision.push_back(focusCow.x);
                    collision.push_back(otherCow.y);

                    int focusCowLength = otherCow.y - focusCow.y;
                    int otherCowLength = focusCow.x - otherCow.y;
                    collision.push_back(focusCowLength);
                    collision.push_back(otherCowLength);
                    ourCollisions.push_back(collision);
                    // if(focusCowLength > otherCowLength){
                        
                    // }else if( focusCowLength < otherCowLength){

                    // }

                }
            }

        }
        // make sure something else won't block collision before it happens
        // vector<vector<int> > sortedCol;
        // for(int i =0; i< ourCollisions.size(); i++){
        //     if(){

        //     }
        // }       
        vector<vector<int> > sorted = sortCol(ourCollisions);


        //  * third is focusCowLength
        //  * fourth is otherCowLength 
        for( vector<int> col : sorted){
            if(col[2] > col[3]){
                // our cow is further, other cow will get there first
                focusCow.tilesEaten = to_string(col[2]);
            }else if( col[3] < col[2]){
                // their cow is further
                focusCow.tilesEaten = "Infinity";
            }else if(col[3] == col[2]){
                // equal
                focusCow.tilesEaten = "Infinity";
            }
        }


    }



    for(Cow cow: allCows){
        cout << cow.tilesEaten << endl;
    }

    return 0;
}