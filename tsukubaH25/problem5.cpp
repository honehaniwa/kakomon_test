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
            if(flag1)printf("i=%d, j=%d\n",i,j);
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
        //if(problem3 == 5) {
            for(int i=0; i<n; i++)  printf("%d ",t[i]);
            printf("\n");
        //}
        cout << problem3 << endl;
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
    printf("\nproblem2\n");

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