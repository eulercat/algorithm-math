import java.util.*;

class Code_5_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		if (N % 4 == 0) {
			System.out.println("Second"); // 후수필승
		}
		else {
			System.out.println("First"); // 선수필승
		}
	}
}
