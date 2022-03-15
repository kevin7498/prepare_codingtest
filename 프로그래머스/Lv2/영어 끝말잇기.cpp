#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkLetter(string a, string b){
    int length = a.length();
    if(a[length - 1] == b[0]){
        return true;
    }
    return false;
}

bool checkNew(string a, vector<string> &list){
    if(find(list.begin(), list.end(), a) == list.end()){
        list.push_back(a);
        return true;
    }
    return false;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> list;
    string last = "";

    for(int i = 0; i < words.size(); i++){
        int person = (i + 1) % n;
        int turn = (i / n) + 1;
        string now = words[i];
        
        if(person == 0){
            person = n;
        }
        
        if(i == 0){
            list.push_back(now);
            last = now;
            continue;
        }
              
        if(!(checkLetter(last, now) && checkNew(now, list))){
            answer.push_back(person);
            answer.push_back(turn);
            return answer;
        }
        
        last = now;
    }
    
    answer.push_back(0);
    answer.push_back(0);      
    return answer;
}
