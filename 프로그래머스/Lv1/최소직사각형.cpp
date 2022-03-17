#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> w;
    vector<int> h;
    
    for(int i= 0; i < sizes.size(); i++){
        w.push_back(min(sizes[i][0], sizes[i][1]));
        h.push_back(max(sizes[i][0], sizes[i][1]));
    }
    
    sort(w.begin(), w.end());
    sort(h.begin(), h.end());
    answer = *(h.end() - 1) * *(w.end() - 1);
    return answer;
}
