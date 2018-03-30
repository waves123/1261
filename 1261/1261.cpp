#include <cstdio>
#include <queue>
using namespace std;

int a[555][555];
int d[555][555];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;
int main() {

	scanf("%d", &M);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;

	q.push(make_pair(0, 0));
	d[0][0] = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (d[nx][ny] == -1) {
					if (a[nx][ny] == 0) {
						d[nx][ny] = d[x][y];
						q.push(make_pair(nx, ny));
					}
					else {
						d[nx][ny] = d[x][y] + 1;
						next_q.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (q.empty()) {
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
	}
	printf("%d", d[N - 1][M - 1]);
}