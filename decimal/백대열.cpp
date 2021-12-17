#include <iostream>
#include <string>

int get_gcd(int A, int B) {

	int R = A % B;
	if (R == 0) return B;
	else return get_gcd(B, R);

}

int main() {

	int current, gcd;
	
	std::string substring[2];
	std::string str;

	std::cin >> str;

	current = str.find(':');
	substring[0] = str.substr(0, current);
	substring[1] = str.substr(current+1);
		
	int a = std::stoi(substring[0]);
	int b = std::stoi(substring[1]);

	gcd = get_gcd(a, b);
	std::cout << a / gcd << ":" << b / gcd << '\n';

}