#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size(); //원래 길이
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < number.size() - 1; j++){
            if(number[j] < number[j + 1]){
                number.erase(j, 1);
                break;
            }
        }
    }
    int now = number.size(); //반복문 돌고 난 뒤의 길이
    int r = now - (size - k); //현재 길이와 답의 길이의 차이

    if(now != size - k){
        number.erase(number.size() - r, r);
    }
    
    answer = number;
    return answer;
}
