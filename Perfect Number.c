#include <stdio.h>

int main(){
    int a=2,ans=1,n;

    printf("Input n: ");
    scanf("%i",&n);

    while(a*a<=n){
        if (n%a==0)
            ans=ans+a+n/a;
        a++;
    }

    if (ans==n)
        printf("%i is a Perfect Number",n);
    else
        printf("%i is not a Perfect Number",n);

    return 0;
}
