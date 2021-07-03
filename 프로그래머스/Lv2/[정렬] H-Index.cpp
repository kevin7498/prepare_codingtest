#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {    
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    //i보다 큰 값의 수가 i이상
    for(int i = 0; i <= citations.size(); i++){
        int count = 0;
        for(int j = 0; j < citations.size(); j++){
            if(citations[j] >= i)
                count++;
        }
        if(count >= i && citations.size() - count + 1 <= i)
            answer = i;        
    }
    return answer;
}
