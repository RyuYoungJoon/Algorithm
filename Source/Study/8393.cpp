#include <iostream>

using namespace std;

int main()
{

	int N{};
	int result{};
	cin >> N;

	for (int i = N; i > 0; --i) {
		result += i;
	}

	cout << result << endl;
}