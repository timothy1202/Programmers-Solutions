#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        int current = storey % 10; // 현재 일의 자리 수
        int next = (storey / 10) % 10; // 그다음 십의 자리 수
        
        if (current > 5) {
            // 5보다 크면 더해서 올림을 하는 게 이득
            answer += (10 - current);
            storey += (10 - current);
        } 
        else if (current == 5) {
            // 5일 때는 앞자리를 보고 결정
            if (next >= 5) {
                // 앞자리가 5 이상이면 올림이 이득
                answer += 5;
                storey += 5;
            } else {
                // 앞자리가 5 미만이면 내림이 이득
                answer += 5;
            }
        } 
        else {
            // 5보다 작으면 빼서 내림을 하는 게 이득
            answer += current;
        }
        
        // 다음 자릿수로 이동
        storey /= 10;
    }
    
    return answer;
}