//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program shall ask three inputs from the user, all in strings:
1st String & 2nd String could be any computer number and the 3rd shall
be an integer that designates what base the two strings are in*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char[],char[],int);
void capitalize(char[]);
int compare(char[],char[]);
int compareSub(char[],char[]);
void rev(char[]);
int valConvert(char);
char charConvert(int);
void normalize(char[],char[]);
void add(char[],char[],int);
int subtract(char[],char[],int);

int main(){
    char num1[30], num2[30], sel;
    int base, proceed=1;

    do{ //creates a loop until proper inputs have been passed
        printf("\n\tNumber Calculation\n\n");

        if(proceed==0) //declares the message when input is wrong
            printf("\tNOTE: INPUTS MUST BE IN THE SAME BASE AS DECLARED\n\t      BASE MUST ALSO BE A NUMBER BETWEEN 2 - 36\n\n");
        else //leaves a space
            printf("\n\n\n");

        printf("\tInput first number: ");
        scanf("%[^\n]s",&num1);
        fflush(stdin);
        printf("\tInput second number: ");
        scanf("%[^\n]s",&num2);
        fflush(stdin);
        printf("\tInput base: ");
        scanf("%d",&base);
        fflush(stdin);
        proceed=check(num1,num2,base);

        if (proceed==0) //cleans the screen
            system("cls");

    }while (proceed==0);

    proceed=1;

    do{ //loop for the actual operations until exit
        do{
            system("cls");
            printf("\n\tInput 1: %s\n\tInput 2: %s\n\n\t",num1,num2);
            printf("What do you want to do?\n\n\t\t1.) Addition\n\t\t2.) Subtraction\n\t\t3.) Absolutely nothing\n\n\tInput: ");
            scanf("%c",&sel);
            fflush(stdin);

            switch(sel){
            case '1':
                add(num1,num2,base);
                break;
            case '2':
                subtract(num1,num2,base);
                break;
            case '3':
                printf("\n\t\tProgram will now exit.");
                break;
            default:
                printf("\n\t\tInput is not an action.");
                break;
            }

            printf("\n\n\t");
            system("pause");
            system("cls");
        }while(sel!='3');
    }while(proceed=0);

    return 0; //because I am OCD
}

int check(char first[], char second[],int base){ //checks for the validity of input
    int firEnd = strlen(first), secEnd = strlen(second), i;

    for(i=0;i<firEnd;i++){ //checks first input [num1]
        if ((!(first[i]>='0'&&first[i]<='9'))&&(!(first[i]>='A'&&first[i]<='Z'))&&(!(first[i]>='a'&&first[i]<='z')))
            return 0;
    }

    for(i=0;i<secEnd;i++){ //checks second input [num2]
        if ((!(second[i]>='0'&&second[i]<='9'))&&(!(second[i]>='A'&&second[i]<='Z'))&&(!(second[i]>='a'&&second[i]<='z')))
            return 0;
    }

    if (base<2||base>36) //checks if base is valid
        return 0;

    capitalize(first);
    capitalize(second);

    if (base<10){ //check if inputs are within the base [if base is less than '10' or 'A']
        for(i=0;i<firEnd;i++){ //checks first input [if base is less than '10' or 'A']
            if (first[i]>=(base+48)) //checks if first[i] is a legit remainder of %base
                return 0;
        }
        for(i=0;i<secEnd;i++){ //checks second input [if base is less than '10' or 'A']
            if (second[i]>=(base+48)) //checks if first[i] is a legit remainder of %base
                return 0;
        }
    }
    else{ //check if inputs are within the base [if base is less than '10' or 'A']
        for(i=0;i<firEnd;i++){ //checks first input [if base is less than '10' or 'A']
            if (first[i]>=(base+55)) //checks if first[i] is a legit remainder of %base
                return 0;
        }
        for(i=0;i<secEnd;i++){ //checks second input [if base is less than '10' or 'A']
            if (second[i]>=(base+55)) //checks if first[i] is a legit remainder of %base
                return 0;
        }
    }

    return 1;
}

void capitalize(char word[]){ //capitalizes tha lowercase characters in a string
    int i, strEnd = strlen(word);

    for(i=0;i<strEnd;i++){
        if (word[i]>='a'&&word[i]<='z')
            word[i]=word[i]-('a'-'A');
    }

    return; //because I am OCD
}

int compare(char first[], char second[]){ //compares the size/value of two strings; returns 1 if F>S, returns -1 if S>F, returns 0 if F==S
    int minuend = strlen(first), subtrahend = strlen(second);

    if (minuend<subtrahend) //returns [-1] if Second String is longer than the First
        return -1;
    else if (subtrahend<minuend) //return [1] if First String is longer than the Second
        return 1;
    else
        return 0; //if String reaches here then both strings are the same
}

