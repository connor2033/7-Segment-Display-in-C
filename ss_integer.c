#include <stdio.h>
#include <stdlib.h>

int input();
int digCount(int);

char segments[10][3][3] = {
        {{' ', '_', ' '}, {'|', ' ','|'}, {'|', '_', '|'}}, //0
        {{' ', ' ', ' '}, {' ', ' ','|'}, {' ', ' ', '|'}}, //1
        {{' ', '_', ' '}, {' ', '_','|'}, {'|', '_', ' '}}, //2
        {{' ', '_', ' '}, {' ', '_','|'}, {' ', '_', '|'}}, //3
        {{' ', ' ', ' '}, {'|', '_','|'}, {' ', ' ', '|'}}, //4
        {{' ', '_', ' '}, {'|', '_',' '}, {' ', '_', '|'}}, //5
        {{' ', '_', ' '}, {'|', '_',' '}, {'|', '_', '|'}}, //6
        {{' ', '_', ' '}, {' ', ' ','|'}, {' ', ' ', '|'}}, //7
        {{' ', '_', ' '}, {'|', '_','|'}, {'|', '_', '|'}}, //8
        {{' ', '_', ' '}, {'|', '_','|'}, {' ', '_', '|'}}  //9
};

int main() {
        char prompt = 'y';
        int num;
        int length;
        char negative = 'F';

    //program loop
    while (prompt == 'Y' || prompt == 'y'){
        num = input();
        if(num < 0) negative = 'T';
        num = abs(num);
        length = digCount(num);

        //creating array of digits from the int
        int digits[length];
        for(int i = length-1; i > -1; i--){
            digits[i] = num%10;
            num /= 10;
        }

        printf("\n");

        //Printing 7 segment display of integer
        for(int k = 0; k < 3; k++){ //height

            //if int is negative
            if(negative == 'T' && k == 1) printf("_ ");
            else if(negative == 'T') printf("  ");

            for(int i = 0; i < length; i++){ //digit
                for(int j = 0; j < 3; j++){ //char
                    printf("%c", segments[digits[i]][k][j]);
                }
                printf(" ");
            }
            printf("\n");
        }

        //Continuation Prompt
        printf("\nDo you want to continue? Y = Yes, N = No.");
        scanf(" %c", &prompt);
    }
}

//returns the number of digits in a given integer
int digCount(int num){
    int result = 1;
    while (num/=10){
        result = result + 1;
    }
    return result;
}

//Function that gets positive integer as input from user.
int input(void){
    int num;
    printf("\nEnter an integer of 9 digits or less: ");
    scanf("%d", &num);
    return num;
}