// algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> max;
int max_sum = 0;

// 점수 배열, 인덱스 배열, 점수 배열의 사이즈
int raiseStairs(vector<int> &score, vector<int> &m, int n) {

	int temp = 0;
	
	for (int i = 4; i <= n; i++) {
		m.push_back(i);

		for (int j = 0; j < m.size(); j++)
			temp += score[m[j]];

		if (max_sum < temp)
			max_sum = temp;
	}

	return max_sum;


}



int main() {

	vector<int> m1{ 1,2 };
	vector<int> m2{ 1,3 };
	
	int n = 0, input = 0;
	cin >> n;
	
	vector<int> score;

	for (int i = 0; i < n; i++) {
		cin >> input;
		score.push_back(input);
	}

	int m1_sum = raiseStairs(score, m1, n);
	int m2_sum = raiseStairs(score, m1, n);

	if (m1_sum < m2_sum)
		cout << m2_sum;
	else
		cout << m1_sum;

	return 0;
}


