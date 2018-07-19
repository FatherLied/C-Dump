#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

int main(){
    srand((unsigned int)time(NULL));
    char sel;
    int choice,life[2],manna[2],reroll,weapon[2],shield[2],mirror[2],whold,shold,mirget,cont,gameover,hp,mp,turn,miss,rounds,win;

    do{
        gameover=0;
        cont=0;
        do{
            printf("\n\t__________         __                       ");
            printf("\n\t\\______   \\_____ _/  |______ ___  _______   ");
            printf("\n\t |       _/\\__  \\\\   __\\__  \\\\  \\/ /\\__  \\");
            printf("\n\t |    |   \\ / __ \\|  |  / __ \\\\   /  / __ \\_");
            printf("\n\t |____|_  /(____  /__| (____  /\\_/  (____  /");
            printf("\n\t        \\/      \\/          \\/           \\/ \n\n\n");
            printf("\n\n\t\tStart Game [a]\n\t\tExit       [b]\n\n\n\t\tInput : ");
            scanf("%c",&sel);
            fflush(stdin);

            if(sel=='a')
                choice=1;
            else if(sel=='b')
                choice=0;
            else
                choice=(rand()%3)-4;

            system("cls");
        }while (choice<0||choice>1);

        if(choice==0){
            printf("Program will now Exit!!!\nThanks for playing! (If you did...)\n\n\n\tFinal Project for CMSC 11 @ 2014-2015\n\t  by JCM\n\n");
            return 0;
        }

        do{
            printf("Welcome to Ratava!\nThe two-player game where both of you will fight to the death!\n\n");
            printf("The Rules are simple:\n\n");
            printf("* Each player is given random equipment at the start, with various stats and\n  some stronger than others.");
            printf("\n* Players have can re-roll their equips before the game begins, however their\n  equips will not be revealed until the start of the game.");
            printf("\n* Players can either attack with their weapon or use a spell per round.");
            printf("\n* Melee damage can be reduced thanks to shield blockage.");
            printf("\n* Spells cannot be blocked, however, there is a special chance for an item to\n  appear, thus negating its effects.");
            printf("\n* Shields, regardless of type can fail to block attacks at all.");
            printf("\n\n\nRemember, the game is just for fun. No need to bludgeon each other thanks to\nrandom chance.\nEnjoy!");
            printf("\n\n\tContinue        [a]\n\tSee Equips List [b]\n\n\tInput: ");
            scanf("%c",&sel);
            fflush(stdin);

            if(sel=='a')
                choice=1;
            else if(sel=='b')
                choice=0;
            else
                choice=(rand()%3)-4;

            system("cls");
        }while(choice<0||choice>1);

        if(choice==0){
            printf("The possible equipment are as follows:\n\nMelee Weapons\t\t\tShields\n");
            printf("\tWooden Spear   - 1 dmg\t\tWooden Shield  - negate wood\n");
            printf("\tSilver Axe     - 2 dmg\t\tSilver Shield  - negate silver\n");
            printf("\tDiamond Scythe - 3 dmg\t\tDiamond Shield - negate diamond\n");
            printf("\nNote: Higher class materials can negate lower class materials.\nWooden->Silver->Diamond\n\n* Diamond Shield reflects damage back to the attacker.");
            printf("\n\n* There is a 1/20 for a player to stumble upon the Mona Lisa's Blink, a golden\n  mirror with the power to negate spells.\n\n  Note: Mona Lisa's Blink disappears after it's used but it can be stumbled upon  again.");
            printf("\n\n* Shields have a 1/3 chance to succeed\n\nIf you do not know how manna works, it is consumed by 6 every time you cast a\nspell. A player regenerates 2 manna per round.\n\n");
            system("pause");
            system("cls");
        }

        do{
            mirget=0;
            whold=rand()%3;
            shold=rand()%3;
            mirror[0]=mirget;
            weapon[0]=whold;
            shield[0]=shold;
            printf("The Gods have chosen your stuff!\nPlayer 1, do you have trust in their selection?\n\n");
            printf("\tYes [a]\n\tNo  [s]\n\n\tAnswer: ");
            scanf("%c",&sel);
            fflush(stdin);

            if(sel=='a'){
               reroll=1;
               printf("\n");
               system("pause");
            }
            else
                reroll=0;

            system("cls");
        }while(reroll<1);

        do{
            mirget=0;
            whold=rand()%3;
            shold=rand()%3;
            mirror[1]=mirget;
            weapon[1]=whold;
            shield[1]=shold;
            printf("The Gods have chosen your stuff!\nPlayer 2, do you have trust in their selection?\n\n");
            printf("\tYes [k]\n\tNo  [l]\n\n\tAnswer: ");
            scanf("%c",&sel);
            fflush(stdin);

            if(sel=='k'){
               reroll=1;
               printf("\n");
               system("pause");
            }
            else
                reroll=0;

            system("cls");
        }while(reroll<1);

        turn=0,gameover=0,hp=10,mp=10;
        life[0]=hp,life[1]=hp;
        manna[0]=mp,manna[1]=hp;
        printf("The Game has begun!!!\n");
        while(gameover==0){
            if (turn%2==0){
                mirget=rand()%20;
                if (mirget==0){
                    mirget=1;
                    mirror[0]=mirget;
                }
                if (manna[0]<10)
                    manna[0]=manna[0]+2;
                do{
                    printf("Player 1\n\tLife: %i/10\n\tManna: %i/10\n\n  Player 1, what will you do?\n\n",life[0],manna[0]);
                    printf("\tAttack -- ");
                    if (weapon[0]==0)
                        printf("Wooden Spear     [a]\n");
                    else if (weapon[0]==1)
                        printf("Silver Ax        [a]\n");
                    else
                        printf("Diamond Scythe   [a]\n");
                    printf("\tCast 'Kiss of Jade Smoke'  [s]");
                    if(manna[0]<6){
                        printf("\n\t\t*Not enough Manna to cast spell!*");
                    }
                    printf("\n\n\tAction: ");
                    scanf("%c",&sel);
                    fflush(stdin);

                    if(sel=='a'){
                        reroll=0;
                        choice=1; //melee
                    }
                    else if(sel=='s'){
                        if(manna[0]>=6){
                            reroll=0;
                            manna[0]=manna[0]-6;
                            choice=0; //magic
                        }
                        else
                            reroll=1;
                    }
                    else
                        choice=(rand()%3)-4;
                    system("cls");
                }while(choice<0||choice>1||reroll==1);

                printf("Player 1\n\tLife: %i/10\n\tManna: %i/10\n\n",life[0],manna[0]);

                if(choice==0){
                    printf("You cast the 'Kiss of Jade Smoke'!");
                    if (mirror[1]==1){
                        printf("\n      Opponent has the Mona Lisa's Blink! Spell failed!");
                        mirror[1]=0;
                    }
                    else {
                        printf("\n      Spell successful! You deal 2 dmg!");
                        life[1]=life[1]-2;
                    }
                }
                else{
                    miss=rand()%3;
                    printf("You swing the ");
                    if (weapon[0]==0){
                        printf("Wooden Sword!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 1 dmg!");
                            life[1]=life[1]-1;
                        }
                        else if (shield[1]==0)
                            printf("Opponent blocked with wooden shield! Dmg neutralized!");
                        else if (shield[1]==1){
                            printf("Opponent blocked with silver shield! It flies back to your face [1 dmg]!");
                            life[0]=life[0]-1;
                        }
                        else {
                            printf("Opponent blocked with diamond shield! It flies back to your face [1 dmg]!");
                            life[0]=life[0]-1;
                        }
                    }
                    else if (weapon[0]==1){
                        printf("Silver Ax!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 2 dmg!");
                            life[1]=life[1]-2;
                        }
                        else if (shield[1]==0){
                            printf("Opponent blocked with wooden shield! You deal only 1 dmg!");
                            life[1]=life[1]-1;
                        }
                        else if (shield[1]==1)
                            printf("Opponent blocked with silver shield! Dmg neutralized!");
                        else {
                            printf("Opponent blocked with diamond shield! It flies back to your face [2 dmg]!");
                            life[0]=life[0]-2;
                        }win=1;
                    }
                    else if (weapon[0]==2){
                        printf("Diamond Scythe!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 3 dmg!");
                            life[1]=life[1]-3;
                        }
                        else if (shield[1]==0){
                            printf("Opponent blocked with wooden shield! You deal 3 dmg!");
                            life[1]=life[1]-3;
                        }
                        else if (shield[1]==1){
                            printf("Opponent blocked with silver shield! You deal only 2 dmg!");
                            life[1]=life[1]-2;
                        }
                        else
                            printf("Opponent blocked with diamond shield! Dmg neutralized!");
                    }
                }
                if(life[1]<=0){
                    printf("\n\n\tOpponent has died! Player 1 wins!!\n\n");
                    system("pause");
                    system("cls");
                    win=0;
                    gameover=1;
                    break;
                }
                printf("\n\n");
                system("pause");
                system("cls");
                turn++;
            }
            if (turn%2==1){
                mirget=rand()%20;
                if (mirget==0){
                    mirget=1;
                    mirror[1]=mirget;
                }
                if (manna[1]<10)
                    manna[1]=manna[1]+2;
                do{
                    printf("Player 2\n\tLife: %i/10\n\tManna: %i/10\n\n  Player 2, what will you do?\n\n",life[1],manna[1]);
                    printf("\tAttack -- ");
                    if (weapon[1]==0)
                        printf("Wooden Spear     [k]\n");
                    else if (weapon[1]==1)
                        printf("Silver Ax        [k]\n");
                    else
                        printf("Diamond Scythe   [k]\n");
                    printf("\tCast 'Kiss of Jade Smoke'  [l]");
                    if(manna[1]<6){
                        printf("\n\t\t*Not enough Manna to cast spell!*");
                    }
                    printf("\n\n\tAction: ");
                    scanf("%c",&sel);
                    fflush(stdin);

                    if(sel=='k'){
                        reroll=0;
                        choice=1; //melee
                    }
                    else if(sel=='l'){
                        if(manna[1]>=6){
                            reroll=0;
                            manna[1]=manna[1]-6;
                            choice=0; //magic
                        }
                        else
                            reroll=1;
                    }
                    else
                        choice=(rand()%3)-4;
                    system("cls");
                }while(choice<0||choice>1||reroll==1);

                printf("Player 2\n\tLife: %i/10\n\tManna: %i/10\n\n",life[1],manna[1]);

                if(choice==0){
                    printf("You cast the 'Kiss of Jade Smoke'!");
                    if (mirror[0]==1){
                        printf("\n      Opponent has the Mona Lisa's Blink! Spell failed!");
                        mirror[0]=0;
                    }
                    else {
                        printf("\n      Spell successful! You deal 2 dmg!");
                        life[0]=life[0]-2;
                    }
                }
                else{
                    miss=rand()%3;
                    printf("You swing the ");
                    if (weapon[1]==0){
                        printf("Wooden Spear!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 1 dmg!");
                            life[0]=life[0]-1;
                        }
                        else if (shield[0]==0)
                            printf("Opponent blocked with wooden shield! Dmg neutralized!");
                        else if (shield[0]==1){
                            printf("Opponent blocked with silver shield! It flies back to your face [1 dmg]!");
                            life[1]=life[1]-1;
                        }
                        else {
                            printf("Opponent blocked with diamond shield! It flies back to your face [1 dmg]!");
                            life[1]=life[1]-1;
                        }
                    }
                    else if (weapon[1]==1){
                        printf("Silver Ax!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 2 dmg!");
                            life[0]=life[0]-2;
                        }
                        else if (shield[0]==0){
                            printf("Opponent blocked with wooden shield! You deal only 1 dmg!");
                            life[0]=life[0]-1;
                        }
                        else if (shield[0]==1)
                            printf("Opponent blocked with silver shield! Dmg neutralized!");
                        else {
                            printf("Opponent blocked with diamond shield! It flies back to your face [2 dmg]!");
                            life[1]=life[1]-2;
                        }
                    }
                    else if (weapon[1]==2){
                        printf("Diamond Scythe!\n      ");
                        if (miss==0||miss==1){
                            printf("Opponent failed to block! You deal 3 dmg!");
                            life[0]=life[0]-3;
                        }
                        else if (shield[0]==0){
                            printf("Opponent blocked with wooden shield! You deal 3 dmg!");
                            life[0]=life[0]-3;
                        }
                        else if (shield[0]==1){
                            printf("Opponent blocked with silver shield! You deal only 2 dmg!");
                            life[0]=life[0]-2;
                        }
                        else
                            printf("Opponent blocked with diamond shield! Dmg neutralized!");
                    }
                }
                if(life[0]<=0){
                    printf("\n\n\tOpponent has died! Player 2 wins!!\n\n");
                    system("pause");
                    system("cls");
                    win=1;
                    gameover=1;
                    break;
                }
                printf("\n\n");
                system("pause");
                system("cls");
                turn++;
            }
        }while(gameover==0);
        if (turn%2==0)
            rounds=turn/2;
        else
            rounds=(turn/2)+1;
        printf("The game has ended! Player %i won!\n\nThe game lasted for %i turns, equivalent to %i rounds!\n\n",win+1,turn,rounds);
        do{
            printf("Play Again?\n\n\tYes [a]\n\tNo  [b]\n\n\tInput: ");
            scanf("%c",&sel);
            fflush(stdin);

            if(sel=='a'){
                choice=1;
                cont=1;
            }
            else if(sel=='b'){
                choice=0;
                cont=0;
            }
            else
                choice=(rand()%3)-4;

            system("cls");
        }while (choice<0||choice>1);
    }while (cont==1);

    printf("Program will now Exit!!!\nThanks for playing! (If you did...)\n\n\n\tFinal Project for CMSC 11 @ 2014-2015\n\t  by JCM\n\n");

    return 0;
}
