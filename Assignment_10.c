//Write a C program to print the month-by-month calendar for the given year.


#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    char *months[] = {"January", "February", "March",
                      "April", "May", "June",
                      "July", "August", "September",
                      "October", "November", "December"};

    char *weekdays[] = {"Sun", "Mon", "Tue", "Wed",
                        "Thu", "Fri", "Sat"};

    struct tm date = {0};

    printf("Enter year: ");
    scanf("%d", &year);

    // Check leap year
    if((year % 400 == 0) ||
       (year % 4 == 0 && year % 100 != 0))
    {
        daysInMonth[1] = 29;
    }

    // Find first day of the year
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;

    mktime(&date);

    int firstDay = date.tm_wday;

    // Display calendar
    for(month = 0; month < 12; month++)
    {
        printf("\n\n      %s %d\n", months[month], year);

        for(day = 0; day < 7; day++)
        {
            printf("%4s", weekdays[day]);
        }

        printf("\n");

        for(day = 0; day < firstDay; day++)
        {
            printf("    ");
        }

        for(day = 1; day <= daysInMonth[month]; day++)
        {
            printf("%4d", day);

            if((firstDay + day) % 7 == 0)
                printf("\n");
        }

        firstDay = (firstDay + daysInMonth[month]) % 7;
    }

    printf("\n");

    return 0;
}