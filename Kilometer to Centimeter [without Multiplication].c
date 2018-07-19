#include <stdio.h>
int main(){
    int km;

    printf("Enter value of km: ");
    scanf("%i",&km);

    while(km<0){
        printf("\nInput is invalid.\nPlease enter a positive number: ");
        scanf("%i",&km);
        }
    if(km==0)
        printf("\n%i kilometer/s is equivalent to 0 centimeter/s.",km,km);
    else
        printf("\n%i kilometer/s is equivalent to %i00000 centimeter/s.\n",km,km);

    return 0;
}
