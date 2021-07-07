#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string temp;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        temp = phone_book[i];
        if(temp == phone_book[i + 1].substr(0, temp.length()))
            return false;
        else continue;
    }
    return answer;
}
