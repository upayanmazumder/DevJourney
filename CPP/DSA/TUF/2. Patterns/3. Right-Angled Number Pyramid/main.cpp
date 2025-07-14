void nTriangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << j + 1 << ' ';
		}
		cout << '\n';
	}
}
