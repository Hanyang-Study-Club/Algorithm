#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>

using namespace std;

void input(vector<int>& order);
void solution(vector<int>& preorder);
void postOrder(vector<int>& preorder, int startIdx, int endIdx);
int GetChildRightRootIdx(vector<int>& preorder, int startIdx, int endIdx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> preorder;

    input(preorder);

    solution(preorder);
    return 0;
}

void input(vector<int>& order)
{
    int num;
    while (cin >> num) {
        if (num == EOF) break;
        order.push_back(num);
    }
}

void solution(vector<int>& preorder)
{
    postOrder(preorder, 0, preorder.size());
}

// 전위 탐색은 첫번째 노드가 루트 노드.

void postOrder(vector<int>& preorder, int startIdx, int endIdx)
{
    if (endIdx <= startIdx) return;
    if (startIdx == endIdx -1) // 탐색 끝
    {
        cout << preorder[startIdx] << "\n";
        return;
    }

    int leftRootIdx = GetChildRightRootIdx(preorder, startIdx, endIdx);

    postOrder(preorder, startIdx + 1, leftRootIdx);
    postOrder(preorder, leftRootIdx, endIdx);

    cout << preorder[startIdx] << "\n";
}

// 이진트리 규칙에 따라 부모 노드 보다 작은 노드는 왼편에 있음
int GetChildRightRootIdx(vector<int>& preorder, int startIdx, int endIdx)
{
    int idx = startIdx + 1;
    while (idx < endIdx) {
        if (preorder[startIdx] < preorder[idx]) {
            break;
        }
        idx++;
    }
    return idx;
}