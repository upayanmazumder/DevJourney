void triangle(int n) {
	string out;
	for (int i = 0; i < n; ++i) {
		int val = i + 1;
		for (int j = 0; j <= i; ++j)
			out += to_string(val) + ' ';
		out.back() = '\n';
	}
	cout << out;
}