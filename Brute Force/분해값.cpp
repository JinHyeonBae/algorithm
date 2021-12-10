#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

int sum;

int calc_digits_sum(int M) {

	sum = 0;
	while (M > 0) {
		sum += M % 10;
		M = M / 10;
	};

	return sum;
}


int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, decomposition_sum = 0, digits_sum = 0;

	std::cin >> N;
	for (int i = N - 54; i < N; i++) {
		digits_sum = calc_digits_sum(i);
		
		if (N - digits_sum == i) {
			decomposition_sum = i;
			break;
		}
	}

	std::cout << decomposition_sum;

	return 0;
}