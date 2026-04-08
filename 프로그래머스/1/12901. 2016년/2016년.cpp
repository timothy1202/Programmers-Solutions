#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) 
{

    int days_before_month[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    
    int num = days_before_month[a-1] + b - 1;
    int day = num % 7;

    if(day == 0) return "FRI";
    else if(day == 1) return "SAT";
    else if(day == 2) return "SUN";
    else if(day == 3) return "MON";
    else if(day == 4) return "TUE";
    else if(day == 5) return "WED";
    else if(day == 6) return "THU";
    
    return "";
}