#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> buy;

    for(int i = 0; i < want.size(); i++)
    {
        buy[want[i]] = number[i];
    }

    for(int i = 0; i < discount.size(); i++)
    {
        if(i + 10 > discount.size()) break;

        unordered_map<string, int> c = buy;

        for(int j = i; j < i + 10; j++)
        {
            if(c.find(discount[j]) != c.end())
            {
                c[discount[j]]--;
            }
        }

        bool isok = true;
        for(auto& [key, val] : c)
        {
            if(val != 0) isok = false;
        }

        if(isok) answer++;
    }

    return answer;
}