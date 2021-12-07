
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//분할..? 그걸로도 풀 수 있을 것 같은데

vector<int> memorization{0};

// 메모리제이션을 위한 함수
void memorize(int index, int input) {

	memorization.push_back(input);
}

// line 갯수
int max_sum(int index) {
	
	if (memorization[index] > 0) {
		int sum = 0;
		for (int i = 1; i <= index; i++)
			sum += memorization[i];
	}

	return 0;
}


int count_element(int array_count) {
	int sum = 0;

	for (int i = 1; i <= array_count; i++)
		sum += i;

	return sum;
}
vector<int> m1;


int main() {

	int n, trian_value;
	cin >> n;

	n = count_element(n);

	for (int i = 1; i <= n; i++) {
		cin >> trian_value;
		m1.push_back(trian_value);
	}

	return 0;
}