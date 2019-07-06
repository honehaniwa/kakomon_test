    #include    <stdio.h>
    #define     NUM     5
    int         tbl[NUM];

    // 順列を List
    void  list()
    {   int     i;
        for(i=0; i<NUM; i++)  printf("%d ",tbl[i]);
        printf("\n");
    }

    // 順列を求める
    void  jyun(int t[], int n)
    {   int     i,k,w;

        if (n<2)
        {   list();
            return;
        }
        k= n-1;
        for(i=n-1; i>=0; i--)
        {   w= t[k];
            t[k]= t[i];
            t[i]= w;
            jyun(t,k);
            t[i]= t[k];
            t[k]= w;
        }
        return;
    }

    //★ MAIN PROGRAM
    int  main()
    {   int     i;

        for(i=0; i<NUM; i++)    tbl[i]= i+1;
        jyun(tbl,NUM);
        return(0);
    }