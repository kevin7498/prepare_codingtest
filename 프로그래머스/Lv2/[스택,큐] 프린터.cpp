#include <string>
#include <vector>
#include <list>

using namespace std;

class task{
    int priority;
    int choice = 0;
public:
    task(int i){
        this->priority = i;
    }
    void setChoice(){
        this->choice = 1;
    }    
    int getPriority(){
        return this->priority;
    }
    int getChoice(){
        return this->choice;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;    
    list<task> l;
    
    for(int i = 0; i < priorities.size(); i++){
        task t = task(priorities[i]);
        if(i == location){
            t.setChoice();
        }
        l.push_back(t);       
    }
    
    list<task>::iterator iter;
    
    while(!l.empty()){        
        for(iter = l.begin(); iter != l.end(); iter++){
            if(l.front().getPriority() < iter->getPriority()){
                l.push_back(l.front());
                l.pop_front(); 
                iter = l.begin();
            }              
        }
        if(l.front().getChoice() == 1){
            answer++;
            break;
        }
        else{
            answer++;
            l.pop_front();
        }
    }    
    return answer;
}
