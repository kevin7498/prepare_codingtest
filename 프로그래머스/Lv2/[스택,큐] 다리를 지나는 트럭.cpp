#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int possible = 0;
    int index = 0;        
    queue<int> q;
    
    //다리 길이만큼 0 넣어준다
    for(int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    
    for(int i = 0; i < truck_weights.size(); i++){
        possible -= q.front();      
        //올라갈 수 있으면
        if(possible + truck_weights[i] <= weight){
            possible += truck_weights[i];
            q.pop();
            q.push(truck_weights[i]);
            answer++;
        }
        //못올라가면
        else{
            q.pop();
            q.push(0);
            i--;           
            answer++;
        }
    }  
    //마지막 트럭의 위치 파악
    for(int i = 0; i < bridge_length; i++){
        if(q.front() != 0){
            index = i;
        }
        q.pop();
    }
    //다리에 트럭이 남아 있었다면
    if(index != 0){
        answer += index + 1;
    }
    return answer;
}
