#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    // 1. 점수 저장용 맵
    map<char, int> point;
    
    // 2. 점수 계산 로직 (사용자님 원본 유지)
    for(int i = 0; i < choices.size(); i++)
    {
        if(choices[i] < 4)
        {
            char name = survey[i][0];
            point[name] += 4 - choices[i];
        }
        else if(choices[i] > 4)
        {
            char name = survey[i][1];
            point[name] += choices[i] - 4;
        }
    }
    
    string answer = "";

    if(point['R'] >= point['T']) answer += 'R';
    else answer += 'T';
    

    if(point['C'] >= point['F']) answer += 'C';
    else answer += 'F';
    
    if(point['J'] >= point['M']) answer += 'J';
    else answer += 'M';
    
    if(point['A'] >= point['N']) answer += 'A';
    else answer += 'N';

    return answer;
}