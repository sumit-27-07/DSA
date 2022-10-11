#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int b = 0;
int a = 0;
int rndno(int x)
{
    srand(time(NULL));
    return rand() % x;
}
int func1()
{
    a=a+1;
    return(a);
}
int func2()
{
    b=b+1;
    return b;
}
int main()
{
    int count = 0, n, num, s,k,l;
    char *ptr;
    printf("Enter the number of alphabets in your name:\n");
    scanf("%d", &n);
    printf("Enter your name:\n");
    ptr = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", ptr);
    // free(ptr);

    while (count < 3)
    {
        s = rndno(3);
        printf("Enter your choice-%d %s\n", count + 1, ptr);
        printf("Choose for\nPAPER=0\nSCISSOR=1\nROCK=2\n");
        scanf("%d", &num);
        printf("You choose %d\n", num);
        printf("Computer choose %d\n", s);
        if (num == s)
        {
            printf("The round is draw:\n\n");
        }
        else if ((num == 0 && s == 1) || (num == 1 && s == 2) || (num == 2 && s == 0))
        {
            printf("Computer won the round...\n");
            k=func1();
            printf("Computer point is %d\n",k);

            printf("\n\n");
        }
        else
        {
            printf("%s won the round\n", ptr);
            l=func2();

            printf("%s point is %d\n",ptr, l);;
            printf("\n\n");
        }

        count++;
    }
    printf("Points of %s is %d...\n", ptr, l);
    printf("Points of Computer is %d...\n", k);
    if(func1()>func2()){
        printf("Computer wins\n");
    }
    else{
        printf("%s Wins\n",ptr);
    }
    return 0;
}