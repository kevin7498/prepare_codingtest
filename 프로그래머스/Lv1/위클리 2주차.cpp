#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    float total = 0;
    vector<int> temp;
    
    for(int i = 0; i < scores.size(); i++){
        for(int j = 0; j < scores[0].size(); j++){
            total += scores[j][i];
            temp.push_back(scores[j][i]);
        }
        sort(temp.begin(), temp.end());
        if((scores[i][i] == temp.front() && temp[0] < temp[1]) || 
          (scores[i][i] == temp.back() && temp[temp.size() - 1] > temp[temp.size() - 2])){
            total -= scores[i][i];
            total = total / ((temp.size() - 1) * 10);
        }else{
            total = total / (temp.size() * 10);
        }
        
        switch((int)total){
            case 10: case 9:
                answer += 'A';
                break;
            case 8:
                answer += 'B';
                break;
            case 7:
                answer += 'C';
                break;
            case 6: case 5:
                answer += 'D';
                break;
            default:
                answer += 'F';
                break;
        }
        temp.clear();
        total = 0;
    }
    return answer;
}
