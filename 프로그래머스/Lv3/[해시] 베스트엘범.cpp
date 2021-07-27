#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
        return a.second > b.second;
    }

bool cmp2(const pair<int, int>& a, const pair<int, int>& b){
        return a.first > b.first;
    }

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    multimap<string, int> info;
    multimap<string, int>:: iterator iter;
    
    vector<pair<string, int>> counter;
    vector<pair<int, int>> result;

    int count = 0, a = 0, index = 0;
    string temp = "";
    
    for(int i = 0; i < genres.size(); i++){
        info.insert(make_pair(genres[i], i));
    }
    
    //각 장르별 총 재생 횟수 구하는 곳
    temp = info.begin()->first;
    for(iter = info.begin(); iter != info.end(); iter++){
        if(iter->first == temp){
            count += plays[iter->second];
        }
        else{
            counter.push_back(make_pair(temp, count));
            temp = iter->first;
            count = plays[iter->second];
        }
    }
    counter.push_back(make_pair(temp, count));        
    sort(counter.begin(), counter.end(), cmp);
    
    for(int i = 0; i < counter.size(); i++){
        a = 0;
        for(iter = info.begin(); iter != info.end(); iter++){
            //같은 장르이면
            if(iter->first == counter[i].first){
                result.push_back(make_pair(plays[iter->second], iter->second));                
            }
        }
        sort(result.begin(), result.end(), cmp2);
        answer.push_back(result[0].second);
        if(result.size() > 1){
            answer.push_back(result[1].second);
        }
        result.clear();
    }  
    return answer;
}
