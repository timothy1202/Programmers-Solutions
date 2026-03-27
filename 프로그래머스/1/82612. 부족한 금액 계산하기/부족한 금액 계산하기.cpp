using namespace std;

long long solution(int price, int money, int count)
{
    int start_price = price;
    long long answer = -1;
    long long sum =price;
    for(int i=2;i<count+1;i++)
    {
        price = price + start_price;
        sum += price;
    }
    answer = sum - money;
    if(answer<0) answer =0;

    return answer;
}