#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int correct = 0;
    
    for(int a : lottos){
        if(a == 0){
            zero += 1;
            continue;
        }        
        for(int b : win_nums){
            if(a == b){
                correct += 1;
                break;
            }
        }
    }
    
    if(7 - (zero + correct) > 5){
        answer.push_back(6);
    } else {
        answer.push_back(7 - (zero + correct));
    }

    if(correct < 2){
        answer.push_back(6);
    } else {
        answer.push_back(7 - correct);
    }
  
    return answer;
}
