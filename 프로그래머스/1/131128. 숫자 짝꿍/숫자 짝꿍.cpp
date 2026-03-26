#include <string>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

string solution(string X, string Y) 
{
    map<int, int, greater<int>> countX;
    map<int, int, greater<int>> countY;

    for(const char& a : X) 
    {
        countX[a - '0'] += 1;
    }
    for(const char& b : Y) 
    {
        countY[b - '0'] += 1;
    }

    string answer = "";

    for(auto const& [num, count] : countX) 
    {
        if(countY.find(num) != countY.end()) 
        {
            int common = min(count, countY[num]);
            
            for(int i = 0; i < common; i++) 
            {
                answer += to_string(num);
            }
        }
    }

    if(answer == "") return "-1";          
    if(answer[0] == '0') return "0";       

    return answer;
}