//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program works like a student database. User can enroll,
drop, display all students as well as search using student number*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char stNo[11], firName[200], midName[200], lastName[200], sex;
    int yearLvl, age, grade,prog;
}student;

void display(student); //displays student data from student structure
int stCheck(student[],char[]); //checks for  student number availability
void capitalize(char[]); //capitalize
int stValid(char[]); //checks if input is a valid Student Number
int alphaCheck(char[]); //checks for the alphabet
void disRecur(student,int); //displays current elements in input
void courseDis(int);
int enroll(student[],student,int*);

int main(){
    student sheet[5], input; //'sheet' is the list of students; 'input' is temp input for student
    int total=0,step,valid,pSel,confirm,i; //'total' is total no. of students;'step' is step/state in input;'valid' is for the validity of input; 'confirm' is for confirmation of input
    char sel,des; //'sel' is the selection in Menu

    for(i=0;i<5;i++)
        sheet[i].stNo[0]=0;

    do{
        printf("\n\tSTUDENT RECORD\n");
        printf("\n\t\t1.  Enroll a student\n\t\t2.  Drop a student\n\t\t3.  Display all students\n\t\t4.  Search by Family Name\n\t\t5.  Exit");

        printf("\n\tTotal in main is: %d",total); //remove later

        if (total==5) //if class is full, it invalidates the use of enrolling as well as notify that the class if full
            printf("\n\n\t\t  NO MORE SLOTS! CANNOT EXCEPT ANY MORE STUDENTS");

        printf("\n\n\t\tInput: ");

        scanf("%[^\n]c",&sel); //proceeds after being given a value or if enter is pressed
        fflush(stdin);

        switch(sel){
        case '1': //does the enrolling
            if(total<5){
                do{ //loops until input has been confirmed
                        valid=1; //initializes valid
                        step=0; //initializes 'step'

                        do{
                                system("cls");

                                printf("\n\tStudent Information:\n");

                                disRecur(input,step); //displays elements that exist

                                switch(step){ //switch for input, 'step' defines what is currently being inputed
                                case 0:
                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\tPrevious input was invalid.");

                                    printf("\n\tStudent No.: "); //collects input
                                    gets(input.stNo);
                                    fflush(stdin);

                                    valid=stCheck(sheet,input.stNo); //replace with stCheck

                                    if (valid==1){
                                        step++;
                                        valid=1; //re-initializes 'valid'
                                    }

                                    break;
                                case 1:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tFamily Name: "); //collects input
                                    gets(input.lastName);
                                    fflush(stdin);
                                    capitalize(input.lastName); //capitalizes input

                                    valid=alphaCheck(input.lastName); //checks if input is valid

                                    if (valid==1){
                                        step++;
                                        valid=1; //re-initializes 'valid'
                                    }

                                    break;
                                case 2:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tFirst Name: "); //collects input
                                    gets(input.firName);
                                    fflush(stdin);
                                    capitalize(input.firName); //capitalizes input

                                    valid=alphaCheck(input.firName); //checks if input is valid

                                    if (valid==1){
                                        step++;
                                        valid=1; //re-initializes 'valid'
                                    }

                                    break;
                                case 3:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tMiddle Name: "); //collects input
                                    gets(input.midName);
                                    fflush(stdin);
                                    capitalize(input.midName); //capitalizes input

                                    valid=alphaCheck(input.midName); //checks if input is valid

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                case 4:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tProgram:"); //collects input
                                    printf("\n\n\t\t\tSelect from the following:\n");
                                    printf("\n\t\t1. BS Computer Science\n\t\t2. B Fine Arts\n\t\t3. BS Management");
                                    printf("\n\t\t4. BA Mass Communication\n\t\t5. BS Mathematics\n\t\t6. BA Political Science");
                                    printf("\n\t\t7. BA Psychology\n\t\t8. BS Biology\n\n\t\tSelection: ");

                                    scanf("%d",&input.prog);
                                    fflush(stdin);

                                    if(input.prog>=1&&input.prog<=8) //checks if input is valid
                                        valid=1;
                                    else
                                        valid=0;

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                case 5:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tYear Level: "); //collects input
                                    scanf("%d",&input.yearLvl);

                                    if(input.yearLvl<1) //checks if input is valid
                                        valid=0;
                                    else
                                        valid=1;

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                case 6:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tAge: "); //collects input
                                    scanf("%d",&input.age);
                                    fflush(stdin);

                                    if(input.age<1) //checks if input is valid
                                        valid=0;
                                    else
                                        valid=1;

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                case 7:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tGender [M/F]: "); //collects input
                                    scanf("%c",&input.sex);
                                    fflush(stdin);
                                    if(input.sex=='f'||input.sex=='m') //capitalizes input
                                        input.sex=input.sex-('a'-'A');

                                    if(input.sex=='F'||input.sex=='M') //checks if input is valid
                                        valid=1;
                                    else
                                        valid=0;

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                case 8:
                                    printf("\n"); //add a blank line for cleanliness

                                    if(valid==0) //displays a message on invalid input
                                        printf("\n\t\tPrevious input was invalid.");

                                    printf("\n\t\tFinal Grade: "); //collects input
                                    scanf("%d",&input.grade);
                                    fflush(stdin);

                                    if(input.grade<0||input.grade>100) //checks if input is valid
                                        valid=0;
                                    else
                                        valid=1;

                                    if (valid==1){
                                        step++;
                                    }

                                    break;
                                default:
                                    break;
                                }

                        }while(step<9);

                        confirm=enroll(sheet,input,&total); //does the function for enrollment

                }while(confirm!=1);
            }
            else
                printf("\n\tCan't Accept any More Students.");
            break;
        case '2':
            system("cls");
            if(total==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to drop!\n\n\t");
            }
            else{ //proceeds to drop selected students
                valid=1; //initializes valid to 1

                do{
                    do{
                        printf("\n\tInput Student to Drop:\n");

                        if(valid==0)
                            printf("\n\t\tInput was invalid.");

                        printf("\n\t\tStudent No.: ");
                        gets(input.stNo);
                        fflush(stdin);

                        valid=stValid(input.stNo);

                        system("cls");

                    }while(valid!=1);

                    for(i=0;i<5;i++){ //checks for each student no. in the class record
                        if(strcmp(sheet[i].stNo,input.stNo)==0) //checks if input and student no. in the record match
                            break;
                    }

                    if(i==5) //if, through search, no results are found
                        printf("\n\tThere are no students who have that student number.");
                    else{
                        do{
                            display(sheet[i]); //displays matches student number

                            printf("\n\n\tRemove Student?\n\t[Y/N]: "); //asks confirmation from the user
                            scanf("%[^\n]c",&des);
                            fflush(stdin);

                            system("cls"); //cleans screen

                        }while(!(des=='n'||des=='N'||des=='y'||des=='Y'));

                        if(des=='y'||des=='Y'){
                            sheet[i].stNo[0]=0; //'deletes' that record of that particular student
                            total--; //reduces the number of students in class
                            confirm=1;
                        }
                        else{
                            do{ //asks if user wants to Re-input
                                system("cls");
                                printf("\n\t\tRe-input?\n\t\t[Y/N]: ");
                                scanf("%[^\n]c",&des);
                                fflush(stdin);

                            }while(!(des=='n'||des=='N'||des=='y'||des=='Y'));

                            if(des=='y'||des=='Y') //if user put 'yes', they can re-input values again
                                confirm=0;
                            else //else they will go back to Menu
                                confirm=1;
                        }
                    }
                }while(confirm!=1);
            }
            break;
        case '3':
            system("cls");

            if(total==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class.\n\n\t");
            }
            else{ //proceeds to display if there ARE students
                printf("\n\tDisplaying all students:");
                for(i=0;i<5;i++){ //checks through the student record
                    if(sheet[i].stNo[0]!='\0') //if student 'exists' they are printed out
                        display(sheet[i]);
                }
                printf("\n"); //adds a clean space
            }
            break;
        case '4':
            system("cls");

            if(total==0){ //checks if there are existing students
                printf("\n\tThere are no students in this class to search for!\n\n\t");
            }
            else{ //proceeds to search for students
                valid=1; //initializes valid to 1

                do{
                    do{
                        printf("\n\tInput Student(s) to Look For:\n");

                        if(valid==0)
                            printf("\n\t\tInput was invalid.");

                        printf("\n\t\tFamily Name: ");
                        gets(input.lastName);
                        fflush(stdin);

                        capitalize(input.lastName); //capitalize input)

                        valid=alphaCheck(input.lastName); //checks validity of input

                        system("cls");

                    }while(valid!=1);

                    valid=0; //re-initializes valid

                    printf("\n\tSearch Results:");

                    for(i=0;i<5;i++){ //checks for each student in the class record
                        if(strcmp(sheet[i].lastName,input.lastName)==0&&sheet[i].stNo[0]!='\0'){ //checks if input and last name in the record match as well as if that person is still 'in' class
                            display(sheet[i]);
                            valid=1; //valid is a placeholder term for 'search results have been found'
                        }
                    }

                    if(valid==0) //if, through search, no results are found
                        printf("\n\n\tThere are no students who have that last name.");

                    printf("\n\n\t"); //adds a clean space
                    system("pause");

                    do{ //asks if user wants to Re-input
                        system("cls");
                        printf("\n\t\tSearch again?\n\t\t[Y/N]: ");
                        scanf("%[^\n]c",&des);
                        fflush(stdin);
                    }while(!(des=='n'||des=='N'||des=='y'||des=='Y'));

                    if(des=='y'||des=='Y') //if user put 'yes', they can re-input values again
                        confirm=0;
                    else //else they will go back to Menu
                        confirm=1;

                }while(confirm!=1);
            }
            break;
        case '5':
            printf("\n\tProgram will now exit...");
            break;
        default:
            break;
        }

        printf("\n\t");
        system("pause");
        system("cls"); //cleans the screen
    }while(sel!='5');

    return 0;
}

