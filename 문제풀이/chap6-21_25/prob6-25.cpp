#include <vector>
#include <iostream>
using namespace std;

int N, M, A[100009], B[100009]; vector<int> G[100009];

int dp[100009]; bool visited[100009];
void dfs(int pos) {
	visited[pos] = true;
	dp[pos] = 1;
	for (int i : G[pos]) {
		if (visited[i] == false) {
			dfs(i);
			dp[pos] += dp[i];
		}
	}
}

int main() {
	// 입력
	int N;
	cin >> N;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// 깊이 우선 탐색 (DFS)를 사용한 동적계획법
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dfs(1);
	
	// 답을 계산하고 출력
	long long answer = 0;
	for (int i = 2; i <= N; i++) {
		answer += 1LL * dp[i] * (N - dp[i]);
	}
	cout << answer << endl;
	
	return 0;
}