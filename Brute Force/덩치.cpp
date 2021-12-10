#include <iostream>
#include <algorithm>

int main() {

	int n = 0, ranking;
	int build_info[50][2] = { 0, }, rank[50] = { 0, };
	
	std::fill(rank, rank+50, 1);

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		//¸ö¹«°Ô, Å°
		std::cin >> build_info[i][0] >> build_info[i][1];

		for (int j = 0; j < i; j++) {			

			if (build_info[i][0] < build_info[j][0] && build_info[i][1] < build_info[j][1]) 
				rank[i] += 1;

			if (build_info[i][0] > build_info[j][0] && build_info[i][1] > build_info[j][1]) 
				rank[j] += 1;

		}
	}

	for (int i = 0; i < n; i++)
		std::cout << rank[i] << ' ';

	return 0;
}