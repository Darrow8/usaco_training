#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define GET_VARIABLE_NAME(Variable) (#Variable)


class Cup{
    public:
        int capacity;
        int current;
    
};


Cup cup_1, cup_2, cup_3;


void pour(Cup &from_cup,Cup &to_cup) {

    if(to_cup.capacity >= from_cup.current + to_cup.current){
        // all good we can pour fully
        to_cup.current += from_cup.current;
        from_cup.current -= from_cup.current;

    }else{
        // no we cannot pour fully, pour as much as possible
        to_cup.current = to_cup.capacity;
        from_cup.current -= to_cup.capacity;

    }
    cout << "poured! \n";
    cout << cup_1.current << " " << cup_2.current << " "  << cup_3.current << '\n';


}

void setCups(){
    freopen("mixmilk.in", "r", stdin);

    scanf("%d%d", &cup_1.capacity, &cup_1.current);
    scanf("%d%d", &cup_2.capacity, &cup_2.current);
    scanf("%d%d", &cup_3.capacity, &cup_3.current);

    cout << "cup1: current= " << cup_1.current << " capactiy= " << cup_1.capacity << endl;
    cout << "cup2: current= " << cup_2.current << " capactiy= " << cup_2.capacity << endl;
    cout << "cup3: current= " << cup_3.current << " capactiy= " << cup_3.capacity << endl;
}


int main() {

    setCups();

    for (int i=0; i < 100; i++){
        
        if(i % 3 == 0){
            // pour from cup 1 to cup 2
            pour(cup_1,cup_2);

        }else if(i % 3 == 1){
            // pour from cup 2 to cup 3
            pour(cup_2,cup_3);

        }else if (i % 3 == 2){
            // pour from cup 3 to cup 1
            pour(cup_3,cup_1);

        }
    }

    cout << "cup1: current= " << cup_1.current << " capactiy= " << cup_1.capacity << endl;
    cout << "cup2: current= " << cup_2.current << " capactiy= " << cup_2.capacity << endl;
    cout << "cup3: current= " << cup_3.current << " capactiy= " << cup_3.capacity << endl;
    freopen("mixmilk.out", "w", stdout);

    printf("%d\n%d\n%d\n", cup_1.current, cup_2.current, cup_3.current);


  return 0;
}
