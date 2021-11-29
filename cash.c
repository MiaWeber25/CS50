#include <cs50.h>
#include <stdio.h>
#include <math.h>

//ask the user for how much change is owed (if a non-negative value is not entered - re-prompt) *DONE*
//convert the doller amound entered by the user to a coin value to be used for the rest of the program (we will have to round this new number)
    // use the largest coin possible first (subtract 25 from the change to see if it is >=0 then do this for the rest of the coins)
    //can I use a quarter? can I use another quarter? etc.
    //keep track of the total number of coins that I use (when you subtract the coin from the change owed, increase the counter by 1)
//prints the minimum number of coins needed to make the change
int main(void){

    float change = -1;
    int counter = 0;
    while (change <=0) {

        change = get_float("Change owed: ");
    }
    int coins = round(change*100);


    counter = coins/25;

    coins = coins %25;

    counter += coins/10;

    coins = coins %10;

    counter += coins/5;

    counter += coins %5;

    printf("%i\n", counter);

}