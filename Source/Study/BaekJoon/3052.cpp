#include <iostream>

using namespace std;

int main()
{
	int N{};
	int rest{};
	int cnt{};
	int result{};
	int num[10]{};


	for (int i = 0; i < 10; ++i) {		// �����
		cin >> N;
		num[i] = N % 42;
	}

	for (int i = 0; i < 10; ++i) {
		cnt = 0;	// �ٽ� �ʱ�ȭ
		for (int j = i+1; j < 10; ++j) {
			if (num[i] == num[j]) // �ߺ��� �ִ��� ������ Ȯ��
				cnt++;
			
		}
		if (cnt == 0) // ��ü Ž�� ������ ��ġ�°��� ���ٸ�
			result++; // ��� +1
	}

	

	cout << result << endl;

}