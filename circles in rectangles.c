#include<stdio.h>
#include<math.h>
int main()
{int t;
unsigned long long l,b,d;
unsigned long long i,p,q,r; 
printf("enter no of testcases\n");
scanf("%d",&t);
while(t--)
{printf("enter length,breadth and diameter\n");
scanf("%llu%llu%llu",&l,&b,&d);
if(d>=l || d>=b)
printf("0\n");
else
{p=l/d;
 q=b/d;
 r=p*q;
//for(i=1;i<=p;i++)
//{r+=q;
r=r%((int)pow(10,9)+7);
//}
printf("%llu\n",r);
}
}
}

