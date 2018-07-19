//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program shall ask a string input of their birthday which will then
tell them their Zodiac as well as a mini-fortune. The program will also
check the validity of input.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{ //creates a data type for easier transmission of data
    int month;
    int day;
    int year;
}date;

int parse(char[],int[][3]); //parses through input; also is error check
void initialize(int[][3]); //initializes a state diagram
void horoscope(char [60][200]); //transfers data from data.fort.txt to an array of arrays
int statePut(char); //returns state based on input
date convert(char[]); //converts date passed as string
int day31(int); //checks if the month has 31 days
void store(char[]); //stores input if valid
int zodiac(date); //identifies zodiac on input
void zodDis(int); //displays your zodiac
void displayDate(date); //function to display date structures


int main(){
    int table[3][3],valid,zCount[12],zod,i;
    char horo[60][200],input[20],quit,test[]="8/18/2014";
    date cast;

    initialize(table);
    horoscope(horo);

    for(i=0;i<12;i++) //initializes zCount
        zCount[i]=0;

    do{
        valid=1; //initializes valid for input

        do{
            system("cls"); //cleans screen
            printf("\n\tMP 6 (Today is a Good Day for Writing to and reading from Files)"); //types thing to console

            if(valid==0) //checks validity and prints if invalid
                printf("\n\n\tPrevious Input is invalid.");

            printf("\n\n\t\tInput date [mm/dd/yy]: ");
            gets(input); //gets input
            fflush(stdin);

            valid=parse(input,table);
        }while(valid==0);

        system("cls");

        store(input); //stores input to data.in

        cast=convert(input); //converts input to date structure and has cast hold it

        printf("\n\tBorn on ");
        displayDate(cast);
        printf(", your Zodiac is: ");
        zodDis(zodiac(cast));

        printf("\n\n\tYour horoscope for today is:\n\t\t%s",horo[(zodiac(cast)+(zCount[zodiac(cast)]*12))%60]);

        zCount[zodiac(cast)]++;

        printf("\n\t");
        system("pause");

        do{ //ask user if they want to quit; error check
            system("cls"); //cleans screen
            printf("\n\tQuit? [Y/N]: ");
            scanf("%[^\n]c",&quit);
            fflush(stdin);
        }while(!(quit=='Y'||quit=='y'||quit=='N'||quit=='n'));
    }while(!(quit=='Y'||quit=='y'));

    system("cls");
    printf("Program will exit...");

    return 0;
}

int parse(char birth[],int table[][3]){ //parsing function
    int slash=0,i,state=1;
    date check;

    for(i=0;birth[i]!='\0';i++){  //parses through input
        state=table[state][statePut(birth[i])]; //defines state through table

        if(state==0) //returns zero if at any point,
            return 0;

        if(state==2) //increments when 'slash' is encountered
            slash++;

        if(slash>2) //returns 0 if there are too many slashes
            return 0;
    }

    check=convert(birth);

    if(check.day==0||(check.month>12||check.month<=0))
        return 0; //returns 0 if month or day is non-existent

    if(check.month==2&&check.day>29)
        return 0; //returns 0 if date is higher that Feb. 29

    if((check.day>28)&&check.month==2&&check.year%4!=0)
        return 0; //returns 0 if date is on Feb. 29 on a non-leap year

    if((check.day>30)&&day31(check.month)==0)
        return 0; //returns 0 if day is higher than 30 on non-31 day months

    if((check.day>31)&&day31(check.month)==1)
        return 0; //returns 0 if day is higher than 31 on 31-day months

    return 1; //if everything is valid
}

void initialize(int table[][3]){ //initializes a state diagram
    int i;

    for(i=0;i<3;i++){ //initializes 'dead state'
        table[0][i]=0;
    }

    table[1][0]=0; //initializes outputs for state 1
    table[1][1]=1;
    table[1][2]=2;

    table[2][0]=0; //initializes outputs for state 2
    table[2][1]=1;
    table[2][2]=2;

    return;
}

void horoscope(char horo[][200]){ //initializes horoscopes
    int i;
    FILE *fp;

    fp = fopen("data.fort.txt", "r");
    if (fp == NULL) //displays a message if an error occurs
        printf("\n\tFile: data.fort.txt cannot be opened\n");

    for(i=0;fgets(horo[i],200,fp)!= NULL;i++); //copies lines from data.fort to array

    fclose(fp);

    return;
}

