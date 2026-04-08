#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    if(arr.size()==1)
    {
        answer.push_back(-1);
    }
    else
    {
        int idx = 0;
        for(int i=1;i<arr.size();i++) 
        {
            if(arr[i]<arr[idx]) idx=i;
        }
         for (int i = 0; i < arr.size(); i++)
        {
            if (i != idx) answer.push_back(arr[i]);
        }
    }
 
    
    return answer;
}