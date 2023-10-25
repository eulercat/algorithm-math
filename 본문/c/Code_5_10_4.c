#include <stdio.h>

int main() {
	// 입력
	int N; char S[500009];
	scanf("%d%s", &N, S);

	// (의 수에서 )의 수를 뺀 값을 depth에 할당합니다.
	// 중간에 depth가 음수가 된다면, 곧바로 답이 No입니다.
	int depth = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			printf("No\n");
			return 0;
		}
	}

	// 마지막으로 depth = 0[(와 )의 수가 같음]을 추가적으로 판정합니다.
	if (depth == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
