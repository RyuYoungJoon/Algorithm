#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{};
	int Max = -1'000'000;
	int Min = 1'000'000;
	cin >> N;

	int* pArray = new int[N];

	for (int i = 0; i < N; ++i)
		cin >> pArray[i];

	for (int i = 0; i < N; ++i) {
		if (pArray[i] > Max)
			Max = pArray[i];
		if (pArray[i] < Min)
			Min = pArray[i];
	}

	cout << Min << " " << Max << endl;
	delete[] pArray;


}