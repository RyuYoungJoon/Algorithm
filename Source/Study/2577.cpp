#include <iostream>

using namespace std;

int main()
{
	int A{};
	int B{};
	int C{};
	int Arr[10]{};

	

	cin >> A;
	cin >> B;
	cin >> C;

	int Result = A * B * C;
	int Rest{};

	for (int i = 0; Result > 0; ++i) {
		Rest = Result % 10;
		Result = Result / 10;
		Arr[Rest]++;
	}

	for (int i = 0; i < 10; ++i)
		cout << Arr[i] << endl;
}