#include <bits/stdc++.h>

using namespace std;

class Editor
{
public:
	Editor(){}
	Editor(string s) 
	{
		for (auto c : s)
			ls.push_back(c);
		cursor = ls.end();
	}

private:
	list<char> ls;
	list<char>::iterator cursor;

public:
	void Command(const char cmd, char parm = '\0')
	{
		switch (cmd)
		{
		case 'L':
			if (ls.begin() != cursor)
				cursor--;
			break;
		case 'D':
			if (ls.end() != cursor)
				cursor++;
			break;
		case 'B':
			if (cursor != ls.begin())
				cursor = ls.erase(--cursor);
			break;
		case 'P':
			cursor = ls.insert(cursor, parm);
			cursor++;
			break;
		default:
			break;
		}

	}


	void Print()
	{
		for (auto c : ls) cout << c;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string s;
	char cmd, parm;
	
	cin >> s;
	cin >> N;

	Editor editor = Editor(s);

	while (N--)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> parm;
			editor.Command(cmd, parm);
		}
		else
		{
			editor.Command(cmd);
		}
	}

	editor.Print();

}



