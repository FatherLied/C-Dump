//I solemnly swear upon my honor, that I have made this MP all by myself

/*The program will ask the user to input two separate monomial terms
in the form of strings. The program will then compute for the product
of the two terms*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int xPow;
    int coef;
}term;

int validity(char[]);
term extract(char[]);
void multiply(term,term);
void display(term);

int main(){
    char term1[30],term2[30],sel;
    term first, second;
    int valid=1;

    do{
        do{ //loops until you get a valid input
            printf("\n  Term Multiplication\n\n");

            printf("\tInput two terms\n\tNOTE: Format is like this: <coefficient>x^<exponent>\n\n");

            if(valid==0){ //prints when invalid
                printf("\t     INPUT WAS INVALID.\n\n");
            }
            valid=0;

            printf("\t     Input Term 1: "); //collect input for Term 1
            scanf("%[^\n]s",&term1);
            fflush(stdin);

            printf("\t     Input Term 2: "); //collect input for Term 2
            scanf("%[^\n]s",&term2);
            fflush(stdin);

            valid=validity(term1); //checks if Term 1 is valid
            if (valid==1) //skips checking of Term 2 is Term 1 is invalid
                valid=validity(term2); //checks if Term 2 is valid

            system("cls"); //cleans the screen

        }while(valid==0);

        first=extract(term1); //extracts term from string
        second=extract(term2); //extracts term from string

        multiply(first,second); //multiplies terms

        printf("\n\n");
        system("pause");
        system("cls");

        do{ //allows user to choose if they want to input values again
            printf("\n\tInput again? (Y/N)\n\t Input: ");
            scanf("%[^\n]s",&sel);
            fflush(stdin);
            system("cls");
        }while(!(sel=='n'||sel=='N'||sel=='y'||sel=='Y'));

        system("cls");

    }while (!(sel=='N'||sel=='n'));
}

int validity(char term[]){
    int xCount=0, caret=0,hyp=0,i;

    for(i=0;term[i]!='\0';i++){ //checks each and every element of the string
        if (!(term[i]=='x'||term[i]=='X'||term[i]=='^'||term[i]=='-'||(term[i]>='0'&&term[i]<='9'))) //returns invalid if term[i] isn't within listed characters
            return 0;

        if (term[i]=='x'||term[i]=='X'){ //checks if term[i] is 'x'
            term[i]='x'; //lowercases 'X'
            hyp=0; //allows hyphen for next numerals
            xCount++; //counts x

            if(!(term[i+1]=='^'||term[i+1]=='\0'))
                return 0;
        }
        else if(term[i]=='^'){ //checks if term[i] is '^'
            caret++; //counts '^'
            if (xCount==0) //if no pre-existing 'x' is defined, returns invalid
                return 0; //prints when invalid
        }
        else if(term[i]=='-') //checks if term[i] is '-'
            hyp++; //counts '-'


        if (xCount>1) //if there are more instances of 'x', returns invalid
            return 0;
        if (caret>1||(term[i]=='^'&&term[i+1]=='\0')) //if there are more instances of '^' or '^' is last, returns invalid
            return 0;
        if (hyp>1) //if there are more instances of '-', returns invalid
            return 0;

    }

    return 1; //if nothing's wrong, then nothing could go wrong
}

term extract(char mono[]){
    int i, x=0, neg=0, coef=0,exp=0;
    term ans;

    for(i=0;mono[i]!='\0';i++){
        if (mono[i]=='-') //if hyphen appears, integer will be converted to negative
            neg=1;
        else if (mono[i]=='x'){ //checks if character is 'x'
            x++;
            if (neg==1) //if neg is 1, it multiplies coef by -1
                coef=coef*-1;
            neg=0;
        }
        else if (mono[i]>='0'&&mono[i]<='9'){ //if character is a numeral
            if (x==0) //adds to coefficient if 'x' hasn't appeared
                coef=coef*10+(mono[i]-('1'-1));
            else //adds to exponent if 'x' has appeared
                exp=exp*10+(mono[i]-('1'-1));
        }

        if (mono[i+1]=='\0'&&neg==1) //checks if next character is null, if neg is 1, multiplies exp by -1
            exp=exp*-1;

        if (mono[0]=='x') //check if x is the first character
            coef=1;
    }

    if(mono[i-1]=='x'/*&&mono[1]=='\0'*/){
        exp=1;
    }

    ans.coef=coef; //assigns coefficient to ans coefficient
    ans.xPow=exp; //assigns exponent to ans exponent

    return ans; //returns term

}

void multiply(term fir,term sec){
    term ans;

    ans.coef=fir.coef*sec.coef; //multiplies coefficients together
    ans.xPow=fir.xPow+sec.xPow; //adds exponents together

    printf("\n\t   ");
    display(fir); //makes a clean output
    printf(" * ");
    display(sec);
    printf(" = ");

    display(ans); //displays answer

    printf("\n\t   Answer is ");
    display(ans);

    return; //because I am OCD
}

void display(term mono){

    if(!(mono.coef==1&&mono.xPow>0)) //1 will only be displayed if there is no 'x'
        printf("%d",mono.coef);

    if(mono.coef!=0){ //if coefficient is zero, it will not print out x
        if(mono.xPow!=0){ //checks if exponent is not zero
            if(mono.xPow==1) //if exponent is just 1, it simply prints x
                printf("x");
            else //if exponent is neither 1 or 0, it is printed as the power of <exponent>
                printf("x^%d",mono.xPow);
        }
    }

    return; //because I am OCD
}
