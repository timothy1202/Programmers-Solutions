#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) 
{
    int n = signals.size();
    

    for (int t = 1; t <= 5000000; t++) 
    {
        bool all_yellow = true;
        
        for (int i = 0; i < n; i++) 
        {
            int g = signals[i][0];
            int y = signals[i][1];
            int r = signals[i][2];
            int cycle = g + y + r;

            int remain = t % cycle;
            if (remain == 0) remain = cycle; 
            

            if (!(remain > g && remain <= g + y)) 
            {
                all_yellow = false;
                break; 
            }
        }
        
        if (all_yellow) return t;
    }
    
    return -1;
}