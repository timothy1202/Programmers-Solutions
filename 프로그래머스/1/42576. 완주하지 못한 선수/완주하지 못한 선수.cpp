#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    map<string,int> per;
    map<string,int> fin;
    
    for(const string & name : participant)
    {
        per[name]++;
    }
    
    for(const string& name : completion)
    {
        fin[name]++;
    }
    
    for(const string& name: participant)
    {
        if(per[name] != fin[name])
        {
            return name;
        }
    }
    
    return answer;
}