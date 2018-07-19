#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nume;
    int deno;
}fraction;

fraction parse(char[]);
void fractText(fraction);

int main(){
    char string[50],sel;
    fraction validity;
    int quit=0;

    validity.deno=1;

    do{
        do{
            printf("Parsing: String to Fraction\n\n");

            if (validity.deno==0)
                printf("\tInput was invalid.\n\tEither Denominator was 0 or String was not a fraction.\n\n");
            else
                printf("\n\n\n\n");

            printf("\tInput String: ");
            scanf("%[^\n]s",&string);
            fflush(stdin);

            validity=parse(string);

            printf("\n\tThe fraction is: ");
            fractText(validity);
            if (validity.deno==1)
                printf(" or %d",validity.nume);
            else if (validity.deno==0&&validity.nume==0)
                printf("\n\t[input string might have been invalid]");
            else if (validity.deno==0)
                printf(" or |undefined|");

            printf("\n\n");
            system("pause");
            system("cls");

        }while(validity.deno==0);
    do{
        printf("\n\tQuit? [1=Yes/0=No]\n\t");
        scanf("%c",&sel);
        fflush(stdin);
        system("cls");
    }while(sel!='1'&&sel!='0');

    if (sel=='1')
        quit=1;

    }while(quit==0);
}

fraction parse(char string[]){
    int num=0, den=0, slash=0, i, end=0, numerator=0, denominator=0;
    fraction fract;

    for(i=0;string[i]!='\0';end++,i++); //counts the string

    for(i=0;i<end;i++){
        if(slash==0){
            if (num==0 && string[i]=='/'){
                fract.deno=0;
                fract.nume=0;
                return fract;
            }
            else if (!(string[i]>='0'&&string[i]<='9') && string[i]!='/'){
                fract.deno=0;
                fract.nume=0;
                return fract;
            }
            else if(string[i]!='/'){
                num=1;
                numerator=(numerator*10)+(string[i]-('1'-1));
            }
            else
                slash++;
        }
        else{
            if (!(string[i]>='0'&&string[i]<='9')){
                fract.deno=0;
                fract.nume=0;
                return fract;
            }
            else{
                den=1;
                denominator=(denominator*10)+(string[i]-('1'-1));
            }
        }
    }

    if(den==0)
        denominator=1;

    fract.nume=numerator;
    fract.deno=denominator;

    return fract;
}

void fractText(fraction frac){
    printf("%d/%d",frac.nume,frac.deno);
}
