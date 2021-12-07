#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	vector<int> binary;

	long long n = 0;
	cin >> n;

	while (n != 0) {
		
		binary.push_back(n % 2);
		n = n / 2;
	}

	for (auto ir = binary.rbegin(); ir != binary.rend(); ++ir)
		cout << *ir;

	return 0;
}