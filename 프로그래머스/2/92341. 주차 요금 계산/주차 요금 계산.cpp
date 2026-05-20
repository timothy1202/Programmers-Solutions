#include <bits/stdc++.h>
using namespace std;

int toMinutes(string time) 
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int calcFee(int totalTime, vector<int>& fees) 
{
    int baseTime = fees[0], baseFee = fees[1];
    int unitTime = fees[2], unitFee = fees[3];

    if (totalTime <= baseTime) return baseFee;

    int over = totalTime - baseTime;
    return baseFee + ((over + unitTime - 1) / unitTime) * unitFee; // 올림 나눗셈!
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    map<string, int> inTime; 
    map<string, int> total;  

    for (auto& record : records) 
    {
        string time = record.substr(0, 5);
        string carNum = record.substr(6, 4);
        string type = record.substr(11);

        if (type == "IN") 
        {
            inTime[carNum] = toMinutes(time);
        } 
        else 
        { // OUT
            total[carNum] += toMinutes(time) - inTime[carNum];
            inTime.erase(carNum);
        }
    }

    // 출차 기록 없는 차량 → 23:59 출차 처리
    for (auto& [carNum, t] : inTime) 
    {
        total[carNum] += toMinutes("23:59") - t;
    }

    // map은 이미 차량번호 오름차순 정렬됨
    vector<int> answer;
    for (auto& [carNum, t] : total) 
    {
        answer.push_back(calcFee(t, fees));
    }

    return answer;
}