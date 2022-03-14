#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> temp;
    
    while(true){
        int a = n % 3;
        int b = n / 3;
        
        if(a == 0){
            a = 4;
            b -= 1;
        }
        temp.push_back(a);
        
        if(b <= 3){
            if(b == 3){
                temp.push_back(4);
            } else if(b == 0){
                break;
            } else {
                temp.push_back(b);
            }  
            break;
        }
        n = b;  
    }
    
    reverse(temp.begin(), temp.end());
    for(int i : temp){
        answer += to_string(i);
    }
    
    return answer;
}
