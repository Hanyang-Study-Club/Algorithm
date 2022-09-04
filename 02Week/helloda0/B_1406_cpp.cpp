#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n;
string word;
stack<char> s1;
stack<char> s2;

int main() {
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		s1.push(word[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		char newc;
		cin >> newc;
		if (newc == 'P') {
			char newsc;
			cin >> newsc;
			s1.push(newsc);
		}
		else if (newc == 'L') {
			if (!s1.empty()) {
				char movechar = s1.top();
				s1.pop();
				s2.push(movechar);
			}
		}
		else if (newc == 'D') {
			if (!s2.empty()) {
				char movechar = s2.top();
				s2.pop();
				s1.push(movechar);
			}
		}
		else if (newc == 'B') {
			if (!s1.empty()) {
				s1.pop();
			}
		}
	}
	while (!s1.empty()) {
		char movechar = s1.top();
		s1.pop();
		s2.push(movechar);
	}

	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}

	return 0;
}