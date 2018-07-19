//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program shall do three things involving words, integers and Roman Numerals.
First function shall convert integers to words, another shall turn integers to Roman
Numerals while the last shall do vise-versa.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void toWords(int); //converts integers to words
void toRom(int); //converts integers to Roman Numerals
void initialize(int[][14]); //initializes state diagram/table
int romInput(char,char); //defines state based on input
int romCheck(char[],int[][14]); //checks it Roman Numeral is valid
void capitalize(char[]); //capitalizes strings
void toInt(char[]); //converts Roman Numerals to integers


int main(){
    char sel,confirm,roman[30];
    int table[14][14],num,valid;

    initialize(table); //initializes state diagram

    do{
        system("cls"); //cleans screen
        printf("\n\tMPA 4 (Romans, Countrymen and err, Romans, Integers and Words)"); //types thing to console
        printf("\n\n\tWhat will you do?");
        printf("\n\n\t\t1. Integer to Words\n\t\t2. Integer to Roman\n\t\t3. Roman to Integers\n\t\t4. Exit...");
        printf("\n\n\tInput: ");

        scanf("%[^\n]c",&sel); //selection input
        fflush(stdin);

        switch(sel){
        case '1':
            system("cls"); //cleans screen
            printf("\n\tINTEGERS TO WORDS\n\n\tInput number: "); //types thing to console
            scanf("%d",&num);
            fflush(stdin);

            printf("\n\tNummber Wrapped around to: %d",num);
            printf("\n\n\tIn words: \n\n\t\t");
            toWords(num);

            printf("\n");
            break;
        case '2':
            do{ //repeat until input is right
                system("cls"); //cleans screen
                printf("\n\tINTEGERS TO ROMAN NUMERALS\n\n\tInput number [must be 1 - 3000]: "); //types thing to console
                scanf("%d",&num);
                fflush(stdin);
            }while(!(num>=1&&num<=3000));

            printf("\n\tInteger:\t%d",num);
            printf("\n\tRoman:\t\t");
            toRom(num);

            printf("\n");
            break;
        case '3':
            valid=1; //initializes valid

            do{
                system("cls"); //cleans screen
                printf("\n\tROMAN NUMERALS TO INTEGER\n"); //types thing to console

                if(valid==0) //if input is invalid
                    printf("\n\tInput is not a valid Roman Numeral!");

                printf("\n\tInput Roman Numeral: ");
                scanf("%[^\n]s",&roman);
                fflush(stdin);

                capitalize(roman); //capitalizes numerals
                valid=romCheck(roman,table);

            }while(valid==0);

            printf("\n\tRoman:\t\t%s",roman);
            printf("\n\tInteger:\t");
            toInt(roman);

            printf("\n");
            break;
        case '4':
            printf("\n\tProgram will now exit...\n");
            break;
        default:
            printf("\n\tInput is invalid...\n");
            break;
        }

        printf("\n\t");
        system("pause");
    }while(sel!='4');

}

