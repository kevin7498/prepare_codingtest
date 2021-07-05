#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//소수 판별하는 함수
bool prime(int num){
    if(num == 1 || num == 0)
        return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int num = 0;
    set<int> number;
    string a = "";
    
    vector<int> temp;
    
    //문자열을 하나씩 벡터에 넣어줌
    for(int i = 0; i < numbers.length(); i++){
        temp.push_back(numbers[i]);
    }
    sort(temp.begin(), temp.end()); //오름차순 정렬

    int n = temp.size();
    //nPi 구하는 반복문
    for(int i = 1; i <= n; i++){
        do{
            for(int j = 0; j < i; j++){
                a += temp[j];
            }
            num = stoi(a);
            if(prime(num)){
                number.insert(num);
            }         
            a = "";
            reverse(temp.begin() + i, temp.end());
        }while(next_permutation(temp.begin(), temp.end()));
    }  
    answer = number.size();
    
    return answer;
}
