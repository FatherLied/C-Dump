#include <stdio.h>

int main(){
    int x = 403, y = 5, z = 14, *p1 = &x, *p2 = &z;

    p1++;
    p1 = p1 - 1;
    *p1 = 69;
    x = 23;
    y = 17;
    z = 96;
    printf("%p--%p--%d\n",p1,p1+1,*p2);
    printf("%p--%p--%p\n",&x,&y,&z);
}
