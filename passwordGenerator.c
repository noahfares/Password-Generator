#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define stdLength 100

int characterGenerator();
int upperLowerNumberMix();
void passwordGenerator();

char password[stdLength] = {0};
int numCount, upperCount, lowerCount, specialCount;

int main()
{
    srand(time(0));
    int passwordLength, passwordType;

    printf("\nWhat length should the password be: ");
    scanf("%d", &passwordLength);

    printf("\nWould you like special characters or not (1 for yes, 2 for no): ");
    scanf("%d", &passwordType);

    passwordGenerator(passwordLength, passwordType);

    if (passwordType == 1)
    {
        while (numCount == 0 || upperCount == 0 || lowerCount == 0 || specialCount == 0)
        {
            passwordGenerator(passwordLength, passwordType);
        }
    }
    else if (passwordType == 2)
    {
        while (numCount == 0 || upperCount == 0 || lowerCount == 0)
        {
            passwordGenerator(passwordLength, passwordType);
        }
    }

    printf("%s", password);
    password[0] = '\0';

    return 0;
}

/*
---------------------------------------------------
Functions for the code
---------------------------------------------------
*/

int characterGenerator()
{
    int digit = rand() % (126 + 1 - 33) + 33;

    return digit;
}

int upperLowerNumberMix()
{
    int digit = rand() % (122 + 1 - 48) + 48;

    while (digit >= 58 && digit <= 64 || digit >= 91 && digit <= 96)
    {
        digit = rand() % (122 + 1 - 48) + 48;
    }

    return digit;
}

void passwordGenerator(int passwordLength, int passwordType)
{
    // storing the values obtained in the array holding the password
    for (int i = 0; i < passwordLength; i++)
    {
        if (passwordType == 1)
        {
            password[i] = characterGenerator();
        }
        else if (passwordType == 2)
        {
            password[i] = upperLowerNumberMix();
        }

        if (i == passwordLength - 1)
        {
            password[i + 1] = '\0';
        }
    }

    // using this for loop to check if there are at least one number,
    // lower case, upper case and special charcter
    for (int i = 0; i < passwordLength; i++)
    {
        // check for number
        if (password[i] < 58 && password[i] > 47)
        {
            numCount++;
        }
        // check for upper case
        if (password[i] < 91 && password[i] > 64)
        {
            upperCount++;
        }
        // check for lower case
        if (password[i] < 123 && password[i] > 96)
        {
            lowerCount++;
        }
        // check for special characters
        if (password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96)
        {
            specialCount++;
        }
    }
}

