#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer; 
    map<string, int> member;
    map<string, int>::iterator iter;
    string temp = "";
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{'){
            continue;
        }     
        if((s[i] == '}' || s[i] == ',')){
            if(temp.length() == 0) {
                continue;
            }            
            if(member.find(temp) != member.end()){
                member[temp] += 1;
            } else {
                member.insert(make_pair(temp, 1));
            }
            temp = "";
        } else {
            temp += s[i];
        }     
    }
    
    int check = member.size();   
    for(int i = 0; i < member.size(); i++){
        for(iter = member.begin(); iter != member.end(); iter++){
            if(iter->second == check){
                answer.push_back(stoi(iter->first));
                check -= 1;
            }
        }
    }  
    return answer;
}
