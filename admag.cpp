#include<stdio.h>
long long fib(long long n)
{ long long i=1,a=1,b=1,c;
  do
  { c=a+b;
    if(c>n)
     break;
    a=b;
    b=c;
    i++;
  } while(c<n);
  return i;
}
int main()
{ long int t;
  long long n,k;
  scanf("%ld",&t);
  while(t--)
  { scanf("%lld",&n);
    k=fib(n);
    printf("%lld\n",k);
  }
  return 0;
}
