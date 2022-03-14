#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    if(numbers.size() == 0 && target == 0){
        return 1;
    }
    if(numbers.size() == 0){
        return 0;
    }
    
    int temp = numbers[0];
    numbers.erase(numbers.begin());
    
    return solution(numbers, target - temp) + solution(numbers, target + temp);
}
