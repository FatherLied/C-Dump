#include <stdio.h>
#include <stdlib.h>
int binary(char[]);
int octal(char[]);
int hexadecimal(char[]);
int length(char[]);
int power(int,int);
char bitcount(char[],int);

int main(){
    int bit,len,bin,oct,hex,pow,sum,i,j,b,skip,neg;
    char sel,input[100],byte[32];

    do{
        printf("What would you like to do?\n\n\t1. Binary to Decimal\n\t2. Octal to Decimal\n\t3. Hexadecimal to Decimal\n\t4. Binary to Octal\n\t5. Binary to Hexadecimal\n\t6. Exit\n\n\t0. Clear Screen\n\nInput: ");
        scanf("%c",&sel);
        fflush(stdin);
        switch(sel){
        case '1':
            sum=0,neg=0,bin=1;
            printf("\nBinary to Decimal\n");
            printf("\n\tInput a Binary Number: ");
            do{
                if (bin==0)
                    printf("\n\tInput is not Binary[32-bit]!\n\tInput a Binary Number: ");
                scanf("%[^\n]s",&input);
                fflush(stdin);
                bin=binary(input);
            }while(bin==0);
            pow=length(input);
            for (i=0;pow!=0;i++,pow--){
                if (pow==32&&input[i]=='1'){
                    neg=1;
                    i++;
                    pow--;
                }
                if (input[i]=='1')
                    sum=sum+power(pow-1,2);
            }
            if (neg==0)
                printf("\nThe binary '%s' is '%d' in decimal\n\n",input,sum);
            else{
                sum=(unsigned)(2147483648-sum);
                printf("\nThe binary '%s' is '-%u' in decimal\n\n",input,sum);
            }
            break;
        case '2':
            sum=0;
            oct=1;
            printf("\nOctal to Decimal\n");
            printf("\n\tInput a Octal Number: ");
            do{
                if (oct==0)
                    printf("\n\tInput is not Octal!\n\tInput an Octal Number: ");
                scanf("%[^\n]s",&input);
                fflush(stdin);
                oct=octal(input);
            }while(oct==0);
            pow=length(input);
            for (i=0;pow!=0;i++,pow--){
                if (input[i]>='1'&&input[i]<='7'){
                    bit=input[i]-48;
                    sum=sum+bit*power(pow-1,8);
                }
            }
            printf("\nThe octal '%s' is '%d' in decimal\n\n",input,sum);
            break;
        case '3':
            sum=0;
            oct=1;
            printf("\nHexadecimal to Decimal\n");
            printf("\n\tInput a Hexadecimal Number: ");
            do{
                if (hex==0)
                    printf("\n\tInput is not Octal!\n\tInput an Octal Number: ");
                scanf("%[^\n]s",&input);
                fflush(stdin);
                hex=hexadecimal(input);
            }while(hex==0);
            pow=length(input);
            for (i=0;pow!=0;i++,pow--){
                if (input[i]>='1'&&input[i]<='9'){
                    bit=input[i]-48;
                    sum=sum+bit*power(pow-1,16);
                }
                else if (input[i]>='A'&&input[i]<='F'){
                    bit=input[i]-55;
                    sum=sum+bit*power(pow-1,16);
                }
                else if (input[i]>='a'&&input[i]<='f'){
                    bit=input[i]-87;
                    sum=sum+bit*power(pow-1,16);
                }
            }
            printf("\nThe hexadecimal '%s' is '%d' in decimal\n\n",input,sum);
            break;
        case '4':
            bin=1,skip=0;
            printf("\nBinary to Octal\n");
            printf("\n\tInput a Binary Number: ");
            do{
                if (bin==0)
                    printf("\n\tInput is not Binary[32-bit]!\n\tInput a Binary Number: ");
                scanf("%[^\n]s",&input);
                fflush(stdin);
                bin=binary(input);
            }while(bin==0);
            len=length(input);
            for(i=0,b=0;input[i]!='\0';i++,b++){
                sum=0;
                while(input[i]=='0'&&i!=len-1){
                    i++;
                    skip++;
                }
                if ((len-skip)%3==1&&i-skip==0){
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                else if ((len-skip)%3==2&&i-skip==0){
                    if (input[i]=='1')
                        sum=sum+power(1,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                else {
                    if (input[i]=='1')
                        sum=sum+power(2,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(1,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                byte[b]=sum+48;
            }
            byte[b]='\0';
            printf("\nThe binary '%s' is '%s' in octal\n\n",input,byte);
            break;
        case '5':
            bin=1,skip=0;
            printf("\nBinary to Hexadecimal\n");
            printf("\n\tInput a Binary Number: ");
            do{
                if (bin==0)
                    printf("\n\tInput is not Binary[32-bit]!\n\tInput a Binary Number: ");
                scanf("%[^\n]s",&input);
                fflush(stdin);
                bin=binary(input);
            }while(bin==0);
            len=length(input);
            for(i=0,b=0;input[i]!='\0';i++,b++){
                sum=0;
                while(input[i]=='0'&&i!=len-1){
                    i++;
                    skip++;
                }
                if ((len-skip)%4==1&&i-skip==0){
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                else if ((len-skip)%4==2&&i-skip==0){
                    if (input[i]=='1')
                        sum=sum+power(1,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                else if ((len-skip)%4==3&&i-skip==0){
                    if (input[i]=='1')
                        sum=sum+power(2,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(1,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                else {
                    if (input[i]=='1')
                        sum=sum+power(3,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(2,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(1,2);
                    i++;
                    if (input[i]=='1')
                        sum=sum+power(0,2);
                }
                if (sum>=0&&sum<=9)
                    byte[b]=sum+48;
                else /*if (sum>=10&&sum<=15)*/
                    byte[b]=sum+55;
            }
            byte[b]='\0';
            printf("\nThe binary '%s' is '%s' in hexadecimal\n\n",input,byte);
            break;
        case '6':
            printf("\nProgram will now Exit...\n");
            break;
        case '0':
            system("cls");
            break;
        default:
            printf("\nInput is not part of the choices.\n\n");
            break;
        }
    }while (sel!='6');
}

int binary(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++){
        if (str[i]!='1'&&str[i]!='0')
            return 0;
    }
    if (i>32)
        return 0;
    return 1;
}

int octal(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++){
        if (str[i]<'0'||str[i]>'7')
            return 0;
    }
    if (i>10)
        return 0;
    return 1;
}

int hexadecimal(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++){
        if (str[i]<'0'||(str[i]>'8'&&str[i]<'A')||(str[i]>'F'&&str[i]<'a')||str[i]>'f')
            return 0;
    }
    if (i>7)
        return 0;
    return 1;
}

int length(char str[]){
    int i;
    for (i=0;str[i]!='\0';i++);

    return i;
}

int power(int e, int b){
    int ans;
    if (e==0)
        return 1;
    else
        for (ans=1;e>0;e--)
            ans*=b;

    return ans;
}
