#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) 
{
    string answer = "";
    for(int i=1;i<food.size();i++)
    {
        int num =food[i]/2;
        for(int j=0;j<num;j++)
        {
            answer +=to_string(i);
        }
    }
    
    string same(answer.rbegin(),answer.rend());
    answer += '0';
    answer += same;
    
    
    return answer;
}