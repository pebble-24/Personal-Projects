#include <stdio.h>

int checkCompany(long cardNum, int length) {
    int first2Digits;
    switch (length) {
    case 16:
        cardNum /= 100000000000000;
        int _2ndDigit = cardNum % 10;
        int firstDigit = (cardNum / 10) % 10;
        if (firstDigit == 5) {
            switch (_2ndDigit) {
            case 1: case 2: case 3: case 4: case 5:
                return 2;
                break;
            
            default:
                break;
            }
        }
        if (firstDigit == 4) {
            return 3;
        }
        break;

        if (firstDigit == 4) {
            return 3;
        } 
        break;
    case 15:
        cardNum /= 10000000000000;
        first2Digits = cardNum % 100;
        if (first2Digits == 34 || first2Digits == 37) {
            return 1;
        }
        break;

    case 13:
        cardNum /= 1000000000000;
        if (cardNum % 10 == 4) {
            return 3;
        }
        break;

    default:
        break;
    }
}

int main(void) {
    long card;
    printf("Please enter a card number: ");
    scanf("%ld", &card);
    int length = 0;
    long tempcard = card;
    while (tempcard > 0) {
        tempcard /= 10;
        length += 1;
    }

    int count = 1;
    int sumOdd = 0; // Every digit starting from last
    int sumEven = 0; // Every digit starting from 2nd last
    long card_temp = card;

    for (int i = 0 ; i < length ; i++) {
        int num = card_temp % 10;
        if (i % 2 == 0) {
            sumOdd += num;
        } else {
            num *= 2;
            if (num >= 10) {
                int splitNum = num % 10;
                sumEven += splitNum;
                num /= 10;
                splitNum = num % 10;
                sumEven += splitNum;
            } else {
                sumEven += num;
            }
        }
        card_temp /= 10;
    }
    
    int totalSum = sumEven + sumOdd;
    if (totalSum % 10 == 0) {
        switch (checkCompany(card, length)) {
        case 1:
            printf("AMEX\n");
            break;

        case 2:
            printf("MASTERCARD\n");
            break;

        case 3:
            printf("VISA\n");
            break;

        default:
            printf("INVALID\n");
            break;
        }
    } else {
        printf("INVALID\n");
    } 
}