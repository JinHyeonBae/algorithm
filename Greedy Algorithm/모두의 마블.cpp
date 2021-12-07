#include <iostream>
#include <vector>
using namespace std;


int get_maximum_gold(vector<int>& card_levels) {

	int max = 0, max_index = 0, sum = 0;

	for (int i = 0; i < card_levels.size(); i++) {
		if (max < card_levels[i]) {
			max = card_levels[i];
			max_index = i;
		}
	}

	int cal_index = 0;
	while (card_levels.size() != 1) {
		
		cal_index = max_index - 1;
	
		if (cal_index < 0) 
			cal_index = max_index + 1;
		
		sum += max + card_levels[cal_index];
		card_levels.erase(card_levels.begin() + cal_index);
		
		if (max_index != 0)
			max_index = max_index - 1;
	}
	
	return sum;

}


int main() {

	int card_count =0, n, result =0;
	vector<int> card_levels;

	cin >> card_count;
	for (int i = 0; i < card_count; i++) {
		cin >> n;
		card_levels.push_back(n);
	}
	
	result = get_maximum_gold(card_levels);
	cout << result;

	return 0;
}