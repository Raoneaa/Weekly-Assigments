#include <stdio.h>
#include <string.h>
#include <limits.h>



//all functions must use recrsion!
//you may write other helper functions to assist you, but all functions below must work as described

//return 1 if the word is a palendrome (spelled the same forwards and backwards), return 0 otherwise.
//string is the string, start is the initial index (0) and end is the final index
//hint: your recursive call will need to change the value of start and end
//Examples...
//-------isPalendrome("racecar",0,6) should return 1
//-------isPalendrome("neco arc",0,7 ) should return 0
int isPalendrome(char* string, int start, int end){
    if(start >= end){
        return 1;
    }
    if(string[start] != string[end]){
        return 0;
    }
    return isPalendrome(string,start +1,end-1);
}


//return the length of the longest string contained in X and Y
//i and j are both indexes and should be set to 0 initially
//hint: you will need to increase the values of i and j each recursive call
//hint: remember strings end with the null terminator
//Examples...
//-------longestCommon("my_dog", "my_cat",0,0) should return 3, "my_" is in both strings
//-------longestCommon("aaab", "abbb",0,0) should return 2, "ab" is in both strings
int longestCommonCount(char* X, char* Y, int i , int j, int count){
    if(X[i] == '\0' || Y[j] == '\0'){
        return count;
    }
    if(X[i] == Y[j]){
        count = longestCommonCount(X,Y,i +1,j +1,count + 1);
    }
    return count;
}


int longestCommon(char* X, char* Y, int i, int j) {
    int lengthX = strlen(X);
    int lengthY = strlen(Y);
    int maxLength = 0;
    int count = 0;

    for (int i = 0; i < lengthX; ++i) {
        for(int j = 0; j < lengthY;++j){
            int length = longestCommonCount(X,Y,i,j,0);
            if(length > maxLength){
                maxLength = length;
            }
        }
    }
    return maxLength;
}



//return the minimum number of coins you need to reach a certain amount
//coins contains the values for each type of coin you have e.g [1,5,10,25] cents
//coinsLen stores the length of the coins array
//amount is the amount of money (in cents) you are trying to reach
//note: you are allowed to use the same type of coin more than once
//hint: you will need to update the amount in your recursive call
//hint: don't be afraid to combine loops and recursion
//Examples...
//-------int coins[] = {1, 5, 10, 25};
//-------minCoinsRecursive(coins,4,3) should return 3, because 1+1+1 is the fewest coins needed to get 3
//-------minCoinsRecursive(coins,4,26) should return 2, because 1+25 is the fewest coins needed to get 26

int minCoinsHelper(int coins[], int coinsLen, int amount, int memo[]) {

    if (amount == 0) return 0;

    if (amount < 0) return INT_MAX;

    if (memo[amount] != -1) return memo[amount];

    int minCoins = INT_MAX;

    for (int i = 0; i < coinsLen; ++i) {
        int result = minCoinsHelper(coins, coinsLen, amount - coins[i], memo);
        if (result != INT_MAX) {
            minCoins = (minCoins < result + 1) ? minCoins : (result + 1);
        }
    }

    // Store the result in the memo array
    memo[amount] = minCoins;
    return minCoins;
}

int minCoinsRecursive(int coins[], int coinsLen, int amount) {
    int memo[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        memo[i] = -1;
    }

    int result = minCoinsHelper(coins, coinsLen, amount, memo);
    return result == INT_MAX ? -1 : result;
}

int main(void){
    printf("\nTesting isPalendrome...\n");
    printf("Should be 1: %d\n",isPalendrome("racecar",0,6));
    printf("Should be 0: %d\n",isPalendrome("neco arc",0,7));


    printf("\nTesting longestCommon...\n");
    printf("Should be 3: %d\n",longestCommon("my_dog", "my_cat",0,0));
    printf("Should be 2: %d\n",longestCommon("aaab", "abbb",0,0));

    printf("\nTesting minCoinsRecursive...\n");
    int coins[4] = {1,5,10,25};
    printf("Should be 3: %d\n",minCoinsRecursive(coins,4,3));
    printf("Should be 2: %d\n",minCoinsRecursive(coins,4,26));


    return 1;
}