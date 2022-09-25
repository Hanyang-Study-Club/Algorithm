#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;

void solution( vector<int>& tree, int node1, int node2);
vector<int> getParents(vector<int>& tree, int child);


int main()
{
    int T, N, n1, n2;
    cin >> T;

    // 부모가 같는 자식으로 이중 배열을 만들어서 동작했는데
    // 자식이 갖는 부모로 배열을 만들어서 탐색하면 되지 않을까 싶음.
    while(T--)
    {
        cin >> N;
        vector<int> tree(N, -1); // 부모가 -1 인 노드는 가장 루트 노드 인 경우
        int parent, child;
        for (int i = 0; i < N-1; i++)
        {
            cin >> parent >> child;
            tree[child - 1] = parent - 1;
        }
        cin >> n1 >> n2;
        solution(tree, n1 -1, n2 -1);
    }

}

void solution( vector<int>& tree, int node1, int node2)
{
    vector<int> parents1 = getParents(tree, node1);
    vector<int> parents2 = getParents(tree, node2);


    int ptr1 = parents1.size() -1, ptr2 = parents2.size() - 1;
    int result = -1;

    while(0 <= ptr1 && 0 <= ptr2)
    {
        if(parents1[ptr1] != parents2[ptr2])
        {
            cout << result + 1<< "\n";
            return ;
        }
        else
        {
            result = parents1[ptr1];
            ptr1--;
            ptr2--;
        }
    }

    if(ptr1 < 0) cout << parents1[0] + 1 << "\n";
    else cout << parents2[0] + 1<< "\n";
}


vector<int> getParents(vector<int>& tree, int child)
{
    int curr = child;
    vector<int> result;
    result.push_back(child);
    while(tree[curr] != -1)
    {
        result.push_back(tree[curr]);
        curr = tree[curr];
    }
    return result;
}


