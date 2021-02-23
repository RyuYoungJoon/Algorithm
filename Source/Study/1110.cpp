#include <iostream>

using namespace std;

int main()
{
	int N{};
	int cnt = 0;
	cin >> N;
	int N2 = N;
	while (true) {
		cnt++;

		int X = N2 / 10;
		int Y = N2 % 10;

		int result = X + Y;

		N2 = (Y * 10) + (result % 10);
		if (N2 == N)
			break;

	}

	cout << cnt << endl;
}