int statePut(char input){ //returns state based on input
    if(input>='0'&&input<='9') //returns 1 if input is numerical
        return 1;
    else if(input=='/')
        return 2;  //returns 2 if input is 'slash'
    else
        return 0; //returns 0 [dead state] if anything else
}

date convert(char birth[]){
    int slash=0,i;
    date occ;

    occ.year=0;
    occ.month=0;
    occ.day=0;

    for(i=0;birth[i];i++){
        if(birth[i]=='/'){
            slash++;
            i++;
        }
        if(slash==0)
            occ.month=occ.month*10+(birth[i]-('1'-1));
        else if(slash==1)
            occ.day=occ.day*10+(birth[i]-('1'-1));
        else if(slash==2)
            occ.year=occ.year*10+(birth[i]-('1'-1));
    }

    return occ;
}

int day31(int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 1; //returns 1 if it's Jan, Mar, May, Jul, Aug, Oct, or Dec
    else
        return 0; //return 0 if not
}

void store(char input[]){ //function that stores input
    FILE *fp;
    int i, i3;

    fp = fopen("data.in", "a");
    if (fp == NULL) //displays a message if an error occurs
        printf("\n\tFile: data.in could not be opened\n");

    fprintf(fp, "%s\n",input);

    fclose(fp);
    return;
}

int zodiac(date input){
    if(((input.month==1)&&(input.day>20&&input.day<32))||(input.month==2&&(input.day>0&&input.day<20))){ // for Aquarius
        return 0;
    }
    else if((input.month==2&&(input.day>19&&input.day<30))||(input.month==3&&(input.day>0&&input.day<21))){ // for Pisces
        return 1;
    }
    else if((input.month==3&&(input.day>20&&input.day<32))||(input.month==4&&(input.day>0&&input.day<21))){ //for Aries
        return 2;
    }
    else if((input.month==4&&(input.day>20&&input.day<31))||(input.month==5&&(input.day>0&&input.day<22))){ //for Taurus
        return 3;
    }
    else if((input.month==5&&(input.day>21&&input.day<32))||(input.month==6&&(input.day>0&&input.day<22))){ //for Gemini
        return 4;
    }
    else if((input.month==6&&(input.day>21&&input.day<31))||(input.month==7&&(input.day>0&&input.day<23))){ //for Cancer
        return 5;
    }
    else if((input.month==7&&(input.day>22&&input.day<32))||(input.month==8&&(input.day>0&&input.day<23))){ //for Leo
        return 6;
    }
    else if((input.month==8&&(input.day>22&&input.day<32))||(input.month==9&&(input.day>0&&input.day<24))){ //for Virgo
        return 7;
    }
    else if((input.month==9&&(input.day>23&&input.day<31))||(input.month==10&&(input.day>0&&input.day<24))){ //for Libra
        return 8;
    }
    else if((input.month==10&&(input.day>23&&input.day<32))||(input.month==11&&(input.day>0&&input.day<23))){ //for Scorpio
        return 9;
    }
    else if((input.month==11&&(input.day>22&&input.day<31))||(input.month==12&&(input.day>0&&input.day<22))){ //for Sagittarius
        return 10;
    }
    else if((input.month==12&&(input.day>21&&input.day<32))||(input.month==1&&(input.day>0&&input.day<21))){ //for Capricorn
        return 11;
    }
}

void zodDis(int zod){
    if(zod==0)
        printf("Aquarius");
    else if(zod==1)
        printf("Pisces");
    else if(zod==2)
        printf("Aries");
    else if(zod==3)
        printf("Taurus");
    else if(zod==4)
        printf("Gemini");
    else if(zod==5)
        printf("Cancer");
    else if(zod==6)
        printf("Leo");
    else if(zod==7)
        printf("Virgo");
    else if(zod==8)
        printf("Libra");
    else if(zod==9)
        printf("Scorpio");
    else if(zod==10)
        printf("Sagittarius");
    else if(zod==11)
        printf("Capricorn");
}

void displayDate(date occ){ //used to display the date structure
    printf("%d/%d/%d",occ.month,occ.day,occ.year);
    return;
}
