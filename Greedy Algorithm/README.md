<br>

# 해당 README는 그리드 알고리즘에 대한 코드리뷰입니다.
---
<br>

## 그리디 알고리즘이란?

매 선택에서 "현재" 가장 최적인 답을 선택하여 적합한 결과를 도출하는 알고리즘이다. 백트래킹을 통해 추가점검하지 않고, 현재 조건에서 선택을 했다면 다른 선택의 가능 경우는 검증하지 않는다.

이러한 특징 때문에 전체에서 최적값을 언제나 구할 수 없다. 즉, 부분 최적해는 구할 수 있으나 전체 문제에서의 최적값은 구하지 못하는 경우가 생긴다.

그리디 알고리즘이 사용되는 조건은 아래와 같다.

1. 탐욕 선택 속성
    
    이전의 선택이 이후에 영향을 주지 않음
    
2. 최적 부분 구조
    
    부분 문제의 최적 결과가 전체에도 적용될 수 있음
    
<br>

## 스네이크버그(백준 12845번)
<br>

### 풀었던 방식

---

c++ stl의 sort 함수로 오름차순 정렬을 시행한 다음, 벌레의 크기와 배열의 값을 비교하는 방식으로 벌레의 크기를 늘렸다. 

오름차순 정렬을 시행하면, 무조건 작은 것부터 큰 것까지 줄 세워지므로 만일 특정 배열값이 벌레의 값보다 크다면, 그 이후의 값들은 무조건 벌레가 먹지 못하므로 효율적이다.

### 부족했던 점

---

1. 오름차순이라 배열의 크기만큼 비교할 필요 없이, 더 큰 것이 나올 때까지 반복문을 시행하면 되었을 것이다. 코드 리뷰하다가 깨달은 사실..
2. 사실 메모리 효율을 위해서는 동적 할당이 더 낫지 않았나 싶다. 실행할 당시에 배열로만 40004 Bytes의 크기가 스택에 쌓였으므로 stack 메모리 초과 경고가 떴었다.


### 부족했던 점을 보완하여 다시 작성한 코드

```
#include <iostream>
#include <algorithm>
#define MAX_INPUT 10001
using namespace std;

void calc_max_length(int* arr, int* L, int size) {

	for (int i = 1; i <= size; i++) {
		if (arr[i] > *L) 
			break;
			
		*L = *L + 1;
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
```
<br>

## 모두의 마블(백준 12845번)
<br>
### 풀었던 방법

---

1. 카드 레벨 중 가장 큰 값을 찾는다.
2. 가장 큰 값의 앞, 혹은 뒤의 값과 더한다. 앞뒤의 값이 얼마이든 상관이 없다.
3. 더한 숫자를 벡터에서 지운다.
4. 벡터의 size가 1이 될 때까지 1,2,3을 반복한다.

우선 벡터는 배열에 비해 접근은 느리지만 삽입, 삭제가 용이할 때에 사용하므로 벡터를 이용하였다. 가장 큰 값이 위치한 값 인덱스를 구하여 그 주위의 값을 찾아 더하고 없앴다. 

없어지는 숫자에 따라 최댓값 index 또한 -1이 경감되기 때문에 max_index를 조절해주었다. 

단, outOfIndex가 나면 안되므로 조건을 적절히 넣어주었다. 

  

### 부족했던 점

---

1. 정렬을 하지 않은 것.
    
    풀 때 정렬은 염두해놓지 않았었는데, 왜냐하면 가장 큰 값의 주위의 값을 더해야하기 때문이었다. 정렬을 하게 되면 주위의 값들이 아닌 값들도 더할 수 있다는 생각 뿐이었다.
    
    다른 사람의 코드를 보고 생각해보니, 어차피 가장 큰 값과 나머지 값들을 더하는 문제이기 때문에 정렬을 해도 결국 같은 답을 내놓았다.  또한 정렬을 하면 결국 max값을 찾는 수고도 덜 수 있었다.

### 부족한 점을 보완한 코드
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	int card_count = 0, n, result = 0;
	vector<int> card_levels;

	cin >> card_count;

	for (int i = 0; i < card_count; i++) {
		cin >> n;
		card_levels.push_back(n);
	}

	sort(card_levels.begin(), card_levels.end());
	
	int card_size = card_levels.size();
	
	for (int i = 0; i < card_size-1; i++)
		result += card_levels[card_size - 1] + card_levels[i];

	cout << result;

	return 0;
}
```
