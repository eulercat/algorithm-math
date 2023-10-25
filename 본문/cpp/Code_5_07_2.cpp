#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long N, A[200009], Answer = 0;
long long fact[200009];

long long modpow(long long a, long long b, long long m) {
	// 반복제곱법(p에는 a^1, a^2, a^4, a^8, ...가 할당됨)
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long ncr(int n, int r) {
	// ncr은 n!를 r! × (n-r)!으로 나눈 값
	return Division(fact[n], fact[r] * fact[n - r] % mod, mod);
}

int main() {
	// 배열 초기화(fact[i]는 i의 거듭제곱을 1000000007로 나눈 나머지)
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = 1LL * i * fact[i - 1] % mod;

	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 답 구하기 → 답 출력
	for (int i = 1; i <= N; i++) {
		Answer += A[i] * ncr(N - 1, i - 1);
		Answer %= mod;
	}
	cout << Answer << endl;
	return 0;
}