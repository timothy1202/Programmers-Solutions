#include <string>
#include <vector>

using namespace std;

// 최대 체력을 넘지 않도록 제한하는 함수
void is_max_hp(int &health, int max_health)
{
    if(health > max_health)
        health = max_health;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int max_health = health;
    int attack_num = 0;      // 현재 처리할 공격의 인덱스
    int bandage_time = 0;    // 현재 연속 회복 시간
    int end_time = attacks.back()[0]; // 마지막 공격 시간

    for(int i = 0; i <= end_time; ++i)
    {
        // 1. 공격 확인 (공격이 남아있고, 현재 시간이 공격 시간인 경우)
        if(attack_num < attacks.size() && i == attacks[attack_num][0])
        {
            health -= attacks[attack_num][1];
            bandage_time = 0; // 공격당하면 연속 회복 초기화
            attack_num++;
            
            if(health <= 0) return -1; // 체력이 0 이하가 되면 사망
            continue; // 공격받은 초에는 회복 불가
        }

        // 2. 회복 로직 (공격을 받지 않았을 때)
        health += bandage[1]; // 1초당 회복
        bandage_time++;
        
        // 시전 시간(bandage[0])만큼 연속 성공 시 추가 회복
        if(bandage_time == bandage[0])
        {
            health += bandage[2];
            bandage_time = 0; // 연속 회복 시간 초기화
        }

        // 3. 최대 체력 제한 적용
        is_max_hp(health, max_health);
    }
    
    return health;
}