#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, int k) {
    int answer = 0;

    vector<int> div_k;
    while (n > 0) {
        div_k.push_back(n % k);
        n /= k;
    }

    vector<long long> nums; // ✅ long long
    long long sum = 0;      // ✅ long long
    for (int i = div_k.size() - 1; i >= 0; i--) {
        if (div_k[i] == 0) {
            if (sum != 0) {
                nums.push_back(sum);
                sum = 0;
            }
        } else {
            sum = sum * 10 + div_k[i];
        }
    }
    if (sum != 0) nums.push_back(sum);

    for (long long num : nums) {
        if (num < 2) continue;
        bool isprime = true;
        for (long long j = 2; j <= sqrt((double)num); j++) {
            if (num % j == 0) { isprime = false; break; }
        }
        if (isprime) answer++;
    }

    return answer;
}