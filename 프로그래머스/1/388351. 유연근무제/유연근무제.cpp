#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); ++i)
    {
        int h = schedules[i] / 100;
        int m = schedules[i] % 100 + 10;
        if(m >= 60) 
        {
            h += 1;
            m -= 60;
        }
        int max_time = h * 100 + m;
        
        int today = startday;
        int pass_count = 0; 
        
        for(int j = 0; j < 7; ++j)
        {
            // 평일(1~5)일 때만 체크
            if(today >= 1 && today <= 5)
            {
                if(timelogs[i][j] <= max_time)
                {
                    pass_count++;
                }
            }
            
            today++;
            if(today > 7) today = 1;
        }
        
        if(pass_count == 5) answer++;
    }
    
    return answer;
}