# 입력
N = int(input())

# 소인수분해
Answer = []
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT + 1):
	while N % i == 0:
		N /= i
		Answer.append(i)

if N >= 2:
	Answer.append(int(N))

# 출력
print(*Answer)