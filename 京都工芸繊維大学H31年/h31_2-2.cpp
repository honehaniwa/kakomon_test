#include<bits/stdc++.h>
using namespace std;

int n;

bool isOK(int mid, double key) {
	double y = (double)mid / (double)n;
	//cout << sqrt(key + y * y) << " ";
	if (sqrt(key + (y * y)) <= 1) return true;
	else return false;
}

int binary_search(double key) {
	int ng = -1;
	int ok = n;

	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		//for debug
		//cout << mid << " " << key << endl;
		if (!isOK(mid, key)) ok = mid;
		else ng = mid;
	}
	
	return ok;
}



int main() {
	long long count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x = (double)i / (double)n;
		double xx = x * x;
		count += binary_search(xx);
	}
	//for debug
	//cout << count << endl;
	cout << fixed << setprecision(10) << 4.0*(double)count / ((double)n*(double)n) << endl;
	return 0;
}

/*
sample imput

4
3.7500000000
100
3.1812000000
1000
3.1455440000
10000
3.1419904800
100000(ここから先は二分探索の為O(n^2)よりも顕著に高速)
3.1416325452
1000000
3.1415966496
10000000
3.1415930535
*/
