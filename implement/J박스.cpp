#include <iostream>


int main() {

	int n, count=0;
	std::cin >> n;

	for(int c=0; c<n; c++){
	
		std::cin >> count;

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (i == 0 || i == count - 1)
					std::cout << '#';
				else {
					if (j == 0 || j == count - 1)
						std::cout << '#';
					else
						std::cout << "J";
				}

				if (j == count - 1)
					std::cout << '\n';

				}
			}
		std::cout << '\n';
	}

	return 0;
}