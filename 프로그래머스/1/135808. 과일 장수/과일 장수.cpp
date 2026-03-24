#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) 
{
    sort(score.begin(),score.end(),greater<int>());
    int max_box = score.size()/m;
    int j=m-1;
    int answer =0;
    for(int i=0;i<max_box;i++)
    {
        int low = score[j];
        answer = answer + low*m;
        j +=m;
        
    }
    
    return answer;
}