void toWords(int n){
    if (n==0){ //if input is zero
        printf("Zero");
        return;
    }

    if (n<0){ //checks if input is negative
        printf("Negative ");
        n=n*-1;
    }

    if(n/1000000000==1) //counts billion
        printf("One Billion ");
    else if(n/1000000000==2)
        printf("Two Billion ");

void toRom(int);    if((n/100000000)%10==9) //counts hundred millions
        printf("Nine Hundred ");
    else if((n/100000000)%10==8)
        printf("Eight Hundred ");
    else if((n/100000000)%10==7)
        printf("Seven Hundred ");
    else if((n/100000000)%10==6)
        printf("Six Hundred ");
    else if((n/100000000)%10==5)
        printf("Five Hundred ");
    else if((n/100000000)%10==4)
        printf("Four Hundred ");
    else if((n/100000000)%10==3)
        printf("Three Hundred ");
    else if((n/100000000)%10==2)
        printf("Two Hundred ");
    else if((n/100000000)%10==1)
        printf("One Hundred ");

    if((n/1000000)%100<=19&&(n/1000000)%100>=10){ //counts for thousands lesser than hundred thousands
        if((n/1000000)%100==19) //writes for 19 million to 10 million
            printf("Nineteen ");
        if((n/1000000)%100==18)
            printf("Eighteen ");
        if((n/1000000)%100==17)
            printf("Seventeen ");
        if((n/1000000)%100==16)
            printf("Sixteen ");
        if((n/1000000)%100==15)
            printf("Fifteen ");
        if((n/1000000)%100==14)
            printf("Fourteen ");
        if((n/1000000)%100==13)
            printf("Thirteen ");
        if((n/1000000)%100==12)
            printf("Twelve ");
        if((n/1000000)%100==11)
            printf("Eleven ");
        if((n/1000000)%100==10)
            printf("Ten ");
    }
    else{
        if((n/10000000)%10==9)//writes for 99 million to 20 million
            printf("Ninety ");
        if((n/10000000)%10==8)
            printf("Eighty ");
        if((n/10000000)%10==7)
            printf("Seventy ");
        if((n/10000000)%10==6)
            printf("Sixty ");
        if((n/10000000)%10==5)
            printf("Fifty ");
        if((n/10000000)%10==4)
            printf("Forty ");
        if((n/10000000)%10==3)
            printf("Thirty ");
        if((n/10000000)%10==2)
            printf("Twenty ");

        if((n/10000000)%10>1) //hyphenates for compound words
            printf("- ");

        if((n/1000000)%10==9) //for singular millions/compounds
            printf("Nine ");
        if((n/1000000)%10==8)
            printf("Eight ");
        if((n/1000000)%10==7)
            printf("Seven ");
        if((n/1000000)%10==6)
            printf("Six ");
        if((n/1000000)%10==5)
            printf("Five ");
        if((n/1000000)%10==4)
            printf("Four ");
        if((n/1000000)%10==3)
            printf("Three ");
        if((n/1000000)%10==2)
            printf("Two ");
        if((n/1000000)%10==1)
            printf("One ");
    }

    if((n/1000000)%1000!=0) //writes million if value reaches
        printf("Million ");

    if((n/100000)%10==9) //counts hundred thousands
        printf("Nine Hundred ");
    else if((n/100000)%10==8)
        printf("Eight Hundred ");
    else if((n/100000)%10==7)
        printf("Seven Hundred ");
    else if((n/100000)%10==6)
        printf("Six Hundred ");
    else if((n/100000)%10==5)
        printf("Five Hundred ");
    else if((n/100000)%10==4)
        printf("Four Hundred ");
    else if((n/100000)%10==3)
        printf("Three Hundred ");
    else if((n/100000)%10==2)
        printf("Two Hundred ");
    else if((n/100000)%10==1)
        printf("One Hundred ");

    if((n/1000)%100<=19&&(n/1000)%100>=10){ //counts for thousands lesser than hundred thousands
        if((n/1000)%100==19) //writes for 19 thousand to 10 thousand
            printf("Nineteen ");
        if((n/1000)%100==18)
            printf("Eighteen ");
        if((n/1000)%100==17)
            printf("Seventeen ");
        if((n/1000)%100==16)
            printf("Sixteen ");
        if((n/1000)%100==15)
            printf("Fifteen ");
        if((n/1000)%100==14)
            printf("Fourteen ");
        if((n/1000)%100==13)
            printf("Thirteen ");
        if((n/1000)%100==12)
            printf("Twelve ");
        if((n/1000)%100==11)
            printf("Eleven ");
        if((n/1000)%100==10)
            printf("Ten ");
    }
    else{
        if((n/10000)%10==9)//writes for 99 thousand to 20 thousand
            printf("Ninety ");
        if((n/10000)%10==8)
            printf("Eighty ");
        if((n/10000)%10==7)
            printf("Seventy ");
        if((n/10000)%10==6)
            printf("Sixty ");
        if((n/10000)%10==5)
            printf("Fifty ");
        if((n/10000)%10==4)
            printf("Forty ");
        if((n/10000)%10==3)
            printf("Thirty ");
        if((n/10000)%10==2)
            printf("Twenty ");

        if((n/10000)%10>1) //hyphenates for compound words
            printf("- ");

        if((n/1000)%10==9) //for singular thousands/compounds
            printf("Nine ");
        if((n/1000)%10==8)
            printf("Eight ");
        if((n/1000)%10==7)
            printf("Seven ");
        if((n/1000)%10==6)
            printf("Six ");
        if((n/1000)%10==5)
            printf("Five ");
        if((n/1000)%10==4)
            printf("Four ");
        if((n/1000)%10==3)
            printf("Three ");
        if((n/1000)%10==2)
            printf("Two ");
        if((n/1000)%10==1)
            printf("One ");
    }

    if((n/1000)%1000!=0) //writes thousand if value reaches
        printf("Thousand ");

    if((n/100)%10==9) //counts hundreds
        printf("Nine Hundred ");
    else if((n/100)%10==8)
        printf("Eight Hundred ");
    else if((n/100)%10==7)
        printf("Seven Hundred ");
    else if((n/100)%10==6)
        printf("Six Hundred ");
    else if((n/100)%10==5)
        printf("Five Hundred ");
    else if((n/100)%10==4)
        printf("Four Hundred ");
    else if((n/100)%10==3)
        printf("Three Hundred ");
    else if((n/100)%10==2)
        printf("Two Hundred ");
    else if((n/100)%10==1)
        printf("One Hundred ");

    if(n%100<=19&&n%100>=10){ //counts for ones lesser than hundreds
        if(n%100==19) //writes for 19 to 10
            printf("Nineteen ");
        if(n%100==18)
            printf("Eighteen ");
        if(n%100==17)
            printf("Seventeen ");
        if(n%100==16)
            printf("Sixteen ");
        if(n%100==15)
            printf("Fifteen ");
        if(n%100==14)
            printf("Fourteen ");
        if(n%100==13)
            printf("Thirteen ");
        if(n%100==12)
            printf("Twelve ");
        if(n%100==11)
            printf("Eleven ");
        if(n%100==10)
            printf("Ten ");
    }
    else{
        if((n/10)%10==9)//writes for 99 thousand to 20 thousand
            printf("Ninety ");
        if((n/10)%10==8)
            printf("Eighty ");
        if((n/10)%10==7)
            printf("Seventy ");
        if((n/10)%10==6)
            printf("Sixty ");
        if((n/10)%10==5)
            printf("Fifty ");
        if((n/10)%10==4)
            printf("Forty ");
        if((n/10)%10==3)
            printf("Thirty ");
        if((n/10)%10==2)
            printf("Twenty ");

        if((n/10)%10>1) //hyphenates for compound words
            printf("- ");

        if(n%10==9) //for singular ones/compounds
            printf("Nine ");
        if(n%10==8)
            printf("Eight ");
        if(n%10==7)
            printf("Seven ");
        if(n%10==6)
            printf("Six ");
        if(n%10==5)
            printf("Five ");
        if(n%10==4)
            printf("Four ");
        if(n%10==3)
            printf("Three ");
        if(n%10==2)
            printf("Two ");
        if(n%10==1)
            printf("One ");
    }

    return;
}

