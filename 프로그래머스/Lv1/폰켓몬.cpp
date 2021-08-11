#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums){
    int answer = 0;
    set<int> kind;
    
    for(int i = 0; i < nums.size(); i++){
        kind.insert(nums[i]);
    }
    
    if(kind.size() >= (nums.size()/2))
        answer = nums.size()/2;
    else
        answer = kind.size();
    
    return answer;
}
