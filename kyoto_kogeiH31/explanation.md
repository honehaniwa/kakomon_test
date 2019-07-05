# 解説

円の面積はπr^2で求められる。<br>

1/4の円の場合、1/4πr^2となる。<br>

半径r = 1の時、面積は1/4πに等しい。<br>

つまり、変数(x,y)は、1辺が1/nの正方形のブロックの右上の座標を示している(下図)。<br>

![circle](https://github.com/honehaniwa/kakomon_test/blob/master/kyoto_kogeiH31/circle.png "circle")

つまり、この(x,y)が円周を超えた場合、このブロックの一部は円の面積から外れることになる。<br>

逆に(x,y)が外れない場合、この半径1/nのブロックは円の面積の一部であると考えられる。<br>

では、(x,y)はどうすれば円周より外側にあると判定できるか？<br>

それは原点から(x,y)までの距離が半径より短いか同かで判断できる。<br>

距離の計算は、三平方の定理よりsqrt(x^2+y^2)となる(マンハッタン距離)。<br>

これらを計算することで、1/4の円の面積の中に1/nが半径の正方形が何個入るかを計算でき、<br>

プログラム内ではこれをcount++;としている。<br>

では、最後にπを求める。<br>

1/4円の面積は、countを使うと、<br>

```
count(1辺1/nの正方形の個数) * (1/n)^2(正方形のブロックの面積)<br>
```

で求められ、それは<br>

1/4πr^2 に等しいので、<br>

```
π = 4 * count(1辺1/nの正方形の個数) * (1/n)^2(正方形のブロックの面積)
```

となる。<br>

```
注:
   ここに2つのファイルがあるが、2-1.cppは問題文のままのソースコードになります。

   逆に2-2.cppは挙動は同じだけど線形に計算せずに二分探索をして高速化してます。

   結果は同じになりますが実行時間に差が出るのでよかったら遊んでみてください。

```

## ソースコード
[2-1(問題に書いてあるほう)](https://github.com/honehaniwa/kakomon_test/blob/master/kyoto_kogeiH31/h31_2-1.cpp) <br>
```cpp
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
```
[2-2(二分探索で書き直した方)](https://github.com/honehaniwa/kakomon_test/blob/master/kyoto_kogeiH31/h31_2-2.cpp)<br>
```cpp
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
```

