//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program is basically a database of students implemented as a linked list.*/


#include <stdio.h>
#include <string.h>
#include "list.h"

void display(list); //displays whole list
void displayStudent(student); //displays specific student
void displayYear(list,int); //displays students by year
void capitalize(char[]); //capitalize
int stValid(char[]); //checks if input is a valid Student Number
int stAvail(list,char[]); //checks if input matches a pre-existing student number
int alphaCheck(char[]); //checks for the alphabet
void sort(list*,int);
void sortLast(list*);
int search(list); //searches for students using last name
int numeral(char[]); //checks if string contains just numerical characters
void courseInit(char[][30]); //initializes courses for copy


int main(){
    list sheet;
    student input,cast;
    int pos,i,yr,valid;
    char sel,choice[3],course[8][30];

    initList(&sheet);
    courseInit(course);

    do{
        printf("\n\tSTUDENT RECORD\n");
        printf("\n\t\t1.  Enroll a student\n\t\t2.  Drop a student\n\t\t3.  Sort by ID\n\t\t4.  Sort by name\n\t\t5.  Display all students\n\t\t6.  Display all students by Year\n\t\t7.  Search by Name\n\t\t8.  Exit");

        printf("\n\n\t\tInput: ");

        scanf("%[^\n]c",&sel); //proceeds after being given a value or if enter is pressed
        fflush(stdin);

        switch(sel){
        case '1': //does the enrolling
            system("cls"); //clears screen
            printf("\n\tInput Student:\n");

            valid=1; //initializes valid
            do{
                if(valid==0){ //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");
                }

                printf("\n\t\tStudent No.: ");
                gets(input.number);
                fflush(stdin);

                valid=stValid(input.number);

                if(valid==1) //if input passes the format validity
                    valid=stAvail(sheet,input.number); //function checks if there are conflicting numbers

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
                printf("\n\tSelect from the following:\n"); //menu for courses
                printf("\n\t\t1. BS Computer Science\n\t\t2. B Fine Arts\n\t\t3. BS Management");
                printf("\n\t\t4. BA Mass Communication\n\t\t5. BS Mathematics\n\t\t6. BA Political Science");
                printf("\n\t\t7. BA Psychology\n\t\t8. BS Biology\n");


                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tProgram: ");
                scanf("%[^\n]s",&choice);
                fflush(stdin);

                valid=numeral(choice); //checks if input is numerical

                if(valid==1){ //passes here if input was numerical
                    if(atoi(choice)<1||atoi(choice)>8) //checks if input is within range of course numbers
                        valid=0;
                }
            }while(valid==0);

            strcpy(input.program,course[atoi(choice)-1]); //defines course based on input

            valid=1;

            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tYear Level: ");
                gets(choice);
                fflush(stdin);

                valid=numeral(choice); //checks if input is numerical

                if(valid==1){ //passes here if input was numerical
                    if(atoi(choice)<1||atoi(choice)>4) //checks if input is within range of year <1-4>
                        valid=0;
                }
            }while(valid==0);

            input.yr=atoi(choice); //assigns year

            valid=1; //initializes valid
            do{
                if(valid==0) //prints a statement based on validity
                    printf("\n\t\tInput was invalid.");

                printf("\n\t\tGender: ");
                scanf("%c",&input.gender);
                fflush(stdin);

                /*if(input.gender=='m'||input.gender=='f') //capitalizes gender
                    input.gender=input.gender-32;*/

                if(input.gender=='m') //capitalizes little inputs
                    input.gender='M';
                else if(input.gender=='f')
                    input.gender='F';

                if(input.gender=='M'||input.gender=='F') //checks if input is valid
                    valid=1;
                else
                    valid=0;
            }while(valid==0);

            append(&sheet,input);
            break;
        case '2':
            system("cls");
            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to drop!\n");
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
                printf("\n\tThere are no students in this class to sort!\n"); //fix later
            }
            else //proceeds to sort students by student number
               sort(&sheet,1);
            break;
        case '4':
            system("cls");
            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to sort!\n"); //fix later
            }
            else //proceeds to sort students by name
               sort(&sheet,2);
               sort(&sheet,2);
            break;
        case '5':
            system("cls");

            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class.\n");
            }
            else{ //proceeds to display if there ARE students
                printf("\n\tStudents of this class:\n");
                display(sheet);

                printf("\n"); //adds a clean space
            }
            break;
        case '6':
            system("cls");

            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to display!\n");
            }
            else{ //proceeds to search for students
                valid=0; //initializes valid

                printf("\n\tInput year level <1-4 or 'all'>: ");
                scanf("%s",&choice);
                fflush(stdin);

                if(numeral(choice)==1){ //checks if input is a numerical value
                    if(atoi(choice)>=1&&atoi(choice)<=4) //check if input is within range
                        valid=1;
                }

                if(strcmp(choice,"all")==0){ //if all is invoke, program will proceed to display all students in order of years
                    for(yr=1;yr<=4;yr++){ //increments by year
                        displayYear(sheet,yr);
                        printf("\n\n");
                    }
                }
                else if(valid==1){
                    yr=atoi(choice); //defines year based on input
                    displayYear(sheet,yr);
                }
                else
                    printf("\n\tInput is not part of the choices\n");
            }
            break;
        case '7':
            system("cls");

            if(sheet.size==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to search for!\n");
            }
            else{ //proceeds to search for students
                valid=search(sheet); //calls search

                if(valid==0) //if search returns unsuccessful
                    printf("\n\tThere are no students that match query!\n");

            }
            break;
        case '8':
            printf("\n\tProgram will now exit...");
            break;
        default:
            printf("\n\tInput is invalid.");
            break;
        }

        printf("\n\t");
        system("pause");
        system("cls"); //cleans the screen
    }while(sel!='8');

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

