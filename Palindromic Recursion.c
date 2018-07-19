#include <stdio.h>
#include <stdlib.h>

int palindromic (int);

int main(){
    int input,yes;

    printf("Input number: ");
    scanf("%d",&input);

    yes=palindromic(input);

    if (yes==1)
        printf("\n\n\t%d is Palindromic.\n",input);
    else
        printf("\n\n\t%d is not Palindromic.\n",input);

    return 0;
}

int palindromic (int n){
    int end=(n%10),revmove=0,power=1,pcount=0;
    int start=n,temp=n,comp,move=0,place=1,count=1;

    if (n<10){
        return 1;
    }
    /*else if(n>=1000){
        while(temp>=10){
            count++;
            temp/=10;
            printf("\nHi\n"); // remove later
        }
        temp=n;
        printf("\nThat complex is this: %d",count-(count/2)); //remove later
        while(pcount<count-(count/2)){
            power*=10;
            pcount++;
        }
        printf("\nPower is %d\n",power); // remove later
        temp=temp/power;
        printf("\nTemp is %d\n",temp);
        while(temp>=10){
            if(temp%10==0){
                printf("\nThat complex is this: %d",(count/2)-move); //remove later
                pcount=0,power=1;
                while(pcount<(count/2)-move){
                    power*=10;
                    pcount++;
                }
                printf("\nPower2 is %d\n",power); // remove later
                comp=n%power; // gives the number to compare with the same amount of digits.
                while (comp>0){
                    revmove=(revmove*10)+(comp%10);
                    comp/=10;
                    printf("\nHallo\n"); // remove later
                }
                if (temp!=revmove)
                    return 0;
                break;
            }
            temp/=10;
            move++;
            printf("\nHello\n"); // remove later
            }
    }*/
    else {
        while(start>=10){
            start=start/10;
            place*=10;
        }
        if (start!=end)
            return 0;
        else{
            return palindromic((n%place)/10);
        }
    }
}
