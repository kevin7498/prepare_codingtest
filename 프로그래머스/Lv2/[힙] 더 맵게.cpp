#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //priority_queue<type, container<type>, cmp_struct> q;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i = 0; i < scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    while (!q.empty()) {
        //맨 앞 2개 연산
        if(q.top() < K){
            int temp = q.top();
            q.pop();
            q.push(temp + (q.top() * 2));
            q.pop();
            answer++;
        }
        else break;
        if(q.size() == 0){
            answer = -1;
            break;
        }       
    }
    return answer;
}
