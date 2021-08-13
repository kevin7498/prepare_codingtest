#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> result;    
    int num = 0;
    
    for(int i = 0; i < moves.size(); i++){
        int line = moves[i] - 1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][line] != 0){
                result.push(board[j][line]);
                board[j][line] = 0;
                if(num == result.top()){
                    result.pop();
                    result.pop();
                    answer += 2;  
                }
                break;
            }            
        }
        if(result.size() == 0){
            num = 0;
        }else{
            num = result.top();
        }
    }
    return answer;
}
