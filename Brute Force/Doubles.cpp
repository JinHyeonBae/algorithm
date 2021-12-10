#include <iostream>
#include <array>
#include <algorithm>



int main() {

	int n = 0, index = 0, count=0;
	int input_array[15] = { 0, };
		
	int* p;


	while (true) {
		
		std::cin >> n;

		if (n != 0) {
			input_array[index] = n;
			index++;
		}
		else {
			// 오름차순
			count = 0;
			std::sort(input_array, input_array + index);

			for (int i = 0; i < index; i++) {
				int want_found = input_array[i] * 2;
				p = std::find(input_array, input_array + index, want_found);

				if (p != input_array + index)
					count++;
			}
			std::cout << count << '\n';
			index = 0;
		}

		if (n == -1)
			break;

	}

	return 0;
}