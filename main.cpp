#include <iostream>
#include<stdio.h>
#include<vector>
#include <set>
#include<map>
#include<algorithm>

using namespace std;
int _count(vector<vector<int>>&res, int i, int j) {
	int mini = max(i - 1, 0);
	int maxi = min(i + 1, (int)(res.size() - 1));
	int minj = max(j - 1, 0);
	int maxj = min(j + 1, (int)(res[0].size() - 1));
	int count = 0;
	for (int n = mini; n <= maxi; n++) {
		for (int m = minj; m <= maxj; m++) {
			count += res[n][m];
		}
	}
	count -= res[i][j];
	return count;
}
vector<vector<int>> live_to_next_time(vector<vector<int>>a) {
	vector<vector<int>>res(a);
	for (int i = 0; i < a.size();i++) {
		for (int j = 0; j < a[0].size();j++) {
			int t = _count(a, i, j);
			if (t == 3) res[i][j] = 1;
			else if (t == 2);
			else res[i][j] = 0;
		}
	}
	return res;
}

int main() {
	vector<vector<int>>vec = { {0,1,0,1},{1,0,1,0},{1,1,0,1},{1,0,1,0} };
	cout<<_count(vec, 0, 2);
	cout<<_count(vec, 1, 0);
	vector<vector<int>>vec2(live_to_next_time(vec));
	for (int i = 0; i < vec2.size(); i++) {
		for (int j = 0; j < vec2[0].size(); j++) {
			cout << vec2[i][j];
		}
		cout << endl;
	}
	cin.get();

	return 0;
}