#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class ChargeSorter {
    // 최대 배터리 시간을 콘센트들에 하나씩 먼저 채워 넣어주는 방식
    priority_queue<int, vector<int>, less<int> > batteries; // max heap
    priority_queue<int, vector<int>, greater<int>> concents; // min heap

    int ConentSize = 0;
public:

    void Input(int N, int M)
    {
        ConentSize = M;
        int battery;
        for(int i = 0; i < N; i++)
        {
            cin >> battery;
            batteries.push(battery);
        }
    }

    void Solve()
    {
        while(!batteries.empty())
        {
            if(concents.size() < ConentSize)
            {
                concents.push(batteries.top());
            }
            else
            {
                concents.push(concents.top() + batteries.top());
                concents.pop();
            }
            batteries.pop();
        }

    }

    void Print()
    {
        int result = INT_MIN;
        while(!concents.empty())
        {
            result = max(result, concents.top());
            concents.pop();
        }
        cout << result;
    }



};

int main() {
    int N, M;
    ChargeSorter cs;
    cin >> N >> M;

    cs.Input(N,M);
    cs.Solve();
    cs.Print();

    return 0;
}
