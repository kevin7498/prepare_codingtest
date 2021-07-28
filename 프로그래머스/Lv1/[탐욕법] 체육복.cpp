#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;    
    answer = n - lost.size();
    
    for(int i = 0; i < reserve.size(); i++){
        for(int j = 0; j < lost.size(); j++){
            if(reserve[i] == lost[j]){
                reserve[i] = -1;
                lost[j] = -1;
                break;
            }
        }
    }
    
    for(int i = 0; i < reserve.size(); i++){
        if(reserve[i] == -1){
            answer++;
            continue;
        }
        for(int j = 0; j < lost.size(); j++){
            if(lost[j] == -1)
                continue;
            if(lost[j] != 0 && (reserve[i] - lost[j] == 1 || reserve[i] - lost[j] == -1)){
                lost[j] = 0;
                answer++;
                break;
            }
        }
    }
    return answer;
}
