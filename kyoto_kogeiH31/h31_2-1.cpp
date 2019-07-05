#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
    	long long count =0;
	for(int i=0;i<n;i++){
      		double x=(double)i/(double)n;
      		for(int j=0;j<n;j++){
       			double y=(double)j/(double)n;
        		if(sqrt(x*x+y*y) <= 1.0) count++;
        		//cout<<x<<" "<<y<<" "<<count<<endl;
      		}
    	}
	cout << fixed << setprecision(10) << 4.0*(double)count/((double)n*(double)n) << endl;
	return 0;
}
