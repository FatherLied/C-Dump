#include <stdio.h>
int main(){
    int four=4, six=6, sum=0, limit;

    printf("Enter number limit: ");
    scanf("%i",&limit);

    while(limit<0){
        printf("\nInput is invalid. Please enter a positive number: ");
        scanf("%i",&limit);
        }

    printf("\nThe multiples of 4 that fit %i are: \n",limit);
    while(four<=limit){
        if(four<=limit){
            printf("%i ",four);
            four=four+4;
            }
        }

    printf("\n\nThe multiples of 6 that fit %i are: \n",limit);
    while(six<=limit){
        if(six<=limit){
            printf("%i ",six);
            six=six+6;
            }
        }

    four=4, six=6;
    while(four<=limit||six<=limit){
        if(four<=limit){
            sum=sum+four;
            four=four+4;
            }
        if(six<=limit){
            sum=sum+six;
            six=six+6;
            }
        }
    printf("\n\nThe sum is %i\n",sum);
    return 0;
}
