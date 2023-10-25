#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N = 1000000;
	int M = 0;
	
	for (int i = 1; i <= N; i++) {
		double px = 6.0 * rand() / (double)RAND_MAX;
		double py = 9.0 * rand() / (double)RAND_MAX;
		
		// 점 (3, 3)과의 거리입니다. 이 값이 3 이하라면, 반지름 3인 원 내부에 포함됩니다.
		double dist_33 = sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
		
		// 점 (3, 7)과의 거리입니다. 이 값이 2 이하라면, 반지름 2인 원 내부에 포함됩니다.
		double dist_37 = sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
		
		// 조건 분기
		if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
	}
	
	// 답 출력
	cout << M << endl;
	return 0;
}