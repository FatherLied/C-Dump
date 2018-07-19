//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program is basically a database of students implemented as a linked list.*/


#include <stdio.h>
#include <string.h>
#include "list.h"

void display(list);
void displayStudent(student);
void capitalize(char[]); //capitalize
int stValid(char num[]); //checks if input is a valid Student Number
int alphaCheck(char[]); //checks for the alphabet

int main(){
    list sheet;
    student input,cast;
    int pos,i,yr,valid;
    char sel;

    initList(&sheet);

    do{
        printf("\n\tSTUDENT RECORD\n");
        printf("\n\t\t1.  Enroll a student\n\t\t2.  Drop a student\n\t\t3.  Display all students\n\t\t4.  Display all students by Year\n\t\t5.  Exit");

        printf("\n\n\t\tInput: ");

        scanf("%[^\n]c",&sel); //proceeds after being given a value or if enter is pressed
        fflush(stdin);

        switch(sel){
        case '1': //does the enrolling
            system("cls");
            printf("\n\tInput Student:\n");

            valid=1; //initializes valid
            do{

                if(valid==0){ //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");
                }

                printf("\n\t\tStudent No.: ");
                scanf("%[^\n]s",&input.number);
                fflush(stdin);

                valid=stValid(input.number);
            }while(valid==0);

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tFirst Name: ");
                scanf("%[^\n]s",&input.fname);
                fflush(stdin);
                capitalize(input.fname);

                valid=alphaCheck(input.fname);
            }while(valid==0);

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tMiddle Name: ");
                scanf("%[^\n]s",&input.mname);
                fflush(stdin);
                capitalize(input.mname);

                valid=alphaCheck(input.mname);
            }while(valid==0);

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tLast Name: ");
                scanf("%[^\n]s",&input.lname);
                fflush(stdin);
                capitalize(input.lname);

                valid=alphaCheck(input.lname);
            }while(valid==0);

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tProgram: ");
                scanf("%[^\n]s",&input.program);
                fflush(stdin);
                capitalize(input.program);

                valid=alphaCheck(input.program);
            }while(valid==0);

            printf("\n\t\tYear Level: ");
            scanf("%d",&input.yr);
            fflush(stdin);

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tGender: ");
                scanf("%c",&input.gender);
                fflush(stdin);

                if(input.gender=='m'||input.gender=='f') //capitalizes gender
                    input.gender=input.gender-('A'-'a');

                if(input.gender=='M'||input.gender=='F') //checks if input is valid
                    valid=1;

            }while(valid==0);


            append(&sheet,input);
            break;
        case '2':
            system("cls");
            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to drop!\n\t");
            }
            else{ //proceeds to drop selected students
                valid=1; //initializes valid to 1

                    do{
                        printf("\n\tInput Student to Drop:\n");

                        if(valid==0)
                            printf("\n\t\tInput was invalid.");

                        printf("\n\t\tPosition: ");
                        scanf("%d",&pos);
                        fflush(stdin);

                        valid=deleteItem(&sheet,pos);

                        system("cls");

                    }while(valid!=1);

                    printf("\n\tDelete Successful...\n");
            }
            break;
        case '3':
            system("cls");

            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class.\n\t");
            }
            else{ //proceeds to display if there ARE students
                printf("\n\tStudents of this class:\n");
                display(sheet);

                printf("\n"); //adds a clean space
            }
            break;
        case '4':
            system("cls");

            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to search for!\n\t");
            }
            else{ //proceeds to search for students
                printf("\n\tInput year level: ");
                scanf("%d",&yr);
                fflush(stdin);

                printf("\n\tStudents of Year %d are:\n");

                for(i=1;i<=sheet.size;i++){
                    cast=getItem(sheet,i);

                    if(cast.yr==yr)
                        displayStudent(cast);
                }

            }
            break;
        case '5':
            printf("\n\tProgram will now exit...");
            break;
        default:
            printf("\n\tInput is invalid.");
            break;
        }

        printf("\n\t");
        system("pause");
        system("cls"); //cleans the screen
    }while(sel!='5');

    return 0;
}

void display(list l){
    int i;
    for(i=1; i<=l.size;i++)
        displayStudent(getItem(l,i));
}

void displayStudent(student s){
    printf("\n\tStudent No.: %s\n",s.number);
    printf("\t\tLast Name:   %s\n",s.lname);
    printf("\t\tFirst Name:  %s\n",s.fname);
    printf("\t\tMiddle Name: %s\n",s.mname);
    printf("\t\tGender: %c\n",s.gender);
    printf("\t\tProgram & Year: %s %d\n",s.program,s.yr);
}

void capitalize(char word[]){ //capitalizes the lowercase characters in a string //for error checking
    int i;

    for(i=0;word[i]!='\0';i++){
        if (word[i]>='a'&&word[i]<='z') //if character is lowercase, it is capitalized
            word[i]=word[i]-('a'-'A');
    }

    return; //because I am OCD
}

int stValid(char num[]){
    int i;

    if(strlen(num)!=10)
        return 0; //returns 0 if input lacks in size

    for(i=0;num[i]!='\0';i++){
        if(i==4){
            if(num[i]!='-')
                return 0; //returns 0 if the fifth element is not a hyphen
            i++;
        }
        if(!(num[i]>='0'&&num[i]<='9'))
            return 0; //returns 0 if element is not a numeral
    }

    return 1; //if every element is valid, returns 1
}

int alphaCheck(char st[]){ //checks if name consists of only alphabetical characters
    int i;

    for(i=0;st[i]!='\0';i++){
        if (!(st[i]>='A'&&st[i]<='Z')&&st[i]!=' ')
            return 0; //returns 0 if other characters appear
    }

    return 1; //returns 1 if and only if the string contains no non-alphabet characters
}
