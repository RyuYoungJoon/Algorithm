#include <iostream>

using namespace std;



	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int X{ };
	int Y{};
	int N{};

	cin >> N;

	int* result = new int[N];

	for (int i = 0; i < N; ++i) {
		cin >> X >> Y;
		result[i] = X + Y;
	}
	
	for (int i = 0; i < N; ++i) {
		cout << result[i] << "\n";
	}

	delete[] result;
}