void displayYear(list sheet,int yr){
    int i;
    student cast;

    printf("\n\tStudents of Year %d are:\n",yr);

    for(i=1;i<=sheet.size;i++){
        cast=getItem(sheet,i);

        if(cast.yr==yr)
            displayStudent(cast);
    }

    return;
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

int stAvail(list l,char num[]){ //checks through list for matching student number
    int i;
    char test[15];
    student check;

    for(i=1;i<l.size+1;i++){
        check=getItem(l,i); //gets student info

        strcpy(test,check.number); //copies check number to test

        if(strcmp(test,num)==0) //checks if input matches a pre-existing number
            return 0;
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

void sort(list *l, int mode){
    int j,i,mini;
    student castA, castB;
    //node *temp,mini,first,second;*/

    if(mode==1)
        printf("\n\tSorting Students by Student Number...");
    else
        printf("\n\tSorting Students by Name...");

    for(i=1;i<l->size+1;i++){ //sorts through elements of linked list
        mini = i; //defaults the first element as the minimum
        castA=getItem(*l,i);

        if(mode==1){ //for mode 1 "Student Number"
            for(j=i+1;j<l->size+1;j++){ //compares the other elements with the elements in linked-list
                castB=getItem(*l,j);

                if (strcmp(castB.number,castA.number)==-1) //if a smaller value is found, minimum is redefined
                    mini = j;
            }
        }
        else if(mode==2){ //for mode 2 "Name"
            for(j=i+1;j<l->size+1;j++){ //compares the other elements with the elements in linked-list
                castB=getItem(*l,j);

                if (strcmp(castB.lname,castA.lname)==-1) //if a smaller value is found, minimum is redefined
                    mini = j;
                else if(strcmp(castB.lname,castA.lname)==0){ //if last names are the same
                    if(strcmp(castB.fname,castA.fname)==-1) //if a smaller value is found, minimum is redefined
                        mini = j;
                    else if(strcmp(castB.fname,castA.fname)==0){ //if first names are the same
                        if(strcmp(castB.mname,castA.mname)==-1) //if a smaller value is found, minimum is redefined
                            mini = j;
                    }
                }
            }
        }

        castB=getItem(*l,mini); //gets the minimum value received from parsing

        deleteItem(l,i); //clears the position 'i' for insert
        insert(l,castB,i); //inserts minimum to position 'i'
        deleteItem(l,mini); //clears  position 'mini'
        insert(l,castA,mini); //inserts value from position 'i' to where minimum once was
    }

    printf("\n\n\tDone!\n\t");

    return; //because I am OCD
}

int search(list l){ //ask for query then searches for it in list
    char query[200];
    int success=0,i;
    student cast;

    printf("\n\t\tSearch Query: ");
    gets(query);
    fflush(stdin);

    capitalize(query); //capitalizes query

    printf("\n\t\tStudents that have the surname <%s>:\n",query);

    for(i=1;i<=l.size;i++){
        cast=getItem(l,i); //casts a student for comparison

        if(strcmp(cast.lname,query)==0){ //checks if query matches a student's surname in the list
            success=1; //turns success into 1
            displayStudent(cast); //displays student
        }
    }

    return success;
}

int numeral(char num[]){
    int i;

    for(i=0;num[i]!='\0';i++){ //parses through input <num>
        if(!(num[i]>='0'&&num[i]<='9'))
            return 0; //returns 0 if anything other than a number is found
    }

    return 1; //returns 1 if everything is okay
}

void courseInit(char course[][30]){
    strcpy(course[0],"BS Computer Science");
    strcpy(course[1],"B  Fine Arts");
    strcpy(course[2],"BS Management");
    strcpy(course[3],"BA Mass Communication");
    strcpy(course[4],"BS Mathematics");
    strcpy(course[5],"BA Political Science");
    strcpy(course[6],"BA Psychology");
    strcpy(course[7],"BS Biology");
}
