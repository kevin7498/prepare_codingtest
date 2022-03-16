#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>

using namespace std;

string makeThree(int n){
    string result = "";
    while(true){
        int a = n % 3;
        int b = n / 3;
        result = to_string(a) + result;
        n = b;
        if(b == 0){
            break;
        }
    }
    return result;
}

int makeTen(string n){
    int result = 0;
    int count = 0;
    for(int i = n.length() - 1; i >= 0; i--){
        result += (n[i] - 48) * pow(3, count);
        count++;        
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    stack<char> temp;
    string s = makeThree(n);
    
    for(char c : s){
        temp.push(c);
    }
    
    s = "";
    int size = temp.size();
    
    for(int i = 0; i < size; i++){
        s += temp.top();
        temp.pop();
    }
    answer = makeTen(s);
    return answer;
}
