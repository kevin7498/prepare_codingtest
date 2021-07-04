#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> find;

    int total = brown + yellow;
    for(int i = 1; i * i <= total; i++){
        if(total % i == 0){
            find.push_back(make_pair(i, total / i));
        }
    }

    for(int i = 0; i < find.size(); i++){
        int h = find[i].first;
        int w = find[i].second;        
        if((h - 2)*(w - 2) == yellow){
            answer.push_back(w);
            answer.push_back(h);    
        }
    }    
    return answer;
}
