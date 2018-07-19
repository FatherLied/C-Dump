#include <stdio.h>
int main(){
    int month,date;

    printf("Enter month, please choose from the list.\n");
    printf(" 1. January\n 2. February\n 3. March\n 4. April\n 5. May\n 6. June\n 7. July\n 8. August\n 9. September\n 10. October\n 11. November\n 12. December\n");
    printf("\nInput is: ");

    scanf("%i",&month);
    if (month<1||month>12){
        while(month<1||month>12){
            printf("\nInvalid input. Please select from the list.\n");
            printf("Input is: ");
            scanf("%i",&month);
        }
    }

    printf("\nEnter day, select a number from 1 to 31.");
    printf("\nInput is: ");

    scanf("%i",&date);

    if (month==2){
        while(date<1||date>29){
            printf("\nFebruary cannot have a date more than 29. Input again.\n");
            printf("Input is: ");
            scanf("%i",&date);
        }
    }
    else if(month==4||month==6||month==9||month==11){
        while(date<1||date>30){
            printf("\nThis month is only up to the 30th. Input again.\n");
            printf("Input is: ");
            scanf("%i",&date);
        }
    }
    else{
        while(date<1||date>31){
            printf("\nThis month is only up to the 31th. Input again.\n");
            printf("Input is: ");
            scanf("%i",&date);
        }
    }

    printf("\nBorn on %i/%i, your Zodiac sign is: ",month,date);

    if((month==3&&(date>20&&date<32))||(month==4&&(date>0&&date<21))){
        printf("Aries.\n\n");
        printf("Your Horoscope for today:\n A few hours grace before the madness begins again.\n");
    }
    else if((month==4&&(date>20&&date<31))||(month==5&&(date>0&&date<22))){
        printf("Taurus.\n\n");
        printf("Your Horoscope for today:\n Questionable day. Ask somebody something.\n");
    }
    else if((month==5&&(date>21&&date<32))||(month==6&&(date>0&&date<22))){
        printf("Gemini.\n\n");
        printf("Your Horoscope for today:\n Cheer Up! Things are getting worse at a slower rate.\n");
    }
    else if((month==6&&(date>21&&date<31))||(month==7&&(date>0&&date<23))){
        printf("Cancer.\n\n");
        printf("Your Horoscope for today:\n It was all so different before everything changed.\n");
    }
    else if((month==7&&(date>22&&date<32))||(month==8&&(date>0&&date<23))){
        printf("Leo.\n\n");
        printf("Your Horoscope for today:\n Never look up when dragons fly overhead.\n");
    }
    else if((month==8&&(date>22&&date<32))||(month==9&&(date>0&&date<24))){
        printf("Virgo.\n\n");
        printf("Your Horoscope for today:\n What happened last night can happen again.\n");
    }
    else if((month==9&&(date>23&&date<31))||(month==10&&(date>0&&date<24))){
        printf("Libra.\n\n");
        printf("Your Horoscope for today:\n You are scrupulously honest, frank, and straightforward. Therefore you have few friends.\n");
    }
    else if((month==10&&(date>23&&date<32))||(month==11&&(date>0&&date<23))){
        printf("Scorpio.\n\n");
        printf("Your Horoscope for today:\n Excellent day to have a rotten day.\n");
    }
    else if((month==11&&(date>22&&date<31))||(month==12&&(date>0&&date<22))){
        printf("Sagittarius.\n\n");
        printf("Your Horoscope for today:\n You are a very redundant person, that's what kind of person you are.\n");
    }
    else if((month==12&&(date>21&&date<32))||(month==1&&(date>0&&date<21))){
        printf("Capricorn.\n\n");
        printf("Your Horoscope for today:\n You will be Told about it Tomorrow. Go Home and Prepare Thyself.\n");
    }
    else if((month==1&&(date>20&&date<32))||(month==2&&(date>0&&date<20))){
        printf("Aquarius.\n\n");
        printf("Your Horoscope for today:\n Good day to let down old friends who need help.\n");
    }
    else{
        printf("Pisces.\n\n");
        printf("Your Horoscope for today:\n You are confused; but this is your normal state.\n");
    }

    return 0;
}
