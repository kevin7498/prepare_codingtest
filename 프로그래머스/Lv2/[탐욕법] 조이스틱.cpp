#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> number;
    int first = 0, second = 0, count = 0;
    int index = 0, len = 0;
    
    for(int i = 0; i < name.length(); i++){
        number.push_back(name[i]);
    }

    //이동하는거 무시하고 알파벳 맞추는데 사용하는 횟수
    for(int i = 0; i < number.size(); i++){
        first = number[i] - 65;
        second = 90 - number[i] + 1;
        if(first < second)
            answer += first;
        else
            answer += second;
    }
    
    //문장에서 A연속으로 많이 나오는 구간에서 그 시작 index와 A연속 수를 저장
    for(int i = 1; i < number.size(); i++){
        if(number[i] == 65){
            count = 1;
            for(int j = i + 1; j < number.size(); j++){
                if(number[j] == 65)
                    count++;
                else{
                    if(count > len){
                        len = count;
                        index = i;
                    }                    
                    break;
                }                    
            }
        }
    }
        
    if(index < len){
        answer += 2 * (index - 1) + number.size() - index - len;
    }
    else if(index == len){
        answer += number.size() - 1 - len;
    }
    else
        answer += number.size() - 1;
    
    return answer;
}
