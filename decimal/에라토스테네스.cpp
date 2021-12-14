#include <iostream>

int is_prime[1000001] = {0,};

int main() {

	int M, N;
	std::cin >> M >> N;
	
	// 현재 모두를 입력
	for (int i = 2; i <= N; i++)
		is_prime[i] = i;

	for (int i = 2; i <= N; i++) {
		if (is_prime[i] == 0) continue;
		
		for (int j = i * 2; j <= N; j += i)
			is_prime[j] = 0;
	}

	for (int i = M; i <= N; i++) {
		if (is_prime[i] != 0) 
			std::cout << is_prime[i]<<'\n';
	}

	return 0;
}