#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./fahrenheit <Ctemp>\n");
        return 1;
    }
    else
    {
        float Ctemp = atof(argv[1]);
        float A = ((Ctemp * 9) / 5) + 32;
        printf("F: %.1f\n", A);
        return 0;
    }
}
