using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long temp = 0;
    
    for(int i = 1; i < count + 1; i++){
        temp += price * i;
    }
    if(temp <= money)
        answer = 0;
    else
        answer = temp - money;
    return answer;
}
