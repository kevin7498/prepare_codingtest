#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

bool check(queue<char> q){
    stack<char> st;
    int size = q.size();
    
    for(int i = 0; i < size; i++) {
        if(st.size() == 0){
            st.push(q.front());
            q.pop();
            continue;
        }
              
        if(q.front() == char(st.top() + 1) || q.front() == char(st.top() + 2)){
            st.pop();
        } else {
            st.push(q.front());
        }   
        q.pop();
    }
    
    if(st.size() == 0){
        return true;
    } else {
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    int length = s.length();
    queue<char> q;
    stack<char> st;
    
    for(int i = 0; i < length; i++){
        q.push(s[i]);
    }
    
    for(int i = 0; i < length; i++){
        char c = q.front();
        q.pop();
        q.push(c);
        
        if(check(q)){
            answer += 1;
        }  
    }
    return answer;
}
