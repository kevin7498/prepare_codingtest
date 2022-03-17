#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    
    for(int i = 0; i < dartResult.length(); i++){
        if(dartResult[i] - 48 >= 0 && dartResult[i] - 48 < 10){
            if(dartResult[i] - 48 == 1 && dartResult[i + 1] - 48 == 0){
                i += 1;
                score.push_back(10);
            } else {
                score.push_back(dartResult[i] - 48);
            }
            continue;
        }
        
        int size = score.size() - 1;  
        switch(dartResult[i]){
            case 'S':
                break;
            case 'D':
                score[size] = pow(score[size], 2);
                break;
            case 'T':
                score[size] = pow(score[size], 3);
                break;
            case '*':
                score[size - 1] *= 2;
                score[size] *= 2; 
                break;
            case '#':
                score[size] *= -1; 
                break;
        }
    }
    
    for(int i : score){
        answer += i;
    }
    
    return answer;
}
