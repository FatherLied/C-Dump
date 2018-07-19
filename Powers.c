#include <stdio.h>
int main(){
    int x, y, product=1, count=0, tempX;

    printf("Input value for x: ");
    scanf("%i",&x);

    printf("\nInput value for y: ");
    scanf("%i",&y);

    if(x==0){
        if(y>0)
            printf("\n%i to the power of %i is 0.",x,y);
        else if(y<=0)
            printf("\nComputation is invalid. MATH ERROR.\n");
        }
    else if(x>0){
        if(y>=0){
            while(y>count){
                product=product*x;
                count=count+1;
                }
            printf("\n%i to the power of %i is %i.\n",x,y,product);
            }
        else if(y<0){
                while(y<count){
                    product=product*x;
                    count=count-1;
                    }
                printf("\n%i to the power of %i is 1/%i.\n",x,y,product);
                }
        }
    else{
        tempX=x*-1; //logic for negative numbers is based on the second example (non-parenthesis) in http://www.purplemath.com/modules/negative4.htm
        if(y>=0){
            while(y>count){
                product=product*tempX;
                count=count+1;
                }
            printf("\n%i to the power of %i is -%i.\n",x,y,product);
            }
        else if(y<0){
                while(y<count){
                    product=product*tempX;
                    count=count-1;
                    }
                printf("\n%i to the power of %i is -1/%i.\n",x,y,product);
                }
        }
    return 0;
}
