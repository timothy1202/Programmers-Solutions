#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 위치(r, c)에서 size만큼의 정사각형 돗자리를 깔 수 있는지 확인하는 함수
bool can_place(int r, int c, int size, const vector<vector<string>>& park) 
{
    int H = park.size();
    int W = park[0].size();

    // 돗자리가 공원 범위를 벗어나면 설치 불가
    if (r + size > H || c + size > W) return false;

    // 해당 범위 내에 사람이("-1"이 아닌 값) 한 명이라도 있으면 설치 불가
    for (int i = r; i < r + size; ++i) 
    {
        for (int j = c; j < c + size; ++j) 
        {
            if (park[i][j] != "-1") return false;
        }
    }
    
    return true;
}


int solution(vector<int> mats, vector<vector<string>> park) 
{
    // 1. 큰 돗자리부터 확인하기 위해 내림차순 정렬
    sort(mats.begin(), mats.end(), greater<int>());

    int H = park.size();
    int W = park[0].size();

    // 2. 가장 큰 돗자리부터 하나씩 꺼내어 검사
    for (int size : mats) 
    {
        // 3. 공원의 모든 좌표를 순회
        for (int i = 0; i < H; ++i) 
        {
            for (int j = 0; j < W; ++j) 
            {
                // 4. 해당 좌표에 돗자리를 깔 수 있는지 확인
                if (can_place(i, j, size, park)) 
                {
                    // 가장 큰 돗자리부터 검사했으므로, 찾자마자 바로 반환
                    return size;
                }
            }
        }
    }

    // 깔 수 있는 돗자리가 하나도 없는 경우
    return -1;
}