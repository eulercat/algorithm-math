#include <iostream>
using namespace std;

int N, A[100009], B[100009];
int Q, L[100009], R[100009];

int main() {
	// 입력 → 누적합 구하기
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= Q; j++) cin >> L[j] >> R[j];
	B[0] = 0;
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];

	// 답 출력
	for (int j = 1; j <= Q; j++) cout << B[R[j]] - B[L[j] - 1] << endl;
	return 0;
}