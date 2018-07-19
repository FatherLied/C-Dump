#include <stdio.h>
int main(){
    int no=0,mini,maxi,syes=0,ayes=0;
    float sjudge[10],ajudge[10],jscore[20],ave,sum=0;

    do{
        printf("Score of Stadium Judge no. %i: ",no+1);
        scanf("%f",&sjudge[no]);
        if((sjudge[no]>=0&&sjudge[no]<=10))
            no++;
        else
            printf("\nThe Score is invalid!\n");
    }while((sjudge[no]<0||sjudge[no]>10)||no<10);

    printf("\n");
    no=0;

    do{
        printf("Score of Remote Judge no. %i: ",no+1);
        scanf("%f",&ajudge[no]);
        if((ajudge[no]>=0&&ajudge[no]<=10))
            no++;
        else
            printf("\nThe Score is invalid!\n");
    }while((ajudge[no]<0||ajudge[no]>10)||no<10);

    no=0;
    do{
        jscore[no]=sjudge[no];
        jscore[(no+10)]=ajudge[no];
        no++;
    }while(no<10);

    no=0,mini=no,maxi=no;

    do{
        if(jscore[no]<jscore[mini])
            mini=no;
        else if(jscore[no]>jscore[maxi])
            maxi=no;
        no++;
    }while(no<20);

    no=0;
    do{
        sum=sum+jscore[no];
        no++;
    }while(no<20);

    ave=(sum-jscore[mini]-jscore[maxi])/18;

    no=0;
    do{
        if(no<10){
            printf("\nThe Scores of the Stadium Judges are:\n");
            for(;no<10;no++)
                printf("\tJudge %i: %.1f\n",no+1,jscore[no]);
        }
        else if(no<20){
            printf("\nThe Scores of the Remote Judges are:\n");
            for(;no<20;no++)
                printf("\tJudge %i: %.1f\n",no-9,jscore[no]);
        }
    }while(no<20);

    no=0;
    do{
        if(no<10){
            printf("\nThe Stadium Judges that gave the lowest score of %.1f are:\n",jscore[mini]);
            for(;no<10;no++)
                if (jscore[no]==jscore[mini]){
                    printf("\tStadium Judge %i: %.1f\n",no+1,jscore[no]);
                    syes=1;
                }
            if(syes==0)
                printf("\tNone\n");
        }
        else if(no<20){
            printf("\nThe Remote Judges that gave the lowest score of %.1f are:\n",jscore[mini]);
            for(;no<20;no++)
                if(jscore[no]==jscore[mini]){
                    printf("\tRemote Judge %i: %.1f\n",no-9,jscore[no]);
                    ayes=1;
                }
            if(ayes==0)
                printf("\tNone\n");
        }
    }while(no<20);

    no=0,syes=0,ayes=0;
    do{
        if(no<10){
            printf("\nThe Stadium Judges that gave the highest score of %.1f are:\n",jscore[maxi]);
            for(;no<10;no++)
                if (jscore[no]==jscore[maxi]){
                    printf("\tStadium Judge %i: %.1f\n",no+1,jscore[no]);
                    syes=1;
                }
            if(syes==0)
                printf("\tNone\n");
        }
        else if(no<20){
            printf("\nThe Remote Judges that gave the highest score of %.1f are:\n",jscore[maxi]);
            for(;no<20;no++)
                if(jscore[no]==jscore[maxi]){
                    printf("\tRemote Judge %i: %.1f\n",no-9,jscore[no]);
                    ayes=1;
                }
            if(ayes==0)
                printf("\tNone\n");
        }
    }while(no<20);

    printf("\nThe unbiased average is: %.1f\n",ave);
    return 0;
}
