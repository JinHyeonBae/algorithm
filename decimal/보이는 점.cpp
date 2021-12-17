#include <iostream>
#include <vector>

int get_gcd(int A, int B) {

	int R = A % B;
	if (R == 0) return B;
	else return get_gcd(B, R);

}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int shown_point[1001] = {0,};
	int c, n, ans = 0;
	
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j < i; j++) {
			if (get_gcd(i, j) == 1) {
				ans++;
			}
		}
		shown_point[i] = ans;
 	}

	std::cin >> c;

	while (c--) {
		std::cin >> n;
		std::cout << shown_point[n] *2 + 3<< '\n';
		
	}

	return 0;
}