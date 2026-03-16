#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int get_index(string s) 
{
    if (s == "code") return 0;
    if (s == "date") return 1;
    if (s == "maximum") return 2;
    return 3; // "remain"
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    int ext_idx = get_index(ext);
    int sort_idx = get_index(sort_by);
    
    vector<vector<int>> answer;
    
    for (const auto& row : data) 
    {
        if (row[ext_idx] < val_ext) 
        {
            answer.push_back(row);
        }
    }
    
    sort(answer.begin(), answer.end(), [sort_idx](const vector<int>& a, const vector<int>& b) 
    {return a[sort_idx] < b[sort_idx]; });
    
    return answer;
}