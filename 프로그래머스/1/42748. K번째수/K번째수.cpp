#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++)
    {

        int start_idx  = commands[i][0] - 1; 
        int end_idx    = commands[i][1] - 1;
        int search_idx = commands[i][2] - 1;
        
        vector<int> temp;
        for(int j = start_idx; j <= end_idx; j++) 
        {
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[search_idx]);
    }
    
    return answer;
}