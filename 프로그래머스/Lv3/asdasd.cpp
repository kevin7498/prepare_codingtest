#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;    
    queue<int> temp;
    
    for(int i = 0; i < progresses.size(); i++){
        int day = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i] != 0){
            day++;
        }
        temp.push(day);
    }
    
    int n = temp.size();
    
    for(int i = 0; i < n; i++){
        int count = 0;
        if(temp.empty()) break;
        int standard = temp.front();
        count++;
        //answer[i]++;
        temp.pop();
        for(int j = 0; j < n; j++){
            if(temp.empty()) break;
            
            if(temp.front() <= standard){
                count++;
                //answer[i]++;
                temp.pop();
            }
            else break;
        }
        answer.push_back(count);
    }    
    
    return answer;
}
