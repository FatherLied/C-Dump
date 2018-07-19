#include <stdio.h>
#include <stdlib.h>

int inputCheck(char[]);
int length(char[]);
int prime(int);

int logBase10Estimate(int);
int floor1(float); //'floor' conflicts with stdlib
int ceiling1(float); //'ceiling' conflicts with stdlib
int isAlNum(char);
int isAlpha(char);
int isUpper(char);
int isLower(char);
char toUpper(char);
char toLower(char);
int isPunctuation(char);
int toInteger(char[]);
float toFloat(char[]);
int abs(int);
void stringCopy(char[],char[]);
int substring(char[],char[]);
int stringCompare(char[],char[]);
void camelCase(char[]);
void creverse(char[]);
int humbleNumber(int);
int nreverse(int);

int main(){
    int choice,numput,valid,i,out,yes;
    char sel[2],charput,string[100],strout[100];
    float floatput;

    do{
        printf("What would you like to do?\n\n\t1.  Log Base Estimate [base 10]\n\t2.  Floor\n\t3.  Ceiling\n\t4.  If Alphanumeric\n\t5.  If Alphabet\n\t6.  If Uppercase\n\t7.  If Lowercase\n\t");
        printf("8.  To Uppercase\n\t9.  To Lowercase\n\t10. If Punctuation\n\t11. Number String to Integer\n\t12. Number String to Float\n\t13. Absolute Value\n\t14. String Copy\n\t15. Substring\n\t");
        printf("16. String Comparison\n\t17. Camel Case\n\t18. Character Reverse\n\t19. Humble Number\n\t20. Number Reverse\n\n\t0.  Exit\n\n\tInput: ");

        do{
            fflush(stdin);
            scanf("%s",&sel);
            fflush(stdin);
            valid=inputCheck(sel);
            if (valid==0)
                printf("\nInput invalid. Must be numeric.\n\tInput: ");
        }while (valid==0);

        for (i=0,choice=0;sel[i]!=0;i++){
            if(i<2){
                choice=choice*10;
                choice=choice+(sel[i]-48);
            }
        }

        switch(choice){
        case 0:
            printf("\nProgram will now exit...");
            break;
        case 1:
            printf("\nLog Base Estimate\n");
            printf("\n\tInput a number: ");
            scanf("%d",&numput);
            if (numput>0)
                printf("\n\tLog base 10 of %d is %d.",numput,logBase10Estimate(numput));
            else
                printf("\n\tInput cannot be used in Log base 10.");
            break;
        case 2:
            printf("\nFloor\n");
            printf("\n\tInput a float: ");
            scanf("%f",&floatput);
            printf("\n\tFloor of %f is %d.",floatput,floor1(floatput));
            break;
        case 3:
            printf("\nCeiling\n");
            printf("\n\tInput a float: ");
            scanf("%f",&floatput);
            printf("\n\tCeiling of %f is %d.",floatput,ceiling1(floatput));
            break;
        case 4:
            printf("\nIf Alphanumeric\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            yes=isAlNum(charput);
            if (yes==1)
                printf("\n\t'%c' is Alphanumeric.",charput);
            else
                printf("\n\t'%c' is not Alphanumeric.",charput);
            break;
        case 5:
            printf("\nIf Alphabet\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            yes=isAlpha(charput);
            if (yes==1)
                printf("\n\t'%c' is part of the Alphabet.",charput);
            else
                printf("\n\t'%c' is not part of the Alphabet.",charput);
            break;
        case 6:
            printf("\nIf Uppercase\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            yes=isUpper(charput);
            if (yes==1)
                printf("\n\t'%c' is an Uppercase Letter.",charput);
            else
                printf("\n\t'%c' is not an Uppercase Letter.",charput);
            break;
        case 7:
            printf("\nIf Lowercase\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            yes=isLower(charput);
            if (yes==1)
                printf("\n\t'%c' is a Lowercase Letter.",charput);
            else
                printf("\n\t'%c' is not a Lowercase Letter.",charput);
            break;
        case 8:
            printf("\nTo Uppercase\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            printf("\n\t'%c' becomes '%c'.",charput,toUpper(charput));
            break;
        case 9:
            printf("\nTo Lowercase\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            printf("\n\t'%c' becomes '%c'.",charput,toLower(charput));
            break;
        case 10:
            printf("\nIf Punctuation\n");
            printf("\n\tInput a character: ");
            scanf("%c",&charput);
            yes=isPunctuation(charput);
            if (yes==1)
                printf("\n\t'%c' is a Punctuation Symbol.",charput);
            else
                printf("\n\t'%c' is not a Punctuation Symbol.",charput);
            break;
        case 11:
            printf("\nNumber String to Integer\n");
            printf("\n\tInput a string: ");
            scanf("%s",&string);
            printf("\n\tThe string '%s' is equivalent to '%d'.",string,toInteger(string));
            break;
        case 12:
            printf("\nNumber String to Float\n");
            printf("\n\tInput a string: ");
            scanf("%s",&string);
            printf("\n\tThe string '%s' is equivalent to '%f'.",string,toFloat(string));
            break;
        case 13:
            printf("\nAbsolute Value\n");
            printf("\n\tInput a number: ");
            scanf("%d",&numput);
            printf("\n\tAbsolute value of '%d' is '%d'.",numput,abs(numput));
            break;
        case 14:
            printf("\nString Copy\n");
            printf("\n\tInput a string: ");
            scanf("%[^\n]s",&string);
            stringCopy(string,strout);
            break;
        case 15:
            printf("\nSubstring\n");
            printf("\n\tInput a string: ");
            scanf("%[^\n]s",&string);
            fflush(stdin);
            printf("\tInput a substring: ");
            scanf("%[^\n]s",&strout);
            fflush(stdin);
            yes=substring(string,strout);
            if (yes==1)
                printf("\n\t'%s' is a Substring of '%s'.",strout,string);
            else
                printf("\n\t'%s' is not a Substring of '%s'.",strout,string);
            break;
        case 16:
            printf("\nString Comparison\n");
            printf("\n\tInput String 1: ");
            scanf("%[^\n]s",&string);
            fflush(stdin);
            printf("\tInput String 2: ");
            scanf("%[^\n]s",&strout);
            fflush(stdin);
            yes=stringCompare(string,strout);
            if (yes==1)
                printf("\n\t'%s' comes after '%s'.",string,strout);
            else if (yes==-1)
                printf("\n\t'%s' comes before '%s'.",string,strout);
            else
                printf("\n\t'%s' and '%s' are the same.",string,strout);
            break;
        case 17:
            printf("\nCamel Case\n");
            printf("\n\tInput a string: ");
            scanf("%[^\n]s",&string);
            printf("Camel Case is: ");
            camelCase(string);
            break;
        case 18:
            printf("\nCharacter Reverse\n");
            printf("\n\tInput a string: ");
            scanf("%[^\n]s",&string);
            printf("\n\tThe reverse of '%s' is: '",string);
            creverse(string);
            printf("'.");
            break;
        case 19:
            printf("\nHumble Number\n");
            printf("\n\tInput a number: ");
            scanf("%d",&numput);
            yes=humbleNumber(numput);
            if (yes==1)
                printf("\n\t'%d' is a Humble Number.",numput);
            else
                printf("\n\t'%d' is not a Humble Number.",numput);
            break;
        case 20:
            printf("\nNumber Reverse\n");
            printf("\n\tInput a number: ");
            scanf("%d",&numput);
            printf("\n\tThe Reverse of '%d' is '%d'.",numput,nreverse(numput));
            break;
        default:
            printf("\nInput is not part of the choices.");
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }while (choice!=0);
    return 0;
}

int inputCheck(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++){
        if (!(str[i]>='0'&&str[i]<='9'))
            return 0;
    }
    return 1;
}

int length(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++);

    return i;
}

int prime(int n){
    int cf=2;
    while(cf < n){
        if(n%cf==0){
            return 0;
        }
        else
            cf++;
    }
    if(cf==n)
        return 1;
}

//Line between My Helper Functions and MP's Functions

int logBase10Estimate(int n){
    int count=0;
    while (n>9){
        n/=10;
        count++;
    }
    return count;
}

int floor1(float x){
    int fl=0;
    if (x>=0){
        while (x>=fl)
            fl++;
        return fl-1;
    }
    else{
        while (x<fl)
            fl--;
        return fl;
    }
}

int ceiling1(float x){
   int ce=0;
    if (x>=0){
        while (x>ce)
            ce++;
        return ce;
    }
    else{
        while (x<ce)
            ce--;
        return ce+1;
    }
}

int isAlNum(char ch){
    if ((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        return 1;
    return 0;
}

int isAlpha(char ch){
    if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        return 1;
    return 0;
}

int isUpper(char ch){
    if (ch>='A'&&ch<='Z')
        return 1;
    return 0;
}

int isLower(char ch){
    if (ch>='a'&&ch<='z')
        return 1;
    return 0;
}

char toUpper(char ch){
    if (ch>='a'&&ch<='z')
        ch-=32;
    return ch;
}

char toLower(char ch){
    if (ch>='A'&&ch<='Z')
        ch+=32;
    return ch;
}

int isPunctuation(char ch){
    if ((ch>=33&&ch<=47)||(ch>=58&&ch<=64)||(ch>=91&&ch<=96)||(ch>=123&&ch<=126))
        return 1;
    return 0;
}

int toInteger(char st[]){
    int sum=0,neg=0,i;
    for(i=0;st[i]!='\0';i++){
        if (st[i]=='-'){
            neg=1;
        }
        else{
            sum*=10;
            sum=sum+(st[i]-48);
        }
    }
    if (neg==1)
        sum*=-1;
    return sum;
}

float toFloat(char st[]){
    int sum1=0,sum2=0,i,dot=0,count=0,temp;
    float ans=0,place=1;
    for(i=0;st[i]!='\0';i++){
        if (st[i]=='.'){
            dot=1;
            i++;
        }
        if (dot==0){
            sum1*=10;
            sum1=sum1+(st[i]-48);
        }
        else{
            sum2*=10;
            sum2=sum2+(st[i]-48);
        }
    }

    for(temp=sum2;temp!=0;temp/=10,count++);
    for(;count!=0;place/=10,count--);
    ans=sum1+sum2*place;

    return ans;
}

int abs(int x){
    if (x<0)
        x*=-1;
    return x;
}
void stringCopy(char src[],char dest[]){
    int i;
    for(i=0;src[i]!='\0';i++)
        dest[i]=src[i];
    dest[i]='\0';
    printf("\n\tSource:\t\t%s",src);
    printf("\n\tDestination:\t%s",dest);
}

int substring(char s1[],char s2[]){
    int i,j,yes=0;
    if (length(s1)<length(s2))
        return 0;
    for(i=0,j=0;s1[i]!='\0';i++){
        if (s1[i]==s2[j]||s2[j]=='\0'){
            yes=1;
            j++;
            if (s2[j]=='\0')
            break;
        }
        else {
            j=0;
            yes=0;
        }
    }
    return yes;
}

int stringCompare(char s1[],char s2[]){
    int i=0;
    while(s1[i]!='\0'||s2[i]!='\0'){
        if (s1[i]<s2[i])
            return -1;
        else if (s1[i]>s2[i])
            return 1;
        i++;
    }
    return 0;
}

void camelCase(char st[]){
    int count;
    for(count=0;st[count]!='\0';count++){
        if (count%2==0)
            if (st[count]>='a'&&st[count]<='z'){
                printf("%c",st[count]-32);
            }
            else
                printf("%c",st[count]);
        else if (count%2==1)
            if (st[count]>='A'&&st[count]<='Z'){
                printf("%c",st[count]+32);
            }
            else
                printf("%c",st[count]);
    }
}
void creverse(char st[]){
    int len;
    len=length(st)-1;
    for(;len>=0;len--)
        printf("%c",st[len]);
}

int humbleNumber(int x){
    int n=2;
    if (x==1)
        return 1;
    if (x==0)
        return 0;
    for (;n<=x;n++){
        if (x%n==0){
            if (!(n==2||n==3||n==5||n==7)){
                if (prime(n)==1)
                    return 0;
            }
        }
    }
    return 1;
}

int nreverse(int x){
    int rev=0;
    while (x>0){
        rev*=10;
        rev=rev+(x%10);
        x/=10;
    }
    return rev;
}
