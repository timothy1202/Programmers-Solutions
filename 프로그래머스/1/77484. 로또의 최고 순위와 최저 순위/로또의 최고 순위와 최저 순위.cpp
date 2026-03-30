#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    int zero_num = 0;
    int right =0;
    
    for(const int& num : lottos)
    {
        if(num == 0) 
        {
            zero_num++;
        }
    }
    
    for(const int& l_num : lottos)
    {
        for(const int& w_num : win_nums)
        {
            if(l_num == w_num)
            {
                right++;
            }
        }
    }
    int highest = right + zero_num;
    int lowest = right;
    
    if(highest == 6) highest = 1;
    else if( highest==5) highest = 2;
    else if(highest==4) highest=3;
    else if(highest==3) highest=4;
    else if(highest==2) highest=5;
    else highest=6;
    
    if(lowest == 6) lowest = 1;
    else if( lowest==5) lowest = 2;
    else if(lowest==4) lowest=3;
    else if(lowest==3) lowest=4;
    else if(lowest==2) lowest=5;
    else lowest=6;
    
    answer.push_back(highest);
    answer.push_back(lowest);
    
    return answer;
}