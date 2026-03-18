#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    int c1_idx =0;
    int c2_idx =0;
    
    for(const string& word : goal)
    {
        if(word == cards1[c1_idx]) c1_idx++;
        else if(word == cards2[c2_idx]) c2_idx++;
        else return "No";
    }
    
    if(c1_idx <= cards1.size() && c2_idx <= cards2.size())
    return "Yes";
    
    return "No";
}