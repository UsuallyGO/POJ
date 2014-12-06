    #include<stdio.h>  
    #include<string.h>  
    #define MAXN 100000000  
    int mark[2014],f[2014],n;  
    char str[2014][8];  
    int val(int i,int j)    //2个字符串的距离  
    {  
        int sum,k;  
        sum=0;  
        for(k=0;k<7;k++)  
            if(str[i][k]!=str[j][k])  
                sum++;  
        return sum;  
    }  
    void  prim()  
    {  
        int i,j,sum=0,minn,k;  
        for(i=0;i<n;i++)        //每个字符串与0的距离  
            f[i]=val(0,i);  
        memset(mark,0,sizeof(mark));  
        f[0]=0;  
        mark[0]=1;              //标记已使用过0  
        for(i=0;i<n-1;i++)      //Prim算法的核心，这个东西必须要自己理解！  
        {  
            minn=MAXN;  
            for(j=0;j<n;j++)  
            {  
                if(!mark[j]&&minn>f[j])  
                {  
                    minn=f[j];  
                    k=j;  
                }  
            }  
            sum+=minn;  
            mark[k]=1;  
            for(j=0;j<n;j++)        //换一个顶点  
                if(!mark[j]&&f[j]>val(k,j))  
                    f[j]=val(k,j);  
        }  
        printf("The highest possible quality is 1/%d.\n",sum);  
    }  
    int main()  
    {  
        int i;  
        while(scanf("%d",&n)!=EOF)  
        {  
            if(n==0)break;  
            for(i=0;i<n;i++)  
                scanf("%s",str[i]);  
            prim();  
        }  
        return 0;  
    }  
