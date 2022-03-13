#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int>::iterator front;
    vector<int>::iterator back;
    
    front = people.begin();
    back = people.end() - 1;
    sort(people.begin(), people.end());
    
    while(true){
        if(*front + *back <= limit){
            front += 1;
        }  
        back -= 1;
        answer += 1;   
        if(front > back){
            break;
        }
    }
    return answer;
}
