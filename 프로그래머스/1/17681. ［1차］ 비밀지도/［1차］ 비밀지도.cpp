#include <string>
#include <vector>
#include <algorithm> // reverse 함수 사용을 위해

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;

    for (int i = 0; i < n; i++) 
    {
        int combined = arr1[i] | arr2[i];
        string row = "";

        for (int j = 0; j < n; j++) 
        {
            if (combined % 2 == 1) 
            {
                row += "#";
            } 
            else 
            {
                row += " ";
            }
            combined /= 2;
        }

        reverse(row.begin(), row.end());
        answer.push_back(row);
    }

    return answer;
}