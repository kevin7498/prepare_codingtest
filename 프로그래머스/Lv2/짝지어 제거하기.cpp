#include <iostream>
#include<string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    if(s.length() <= 1 || s.length()%2 == 1)
        return answer;
    
    stack<char> temp;  
    
    for(int i = 0; i < s.length(); ++i){
        if(temp.empty() || temp.top() != s[i]){
            temp.push(s[i]);
        }else{
            temp.pop();
        }     
    }

    if(temp.empty())
        answer++;

    return answer;
}
