#include <string>
#include <vector>
using namespace std;

string toBinary(int n) 
{
    if (n == 0) return "0";
    string result = "";
    while (n > 0) 
    {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    return result;
}

vector<int> solution(string s) 
{
    vector<int> answer;
    int erased = 0;
    int time = 0;
    
    while (s.size() > 1)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') erased++; 
            else num++;
        }
        s = toBinary(num);
        time++;
    }
    
    answer.push_back(time);  
    answer.push_back(erased);
    
    return answer;
}