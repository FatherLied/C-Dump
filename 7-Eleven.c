#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand((unsigned int)time(NULL));
    float monP1=20000.00,monP2=20000.00,monP3=20000.00,monBank=100000.00,bet1=0,bet2=0,bet3=0;
    int pQuit=0,enter,p1Quit=0,p2Quit=0,p3Quit=0,yes,die,guess1,guess2,guess3,bankrupt=0;

    printf("Welcome to 7/11!!! A dice game where you play until someone's broke!\nCare to Join?\n");

    do {
        printf("1 for Yes, 0 for No: ");
        scanf("%i",&enter);
    }while(enter<0||enter>1);

    if(enter==0){
        system("cls");
        printf("Exiting...\nTry playing next time!!!\n");
        return 0;
    }

    system("cls");
    printf("The game has begun!\n\nHere are the rules, two dice will be thrown and each player has to guess the ");
    printf("\ncorrect number that the dice will give.\nEach player will bet a certain amount for every guess.\n");
    printf("If the player gets it right, the banker will give them that amount otherwise\nit's vice-versa.\n");
    printf("The game ends when there is one player left or the banker has gone bankrupt.\n\n");

    do{
        printf("Plaver 1: PhP %.2f",monP1);
        if(p1Quit==1)
            printf("\t~OUT");
        printf("\nPlaver 2: PhP %.2f",monP2);
        if(p2Quit==1)
            printf("\t~OUT");
        printf("\nPlaver 3: PhP %.2f",monP3);
        if(p3Quit==1)
            printf("\t~OUT");
        printf("\nBanker  : PhP %.2f\n",monBank);

        printf("\nThe die has been cast.\n");
        die=(rand()%11)+2;

        if (p1Quit==0){
            printf("\nPlayer 1, would you like to play?\n");
            do{
                printf("1 for Yes, 0 for No: ");
                scanf("%i",&yes);
            }while(yes<0||yes>1);
            if(yes==1){
                printf("\nWhat is your guess?\n\n");
                do{
                    printf("Note: The value of the two dice can go from 2 - 12.\n");
                    printf("My guess is: ");
                    scanf("%i",&guess1);
                }while(guess1<2||guess1>12);
                printf("\nHow much do you bet?\n\n");
                do{
                    printf("Note: You can only bet within range of your wallet or the Banker's.\n");
                    printf("My bet is: ");
                    scanf("%f",&bet1);
                }while(bet1<0||bet1>monP1||bet1>monBank);
            }
            else{
                printf("\nPlayer 1 has quit the game!!!\n");
                p1Quit=1;
                pQuit=pQuit+1;
            }
        }

        if (p2Quit==0){
            printf("\nPlayer 2, would you like to play?\n");
            do{
                printf("1 for Yes, 0 for No: ");
                scanf("%i",&yes);
            }while(yes<0||yes>1);
            if(yes==1){
                printf("\nWhat is your guess?\n\n");
                do{
                    printf("Note: The value of the two dice can go from 2 - 12.\n");
                    printf("My guess is: ");
                    scanf("%i",&guess2);
                }while(guess2<2||guess2>12);
                printf("\nHow much do you bet?\n\n");
                do{
                    printf("Note: You can only bet within range of your wallet or the Banker's.\n");
                    printf("My bet is: ");
                    scanf("%f",&bet2);
                }while(bet2<0||bet2>monP2||bet2>monBank);
            }
            else{
                printf("\nPlayer 2 has quit the game!!!\n");
                p2Quit=1;
                pQuit=pQuit+1;
            }
        }

        if (p3Quit==0){
            printf("\nPlayer 3, would you like to play?\n");
            do{
                printf("1 for Yes, 0 for No: ");
                scanf("%i",&yes);
            }while(yes<0||yes>1);
            if(yes==1){
                printf("\nWhat is your guess?\n\n");
                do{
                    printf("Note: The value of the two dice can go from 2 - 12.\n");
                    printf("My guess is: ");
                    scanf("%i",&guess3);
                }while(guess3<2||guess3>12);
                printf("\nHow much do you bet?\n\n");
                do{
                    printf("Note: You can only bet within range of your wallet or the Banker's.\n");
                    printf("My bet is: ");
                    scanf("%f",&bet3);
                }while(bet3<0||bet3>monP3||bet3>monBank);
            }
            else{
                printf("\nPlayer 3 has quit the game!!!\n");
                p3Quit=1;
                pQuit=pQuit+1;
            }
        }

        while((bet1+bet2+bet3)>monBank){
            printf("\nAll of the players' bets exceed the Banker's money.\nPlease change your bets.\n\n");
            if(p1Quit==0){
                do{
                    printf("Player 1: ");
                    scanf("%f",&bet1);
                }while(bet1<0||bet1>monP1||bet1>monBank);
            }
            if(p2Quit==0){
                do{
                    printf("Player 2: ");
                    scanf("%f",&bet2);
                }while(bet2<0||bet2>monP2||bet2>monBank);
            }
            if(p3Quit==0){
                do{
                    printf("Player 3: ");
                    scanf("%f",&bet3);
                }while(bet3<0||bet3>monP3||bet3>monBank);
            }
        }
        if(p1Quit==0){
            if(guess1==die){
                printf("\nPlayer 1 got it right!\n");
                monP1=monP1+bet1;
                monBank=monBank-bet1;
                printf("You won: PhP %.2f!\nYour bank is now: Php %.2f\n",bet1,monP1);
            }
            else{
                printf("\nPlayer 1 got it wrong!\n");
                monP1=monP1-bet1;
                monBank=monBank+bet1;
                printf("You lost: PhP %.2f!\nYour bank is now: Php %.2f\n",bet1,monP1);
            }
            if(monP1<=100){
                printf("\nPlayer 1 is no longer fit to play!\n");
                p1Quit=1;
                pQuit=pQuit+1;
            }
        }
        if(p2Quit==0){
            if(guess2==die){
                printf("\nPlayer 2 got it right!\n");
                monP2=monP2+bet2;
                monBank=monBank-bet2;
                printf("You won: PhP %.2f!\nYour bank is now: Php %.2f\n",bet2,monP2);
            }
            else{
                printf("\nPlayer 2 got it wrong!\n");
                monP2=monP2-bet2;
                monBank=monBank+bet2;
                printf("You lost: PhP %.2f!\nYour bank is now: Php %.2f\n",bet2,monP2);
            }
            if(monP2<=100){
                printf("\nPlayer 2 is no longer fit to play!\n");
                p2Quit=1;
                pQuit=pQuit+1;
            }
        }
        if(p3Quit==0){
            if(guess3==die){
                printf("\nPlayer 3 got it right!\n");
                monP3=monP3+bet3;
                monBank=monBank-bet3;
                printf("You won: PhP %.2f!\nYour bank is now: Php %.2f\n",bet3,monP3);
            }
            else{
                printf("\nPlayer 3 got it wrong!\n");
                monP3=monP3-bet3;
                monBank=monBank+bet3;
                printf("You lost: PhP %.2f!\nYour bank is now: Php %.2f\n",bet3,monP3);
            }
            if(monP3<=100){
                printf("\nPlayer 3 is no longer fit to play!\n");
                p3Quit=1;
                pQuit=pQuit+1;
            }
        }

        if(monBank<=100){
            printf("\nThe Banker is unable to play! The players win!\n");
            bankrupt=1;
            printf("Press any key to continue.");
            getch();
            system("cls");
            break;
        }
        else if(pQuit==2){
            printf("\nThe players are unfit to play! The Banker wins!\n");
            printf("Press any key to continue.");
            getch();
            system("cls");
            break;
        }
        printf("\nThe correct answer is %i!\n",die);
        printf("\nPress any key to continue.");
        getch();
        system("cls");
    }while(pQuit<2);

    printf("The Game has ended!!! Here are the final scores!\n");
    printf("Plaver 1: PhP %.2f",monP1);
    if(p1Quit==1)
        printf("\t~OUT");
    printf("\nPlaver 2: PhP %.2f",monP2);
    if(p2Quit==1)
        printf("\t~OUT");
    printf("\nPlaver 3: PhP %.2f",monP3);
    if(p3Quit==1)
        printf("\t~OUT");
    printf("\nBanker  : PhP %.2f",monBank);
    if(bankrupt==1)
        printf("\t~OUT");

    if(bankrupt==1)
        printf("\n\nIn the end, the Players won!");
    else
        printf("\n\nIn the end, the Banker won!");

    printf("\nThe game will now exit.\n\nPlay again next time!\n");

    return 0;
}
