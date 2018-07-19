#include <stdio.h>
int main(){
    int select;
    int octal,octtemp,decimal,notoct,yes,digits,digicount,power;
    int prime,cf;
    int n,base=0,count,times,tempn;

    do{
        printf("What would you like to do?\n\n\t1. Series\n\t2. Germain Prime\n\t3. Base 8 to Decimal\n\t4. Exit\n\nInput: ");
        scanf("%i",&select);
        switch(select){
        case 1:
            printf("\nSeries\n\nInput number: ");
            do{
                scanf("%i",&n);
                if(n<1)
                    printf("Must be greater than 0!: ");
            }while(n<1);
            tempn=1;
            printf("\nThe first %i elements of the sequence are:\n",n);
            while(n>=tempn){
                if (tempn%4==1){
                    base=4;
                    for(times=3,count=1;tempn>count;base=4*times,count=count+4,times=times+2);
                    printf("\%i ",base);
                    if(tempn==n)
                        break;
                    tempn=tempn+1;
                }
                if (tempn%4==2){
                    base=8;
                    for(times=2,count=2;tempn>count;base=8*times,count=count+4,times=times+1);
                    printf("%i ",base);
                    if(tempn==n)
                        break;
                    tempn=tempn+1;
                }
                if (tempn%4==3){
                    base=7;
                    for(times=3,count=3;tempn>count;base=7*times,count=count+4,times=times+2);
                    printf("%i ",base);
                    if(tempn==n)
                        break;
                    tempn=tempn+1;
                }
                if (tempn%4==0){
                    base=14;
                    for(times=2,count=4;tempn>count;base=14*times,count=count+4,times=times+1);
                    printf("%i ",base);
                    if(tempn==n)
                        break;
                    tempn=tempn+1;
                }
            }
            printf("\n\n");
            break;
        case 2:
            cf=2;
            printf("\nGermain Prime\n\nInput number: ");
            do{
                scanf("%d",&prime);
                if(prime<0)
                    printf("Invalid input!: ");
            }while(prime<0);
            while(cf < prime){
                if(prime%cf==0){
                    printf("\n%d is not a Germain prime!\n\n",prime);
                    break;
                }
                else{
                    cf++;
                }
            }
            if(cf==prime){
                cf=2;
                while(cf < 2*prime+1){
                    if(2*prime+1%cf==0){
                        printf("\n%d is not a Germain prime!\n\n",prime);
                        break;
                    }
                    else{
                        cf++;
                    }
                }
                if(cf==2*prime+1)
                    printf("\n%d is a Germain prime!\n\n",prime);
            }
            if(prime<2)
                printf("\n%d is a special case.\n\n",prime);
            break;
        case 3:
            octal=0;
            digicount=0;
            printf("\nBase 8 to Decimal\n\nThe number of digits of the octal:\n");
            do{
                printf("Input must be positive: ");
                scanf("%i",&digits);
            }while(digits<0);
            do{
                octal=octal*10;
                do{
                    printf("Enter the number by digit(must be from 0-8): ");
                    scanf("%i",&octtemp);
                    if(octtemp<0||octtemp>8)
                        printf("Input is invalid.\n");
                }while(octtemp<0||octtemp>8);
                octal=octal+octtemp;
                digicount++;
            }while(digicount!=digits);
            printf("Input is %i.",octal);
            octtemp=octal;
            for(power=1,decimal=0;octtemp!=0;decimal=decimal+(octtemp%10)*power,power=power*8,octtemp=octtemp/10);
            printf("\n\nThe decimal form of %i is %i.\n\n",octal,decimal);
            break;
        case 4:
            printf("Exiting.\n");
            break;
        default:
            printf("\nInput is not part of the choices.\n\n");
        }
    }while(select!=4);

    return 0;
}
