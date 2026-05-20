#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    unordered_set<char> ex;
    for(int i=0;i<skill.size();i++) 
    {
        ex.insert(skill[i]);
    }
    
    for(int i=0;i<skill_trees.size();i++) 
    {
        int idx=0;
        bool good = true;
        for(int j=0;j<skill_trees[i].size();j++) 
        {
            if(ex.count(skill_trees[i][j])!=0) 
            {
                if(skill[idx]==skill_trees[i][j])
                {
                    idx++;
                }
                else
                {
                    good = false;
                    break;
                }
            }
        }
        if(idx == skill.size()-1 || good==true) answer++;

    }
    
    return answer;
}