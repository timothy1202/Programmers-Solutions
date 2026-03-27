#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int max_l = 0;
    int max_s = 0;
    
    for(auto const& size : sizes)
    {

        int a = max(size[0], size[1]);
        int b = min(size[0], size[1]);
        

        if (a > max_l) max_l = a;
        if (b > max_s) max_s = b;
    }
    
    int answer = max_l * max_s;
    return answer;
}