# 筑波大学H25情報基礎

## 大問4

### 問題1

関数の中身を問う問題。 <br>
f4の <br>

```

if(y%2==1)
```

の部分は最後にy=1に必ずなるので注意が必要(筆者が間違えただけです)<br>

<br>

### 問題2

呼び出し回数を聞く問題。<br>
よく見るとy回呼び出されているだけです。<br>

<br>

### 問題3

(2)と同じく呼び出し回数の一般解を求める問題。<br>
f2の変数yにf3のxが代入されているところに注意すること。 <br>

### 問題4

(2)(3)と同じような内容。 <br>
再帰的にy/2をしていくと必ず1を通ることを忘れない!!!! <br>

### 問題5
穴埋め。 <br>
rがそのままf1のrと同じ意味なのでreturn rは確定、 <br>
あとはyを減らしながら再起をしてrにyを足していくだけ <br>
f5はrを初期化してgを呼び出すだけなのでrに0を入れればおしまい <br>

### 問題6
(5)と同じく再起関数を作る問題。 <br>
ただ、今回は値を保持するrを持っていないのでreturnするところに <br>
そのままrを持っておく必要がある。 <br>
rを更新するのは(y/2 == 1)のときのみなので <br>
(カ)でxを足してf6を再帰する必要がある。 <br>

### 大問4解答
```txt
問1
(A) 〇 (B) × (C) 〇 (D) 〇

問2
5回

問3
x * y

問4
文2 -> 2回
文3 -> 6回

問5
(ア) d (イ) i (ウ) f (エ) a

問6
オ -> 0
カ -> x+f6(x*2, y/2)
キ -> x*2
ク -> y/2
```

## 大問5

### 問題1

