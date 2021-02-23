#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N{};
	cin >> N;
	int* result = new int[N];

	int* X = new int[N];
	int* Y = new int[N];

	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
		result[i] = X[i] + Y[i];
	}

	for (int i = 0; i < N; ++i) {
		cout << "Case #" << i + 1 << ": " << X[i] << " + " << Y[i]<<" = " << result[i] << "\n";
	}

}