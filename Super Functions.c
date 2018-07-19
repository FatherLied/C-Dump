#include <stdio.h>
#include <stdlib.h>

int prime(int);
int numLength(int);
int rotateNum(int);
int binarySearch(int[]);
//Line between Required and Own
int amiPair(int,int);
int circlePrime(int);

int main(){
    int numput,numout,yes,arr[10],count,j;
    char sel;

    do{
        printf("What would you like to do?\n\n\t1. Amicable Pair\n\t2. Circular Primes\n\t3. Binary Search\n\t4. Exit\n\n\tInput: ");
        fflush(stdin);
        scanf("%c",&sel);
        fflush(stdin);
        switch(sel){
        case '1':
            printf("\nAmicable Pair\n");
            printf("\n\tInput 1st Number: ");
            scanf("%d",&numput);
            printf("\tInput 2nd Number: ");
            scanf("%d",&numout);
            yes=amiPair(numput,numout);
            if (yes==1)
                printf("\n\t'%d' and '%d' are an Amicable Pair.",numput,numout);
            else
                printf("\n\t'%d' and '%d' are not an Amicable Pair.",numput,numout);
            break;
        case '2':
            printf("\nCircular Primes\n");
            printf("\n\tInput a number: ");
            scanf("%d",&numput);
            printf("\n\tThe number of circular primes less than %d are %d.",numput,circlePrime(numput));
            break;
        case '3':
            count=0;
            printf("\nBinary Search\n\n");
            do{
                printf("\tInput number %d of array: ",count+1);
                scanf("%d",&arr[count]);
                count++;
            }while (count<10);
            printf("\n\tThe Array is:\n\t");
            for(j=0;j<10;)
                printf("%d ",arr[j++]);
            printf("\n");
            yes=binarySearch(arr);
            if (yes==1)
                printf("\n\tQuery is found in Array.");
            else
                printf("\n\tQuery is not found in Array.");
            break;
        case '4':
            printf("\nProgram will now exit...");
            break;
        default:
            printf("\nInput is not part of the choices.");
            break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }while(sel!='4');
    return 0;
}

int prime(int n){
    int cf=2;
    while(cf < n){
        if(n%cf==0){
            return 0;
        }
        else
            cf++;
    }
    if(cf==n)
        return 1;
}

int numLength(int n){
    int count=0;
    for(;n>0;count++)
        n=n/10;
    return count;
}

int rotateNum(int n){
    int power=1,len;
    len=numLength(n)-1;
    for(;len>0;len--)
        power*=10;
    power=power*(n%10);
    n/=10;
    n=n+power;
    return n;
}

//Separator
int amiPair(int a,int b){
    int sum1=0, sum2=0, count;
    for(count=1;count<=a/2;count++){
        if (a%count==0)
            sum1=sum1+count;
    }
    for(count=1;count<=b/2;count++){
        if (b%count==0)
            sum2=sum2+count;
    }
    if (sum1==b&&sum2==a)
        return 1;
    return 0;
}

int circlePrime(int num){
    int count=0,len,cp,rp,yes,turn;//FIX
    for(cp=2;cp<=num;cp++){
        yes=0;
        len=numLength(cp);
        rp=cp;
        for(yes=0,turn=0;turn<len;turn++){
            if(prime(rp)==1){
                yes++;
                rp=rotateNum(rp);
            }
            else
                break;
        }
        if (yes==len)
            count++;
    }
    return count;
}

int binarySearch(int arr[]){
    int i,j,min,temp,search;
    for(i=0; i<9;i++){
            min = i;
            for(j=i+1; j<10;j++ ){
                if(arr[j]<arr[min])
                    min = j;
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

        }
    printf("\n\tThe Sorted Array is:\n\t");
    for(j=0;j<10;)
        printf("%d ",arr[j++]);
    printf("\n");
    printf("\n\tInput Query: ");
    scanf("%d",&search);
    for (i=5;i>=0&&i<=9;){
        if (arr[i]==search){
            return 1;
        }
        else if (arr[i]<search){
            if (arr[i+1]>search||arr[i+1]=='\0')
                return 0;
            i++;
        }
        else if (arr[i]>search){
            if (arr[i-1]<search||arr[i-1]=='\0')
                return 0;
            i--;
        }
    }
    return 0;
}