int compareSub(char first[], char second[]){ //compares the size/value of two strings; returns 1 if F>S, returns -1 if S>F, returns 0 if F==S
    int minuend = strlen(first), subtrahend = strlen(second), valueF, valueS, i;

    if (minuend<subtrahend) //returns [-1] if Second String is longer than the First
        return -1;
    else if (subtrahend<minuend) //return [1] if First String is longer than the Second
        return 1;
    else{
        for(i=0;i<minuend;i++){ //checks each individual
            valueF=valConvert(first[i]);
            valueS=valConvert(second[i]);

            if (valueF>valueS) //compares the value of first[i]
                return 1;
            else if (valueS>valueF)
                return -1;
        }
    }
    return 0; //if String reaches here then both strings are the same
}

void rev(char str[]){ //reverses the input string
    char temp[30];
    int i, j, end = strlen(str);

    for(i=0,j=end-1;i<end;j--,i++){ //places the reverse of string in temp
        temp[i]=str[j];
    }
    temp[i]='\0'; //prevents temp from going 'wild'; not needed but make things cleaner

    for(i=0;i<end;i++){ //puts temp in string
        str[i]=temp[i];
    }

    return; //because I am OCD
}

int valConvert(char bit){ //changes a char ['A'-'Z' & Numerals] into a value
    int value;

    if (bit>='A')
        value=bit-('A'-10);
    else
        value=bit-('1'-1);

    return value;
}

char charConvert(int val){ //changes value into a char ['A'-'Z' & Numerals]
    int bit;

    if (val>=10)
        bit=val+('A'-10);
    else
        bit=val+('1'-1);

    return bit;
}

void normalize(char larger[],char smaller[]){ //evens out the strings
    char temp[30];
    int lrg = strlen(larger), sml = strlen(smaller), i;

    for(i=0;smaller[i]!='\0';i++) //copies smaller to temp
        temp[i]=smaller[i];

    temp[i]='\0'; //seals temp for reversing
    rev(temp);

    for(;i<lrg;i++) //assigns 0 post-reverse
        temp[i]='0';

    temp[i]='\0'; //'seals' temp[i]

    for(i=0;temp[i]!='\0';i++)
        smaller[i]=temp[i];

    smaller[i]='\0';

    rev(smaller);

    return; //because I am OCD
}

void add(char add1[], char add2[],int base){ //what it says: it adds
    int val1, val2, valSum, carry=0, i, a;
    char sum[30];

    if(compare(add1,add2)==1)
        normalize(add1,add2);
    else if (compare(add1,add2)==-1)
        normalize(add2,add1);

    i=strlen(add1)-1;

    for(a=0;i>=0;i--,a++){ //loops to add each digit individually

        val1=valConvert(add1[i]); //converts element into an int
        val2=valConvert(add2[i]); //converts element into an int

        valSum=carry+val1+val2; //adds the carry and first addend
        carry=0; //takes out carry as it was used

        if (valSum>=base){ //if sum is greater than or equal to base, carry
            carry=1;
            valSum=valSum-base;
            sum[a]=charConvert(valSum);
        }
        else{ //if sum is within modulo base
            sum[a]=charConvert(valSum);
        }
    }

    if(carry==1){ //if loop completes with a carry
        sum[a]=carry+('1'-1);
        a++;
    }

    sum[a]='\0';

    rev(sum);

    printf("\n\t\tAnswer is %s",sum);

    return; //because I am OCDsum[a]='\0';
}

int subtract(char min[], char sub[], int base){ //only returns a value for the validity of the operation; it just subtracts
    int val1, val2, valDiff, borrow=0, i, a;
    char diff[30];

    if (compareSub(min,sub)==-1){
        printf("\n\tYou cannot subtract a bigger number from a smaller one.\n");
        return;
    }
    else if (compareSub(min,sub)==1)
        normalize(min,sub);

    i=strlen(min)-1;

    for(a=0;i>=0;i--,a++){

        val1=valConvert(min[i]); //converts element into an int
        val2=valConvert(sub[i]); //converts element into an int

        if (borrow==1){ //if borrow exists
            val1=val1-1;
            borrow=0;
        }

        if (val1<val2){ //if minuend is less than subtrahend;
            val1=val1+base;
            borrow=1;
        }

        valDiff=val1-val2;

        diff[i]=charConvert(valDiff); //difference will be converted
    }

    diff[a]='\0';

    printf("\n\t\tThe Difference is: %s",diff);

    return; //because I am OCD
}
