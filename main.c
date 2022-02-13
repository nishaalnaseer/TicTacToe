#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char switchCases (char turn) {
    switch (turn) {
        case ('X'):
            return 'O';
        case ('O'):
            return 'X';
        default:
            return 'Z';
    }
}

void printBoard(char *array) {
    int x0; int x1; int x2; int x;

    for (x = 0;x < 9; x+=3) {
        x0 = array[x];
        x1 = array[x+1];
        x2 = array[x+2];
        printf("_____________");
        printf("\n| %c | %c | %c |\n", x0, x1, x2);
    }
    printf("_____________\n\n");
}

char *assigningArray(int num1, int num2, int num3, char *array) {
    char *string = malloc(4 * sizeof * string);
    string[0] = array[num1];
    string[1] = array[num2];
    string[2] = array[num3];
    string[3] = '\0';
//    printf("%s\n", string);
    return string;
}

char checkWinner(char *array){
//    printf("test1\n");
    char *case1 = malloc(4 * sizeof * case1); char *case2 = malloc(4 * sizeof * case2);
    char *case3 = malloc(4 * sizeof * case3); char *case4 = malloc(4 * sizeof * case4);
    char *case5 = malloc(4 * sizeof * case5); char *case6 = malloc(4 * sizeof * case6);
    char *case7 = malloc(4 * sizeof * case7); char *case8 = malloc(4 * sizeof * case8);

    case1 = assigningArray(0, 1, 2, array);
    case2 = assigningArray(3, 4, 5, array);
    case3 = assigningArray(6, 7, 8, array);
    case4 = assigningArray(0, 3, 6, array);
    case5 = assigningArray(1, 4, 7, array);
    case6 = assigningArray(2, 5, 8, array);
    case7 = assigningArray(2, 4, 6, array);
    case8 = assigningArray(8, 4, 0, array);
//    printf("%s\n", case1);

    //    char **variables[] = {&a, &b, &c};
    char **cases[] = {&case1, &case2, &case3, &case4,&case5, &case6, &case7,&case8,};

//    printf("\ncase is %s\n", case1);
    int x;

    for (x = 0; x < 8; x++) {
        if (strcmp(*cases[x], "XXX\0") == 0) {
            return 'X';
        }
        if (strcmp(*cases[x], "OOO\0") == 0) {
            return 'O';
        }
    }
    return 'Z';
}

const char* initArray() {
    char *arr = malloc(7 * sizeof *arr);
    char c;
    for (int x= 0; x< 9; x++) {
        c = x + '0';
        arr[x] = c;
    }
    return arr;
}

int isItInArray(char ch, char *arr) {
    int isElementPresent = 0;
    char var;

    for (int i = 0; i < 9; i++) {
        var = arr[i] ;
        // printf("%i: %i\n", i, var);
        if (var == ch) {
            isElementPresent = 1;
            break;
        }
    }
    return isElementPresent;
}

void main() {
    char *array = initArray();
    printBoard(array);

    char turn = 'X';
    int pos;
    char winner = 'Z';
    int finish = 0;
    char *progressArray[8];
//    progressArray[0] = 'p';

    int j = 0;
    for (;j < 9;) {
        printf("It's %c's turn!\n", turn);
        printf("Which position will you take? ");
        scanf_s("%i", &pos);

        if (array[pos] == 'O') {
            printf("Position already taken!\n");
            continue;
        }
        else if (array[pos] == 'X') {
            printf("Position already taken!\n");
            continue;
        }
        else if (isItInArray((pos + '0'), progressArray) == 1) {
            printf("Invalid input\n");
            continue;
        }
        else if (pos > 8) {
            printf("Invalid input\n");
            continue;
        }
        else if (pos < 0) {
            printf("Invalid input\n");
            continue;
        }
        else {
            progressArray[j] = pos + '0';
            j++;
        }

        array[pos] = turn;

        printBoard(array);
        turn = switchCases(turn);
        winner = checkWinner(array);
//        printf("test2\n");

        if (winner != 'Z') {
            printf("%c Wins the Game!\n", winner);
            finish = 1;
            break;
        }
    }
    if (finish == 0) {
        printf("Its a Draw!!!\n");
    }
}
