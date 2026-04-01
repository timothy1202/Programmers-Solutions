#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Pos 
{
    int x, y;
};


Pos keypad[12] = {
    {1, 0}, // 0
    {0, 3}, {1, 3}, {2, 3}, // 1, 2, 3
    {0, 2}, {1, 2}, {2, 2}, // 4, 5, 6
    {0, 1}, {1, 1}, {2, 1}, // 7, 8, 9
    {0, 0}, {2, 0}          // 10(*), 11(#)
};


int getDistance(Pos a, Pos b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    

    Pos leftPos = keypad[10];
    Pos rightPos = keypad[11];
    
    for(int num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            answer += "L";
            leftPos = keypad[num]; // 구조체는 직접 대입이 가능합니다!
        }
        else if(num == 3 || num == 6 || num == 9) {
            answer += "R";
            rightPos = keypad[num];
        }
        else {
            // 가운데 버튼 (2, 5, 8, 0) 처리
            Pos target = keypad[num];
            int l_dist = getDistance(leftPos, target);
            int r_dist = getDistance(rightPos, target);
            
            if(l_dist < r_dist) {
                answer += "L";
                leftPos = target;
            }
            else if(r_dist < l_dist) {
                answer += "R";
                rightPos = target;
            }
            else { // 거리가 같을 때
                if(hand == "right") {
                    answer += "R";
                    rightPos = target;
                } else {
                    answer += "L";
                    leftPos = target;
                }
            }
        }
    }
    
    return answer;
}