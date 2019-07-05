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

/*
入力例
f1(3,5) = 15
(A) = 15
(B) = 8
(C) = 15
(D) = 15

problem2 = 5

problem3
put integer x and y
8 7
problem3 = 56
problem4 = 2 , 6

problem5
put integer x and y
7 8
f1(x,y) = 56
f5(x,y) = 56
problam6
put integer x and y
8 9
f4(x,y) = 72
f6(x,y) = 72

 */