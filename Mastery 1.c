#include <stdio.h>
int main(){
    int sel;
    int count, product, n;
    do{
        printf("What would you like to do?\n\n\t1. Positive Factorial\n\t2. Unbiased Average\n\t3. Exponential Sum\n\nInput: ");
        scanf("%i",&sel);
        switch(sel){
        case 1:
            count=1,product=1;
            do{
                printf("\nInput a positive integer: ");
                scanf("%i",&n);
                if(n==0)
                    printf("\nInput must be greater than 0.");
            }while(n<1);
            while(count<n){
                count++;
                product=product*count;
            }
            printf("\nThe product of the numbers 1 to %i is %i.\n\n",n,product);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInput is not part of choices.\n\n");
            break;
        }
    }while(sel!=4);
}
