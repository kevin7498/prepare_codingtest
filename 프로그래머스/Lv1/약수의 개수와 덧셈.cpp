#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i < right + 1; i++){
        int temp = (int)sqrt(i);
        if(temp * temp == i)
            answer -= i;
        else
            answer += i;
    }
    return answer;
}
