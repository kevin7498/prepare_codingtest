#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool standard(const string& a, const string& b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";    
    vector<string> temp;
    
    if(*max_element(numbers.begin(), numbers.end()) == 0){
        return "0";
    }
    
    for(int i = 0; i < numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(), temp.end(), standard);
    for(int i = 0; i <  temp.size(); i++){
        answer += temp[i];
    }  
  
    return answer;
}
