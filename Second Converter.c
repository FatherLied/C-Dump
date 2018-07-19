#include <stdio.h>
int main(){
    unsigned int secs, days=0,hours=0,minutes=0,seconds=0,temp=0;

    printf("Enter number of secs: ");
    scanf("%i",&secs);

    while(temp+86400<=secs){
        temp=temp+86400;
        days++;
    }

    printf("%i day/s\n",days);

    while(temp+3600<=secs){
        temp=temp+3600;
        hours++;
    }

    printf("%i hour/s\n",hours);

    while(temp+60<=secs){
        temp=temp+60;
        minutes++;
    }

    printf("%i minute/s\n",minutes);

    if(secs==temp)
        printf("%i second/s\n",seconds);
    else{
        while(temp!=secs){
            temp=temp+1;
            seconds++;
        }
        printf("%i second/s\n",seconds);

    }

    return 0;
}