void toRom(int n){
    if(n/1000>0){ //checks if n needs 'M'
        while(n>=1000){ //while there are thousands, print 'M'
            printf("M");
            n-=1000;
        }
    }

    if(n/100>0){ //checks if n needs 'C', 'D', 'CD', or 'CM'
        if(n/100==9){ //if there is 900, print 'CM'
            printf("CM");
            n-=900;
        }
        else if(n/100==4){ //if there is 400, print 'CM'
            printf("CD");
            n-=400;
        }

        if(n/100>=5){ //if 500, prints 'D'
            printf("D");
            n-=500;
        }

        while(n>=100){ //adds 'C' for every 100 not used from earlier
            printf("C");
            n-=100;
        }
    }

    if(n/10>0){ //checks if n needs 'X', 'L', 'XL', or 'XC'
        if(n/10==9){ //if there is 90, print 'XC'
            printf("XC");
            n-=90;
        }
        else if(n/10==4){ //if there is 40, print 'XL'
            printf("XL");
            n-=40;
        }

        if(n/10>=5){ //if 50, prints 'L'
            printf("L");
            n-=50;
        }

        while(n>=10){ //adds 'X' for every 10 not used from earlier
            printf("X");
            n-=10;
        }
    }

    if(n>0){ //checks if n needs 'I', 'V', 'IV', or 'IX'
        if(n==9){ //if there is 9, print 'IX'
            printf("IX");
            n-=9;
        }
        else if(n==4){ //if there is 4, print 'IV'
            printf("IV");
            n-=4;
        }

        if(n>=5){ //if 5, prints 'V'
            printf("V");
            n-=5;
        }

        while(n>=1){ //adds 'I' for every 1 not used from earlier
            printf("I");
            n-=1;
        }
    }

    return;
}

