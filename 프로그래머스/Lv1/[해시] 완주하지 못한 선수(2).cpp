#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> name;
    
    for(int i = 0; i < participant.size(); i++){
        name.insert(participant[i]);
    }
    for(int i = 0; i < completion.size(); i++){
        name.erase(name.find(completion[i]));
    }
    answer = *name.begin();  
    return answer;
}
