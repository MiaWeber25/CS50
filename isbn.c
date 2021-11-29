#include <cs50.h>
#include <stdio.h>
#include <math.h>
/*GET the ISBN first.*/
int main(void)
{
    long isbn = -1;
    long sum = 0;
    while (isbn <0 || isbn >9999999999)
    {
         isbn = get_long("ISBN: ");
    }
/*loop to find the 10th, 9th, 8th, 7th, 6th, 5th, 4th, 3rd, 2nd, and 1st term. multiply by its position, add together, and mod 10*/
    for (long i = 10; i>0; i--)
    {
        sum += ((isbn % 10) *i);
        isbn = isbn/10;
    }
    /*is it an ISBN? was the result of dividing by 11 equal to 0? print yes/no */
    if (sum % 11 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

