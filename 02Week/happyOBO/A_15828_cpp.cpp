#include <bits/stdc++.h>

using namespace std;

queue<int> solution(int N);
void print(queue<int>& q);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	queue<int> q = solution(N);
	print(q);
}


queue<int> solution(int N)
{
	queue<int> q;
	int data;
	while (true)
	{
		cin >> data;

		if (data == 0) q.pop();

		else if (data < 0) break;

		else
		{
			if (q.size() < N)
				q.push(data);
		}
	}
	
	return q;

}


void print(queue<int>& q)
{
	if (q.empty())
		cout << "empty";
	else
	{
		// print
		while (1 < q.size())
		{
			cout << q.front() << " ";
			q.pop();
		}

		cout << q.front();
		q.pop();
	}
}