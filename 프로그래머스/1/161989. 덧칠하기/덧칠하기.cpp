#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int count = 0;
    int last_painted = 0; 

    for (int s : section) 
    {
        if (s > last_painted) 
        {
            count++;
            last_painted = s + m - 1;
        }
    }

    return count;
}