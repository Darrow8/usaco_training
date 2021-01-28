#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>

using namespace std;





int main(){
    int N; // cows (2≤N≤1000)
    vector<int> cowId;
    cin >> N;
    double odd=0;
    double even=0;
    double count =0;

    int input;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        cowId.push_back(input);
    }
    sort(cowId.begin(),cowId.end());
    for(int i=0;i<N;i++){
        // cout << cowId[i] << endl;
    }
    // sum the number of odd and even numbers we have 
    for(int i=0;i<N;i++){
        if(cowId[i] % 2 == 0){
            // even
            even++;
        }else{
            // odd
            odd++;
        }
    }
    /**
     * Our rules:
     * #1 even + even = even
     * #2 even + odd = odd
     * #3 odd + odd = even
    */
   // there should be no reason to do #1 or #2


    // remove equal num of even and odd first
    while(even >= 1 && odd >= 1){
        even--;
        if(even != 0){
            odd--; //! possible issue here
            count += 2;
        }else{
            count ++;
        }
    }
    // cout << "exhausted" << endl;
    // cout << even << endl;
    // cout << odd << endl;
    // cout << "-----" << endl;

    if(odd > 0){
        // cout << odd << endl;
    
        if(fmod(odd,3) == 0){
            // cout << ((2*odd)/3) << endl;
           // can do o+o, o combo
            count += ((2*odd)/3);

       }else if(fmod(odd,3) == 1){
            // cout << "mod 3 = 1" << endl;
           count += ((2*(odd-1)/3) -1);
       }else if(fmod(odd,3) == 2){
            // cout << "mod 3 = 2" << endl;
           count += ((2*(odd-2)/3) +1);
       }
    }
    if(even > 0){
        count++;
    }


//    // for first one
//    if(even >= 1){
//        even--;
//        count++;
//    }else{
//        if(odd % 3 == 0){
//            // can do o+o, o combo
//             count += odd*(2/3);
//        }else if(odd % 3 == 1){
//            count += ((odd-1)*(2/3) -1);
//        }else if(odd % 3 == 2){
//            count += ((odd-2)*(2/3) +1);
//        }
//    }

    cout << count << endl;


    return 0;
}