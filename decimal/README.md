## 정수론 알고리즘에 관한 README입니다.


## 최대 gcd (9417번)
---

### 풀었던 방식
---
구성은 단순한 문제다. 입력받고 난 후 이중 for문으로 max 값을 찾는 방식으로 했다. 
단, C++로 하다보니, 입력으로 주어진 수의 개수가 정해지지 않아서 string으로 받아 스페이스바 기준으로 split한 후 
int형으로 변환해주었다.

### 부족했던 점
---
처음에는 while(cin >> a) 형식으로 했는데, 이러다보니 max_gcd 값을 어디에다 출력시킬지가 고민이었다. 그게 생각이 안 나서 string으로 바꿨다.
cin.ignore를 하기 전, 돌아가는 횟수를 입력받을 때 getline이 wait하지 않고 그대로 max_gcd를 출력시켰다. 이 이유는 좀 더 찾아보자.





## 보이는 점

### 풀었던 방식
---
x,y 좌표가 서로소이면 된다는 점에서 착안하여 풀었다. 그래서 만일 gcd가 1일 경우에 보이는 점으로 판별하였다.
또한, x, y값이 둘 다 N 안에 들어있으므로, y = x에 대해 대칭이다. 그래서 for문을 돌릴 때, j를 i보다 작은 범위로 측정하여(y < x인 부분만을 구하기 위해) 추후에 2를 곱해주었다. 
시간초과가 나서, 원래 있던 값이 있으면 그 index+1부터 푼 후에, 배열의 index부분의 값을 더해주는 식으로 했다.
하지만 여전히 시간 초과였다.

````
int stored_index(int* shown_point, int n) {

	int index = 0;
	for (int i = n; i > 0; i--)
		if (shown_point[i]) {
			//제일 큰 index만 있으면 됨.
			index = i;
			break;
		}

	return index;
}
std::cin >> c;

	while (c--) {
		std::cin >> n;
		shown_point[1] = 3;

		index = stored_index(shown_point, n);

		//i -> x, j -> y
		for (int i = index + 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				gcd = get_gcd(i, j);
				
				if (gcd == 1) {
					//std::cout << "(" << i << " , " << j << ")" << '\n';
					shown_point[n]++;
				}
			}
		}
		shown_point[n] *= 2; 
		shown_point[n] += shown_point[index];
		std::cout << shown_point[n] << '\n';
		
	}
````



### 부족했던 점
---
나의 고질적인 실수다. 이는 골드바흐의 추측 문제를 풀었을 때도 했던 실수였다.
내 원래 코드로 했을 경우에는 최대 1000까지 계속 돈다는 문제가 있다. 만일 c = 1000, n = 1000이라면 아마도 1억번이 넘게 될 것이다.
그러므로 시간을 줄이려면 먼저 shown_point에 들어갈 값들을 계산하고 난 후에 입력받은 숫자를 바로 찾을 수 있게 해야한다.
정말.. 꼭 기억하자. 


