#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    deque<string> cache;

    for(string city : cities) 
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        auto it = find(cache.begin(), cache.end(), city);

        if(it != cache.end()) 
        {
            cache.erase(it);        
            cache.push_back(city);
            answer += 1;
        } 
        else 
        {
            if(cacheSize == 0) 
            {
                answer += 5;
                continue;
            }
            if(cache.size() == cacheSize)
                cache.pop_front(); 
            
            cache.push_back(city);
            answer += 5;
        }
    }
    return answer;
}