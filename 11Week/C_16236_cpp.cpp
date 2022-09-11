#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct xy {
	int y, x;
};

int n;
int nowy, nowx;
int map[21][21] = { 0 };
int babySize = 2;
int babyAte = 0;
int canGo[21][21] = { 0 }; // 아기상어가 갈 수 있는 위치의 거리. 안되면 -1
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
queue<xy> q; // bfs용 큐
int targetY, targetX;
int Ans = 0;
int minDist;

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				nowy = i;
				nowx = j;
			}
		}
	}
}

void bfs() { // 거리 계산
	targetY = -1, targetX = -1;
	minDist = 10e8;
	memset(canGo, 0, sizeof(canGo));
	canGo[nowy][nowx] = 1;
	q.push({ nowy, nowx });
	while (!q.empty()) {
		xy now = q.front();
		for (int i = 0; i < 4; i++) {
			int r = now.y + dr[i];
			int c = now.x + dc[i];
			if (r < 0 || r >= n || c < 0 || c >= n) continue;
			if (canGo[r][c]) continue;
			if (map[r][c] == 9) {
				canGo[r][c] = canGo[now.y][now.x] + 1;
				q.push({ r,c });
			}
			else if (map[r][c] > babySize) {
				canGo[r][c] = -1;
			}
			else if (map[r][c] == babySize || map[r][c] == 0) {
				canGo[r][c] = canGo[now.y][now.x] + 1;
				q.push({ r,c });
			}
			else {
				canGo[r][c] = canGo[now.y][now.x] + 1;
				q.push({ r,c });
				if (minDist > canGo[r][c]) {
					targetY = r;
					targetX = c;
					minDist = canGo[r][c];
				}
				else if (minDist == canGo[r][c]) {
					if (r < targetY) {
						targetY = r;
						targetX = c;
						minDist = canGo[r][c];
					}
					else if (r == targetY) {
						if (c < targetX) {
							targetY = r;
							targetX = c;
							minDist = canGo[r][c];
						}
					}
				}
			}
		}
		q.pop();
	}
}

void Sol() {
	while (1) {
		bfs();
		if (targetY == -1 && targetX == -1) {
			break;
		}
		map[targetY][targetX] = 0;
		Ans += (minDist - 1);
		nowy = targetY;
		nowx = targetX;
		babyAte++;
		if (babySize == babyAte) {
			babySize++;
			babyAte = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력받기
	Input();
	// 솔루션
	Sol();

	cout << Ans;

	return 0;
}