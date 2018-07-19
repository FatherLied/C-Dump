#include <stdio.h>
int main(){
    int a=1,b=1,next=0,sum=0;

    printf("The Fibonacci Sequence (up to 4 million):\n%i %i ",a,b);

    while(next=40000000){
        next=a+b;
        a=b;
        b=next;
        if(next%2==0)
            sum=sum+next;
        printf("%i ",b);
        if (a+b>40000000)
            break;
        }

    a=1,b=1,next=0;
    printf("\n\nAll even elements:\n");

    while(next=40000000){
        next=a+b;
        a=b;
        b=next;
        if(next%2==0)
            printf("%i ",b);
        if (a+b>40000000)
            break;
        }

    printf("\n\nSum of all even elements is %i\n",sum);

    return 0;
}
