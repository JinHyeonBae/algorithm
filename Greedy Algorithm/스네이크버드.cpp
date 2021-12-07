#include <iostream>
#include <algorithm>
#define MAX_INPUT 10001
using namespace std;

void calc_max_length(int* arr, int* L, int size) {

	for (int i = 1; i <= size; i++) {
		if (arr[i] <= *L) {
			*L = *L + 1;
		}
	}
	cout << *L;
}


int main() {

	int N = 0, L = 0;
	int height[MAX_INPUT] = { 0, };
	
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		cin >> height[i];
	
	//오름차순으로 소트
	sort(height+1, height + N+1);
	calc_max_length(height, &L, N);

	return 0;

}