partition関数の挙動をみてprint文の中身を見る問題。 <br>
partition関数はa[r]の値より小さい値を前に詰めていき、 <br>
a[r]より小さい数の個数を返す関数である。(クイックソートのやりたいことを思い出して!)<br>
[参考動画](https://www.youtube.com/watch?v=rG4XYQ5hhMc) <br>

### 問題2

sort関数(クイックソート)を実装する問題。<br>
partition関数で領域を分けたので、分けた領域に対してまたpartition関数を再帰的に <br>
続けていけばソートができることを考えれば(ア)(イ)に入るのはsort(hoge~)となる。 <br>
後は領域をきちんと指定すればOK! <br>

### 問題3

行(B)が1回しか実行されない->p==rまたはi==kとなる。<br>
しかし、r=n-1なので、つまりi==kがtrueのみ達成される。<br>
kはq-pであり、p=0よりq=0のみ成り立つ。<br>
q=0 -> partition(a,0,n-1)が0である必要がある。 <br>
partition関数は、a[n-1]より小さい数の最小値を返すので、 <br>
つまり、a[n-1]が最小値の場合、q=0となる。 <br>
今回はa3={0,1,2,...,n}について考えるため、a[n-1]=0のときに条件に当てはまる。 <br>
つまり、組み合わせはa[n-1]=0,後は任意なので、(n-1)!通りとなる。 <br>

### 問題4

partition関数の行Aの比較回数の最大回数を求める問題。<br>
ここで大切なのは、if文がtrueになる回数ではなく、比較する回数なので、<br>
つまり
```cpp
for(j=p; j<r; j++){
```
の部分のループ回数が最大になる回数を考える。 <br>
このとき、最大の比較回数は、a[n-1]が毎回aの最大値のとき達成される。<br>
なぜなら、毎回partition関数でrが返されるため、select関数で、<br>
```cpp
else if(i < k) return select(a, p, q-1, i);
```
が毎回実行され、q-1が0になるまで再起される。 <br>
つまり、最大比較回数はn+(n-1)+(n-2)+...+1となる。 <br>
つまり、最大比較回数はn*(n+1)/2となる。<br>
[1~nの総和がn*(n+1)/2になる証明](https://mathwords.net/1karannowa) <br>
![1toN](https://mathwords.net/wp-content/uploads/2017/02/1karannowa2-277x300.png "1toN") <br>

### 問題5

partition(a,0,4,2)で行(B)での比較回数が丁度5回になるn=5の配列を考える。<br>
サンプルの例を元に実行していくと、再起で消えていく領域は、<br>
右端->左端->右端->左端->keyという様に近づいていくことが分かる。<br>
つまり真ん中を2にして消される領域を端から消えるように消していけば達成される。<br>
(真ん中が2ではなくてもできるセットがあるので解説自体が間違っているかもしれません。)<br>
(もし間違ていたらpull requestを送っていただけると嬉しいです。)<br>

### 大問5解答
```txt
問1
i=0, j=0
i=1, j=2
i=2, j=4

問2
(ア)sort(a,p,q-1) (イ)sort(a,q+1,r)

問3
(n-1)!

問4
n*(n+1)/2

問5
以下のうち1つ
・1 2 0 3 4
・1 3 2 0 4
・3 2 1 0 4
・1 4 2 3 0
・4 2 1 3 0
```

## ソースコード
[問題4](https://github.com/honehaniwa/kakomon_test/blob/master/tsukubaH25/problem4.c)
```cpp
#include<stdio.h>

int problem2 = 0;
int problem3 = 0;
int problem4_1 = 0;
int problem4_2 = 0;
int f1(int x, int y){
    int r;
    for(r=0; y>0; y--) r += x;
    return r;
}

int f2(int x, int y){
    int r;
    for(r=x; y>0; y--) {
        r++;
        /* 文1 */
        problem3++;
    }
    return r;
}

int f3(int x, int y){
    int r;
    for(r=0;y>0;y--) {
        r = f2(r, x);
        problem2++;
    }
    return r;
}

int f4(int x, int y){
    int r;
    for(r=0; y>0; y= y/2){
        if(y % 2 == 1) {
            r += x; /* 文2 */
            problem4_1++;
        }
        x *= 2; /* 文3 */
        problem4_2++;
    }
    return r;
}

int g(int x, int y, int r){
    if(y == 0) return r;
    else return g(x, y-1, x+r);
}

int f5(int x, int y){
    return g(x, y, 0);
}

int f6(int x,int y){
    if(y==0) return 0;
    else if(y%2 == 1) return x + f6(x*2,y/2);
    else return f6(x*2,y/2);
}

int main(){
    //問題１
    // f1(3,5)
    printf("f1(3,5) = %d\n",f1(3,5));
    //(A)
    printf("(A) = %d\n",f1(5,3));
    //(B)
    printf("(B) = %d\n",f2(3,5));
    //(C)
    printf("(C) = %d\n",f3(3,5));
    //(D)
    printf("(D) = %d\n",f4(3,5));


    //問題2
    printf("\nproblem2 = %d\n",problem2);

    //問題3
    printf("\nproblem3\nput integer x and y\n");
    int x,y;
    scanf("%d%d",&x,&y);
    problem3 = 0;
    f3(x,y);
    printf("problem3 = %d\n",problem3);

    //問題4
    problem4_1 = 0;
    problem4_2 = 0;
    f4(11,33);
    printf("problem4 = %d , %d \n",problem4_1, problem4_2);

    //問題5
    printf("\nproblem5\nput integer x and y\n");
    scanf("%d%d",&x,&y);
    printf("f1(x,y) = %d\nf5(x,y) = %d",f1(x,y),f5(x,y));


    //問題6
    printf("\nproblam6\nput integer x and y\n");
    scanf("%d%d",&x,&y);
    printf("f4(x,y) = %d\nf6(x,y) = %d\n",f4(x,y),f6(x,y));
}
```

[問題5](https://github.com/honehaniwa/kakomon_test/blob/master/tsukubaH25/problem5.cpp)
(注:実装の都合上C++のコードになっています) <br>
(注2:コンパイルコマンドが違います。こうしないとコンパイラのバージョン違いでエラーになります)<br>
```sh
g++ --std=c++11 problem5.cpp
./a.out
```

```cpp
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
int problem3 = 0;
int problem4 = 0;
int max_n = -1e5;
bool flag = false, flag1 = false, flag2 = false,flag3 = false;;

void exch(vector<int> &a, int i, int j){
    int tmp;
    tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

int partition(vector<int> &a, int p, int r){
    int i,j,x;

    x = a[r];
    i = p-1;
    for(j=p; j<r; j++){
        problem4++;
        if(a[j] <= x){ //行(A)
            i++;
            exch(a, i, j);
            if(flag1)printf("i = %d, j = %d\n",i,j);
        }
    }
    exch(a, r, i+1);
    return i+1;
}

void sort(vector<int> &a, int p, int r){
    int q;

    if(p < r){
        q = partition(a, p, r);
        //(ア)
        sort(a, p, q-1);
        //(イ)
        sort(a, q+1, r);
    }
}

int select(vector<int> a, int p, int r, int i){
    int q,k;
    problem3++;
    if(problem3 > 1 && flag) return -1;
    if(p == r) return a[p]; //行(B)
    q = partition(a, p, r);
    k = q - p;
    if(i == k) return a[q];
    else if(i < k) return select(a, p, q-1, i);
    else return select(a, q+1, r, i - (k+1));
}

int c3 = 0;
// 順列を List
void  list(vector<int> t){
    if(flag){
        if(select(t,0,n-1,0)>0){
            for(int i=0; i<n; i++)  printf("%d ",t[i]);
            printf("\n");
        }
        c3++;
        //printf("%d回\n",++c3);
    }
    else if(flag2){
        problem4=0;
        select(t,0,n-1,0);
        max_n = max(max_n,problem4);
    }
    else{
        problem3 = 0;
        select(t,0,n-1,2);
        if(problem3 == 5) {
            for(int i=0; i<n; i++)  printf("%d ",t[i]);
            printf("\n");
        }
    }
}

// 順列を求める
void  jyun(vector<int> t, int N){
    int i,k,w;
    if (N<2)
    {   
        list(t);
        return;
    }
    k= N-1;
    for(i=N-1; i>=0; i--)
    {   
        w = t[k];
        t[k] = t[i];
        t[i] = w;
        jyun(t,k);
        t[i] = t[k];
        t[k] = w;
    }
    return;
}

int main(){
    /*n = 6;
    
    for(int i=0;i<n;i++) cout << select(a1,0,5,i) << " ";
    puts("");
    */

    vector<int> a1{5,10,7,12,8,9};
    
    //問題1
    printf("problem1\n");
    flag1 = true;
    partition(a1, 0, 5);
    flag1 = false;

    //問題2
    printf("\nproblem1\n");

    vector<int> a{8,1,6,2,3,7,9,41,3,58};
    puts("before sort");
    for(int i=0;i<10;i++) printf("%d ",a[i]);

    sort(a,0,9);
    puts("\nafter sort!");
    for(int i=0;i<10;i++) printf("%d ",a[i]);
    puts("");

    //問題3
    printf("\nproblem3\n");

    n = 5;
    flag = true;
    v.resize(n);
    for(int i=0;i<n;i++) v[i] = i;
    jyun(v,n);
    printf("%d回\n",c3);
    flag = false;


    //問題4
    printf("\nproblem4\n");

    flag2 = true;
    n = 5;
    v.resize(n);
    for(int i=0;i<n;i++) v[i] = i;
    jyun(v,n);
    printf("%d\n",max_n);
    flag2 = false;


    //問題5
    printf("\nproblem5\n");

    flag3 = true;
    n = 5;
    v.resize(n);
    for(int i=0;i<n;i++) v[i] = i;
    jyun(v,n);
    return 0;
}
```
