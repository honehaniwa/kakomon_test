# 筑波大学Hxx年大問5挙動解説

プログラムソースの一番下のコメントアウトのtest caseをみるとわかるが、<br>
textに指定された文字列の中にptnの文字列が何文字目から出現するかを示した<br>
ソースコードである。<br>

また、int mainの(argc,argv[])についてはGoogle先生に<br>
「C言語　コマンドラインパラメータ」と検索するとよいでしょう。<br>

また、この.cファイルを実行するには、<br>
```
gcc problem5.c
./a.out ptn txt
```
で実行することができる。<br>

## ソースコード
[大問5](https://github.com/honehaniwa/kakomon_test/blob/master/tsukubaHxx/problem5.c)
```cpp
#include<stdio.h>
#include<string.h>

int proc(char *text, char *ptn) {
	printf("text = %s, ptn = %s\n",text,ptn);
	int i=0,j=0,m,n;
	n = strlen(text);
	m = strlen(ptn);
	while(i < n){
		printf("i = %d (%c), j = %d (%c)\n",i,text[i],j,ptn[j]);
		if(text[i] == ptn[j]){
			if(j == m - 1) {
				puts("patern 1");
				return i - m + 1;
			}
			else i++,j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	puts("patern 2");
	return -1;
}

int main(int argc, char *argv[]) {
		printf("Result: %d.\n", proc(argv[2], argv[1]));
		return 1;
}

/*
```
