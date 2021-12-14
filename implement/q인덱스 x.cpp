#include <iostream>
#include <array>
#include <algorithm>

int main() {

	int thesis_count = 0, q_index = 0, count=0;
	std::array<int, 1001> quotation_count = { 0, };

	std::cin >> thesis_count;

	for (int i = 1; i <= thesis_count; i++) {
		std::cin >> quotation_count[i];
	
	}

	//오름차순 정렬
	std::sort(quotation_count.begin()+1, quotation_count.begin()+thesis_count+1);

	int i = 1;
	while (true) {
		if (thesis_count < quotation_count[i] || thesis_count <= 0)
			break;

		q_index = quotation_count[i];
		thesis_count = thesis_count - i + 1;
		i++; 
	}

	std::cout << q_index<<'\n';

	return 0;
}