void initialize(int table[][14]){ //initializes table for states
    table[0][0]=0; //for 'dead state'
    table[0][1]=0;
    table[0][2]=0;
    table[0][3]=0;
    table[0][4]=0;
    table[0][5]=0;
    table[0][6]=0;
    table[0][7]=0;
    table[0][8]=0;
    table[0][9]=0;
    table[0][10]=0;
    table[0][11]=0;
    table[0][12]=0;
    table[0][13]=0;

    table[1][0]=0; //for 'M'
    table[1][1]=1;
    table[1][2]=2;
    table[1][3]=3;
    table[1][4]=4;
    table[1][5]=5;
    table[1][6]=6;
    table[1][7]=7;
    table[1][8]=8;
    table[1][9]=9;
    table[1][10]=10;
    table[1][11]=11;
    table[1][12]=12;
    table[1][13]=13;

    table[2][0]=0; //for 'CM'
    table[2][1]=0;
    table[2][2]=0;
    table[2][3]=0;
    table[2][4]=0;
    table[2][5]=0;
    table[2][6]=6;
    table[2][7]=7;
    table[2][8]=8;
    table[2][9]=9;
    table[2][10]=10;
    table[2][11]=11;
    table[2][12]=12;
    table[2][13]=13;

    table[3][0]=0; //for 'D'
    table[3][1]=0;
    table[3][2]=0;
    table[3][3]=0;
    table[3][4]=0;
    table[3][5]=5;
    table[3][6]=6;
    table[3][7]=7;
    table[3][8]=8;
    table[3][9]=9;
    table[3][10]=10;
    table[3][11]=11;
    table[3][12]=12;
    table[3][13]=13;

    table[4][0]=0; //for 'CD'
    table[4][1]=0;
    table[4][2]=0;
    table[4][3]=0;
    table[4][4]=0;
    table[4][5]=0;
    table[4][6]=6;
    table[4][7]=7;
    table[4][8]=8;
    table[4][9]=9;
    table[4][10]=10;
    table[4][11]=11;
    table[4][12]=12;
    table[4][13]=13;

    table[5][0]=0; //for 'C'
    table[5][1]=0;
    table[5][2]=0;
    table[5][3]=0;
    table[5][4]=0;
    table[5][5]=5;
    table[5][6]=6;
    table[5][7]=7;
    table[5][8]=8;
    table[5][9]=9;
    table[5][10]=10;
    table[5][11]=11;
    table[5][12]=12;
    table[5][13]=13;

    table[6][0]=0; //for 'XC'
    table[6][1]=0;
    table[6][2]=0;
    table[6][3]=0;
    table[6][4]=0;
    table[6][5]=0;
    table[6][6]=0;
    table[6][7]=0;
    table[6][8]=0;
    table[6][9]=0;
    table[6][10]=10;
    table[6][11]=11;
    table[6][12]=12;
    table[6][13]=13;

    table[7][0]=0; //for 'L'
    table[7][1]=0;
    table[7][2]=0;
    table[7][3]=0;
    table[7][4]=0;
    table[7][5]=0;
    table[7][6]=0;
    table[7][7]=0;
    table[7][8]=0;
    table[7][9]=9;
    table[7][10]=10;
    table[7][11]=11;
    table[7][12]=12;
    table[7][13]=13;

    table[8][0]=0; //for 'XL'
    table[8][1]=0;
    table[8][2]=0;
    table[8][3]=0;
    table[8][4]=0;
    table[8][5]=0;
    table[8][6]=0;
    table[8][7]=0;
    table[8][8]=0;
    table[8][9]=0;
    table[8][10]=10;
    table[8][11]=11;
    table[8][12]=12;
    table[8][13]=13;

    table[9][0]=0; //for 'X'
    table[9][1]=0;
    table[9][2]=0;
    table[9][3]=0;
    table[9][4]=0;
    table[9][5]=0;
    table[9][6]=0;
    table[9][7]=0;
    table[9][8]=0;
    table[9][9]=9;
    table[9][10]=10;
    table[9][11]=11;
    table[9][12]=12;
    table[9][13]=13;

    table[10][0]=0; //for 'IX'
    table[10][1]=0;
    table[10][2]=0;
    table[10][3]=0;
    table[10][4]=0;
    table[10][5]=0;
    table[10][6]=0;
    table[10][7]=0;
    table[10][8]=0;
    table[10][9]=0;
    table[10][10]=0;
    table[10][11]=0;
    table[10][12]=0;
    table[10][13]=0;

    table[11][0]=0; //for 'V'
    table[11][1]=0;
    table[11][2]=0;
    table[11][3]=0;
    table[11][4]=0;
    table[11][5]=0;
    table[11][6]=0;
    table[11][7]=0;
    table[11][8]=0;
    table[11][9]=0;
    table[11][10]=0;
    table[11][11]=0;
    table[11][12]=0;
    table[11][13]=13;

    table[12][0]=0; //for 'IV'
    table[12][1]=0;
    table[12][2]=0;
    table[12][3]=0;
    table[12][4]=0;
    table[12][5]=0;
    table[12][6]=0;
    table[12][7]=0;
    table[12][8]=0;
    table[12][9]=0;
    table[12][10]=0;
    table[12][11]=0;
    table[12][12]=0;
    table[12][13]=0;

    table[13][0]=0; //for 'I'
    table[13][1]=0;
    table[13][2]=0;
    table[13][3]=0;
    table[13][4]=0;
    table[13][5]=0;
    table[13][6]=0;
    table[13][7]=0;
    table[13][8]=0;
    table[13][9]=0;
    table[13][10]=0;
    table[13][11]=0;
    table[13][12]=0;
    table[13][13]=13;
}

