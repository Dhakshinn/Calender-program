#include<stdio.h>
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main()
{
    int year,i,m,n,start;
    scanf("%d",&year);
    char month[12]={'J','F','M','A','M','J','J','A','S','O','N','D'};
    start=dayofweek(1,1,year);
    n=start;
    for(m=1;m<=12;m++,printf("\n"))
    {
        printf("%c\n",month[m-1]);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        if(m==2)
        {
            if(((year%4==0 && year%100!=0)||(year%400==0)))
            {
                for(i=0;i<n;printf("    "),i++);
                for(i=1;i<=29;i++)
                {
                    printf("%3d ",i);
                    n++;
                    if(n==7)
                    {
                        printf("\n");
                        n=0;
                    }
                }
            }
            else
            {
                for(i=0;i<n;printf("    "),i++);
                for(i=1;i<=28;i++)
                {
                    printf("%3d ",i);
                    n++;
                    if(n==7)
                    {
                        printf("\n");
                        n=0;
                    }
                }
            }
        }
        else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        {
            for(i=0;i<n;printf("    "),i++);
            for(i=1;i<=31;i++)
            {
                printf("%3d ",i);
                n++;
                if(n==7)
                {
                    printf("\n");
                    n=0;
                }
            }
        }
        else
        {
            for(i=0;i<n;printf("    "),i++);
            for(i=1;i<=30;i++)
            {
                printf("%3d ",i);
                n++;
                if(n==7)
                {
                    printf("\n");
                    n=0;
                }
            }
        }
    }
    return 0;
}
