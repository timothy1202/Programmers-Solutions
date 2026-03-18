#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    map<char, int> min_press;

    for (const string& keys : keymap) 
    {
        for (int i = 0; i < keys.size(); i++) 
        {
            char current_char = keys[i];
            int press_count = i + 1;

            // 맵에 문자가 없거나, 현재 클릭 횟수가 저장된 값보다 작으면 업데이트
            if (min_press.find(current_char) == min_press.end() || press_count < min_press[current_char]) {
                min_press[current_char] = press_count;
            }
        }
    }

    for (const string& word : targets) 
    {
        int total_sum = 0;
        bool is_possible = true;

        for (char c : word) 
        {
            if (min_press.find(c) != min_press.end()) 
            {
                total_sum += min_press[c];
            } 
            else 
            {
                is_possible = false;
                break;
            }
        }

        if (is_possible) 
        {
            answer.push_back(total_sum);
        } 
        else 
        {
            answer.push_back(-1);
        }
    }

    return answer;
}