#include <iostream>

using namespace std;

void judge_page(int N, int P) {

	// ���� ������
	if (P <= N / 2) {
		if (P % 2 == 0) {
			cout << P - 1 << ' ';
			cout << N+1 - P << ' ';
			cout << N +1 - (P - 1) << '\n';
		}
		else {
			cout << P + 1 << ' ';
			cout << N + 1 -(P+1) << ' ';
			cout << N + 1 -P << '\n';
		}
	}
	else {
		if (P % 2 == 0) {
			cout << N + 1 - P << ' ';
			cout << N + 1 - (P - 1) << ' ';
			cout << P - 1 << '\n';
		}
		else {
			cout << N + 1 - (P + 1) << ' ';
			cout << N + 1 - P << ' ';
			cout << P + 1 << '\n';
		}
	}

}

int main() {

	// �� ������ ����, ���õ� ������ ����
	int N=0, P=0;
	
	while (true) {
		cin >> N;

		if (N == 0)
			break;
		
		cin >> P;
		

		judge_page(N, P);

	}

	return 0;
}
