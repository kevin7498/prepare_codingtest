#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    multimap<string, string> mul;
    vector<int> kind;
    int count = 0;
    string temp;
    
    multimap<string, string>::iterator iter;
    for(int i = 0; i < clothes.size(); i++){
        mul.insert(pair<string, string>(clothes[i][1], clothes[i][0]));        
    }

    temp = mul.begin()->first;
    
    for(iter = mul.begin(); iter != mul.end(); iter++){
        if(iter->first == temp){
            count++;
        }
        else{
            kind.push_back(count);
            count = 1;
            temp = iter->first;
        }
    }    
    kind.push_back(count);
    
    for(int i = 0; i < kind.size(); i++){
        if(i == 0)
            answer = kind[i];
        else
            answer += kind[i] + kind[i]*answer;
    }
    return answer;
}
