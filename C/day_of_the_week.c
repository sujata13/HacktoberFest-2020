// Program to fetch day of the week for a given day

#include <stdio.h>

int isLeapYear(int year)
{
    if(year % 400 == 0)
        return 1;
    if(year%100 == 0)
        return 0;
    if(year%4 == 0)
        return 1; 
    return 0;
}

void calculateDay(int date, int month, int year)
{
    int century_digits = (int)(year / 100);
    int year_digits = year % 100;
    int value = year_digits + (int)(year_digits / 4);

    if(century_digits == 18)
        value += 2;
    else if(century_digits == 20)
        value += 6;
    
    switch(month)
    {
        case 1: if(!isLeapYear(year))
                    value += 1;
                break;
        case 2: if(isLeapYear(year))
                    value += 3;
                else
                    value += 4;
                break;
        case 3: value += 4; break;
        case 5: value += 2; break;
        case 6: value += 5; break;
        case 8: value += 3; break;
        case 9: value += 6; break;
        case 10: value += 1; break;
        case 11: value += 4; break;
        case 12: value += 6; break;
    }
    
    value = (value + date) % 7;

    switch(value)
    {
        case 0: printf("SATURDAY"); break;
        case 1: printf("SUNDAY"); break;
        case 2: printf("MONDAY"); break;
        case 3: printf("TUESDAY"); break;
        case 4: printf("WEDNESDAY"); break;
        case 5: printf("THURSDAY"); break;
        case 6: printf("FRIDAY"); break;
    }
}

int main()
{
    //Sample Date
    int date = 20;
    int month = 10;
    int year = 2021;

    calculateDay(date, month, year);
    return 0;
}