#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// "HH:MM" 문자열을 분(minute) 단위 정수로 변환하는 함수
int convertToMinutes(string timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

int solution(vector<vector<string>> book_time) {
    // 하루는 24시간 * 60분 = 1440분입니다. 
    // 퇴실 후 10분 청소 시간 때문에 1440을 넘길 수 있으므로 여유 있게 1450 정도로 잡습니다.
    vector<int> timeline(1450, 0);

    for (const auto& book : book_time) {
        int start = convertToMinutes(book[0]);
        int end = convertToMinutes(book[1]) + 10; // 퇴실 시간 + 청소 시간 10분

        // 해당 시간에 예약 인원 추가/제거 표시
        timeline[start] += 1;
        timeline[end] -= 1;
    }

    int answer = 0;
    int current_rooms = 0;

    // 시간을 순차적으로 누적해가며 가장 방이 많이 필요한 순간을 찾습니다.
    for (int i = 0; i < 1450; i++) {
        current_rooms += timeline[i];
        answer = max(answer, current_rooms);
    }

    return answer;
}