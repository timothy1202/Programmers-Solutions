#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    vector<int> scores;
    string temp = "";   

    for (int i = 0; i < dartResult.size(); i++) 
    {
        char c = dartResult[i];

        if (isdigit(c)) 
        {
            temp += c;
        }

        else if (c == 'S' || c == 'D' || c == 'T') 
        {
            int score = stoi(temp);
            if (c == 'D') score = pow(score, 2);
            else if (c == 'T') score = pow(score, 3);
            
            scores.push_back(score);
            temp = ""; 
        }

        else if (c == '*') 
        {
            int curr_idx = scores.size() - 1;
            scores[curr_idx] *= 2; 
            if (curr_idx > 0) scores[curr_idx - 1] *= 2; 
        }
        else if (c == '#') 
        {
            scores[scores.size() - 1] *= -1; 
        }
    }

    for (int s : scores) 
    {
        answer += s;
    }

    return answer;
}