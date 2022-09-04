#include <bits/stdc++.h>
#include <climits>

using namespace std;

int GetSecondBigger(int row, int column);

const static int MAXSIZE = 1025;
int mat[MAXSIZE][MAXSIZE];

void Divide(int& CurrentSize)
{
	for (int i = 0; i < CurrentSize; i += 2)
	{
		for (int j = 0; j < CurrentSize; j += 2)
		{
			mat[i / 2][j / 2] = GetSecondBigger(i, j);
		}
	}
	CurrentSize /= 2;
}

int GetSecondBigger(int row, int column)
{
	int SecondMAX, FirstMAX;
	FirstMAX = SecondMAX = INT_MIN;
	for (int i = row; i < row + 2; i++)
	{
		for (int j = column; j < column + 2; j++)
		{
			if (FirstMAX <= mat[i][j])
			{
				SecondMAX = FirstMAX;
				FirstMAX = mat[i][j];
			}
			else if (SecondMAX < mat[i][j])
			{
				SecondMAX = mat[i][j];
			}
		}
	}

	return SecondMAX;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int CurrentSize;

	cin >> CurrentSize;
	for (int i = 0; i < CurrentSize; i++)
	{
		for (int j = 0; j < CurrentSize; j++)
		{
			cin >> mat[i][j];
		}
	}

	while (1 < CurrentSize)
	{
		Divide(CurrentSize);
	}

	cout << mat[0][0];
}
