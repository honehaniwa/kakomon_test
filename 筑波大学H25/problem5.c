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
test case

>./a.out tsukuba ibarakikenntsukubashi

text = ibarakikenntsukubashi, ptn = tsukuba
i = 0 (i), j = 0 (t)
i = 1 (b), j = 0 (t)
i = 2 (a), j = 0 (t)
i = 3 (r), j = 0 (t)
i = 4 (a), j = 0 (t)
i = 5 (k), j = 0 (t)
i = 6 (i), j = 0 (t)
i = 7 (k), j = 0 (t)
i = 8 (e), j = 0 (t)
i = 9 (n), j = 0 (t)
i = 10 (n), j = 0 (t)
i = 11 (t), j = 0 (t)
i = 12 (s), j = 1 (s)
i = 13 (u), j = 2 (u)
i = 14 (k), j = 3 (k)
i = 15 (u), j = 4 (u)
i = 16 (b), j = 5 (b)
i = 17 (a), j = 6 (a)
patern 1
Result: 11.
*/