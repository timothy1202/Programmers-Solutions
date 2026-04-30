#include <vector>
#include <set>
using namespace std;

int solution(vector<int> arr) {
    set<int> s;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[(i + j) % n];
            s.insert(sum);
        }
    }

    return s.size();
}