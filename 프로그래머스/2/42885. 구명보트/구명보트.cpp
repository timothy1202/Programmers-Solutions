#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    
    while(left <= right)
    {
        if(people[left] + people[right] <= limit)
            left++;   // 가벼운 사람도 탑승
        
        right--;      // 무거운 사람은 항상 탑승
        answer++;
    }
    
    return answer;
}