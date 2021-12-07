#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void collect_digits(vector<int>& digits, unsigned long num) {
    if (num > 9) {
        collect_digits(digits, num / 10);
    }
    digits.push_back(num % 10);
}

int count_to_single_digit = 0;
int calc_digits(vector<int>& digits, int num) {
    
    int sum = 0;
    // 한자리 수 일 때
    if (num < 10) {
        return num;
    }
    else {
        collect_digits(digits, num);
        count_to_single_digit++;
        for (int num : digits) {
            cout << "num :" << num << '\n';
            sum += num;
            cout <<" sum :" << sum << '\n';
        }
        digits.clear();
        
        sum = calc_digits(digits, sum);
        cout << "calc_ sum :" << sum<<'\n';
        return sum;
    }
}


void judge_if_multiple(int num) {

    if (num % 3 == 0)
        cout << "YES \n";
    else
        cout << "NO \n";

}

int main() {

    vector<int> digits;
    int num , result = 0;
    cin >> num;

    result = calc_digits(digits, num);
    cout << count_to_single_digit << '\n';
    judge_if_multiple(result);
    return 0;
}