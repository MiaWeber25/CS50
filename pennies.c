#include <cs50.h>
#include <stdio.h>
#include <math.h>
/*take user input for days in the month and make sure that they are between 28 and 31.*/
int main(void)
{
    int days = 0;
    while (days > 31 || days < 28)
    {
        days = get_int("How many days are in the month: ");
    }
/*assign the totalpennies to a double data type and round it to the 100ths place.*/
    double totalpennies = 0.0f;
    double startpennies = 0.0f;
/*take user imput to find out how many pennies on the first day*/
    while (startpennies < 1)
    {
        startpennies = get_long("How many pennies on the first day: ");
    }
/*divide the pennies by 100 and set them equal to the totalpennies.*/
    startpennies = startpennies/100;
    totalpennies = startpennies;

    for (int i = 0; i<days; i++)
    {
        totalpennies = totalpennies * 2;

    }
    totalpennies = totalpennies-startpennies;

    printf("$%.2f\n",((double) totalpennies));
}
