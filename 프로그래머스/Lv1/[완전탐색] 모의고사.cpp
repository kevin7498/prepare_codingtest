#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> temp(3);
    
    //사람당 맞춘 개수 
    for(int i= 0; i < answers.size(); i++){
        if(a[i % 5] == answers[i])
            temp[0]++;
        if(b[i % 8] == answers[i])
            temp[1]++;
        if(c[i % 10] == answers[i])
            temp[2]++;
    }
        
    for(int i = 0; i < 3; i++){
        if(temp[i] == *max_element(temp.begin(), temp.end()))
            answer.push_back(i + 1);
    }    
    return answer;
}
