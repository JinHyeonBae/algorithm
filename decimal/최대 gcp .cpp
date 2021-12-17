#include <iostream>
#include <vector>
#include <sstream>
#include <typeinfo>

int get_max_gcd(int A, int B) {

	if (A < B)
		return B;
	else
		return A;
}

int get_gcd(int A, int B) {

	int R = A % B;
	if (R == 0) return B;
	else return get_gcd(B, R);

}

void str_split(std::string numbers, std::vector<int>& v) {
	
	int strB;
	std::istringstream ss(numbers);
	std::string stringBuffer;
	while (getline(ss, stringBuffer, ' ')) {
		strB = std::stoi(stringBuffer);
		v.push_back(strB);
	}

}


int main() {

	std::vector<int> gcd;
	int n, max_gcd=0;
	
	std::string numbers;
	std::cin >> n;
	std::cin.ignore(); //not working for cin.clear()

	while (n--) {

		gcd.clear();
		max_gcd = 0;
		std::getline(std::cin, numbers);
		str_split(numbers, gcd);

		for (int i = 0; i < gcd.size(); i++) {
			for (int j = i + 1; j < gcd.size(); j++) {
				int temp = get_gcd(gcd[i], gcd[j]);
				max_gcd = get_max_gcd(max_gcd, temp);
			}
		}
		std::cout << max_gcd << '\n';
	}


	return 0;
}