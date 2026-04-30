#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) 
{
    sort(arr.begin(), arr.end());
    int size = arr.size();

    for (int i = arr[size-1]; ; i++) 
    {
        bool good = true;
        for (int j = 0; j < size; j++) 
        {
            if (i % arr[j] != 0) 
            {
                good = false;
                break;
            }
        }
        if (good) return i;
    }
}