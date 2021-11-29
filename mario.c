/*ask the user for the height of the pyramid. Needs to be positive, and no greater than 8
set the gap size to 2*/
#include <cs50.h>
#include <stdio.h>

//function to print the spaces. Takes height and row and prints " "
void printSpaces (int height,int row) {
     for (int c = 1; c<= height-row; c++)
       {
           printf(" ");
       }
       return;
}
//function to print hashes. Takes row and prints "#"
void printHashes (int row) {
    for (int j = 1; j<=row; j++)
       {
           printf("#");
       }
}
//takes user input for height that is a non-zero value and less than 8.
int main(void)
{
    int height = 10;
    while(height > 8 || height <= 0) {

        height = get_int("height: ");
    }
//itterates through the rows and uses the functions above to print spaces and hashes as well as the gap and then the spaces and hashes for the second pyramid
    for (int r = 1; r<=height; r++) {

       printSpaces(height,r);

       printHashes(r);

       printf("  ");

      printHashes(r);

      printf("\n");

    }


}

