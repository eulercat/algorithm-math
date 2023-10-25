#include <stdio.h>

long long GCD(long long A, long long B) {
	if (B == 0) {
		return A; // 베이스 케이스
	}
	return GCD(B, A % B);
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
