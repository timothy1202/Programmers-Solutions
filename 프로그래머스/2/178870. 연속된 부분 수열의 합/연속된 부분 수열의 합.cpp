#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> answer = {0, 0};
    
    int left = 0;
    int right = 0;
    int sum = sequence[0];
    int min_length = 987654321; 

    while (right < sequence.size()) 
    {
        if (sum < k) 
        {
            right++;
            if (right < sequence.size()) 
            {
                sum += sequence[right];
            }
        } 
        else if (sum > k) 
        {
            sum -= sequence[left];
            left++;
        } 
        else 
        { 
            int current_length = right - left + 1;
            
            if (current_length < min_length) 
            {
                min_length = current_length;
                answer[0] = left;
                answer[1] = right;
            }
            
            sum -= sequence[left];
            left++;
        }
    }

    return answer;
}