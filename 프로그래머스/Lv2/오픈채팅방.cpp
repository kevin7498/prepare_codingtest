#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;    
    map<string, string> usid;
    map<string, string>::iterator iter;
    
    //map에 아이디 + 마지막 닉네임 뽑아서
    for(int i = record.size() - 1; i >= 0; i--){
        string text = record[i];
        stringstream ss(text);
        string id, name;
        getline(ss, id, ' ');
        getline(ss, id, ' ');
        getline(ss, name, ' ');
        if(name != "")
            usid.insert(pair<string, string>(id, name));
    }
    
    for(int i = 0; i < record.size(); i++){
        string text = record[i];
        stringstream ss(text);
        string command, id;
        getline(ss, command, ' ');
        getline(ss, id, ' ');
               
        if(command == "Enter")
            answer.push_back(usid[id] + "님이 들어왔습니다.");
        else if(command == "Leave")
            answer.push_back(usid[id] + "님이 나갔습니다.");
    }
    return answer;
}
