#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int hor=0;
    int ver=0;
    
    for(int i=1;i<=yellow;i++)
    {
        for(int j=1;j<=yellow;j++)
        {
            if(i*j==yellow)
            {
                if((i+2)*2 + (j*2)== brown)
                {
                    if(i>=j)
                    {
                        answer.push_back(i+2);
                        answer.push_back(j+2);
                        return answer;
                    }
                    else
                    {
                        answer.push_back(j+2);
                        answer.push_back(i+2);
                        return answer;
                    }
                }
            }
        }
    }
    
    return answer;
}