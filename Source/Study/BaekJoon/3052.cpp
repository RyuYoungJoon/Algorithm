#include <iostream>

using namespace std;

int main()
{
	int N{};
	int rest{};
	int cnt{};
	int result{};
	int num[10]{};


	for (int i = 0; i < 10; ++i) {		// 입출력
		cin >> N;
		num[i] = N % 42;
	}

	for (int i = 0; i < 10; ++i) {
		cnt = 0;	// 다시 초기화
		for (int j = i+1; j < 10; ++j) {
			if (num[i] == num[j]) // 중복이 있는지 없는지 확인
				cnt++;
			
		}
		if (cnt == 0) // 전체 탐색 했을때 겹치는것이 없다면
			result++; // 결과 +1
	}

	

	cout << result << endl;

}