#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    

    vector<int> n1 = {1, 2, 3, 4, 5};
    vector<int> n2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> n3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int n1_a = 0, n2_a = 0, n3_a = 0;
    
    for(int i = 0; i < answers.size(); i++)
    {

        if(n1[i % n1.size()] == answers[i]) n1_a++;
        if(n2[i % n2.size()] == answers[i]) n2_a++;
        if(n3[i % n3.size()] == answers[i]) n3_a++;
    }
    
    int max_score = max({n1_a, n2_a, n3_a});
    
    if(n1_a == max_score) answer.push_back(1);
    if(n2_a == max_score) answer.push_back(2);
    if(n3_a == max_score) answer.push_back(3);
    
    return answer;
}