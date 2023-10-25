#include <stdio.h>

// 뤼카 정리로 ncr mod 3 계산
int ncr(int x, int y) {
	if (x < 3 && y < 3) {
		if (x < y) return 0;
		if (x == 2 && y == 1) return 2;
		return 1;
	}
	return ncr(x / 3, y / 3) * ncr(x % 3, y % 3) % 3;
}

int main() {
	// 입력
	int N; char C[400009];
	scanf("%d", &N);
	scanf("%s", C);
	
	// 답 구하기
	int answer = 0;
	int i;
	for (i = 0; i < N; i++) {
		int code = -1;
		if (C[i] == 'B') code = 0;
		if (C[i] == 'W') code = 1;
		if (C[i] == 'R') code = 2;
		answer += code * ncr(N - 1, i);
		answer %= 3;
	}
	
	// 답에 (-1)^(N-1)을 곱함
	if (N % 2 == 0) {
		answer = (3 - answer) % 3;
	}
	
	// 답 출력("BWR"의 answer번째 문자)
	printf("%c\n", "BWR"[answer]);
	
	return 0;
}