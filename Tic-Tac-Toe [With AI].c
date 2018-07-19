//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program is basically a game of Tic-Tac-Toe played by two human players.
Players will take turns inputting the coordinates of where they plan to place
their symbol ('x' or 'o') */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}point;

void display(char table[3][3]); //displays the Table; Code by Sir Ryan Dulaca
int checkRange(int,int); //checks if input is within range
int checkOcc(char[3][3],int,int); //checks occupancy of that element
int checkWin(char[3][3],char); //checks for the winner
int AIState(char[3][3],char); //looks for any possible win state
point fillIn(int); //assigns a fill given a state
point fillOut(char[3][3]); //fills if neither Win or Block State is possible


int main(){
    char ta[3][3]={{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
    point input;
    int turn=0, proceed=0, x, y;
    char win='d';

    do{
        do{
            printf("\n   Current Table:\n\n");
            display(ta); //displays the table

            if(proceed==1)
                printf("\n Input is not within range. Range is 0 - 2.\n"); //prints if input is not within range
            else if(proceed==2)
                printf("\n That space is NOT vacant.\n"); //prints if that element in the table is not vacant

            proceed=0; //turn proceed back to 0 if it's value is otherwise

            if(turn%2==0){ //determines which player is currently playing
                printf("\n Player 1 <x>");

                printf("\n Input coordinates <[x] [y]>:\n"); //input
                printf("\tx: ");
                scanf("%d",&x);
                printf("\ty: ");
                scanf("%d",&y);

                proceed=checkRange(x,y); //checks for Range

                if (proceed==0) //passes here if range is Legit
                    proceed=checkOcc(ta,x,y); //checks for vacancy/occupancy
            }
            else{
                if(AIState(ta,'o')!=0){ //checks for win [top precedence]
                    input=fillIn(AIState(ta,'o'));
                }
                else if(AIState(ta,'x')!=0){ //checks for areas to block [mid precedence]
                        input=fillIn(AIState(ta,'x'));
                }
                else{ //if AI can neither block nor win
                    input=fillOut(ta);
                }


                x=input.x;
                y=input.y;


                printf("\n AI <o>"); //to see input

                printf("\n Input coordinates <[x] [y]>:\n"); //pseudo-input
                printf("\tx: %d",x);
                printf("\n\ty: %d\n\n\t",y);

                system("pause");

                proceed=0; //proceeds regardless
            }

            system(("cls")); //cleans the screen

        }while(proceed>0);

        if(turn%2==0)
            ta[x][y]='x'; //fills in the input of player 1 with 'x'
        else
            ta[x][y]='o'; //fills in the input of player 2 with 'o'

        turn++; //increases turn

        if(turn>4){ //checks for winners after the fifth placement
            if(checkWin(ta,'x')==1){ //checks if x won
                win='x';
                break;
            }
            else if(checkWin(ta,'o')==1){ //checks if o won
                win='o';
                break;
            }
        }

    }while(turn<8);

    system("cls"); //cleans the screen

    if(win=='d'){
        for(x=0;x<3;x++){ //searches the whole table for '\0' then places 'x'
            for(y=0;y<3;y++){
                if (ta[x][y]=='\0'){
                    ta[x][y]='x';
                }
            }
        }

        if(checkWin(ta,'x')==1){ //checks if x won
            win='x';
        }
        else if(checkWin(ta,'o')==1){ //checks if o won
            win='o';
        }
    }

    printf("\n   Final Table:\n\n");
    display(ta);

    if(win=='x') //displays if Player 1 <x> won
        printf("\n Player 1 won!!!\n\n");
    else if (win=='o') //displays if Player 2 <o> won
        printf("\n Player 2 won!!!\n\n");
    else //displays if neither won
        printf("\n It's a draw!!!\n\n");

    system("pause"); //pauses so if .exe was chosen, you can see the victor

    return 0;
}

void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    printf("     0   1   2   y\n");
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf(" 0 %c %c %c %c %c %c %c\n",186,table[0][0],186,table[0][1],186,table[0][2],186);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf(" 1 %c %c %c %c %c %c %c\n",186,table[1][0],186,table[1][1],186,table[1][2],186);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf(" 2 %c %c %c %c %c %c %c\n",186,table[2][0],186,table[2][1],186,table[2][2],186);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c\n x\n",200,205,205,205,202,205,205,205,202,205,205,205,188);
}

int checkRange(int x, int y){
    if (x<0||x>2)
        return 1; //returns 1 if x is not within 0 - 2
    else if (y<0||y>2)
        return 1; //returns 1 if y is not within 0 - 2
    else
        return 0; //returns zero if input is valid
}

int checkOcc(char table[3][3], int x, int y){
    if (table[x][y]!='\0')
        return 2; //returns 2 if the element in table[x][y] is not '\0' meaning it is not "vacant"
    else
        return 0; //returns 0 if the element is "vacant"
}

int checkWin(char table[3][3], char check){
    int i, j, win;

    for(i=0;i<3;i++){ //checks each x-axis
        for(j=0;j<3;j++){ //check if all y's for x-axis is all equal to check
            if(table[i][j]==check) //if element is equal to check, code proceeds with potential win
                win=1;
            else{ //if something else, potential win will be cancelled
                win=0;
                break;
            }
        }
        if(win==1) //if win is 1 after loop, it returns win
            return 1;
    }

    for(j=0;j<3;j++){ //checks each y-axis
        for(i=0;i<3;i++){ //check if all x's for y-axis is all equal to check
            if(table[i][j]==check) //if element is equal to check, code proceeds with potential win
                win=1;
            else{ //if something else, potential win will be cancelled
                win=0;
                break;
            }
        }
        if(win==1) //if win is 1 after loop, it returns win
            return 1;
    }

    if(table[0][0]==check && table[1][1]==check && table[2][2]==check) //checks if win is diagonal from top-left to bottom-right
        return 1;

    if(table[2][0]==check && table[1][1]==check && table[0][2]==check) //checks if win is diagonal from bottom-left to top-right
        return 1;

    return 0; //returns 0 if nobody won

}

int AIState(char ta[3][3],char let){ //looks for any possible win state

    if(ta[0][0]==let&&ta[0][1]==let&&ta[0][2]=='\0')
        return 1;
    if(ta[1][0]==let&&ta[1][1]==let&&ta[1][2]=='\0')
        return 2;
    if(ta[2][0]==let&&ta[2][1]==let&&ta[2][2]=='\0')
        return 3;
    if(ta[0][0]=='\0'&&ta[0][1]==let&&ta[0][2]==let)
        return 4;
    if(ta[1][0]=='\0'&&ta[1][1]==let&&ta[1][2]==let)
        return 5;
    if(ta[2][0]=='\0'&&ta[2][1]==let&&ta[2][2]==let)
        return 6;
    if(ta[0][0]==let&&ta[1][0]==let&&ta[2][0]=='\0')
        return 7;
    if(ta[0][1]==let&&ta[1][1]==let&&ta[2][1]=='\0')
        return 8;
    if(ta[0][2]==let&&ta[1][2]==let&&ta[2][2]=='\0')
        return 9;
    if(ta[0][0]=='\0'&&ta[1][0]==let&&ta[2][0]==let)
        return 10;
    if(ta[0][1]=='\0'&&ta[1][1]==let&&ta[2][1]==let)
        return 11;
    if(ta[0][2]=='\0'&&ta[1][2]==let&&ta[2][2]==let)
        return 12;
    if(ta[0][0]==let&&ta[1][0]=='\0'&&ta[2][0]==let)
        return 13;
    if(ta[0][1]==let&&ta[1][1]=='\0'&&ta[2][1]==let)
        return 14;
    if(ta[0][2]==let&&ta[1][2]=='\0'&&ta[2][2]==let)
        return 15;
    if(ta[0][0]==let&&ta[0][1]=='\0'&&ta[0][2]==let)
        return 16;
    if(ta[1][0]==let&&ta[1][1]=='\0'&&ta[1][2]==let)
        return 17;
    if(ta[2][0]==let&&ta[2][1]=='\0'&&ta[2][2]==let)
        return 18;
    if(ta[0][0]==let&&ta[1][1]==let&&ta[2][2]=='\0')
        return 19;
    if(ta[0][0]==let&&ta[1][1]=='\0'&&ta[2][2]==let)
        return 20;
    if(ta[0][0]=='\0'&&ta[1][1]==let&&ta[2][2]==let)
        return 21;
    if(ta[0][2]==let&&ta[1][1]==let&&ta[2][0]=='\0')
        return 22;
    if(ta[0][2]==let&&ta[1][1]=='\0'&&ta[2][0]==let)
        return 23;
    if(ta[0][2]=='\0'&&ta[1][1]==let&&ta[2][0]==let)
        return 24;

    return 0; //if nothing matches given states

}

point fillIn(int n){ //assigns a fill given a state
    point rep;

    if(n==4||n==10||n==21){ //if top left is empty
        rep.x=0;
        rep.y=0;
    }
    else if(n==11||n==16){ //if top middle is empty
        rep.x=0;
        rep.y=1;
    }
    else if(n==1||n==12||n==24){ //if top right is empty
        rep.x=0;
        rep.y=2;
    }
    else if(n==5||n==13){ // if middle left is empty
        rep.x=1;
        rep.y=0;
    }
    else if(n==14||n==17||n==20||n==23){ //if middle middle is empty
        rep.x=1;
        rep.y=1;
    }
    else if(n==2||n==15){ // if middle right is empty
        rep.x=1;
        rep.y=2;
    }
    else if(n==6||n==7||n==22){ // if bottom left is empty
        rep.x=2;
        rep.y=0;
    }
    else if(n==8||n==18){ // if bottom middle is empty
        rep.x=2;
        rep.y=1;
    }
    else if(n==3||n==9||n==19){ // if bottom right is empty
        rep.x=2;
        rep.y=2;
    }

    return rep; //returns rep based on states given
}

point fillOut(char ta[3][3]){ //fills if neither Win or Block State is achieved
    point rep;

    if(ta[1][1]=='\0'){ //if table is bare [AI's Priority is the Center]
        rep.x=1;
        rep.y=1;
        return rep;
    }
    else if(ta[1][1]=='x'){
        if(ta[0][0]=='\0'){ //fills diagonal cross [NW,NE,SW,SE]
            rep.x=0;
            rep.y=0;
            return rep;
        }
        else if(ta[0][2]=='\0'){
            rep.x=0;
            rep.y=2;
            return rep;
        }
        else if(ta[2][0]=='\0'){
            rep.x=2;
            rep.y=0;
            return rep;
        }
        else if(ta[2][2]=='\0'){
            rep.x=2;
            rep.y=2;
            return rep;
        }

        if(ta[1][0]=='\0'){ //reaches here if Center,NW,NE,SE,SW are filled
            rep.x=1;
            rep.y=0;
            return rep;
        }
        else if(ta[0][1]=='\0'){
            rep.x=0;
            rep.y=1;
            return rep;
        }
        else if(ta[1][2]=='\0'){
            rep.x=1;
            rep.y=2;
            return rep;
        }
        else if(ta[2][1]=='\0'){
            rep.x=2;
            rep.y=1;
            return rep;
        }
    }
    else{
        if(ta[0][1]=='\0'&&!(ta[0][0]=='x'||ta[0][2]=='x')){ //fills cross [N,E,S,W]
            rep.x=0;
            rep.y=1;
            return rep;
        }
        else if(ta[1][2]=='\0'&&!(ta[0][2]=='x'||ta[2][2]=='x')){
            rep.x=1;
            rep.y=2;
            return rep;
        }
        else if(ta[2][1]=='\0'&&!(ta[2][0]=='x'||ta[2][2]=='x')){
            rep.x=2;
            rep.y=1;
            return rep;
        }
        else if(ta[1][0]=='\0'&&!(ta[0][0]=='x'||ta[2][0]=='x')){
            rep.x=1;
            rep.y=0;
            return rep;
        }


        if(ta[0][0]=='\0'){ //reaches here if Center,N,E,S,W are filled
            rep.x=0;
            rep.y=0;
            return rep;
        }
        else if(ta[2][2]=='\0'){
            rep.x=2;
            rep.y=2;
            return rep;
        }
        else if(ta[2][0]=='\0'){
            rep.x=2;
            rep.y=0;
            return rep;
        }
        else if(ta[0][2]=='\0'){
            rep.x=0;
            rep.y=2;
            return rep;
        }
    }
}
