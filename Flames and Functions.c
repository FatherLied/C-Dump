#include <stdio.h>
int length(char str[250]){
    int i;
    for (i=0;str[i]!='\0';i++);

    return i;
}

int letcount (char first[250], char second[250]){
    int count=0,f=0,s=0,c,lim,dou;
    char clr=' ',let,comb[500];

    lim=length(first)+length(second);

    for (f=0;first[f]!='\0';f++)
        comb[f]=first[f];

    for (s=0;second[s]!='\0';s++)
        comb[s+f]=second[s];

    while (let!=123){
        dou=0;
            for(f=0;comb[f]!='\0';f++){
                if (let>=65&&let<=90){
                    if (comb[f]>=65&&comb[f]<=90){
                        if (comb[f]==let)
                            dou++;
                    }
                    else if (comb[f]>=97&&comb[f]<=122){
                        if (comb[f]-32==let)
                            dou++;
                    }
                }
                if (let>=97&&let<=122){
                    if (comb[f]>=97&&comb[f]<=122){
                        if (comb[f]==let)
                            dou++;
                    }
                    else if (comb[f]>=65&&comb[f]<=90){
                        if (comb[f]+32==let)
                            dou++;
                    }
                }
                if (f+1==lim)
                    break;
            }
        if (dou>1)
            count=count+dou;
        dou=0;
        let++;
        if (let==91)
            let=97;
    }

    count=count/2;

    return count;
}

int main(){
    int len,lensub,sub,ltr,c;
    char sel,str[250],substr[250];

    do{
        printf("What would you like to do?\n\n\t1. FLAMES\n\t2. Substring\n\t3. Exit\n\n\t0. Clear Screen\n\nInput: ");
        scanf("%c",&sel);
        fflush(stdin);
        switch(sel){
        case '1':
            printf("\nFLAMES:\n");
            printf("\n\tEnter the 1st Name: ");
            scanf("%[^\n]s",&str);
            fflush(stdin);

            printf("\n\tEnter the 2nd Name: ");
            scanf("%[^\n]s",&substr);
            fflush(stdin);

            ltr=letcount(str,substr);

            if (ltr%6==1)
                printf("\n\tF for Friends!\n\n");
            if (ltr%6==2)
                printf("\n\tL for Lovers!\n\n");
            if (ltr%6==3)
                printf("\n\tA for Acceptance of Proposal!\n\n");
            if (ltr%6==4)
                printf("\n\tM for Marriage!\n\n");
            if (ltr%6==5)
                printf("\n\tE for Engagement!\n\n");
            if (ltr%6==0)
                printf("\n\tS for Sweethearts!\n\n");
            break;
        case '2':
            sub=0,len=0;
            printf("\nSubstring:\n");
            printf("\n\tInput String: ");
            scanf("%[^\n]s",&str);
            fflush(stdin);

            printf("\n\tInput Substring: ");
            scanf("%[^\n]s",&substr);
            fflush(stdin);

            if(length(substr)>length(str)){
                printf("\n\tSubstring is longer than string! It's impossible!\n\n");
                break;
            }

            while(str[len]!='\0'){
                lensub=0,sub=0;
                while(substr[lensub]!='\0'){
                    if(substr[lensub]==str[len]){
                        lensub++;
                        len++;
                        sub=1;
                    }
                    else{
                        sub=0;
                        break;
                    }
                }
                if(sub==1)
                    break;

                len++;
            }

            if (sub==1)
                printf("\n\t'%s' is a substring of '%s'\n\n",substr,str);
            else
                printf("\n\t'%s' is a not substring of '%s'\n\n",substr,str);


            break;
        case '3':
            printf("Program will now Exit...\n");
            break;
        case '0':
            system("cls");
            break;
        default:
            printf("\nInput is not part of the choices.\n\n");
            break;
        }
    }while (sel!='3');

    return 0;
}