void display(student stud){ //displays all the information of a Student Structure
    printf("\n\n\tStudent No: %s\n\t\tStudent Name:\t%s, %s %s",stud.stNo,stud.lastName,stud.firName,stud.midName);
    printf("\n\t\tAge: %d\n\t\tGender: ",stud.age);

        if(stud.sex=='M') //for gender
            printf("Male");
        else
            printf("Female");

    printf("\n\t\tProgram: "); //for course
    courseDis(stud.prog);

    printf("\n\t\tYear: %d",stud.yearLvl);
    printf("\n\n\t\tGrade: %d%%",stud.grade);

    return; //because I am OCD
}

int stCheck(student table[],char num[]){ //check if student No. does not conflict with existing student numbers
    int i;

    if(stValid(num)==0)
        return 0; //returns 0 if input is not in correct format

    for(i=0;i<5;i++){
        if (strcmp(table[i].stNo,num)==0)
            return 0; //returns 0 if a match is found in the database
    }

    return 1; //returns 1 is everything's good
}

void capitalize(char word[]){ //capitalizes the lowercase characters in a string
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


void disRecur(student stud, int step){ //displays existing elements in input
    switch(step){ //displays the current and all previous 'steps'
        case 1:
            printf("\n\tStudent No.: %s",stud.stNo);
            break;
        case 2:
            disRecur(stud,--step);
            printf("\n\t\tFamily Name: %s",stud.lastName);
            break;
        case 3:
            disRecur(stud,--step);
            printf("\n\t\tFirst Name: %s",stud.firName);
            break;
        case 4:
            disRecur(stud,--step);
            printf("\n\t\tMiddle Name: %s",stud.midName);
            break;
        case 5:
            disRecur(stud,--step);
            printf("\n\t\tProgram: ");
            courseDis(stud.prog);
            break;
        case 6:
            disRecur(stud,--step);
            printf("\n\t\tYear Level: %d",stud.yearLvl);
            break;
        case 7:
            disRecur(stud,--step);
            printf("\n\t\tAge: %d",stud.age);
            break;
        case 8:
            disRecur(stud,--step);
            if(stud.sex=='M')
                printf("\n\t\tGender: Male");
            else
                printf("\n\t\tGender: Female");
            break;
        /*case 9:
            disRecur(stud,--step);
            printf("\n\t\tFinal Grade: %d",stud.grade);
            break;*/ //code would never reach this point, left for documentation
        default:
            break;
    }

    return; //because I am OCD
}

void courseDis(int prog){
    switch(prog){ //prints the course assigned to number
        case 1:
            printf("BS Computer Science");
            break;
        case 2:
            printf("B Fine Arts");
            break;
        case 3:
            printf("BS Management");
            break;
        case 4:
            printf("BA Mass Communication");
            break;
        case 5:
            printf("BS Mathematics");
            break;
        case 6:
            printf("BA Political Science");
            break;
        case 7:
            printf("BA Psychology");
            break;
        case 8:
            printf("BS Biology");
            break;
        default:
            break;
    }
}

int enroll(student sheet[],student input,int* total){
    int i,confirm;
    char des;

    do{ //confirmation of input
        system("cls");
            display(input);

            printf("\n\n\t\tIs input correct?\n\t\t[Y/N]: ");
            scanf("%[^\n]c",&des);
            fflush(stdin);
        }while(!(des=='n'||des=='N'||des=='y'||des=='Y'));

        if(des=='y'||des=='Y'){ //if user is okay with input
            confirm=1;
            (*total)++;
            for(i=0;i<5;i++){ //searches and places input in empty space
                if(sheet[i].stNo[0]==0){
                    sheet[i]=input;
                    break;
                }
            }
        }
        else{ //if user does not like input
            do{ //asks if user wants to Re-input
                system("cls");
                printf("\n\t\tRe-input?\n\t\t[Y/N]: ");
                scanf("%[^\n]c",&des);
                fflush(stdin);
            }while(!(des=='n'||des=='N'||des=='y'||des=='Y'));

            if(des=='y'||des=='Y') //if user put 'yes', they can re-input values again
                confirm=0;
            else //else they will go back to Menu
                confirm=1;
        }

        printf("\nTotal in enrollment function is: %d",*total); //remove later

        return confirm; //returns confirm for confirmation
}
