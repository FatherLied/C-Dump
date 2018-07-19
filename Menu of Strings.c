#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char sel,input,arr[1000];
    int i,mid,lim,count,word,fword;

    do{
        printf("What would you like to do?\n\n\t1. Length\n\t2. Palindromes\n\t3. Count (Words)\n\t4. Exit\n\n\t0. Clear Screen\n\nInput: ");
        scanf("%c",&sel);
        fflush(stdin);
        switch(sel){
        case '1':
            printf("\nLength\n\nString Input: ");
            scanf("%[^\n]s",&arr);
            fflush(stdin);
            for (i=0;arr[i]!='\0';i++);
            printf("\nThe string: '%s' has %i characters.\n\n",arr,i);
            break;
        case '2':
            printf("\nPalindromes\n\nString Input: ");
            scanf("%[^\n]s",&arr);
            fflush(stdin);
            for (i=0;arr[i]!='\0';i++);
            lim=i-1;
            mid=i/2;
            i=0;
            while (i<mid){
                if(arr[i]!=arr[lim]){
                    printf("The string: '%s' is not a Palindrome.\n\n",arr);
                    break;
                }
                lim--;
                i++;
            }
            if (i==mid)
                printf("\n'%s' is a Palindrome.\n\n",arr);
            break;
        case '3':
            word=0,i=0,count=0,fword=0;
            printf("\nCount (Words)\n\nString Input: ");
            scanf("%[^\n]s",&arr);
            fflush(stdin);
            while (arr[i]!='\0'){
                if ((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z')||(arr[i]>='0'&&arr[i]<='9')){
                    word=1;
                    if (fword==0){
                        count++;
                        fword=1;
                    }
                }
                else if(arr[i]==' '){
                    if (word==1){
                        count++;
                        word=0;
                    }
                }
                i++;
            }
            printf("The string: '%s' has %i words.\n\n",arr,count);
            break;
        case '4':
            printf("Program will now Exit...\n");
            break;
        case '0':
            system("cls");
            break;
        default:
            printf("\nInput is not part of the choices.\n\n");
            break;
        }
    }while(sel!='4');
    return 0;
}
