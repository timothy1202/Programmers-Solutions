#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> plus;
    vector<int> answer;

    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            plus.insert(numbers[i] + numbers[j]);
        }
    }
    
    for(auto it = plus.begin(); it != plus.end(); ++it)
    {
        answer.push_back(*it);
    }
    
    return answer;
}