int romInput(char input, char inPlus){ //checking using state diagram/table
    if(input=='M') //if first char is 'M'
        return 1;

    if(input=='C'){ //if first char is 'C'
        if(inPlus=='M') //if 'CM'
            return 2;
        else if(inPlus=='D') //if 'CD'
            return 4;
        else //if just 'C'
            return 5;
    }

    if(input=='D') //if first char is 'D'
        return 3;

    if(input=='X'){  //if first char is 'X'
        if(inPlus=='C') //if 'XC'
            return 6;
        else if(inPlus=='L') //if 'XL'
            return 8;
        else //if just 'X'
            return 9;
    }

    if(input=='L') //if first char is 'L'
        return 7;

    if(input=='I'){ //if first char is 'I'
        if(inPlus=='X') //if 'IX'
            return 10;
        else if(inPlus=='V') //if 'IV'
            return 12;
        else //if just 'X'
            return 13;
    }

    if(input=='V') //if first char is 'V'
        return 11;

    return 0; //if none fits the preceding conditions, returns 0

}

int romCheck(char rom[],int table[][14]){
    int count[14],i,state=1;

    for(i=0;i<14;i++)
        count[i]=0;

    for(i=0;rom[i]!='\0';i++){ //parses through input
        state=table[state][romInput(rom[i],rom[i+1])]; //defines state based on previous state

        if(state==0)
            return 0; //if check is in 'dead state', return 0

        count[state]++; //count number of times an input appears

        if(count[state]>3)
            return 0;

        if(state%2==0) //if input is considered double digit [all even romInputs except 0]
            i++;
    }

    return 1; //returns 1 if nothing goes wrong
}

void capitalize(char word[]){ //capitalizes tha lowercase characters in a string
    int i, strEnd = strlen(word);

    for(i=0;i<strEnd;i++){
        if (word[i]>='a'&&word[i]<='z')
            word[i]=word[i]-('a'-'A');
    }

    return; //because I am OCD
}

void toInt(char rom[]){
    int i,num=0;

    for(i=0;rom[i]!='\0';i++){ //parses through the string
        if(rom[i]=='M') //if parsing detects 'M', converts to equivalent '1000'
            num+=1000;
        else if(rom[i]=='C'){ //if parsing detects 'C', converts to equivalent
            if(rom[i+1]=='M'){ //if parsing finds 'CM', converts to equivalent '900'
                num+=900;
                i++;
            }
            else if(rom[i+1]=='D'){ //if parsing finds 'CD', converts to equivalent '400'
                num+=400;
                i++;
            }
            else //else defaults to equivalent '100'
                num+=100;
        }
        else if(rom[i]=='D') //if parsing detects 'D', converts to equivalent '500'
            num+=500;
        else if(rom[i]=='X'){ //if parsing detects 'X', converts to equivalent
            if(rom[i+1]=='C'){ //if parsing finds 'XC', converts to equivalent '90'
                num+=90;
                i++;
            }
            else if(rom[i+1]=='L'){ //if parsing finds 'XL', converts to equivalent '40'
                num+=40;
                i++;
            }
            else //else defaults to equivalent '10'
                num+=10;
        }
        else if(rom[i]=='L') //if parsing detects 'L', converts to equivalent '50'
            num+=50;
        else if(rom[i]=='I'){ //if parsing detects 'I', converts to equivalent
            if(rom[i+1]=='X'){ //if parsing finds 'IX', converts to equivalent '9'
                num+=9;
                i++;
            }
            else if(rom[i+1]=='V'){ //if parsing finds 'IV', converts to equivalent '4'
                num+=4;
                i++;
            }
            else //else defaults to equivalent '1'
                num+=1;
        }
        else if(rom[i]=='V') //if parsing detects 'D', converts to equivalent '500'
            num+=5;

    }

    printf("%d",num); //prints out number

    return;
}
