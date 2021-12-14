#include <iostream>

int get_gcd(int A, int B) {
	int R = A % B;

	if (R == 0) return B;
	else return get_gcd(B, R);

}

int main() {

	int A, B, gcd, lcm;

	std::cin >> A >> B;
	
	gcd = get_gcd(A, B);
	lcm = A * B / gcd;

	std::cout << gcd << '\n';
	std::cout << lcm << '\n';

	return 0;
}