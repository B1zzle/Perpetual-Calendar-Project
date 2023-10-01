/*
    Group 5 - FINAL PROJECT - PERPETUAL CALENDAR

    Leader:  Flores, Bastian Bragi

    Members: Dichosa, Immanuel
             Fernandez, Martin Rafael

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_NO 91


void wholeYearCalendar();
void specificMonthOfYearCalendar();
void findDayGivenDate();
void calcDay_of_theYear_from_Date();
void info();
//void PrintFile1(int year, int endDay);
//void PrintFile2(int month,int year, int endDay);

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}

/*Functions*/
//1, 3 , 4
int getFirstWeekday(int year);
int checkLeapYear(int year);

//2
int getDay(int dates,int month,int year);
int last2Digits, first2Digits, Zeller, endDay;



//1, 3 ,4
int c, year, month, day, weekday, daysInMonth, weekDay = 0, startingDay;
char *monthNames[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

//2
char* months[] = {"MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC","JAN","FEB"};
int dayofMonth, dates, monthNum, flag = 0;
char strMonth[3];


int main()
{
    system("COLOR F0");
    printf("\n\n\n\n\n\n\n\t\t\t      ***************************************************\n");
    printf("\n\t\t              *                PERPETUAL CALENDAR               *\n");
    printf("\n\t\t              *                  BY   GROUP 5                   *\n");
    printf("\n\t\t\t      ***************************************************");
    printf("\n\n\t\t\t\t         Press any button to proceed.");
    getch();

        /*int a;
        printf("\n\n\n\t\t\t\t\t\tLoading...");
        for(a = 1; a<=9; a++)
            {
                printf(".");
                delay(100);
            }*/

    int userChoice;
    def:
    system("cls");
    system("COLOR F0");
    printf("\n\n\n\t\t\t               WELCOME TO OUR PERPETUAL CALENDAR !               \n");
    printf("\n\n\t\t\t************************ CALENDAR MENU ************************\n");
    printf("\t\t\t*                                                             *");
    printf("\n\n\t\t\t*    Press[1] (User-Input) Whole Year Calendar                *");
    printf("\n\n\t\t\t*    Press[2] (User-Input) Whole Month of a Year Calendar     *");
    printf("\n\n\t\t\t*    Press[3] Get to Know the Day of the Given Date           *");
    printf("\n\n\t\t\t*    Press[4] Calculate the Day of Year from the Given Date   *");
    printf("\n\n\t\t\t*    Press[5] Info/About                                      *");
    printf("\n\n\t\t\t*    Press[6] Exit                                            *");
    printf("\n\n\t\t\t*                                                             *");
    printf("\n\t\t\t***************************************************************\n");
    fflush(stdin);
    printf("\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &userChoice);

    switch(userChoice)
    {
        case 1:  wholeYearCalendar();
                 break;
        case 2:  specificMonthOfYearCalendar();
                 break;
        case 3:  findDayGivenDate();
                 break;
        case 4:  calcDay_of_Year_from_Date();
                 break;
        case 5:  info();
                 break;
        case 6:  exit(0);
                 break;
        default: system("COLOR C0");
                 delay(200);
                 system("COLOR F0");
                 printf("\n\n\n\n\t\t\t\t  Please try again. Invalid Choice!\n\n");
                 break;
    }
        printf("\n");
        delay(1000);
        printf("\n\n\t\t\t\t  Do you want to go to menu again?");
        printf("\n\n\t\t\t\t   Press [Y] if Yes, [N] to exit.");
        c = getch();
        if(c == 'n' || c == 'N')
        {
            exit(0);
        }
        if(c == 'y' || c == 'Y')
        {
            goto def;
        }
}

void wholeYearCalendar()
{
    do{
            system("COLOR B0");
            system("cls");
            fflush(stdin);
            printf("[NOTE: Input your desired year using numbers. (ex. 2002)]\n");
            printf("\nEnter your desired year: ");
            scanf("%d",&year);
            if (year < 0)
                {
                    system("COLOR C0");
                    delay(200);
                    system("COLOR B0");
                    printf("\n\n        Error: year must be greater 0\n\n");
                    break;
                }

            checkLeapYear(year);

            startingDay = getFirstWeekday(year);

            for(month = 0; month< 12; month++)
                {

                    daysInMonth = monthDay[month];
                    printf("\n\n---------------%s-------------------\n", monthNames[month]);
                    printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

                    for(weekDay = 0; weekDay < startingDay; weekDay++)
                    printf("     ");

                    for(day = 1;day <= daysInMonth; day++)
                        {
                            printf("%5d",day);
                            if(++weekDay>6)
                                {
                                    printf("\n");
                                    weekDay=0;
                                }
                            startingDay = weekDay;
                        }
                }

            printf("\n\n\t  Press [Y] to use Program Again, Press [P] to Print, and Press [N] to Ask to Go Back to Main.");
            c = getch();
            if(c == 'n' || c == 'N')
                {
                    break;
                }
            if(c == 'p' || c == 'P')
                {
                    PrintFile1(year, getFirstWeekday);
                    break;
                }
    }while(c == 'y' || c == 'Y');
}

void specificMonthOfYearCalendar()
{

    do{
            system("cls");
            system("COLOR A0");
            fflush(stdin);
            printf("[NOTE: The first 3 letters of the month you'll input must be in UPPERCASE (ex. for January, enter JAN)]\n");
            printf("\n\nEnter first 3 letters of your desired month of the year : ");
            scanf("%s",strMonth);
            for(month = 0; month < 12; month++)
                {
                    if(!strcmp(strMonth, months[month]))
                        {
                            monthNum = month + 1;
                            flag = 1;
                            break;
                        }
                }
            if(flag == 0)
                {
                    system("COLOR C0");
                    delay(200);
                    system("COLOR A0");
                    printf("\nInvalid Month!\n");
                }
            printf("\n[NOTE: Input your desired year using numbers. (ex. 1999)]\n");
            printf("\nEnter your desired year: ");
            scanf("%d",&year);
            if(monthNum == 1 || monthNum == 3 || monthNum == 5 || monthNum == 6 || monthNum == 8 || monthNum==10 || monthNum==11)
                {
                    dates = 31;
                }
            if(monthNum == 2 || monthNum == 4 || monthNum == 7 || monthNum == 9)
                {
                    dates = 30;
                }
            if(monthNum == 12)
                {
                    if(year % 400 == 0)
                        {
                            dates = 29;
                        }else if(year % 100 == 0)
                            {
                                dates = 28;
                            }else if(year % 4 == 0)
                                {
                                    dates = 29;
                                }else
                                    {
                                        dates = 28;
                                    }
                }

            printf("\n\n------------------------%s %d---------------------------\n\n", months[month], year);
            printf(" SUN     MON     TUE      WED      THURS       FRI     SAT      \n\n");


            for(month = 1; month <= dates; month++)
                {
                    int endDay = getDays(month ,monthNum ,year);

                    if(endDay == 0)
                        {
                            printf("%4d", month);
                        }


                    if(endDay == 1)
                        {
                            if(month != 1)
                                {
                                    printf("%8d", month);
                                }else
                                    {
                                        printf("%12d", month);
                                    }
                        }

                    if(endDay == 2)
                        {
                            if(month!= 1)
                                {
                                    printf("%8d", month);
                                }else
                                    {
                                        printf("%20d", month);
                                    }
                        }

                    if(endDay == 3)
                        {
                            if(month != 1)
                                {
                                    printf("%9d", month);
                                }else
                                    {
                                        printf("%29d", month);
                                    }
                        }

                    if(endDay == 4)
                        {
                            if(month!= 1)
                                {
                                    printf("%11d", month);
                                }else
                                    {
                                        printf("%40d", month);
                                    }
                        }

                    if(endDay == 5)
                        {
                            if(month != 1)
                                {
                                    printf("%10d", month);
                                }else
                                    {
                                        printf("%50d", month);
                                    }
                        }

                    if(endDay == 6)
                        {
                            if(month != 1)
                                {
                                    printf("%8d\n", month);
                                }else
                                    {
                                        printf("%58d\n", month);
                                    }
                        }
                }
            printf("\n\n-----------------------------------------------------------\n");
            printf("\n");
            printf("\n\n\t  Press [Y] to use Program Again, Press [P] to Print, and Press [N] to Ask to Go Back to Main.");
            c = getch();
            if(c == 'n' || c == 'N')
                {
                    break;
                }
            if(c == 'p' || c == 'P')
                {
                    PrintFile2(month, year, endDay);
                    break;
                }
    }while(c == 'y' || c == 'Y');

}

int getDays(int dayofMonth,int monthNum,int year)
{
   if(dayofMonth <= 0 || dayofMonth > 31)
   {
     printf("\nInvalid Date\n");
     exit(0);
    }
    if(monthNum == 11|| monthNum == 12)
     {
       year = year - 1;
     }
     last2Digits = year % 100;
     first2Digits = year / 100;
     Zeller = (dayofMonth+(((13*monthNum)-1)/5)+last2Digits+(last2Digits/4)+(first2Digits/4))-(2*first2Digits);

     if(Zeller >= 0)
        {
       endDay= Zeller % 7;
      }
      else
     {
       endDay=((Zeller % 7) + 7) % 7;
      }

      return(endDay);
}


void findDayGivenDate()
{

    int i, remainder = 0, remainder1 = 0, remainder2 = 0, week = 0;
    def:
    system("cls");
    system("COLOR D0");
    fflush(stdin);
    printf("[NOTE: Input your desired numbers and separate it with spaces. (ex. 01 01 2002)]\n");
    printf("\nEnter your desired date (MM/DD/YYYY): ");
    scanf("%d %d %d", &month, &day, &year);
    if(month == 2)
        {
            if((day > 28) && (year%4 != 0))
                {
                    printf("\n\nSorry, Invalid date in February of non leap year. The maximum value is 28.\n\n");
                    goto def;
                }
            if((day > 29) && (year%4 == 0))
                {
                    printf("\n\nSorry, Invalid date in February of leap year. The maximum value is 29.\n\n");
                    goto def;
                }
        }else if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            {
                if(day > 31)
                    {
                        printf("\n\nSorry, Invalid date in %d th month. The maximum value is 31.\n\n", month);
                        goto def;
                    }
            }else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
                {
                    printf("\n\nSorry, Invalid date in the %d th month. The maximum value is 30.\n\n", month);
                    goto def;
                }else if((day > 31))
                    {
                        printf("\n\nEnter valid date! \n\n");
                        goto def;
                    }
            if((day < 1) || (month < 1))
                {
                    printf("\n\nSorry, Enter positive valid data! \n\n");
                }else
                    {
                        switch(month)
                            {
                                case 1:
                                case 10: remainder1 = day + 2;
                                         break;

                                case 2:
                                case 3:
                                case 11: remainder1 = day + 5;
                                         break;

                                case 4:
                                case 7:  remainder1 = day + 1;
                                         break;

                                case 9:
                                case 12: remainder1 = day;
                                         break;

                                case 5:  remainder1 = day + 3;
                                         break;

                                case 6:  remainder1 = day + 6;
                                         break;

                                case 8:  remainder1 = day + 4;
                                         break;

                                default: system("COLOR C0");
                                         delay(200);
                                         system("COLOR D0");
                                         printf("\n\nDon't you know that there is no month greater than 12. Enter a valid month! \n");
                                         goto def;
                            }
                    }
    if(year < 2003)
        {
            for(i = 2002; i >= year; i--)
                {
                    if((i == year) && (i%4 == 0))
                        {
                            if(month > 2)
                                {
                                    week = week + 1;
                                }else if(month <= 2)
                                    {
                                        week = week + 2;
                                    }

                            break;
                        }else if(i%4 == 0)
                            {
                                if(i%100 == 0)
                                    {
                                        if(i%400 == 0)
                                            {
                                                week = week + 2;
                                            }else
                                                {
                                                    week = week + 1;
                                                }
                                    }else
                                        {
                                            week = week + 2;
                                        }
                            }else
                                {
                                    week = week + 1;
                                }
                }
            remainder2 = 7 - week % 7;
        }
    else if(year > 2003)
        {
            for(i = 2004; i <= year; i++)
                {
                    if((i == year) && (i%4 == 0))
                        {
                            if(month > 2)
                                {
                                    week = week + 2;
                                }else if(month <= 2)
                                    {
                                        week = week + 1;
                                    }
                            break;
                        }else if(i%4 == 0)
                            {
                                if(i%100 == 0)
                                    {
                                        if(i%400 == 0)
                                            {
                                                week = week + 2;
                                            }else
                                                {
                                                    week = week + 1;
                                                }
                                    }else
                                        {
                                            week = week + 2;
                                        }
                            }else
                                {
                                    week = week + 1;
                                }
                }
            remainder2 = week % 7;
        }else
            {
                remainder2 = 0;
            }

    remainder = (remainder1 + remainder2) % 7;

    printf("");

    switch(remainder)
        {
            case 0: printf("\nThe Day is SUNDAY.\n");
                    break;

            case 1: printf("\nThe Day is MONDAY.\n");
                    break;

            case 2: printf("\nThe Day is TUESDAY.\n");
                    break;

            case 3: printf("\nThe Day is WEDNESDAY.\n");
                    break;

            case 4: printf("\nThe Day is THURSDAY.\n");
                    break;

            case 5: printf("\nThe Day is FRIDAY.\n");
                    break;

            case 6: printf("\nThe Day is SATURDAY.\n");
                    break;

            default: system("COLOR C0");
                     delay(200);
                     system("COLOR D0");
                     printf("\n\nPlease Try Again.\n\n");
                     break;
        }

        printf("\n");

        delay(1000);
        printf("\n\n\t\t\t\t  Do you want to use this program again?");
        printf("\n\n\t\t\t\t     Press [Y] if Yes, [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N')
        {
            exit(0);
        }
        if(c == 'y' || c == 'Y')
        {
            goto def;
        }

}

void calcDay_of_Year_from_Date()
{

    do{
            int DayOfYear;
            system("cls");
            system("COLOR E0");
            fflush(stdin);
            printf("[NOTE: Input your desired numbers and separate it with spaces. (ex. 12 25 2015)]\n");
            printf("\nEnter your desired date (MM/DD/YYYY): ");
            scanf("%d %d %d", &month, &day, &year);
            if((day < 1) || (month < 1) || (year < 1))
                {
                    system("COLOR C0");
                    printf("\n\nSorry, Enter positive valid data! \n\n");
                    break;
                }

            DayOfYear = day;

            checkLeapYear(year);

            switch(month)
                {
                    case 2: DayOfYear += 31;
                            break;

                    case 3: DayOfYear += 31+monthDay[1];
                            break;

                    case 4: DayOfYear += 31+monthDay[1]+31;
                            break;

                    case 5: DayOfYear += 31+monthDay[1]+31+30;
                            break;

                    case 6: DayOfYear += 31+monthDay[1]+31+30+31;
                            break;

                    case 7: DayOfYear += 31+monthDay[1]+31+30+31+30;
                            break;

                    case 8: DayOfYear += 31+monthDay[1]+31+30+31+30+31;
                            break;

                    case 9: DayOfYear += 31+monthDay[1]+31+30+31+30+31+31;
                            break;

                    case 10: DayOfYear += 31+monthDay[1]+31+30+31+30+31+31+30;
                             break;

                    case 11: DayOfYear += 31+monthDay[1]+31+30+31+30+31+31+30+31;
                             break;

                    case 12: DayOfYear += 31+monthDay[1]+31+30+31+30+31+31+30+31+30;
                             break;

                    default: system("COLOR C0");
                             delay(200);
                             system("COLOR E0");
                             printf("\n\nPlease Try Again. Invalid Input! \n\n");
                             break;
                }

        printf("\nDay of year: %d", DayOfYear);

        printf("\n\n\t\t\t\t  Do you want to use this program again?");
        printf("\n\n\t\t\t\t     Press [Y] if Yes, [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N')
        {
            break;
        }
    }while(c == 'y' || c == 'Y');
}


void info()
{

}


int getFirstWeekday(int year)
{
    /*Zeller's Congruence*/
    int zeller;
    zeller = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return zeller;
}

int checkLeapYear(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
        {
            monthDay[1]=29;
        }
}

void PrintFile1(int Y, int Z)
{
    int i, j;
    char filename[12];
    char stryear[5];
    FILE *fp;

    //strcpy(filename, months[month-1]);
    itoa(year, stryear, 10);
    strcat(filename, stryear);
    strcat(filename, ".txt");

    fp = fopen("wholeYearCalendar.txt", "w");

    fprintf(fp, "\n\t\t\t %d \n\n\t", year);

    for(i=1; i<=MAX_NO; i++)
        fprintf(fp, "-");

    fprintf(fp, "\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\t");
    for(i=1; i<=MAX_NO; i++)
        fprintf(fp, "-");

    /* setting starting position */
    fprintf(fp, "\n");
    for(i = 1; i <= getFirstWeekday; i++)
        fprintf(fp, "\t -");

    j = getFirstWeekday;

    /* printing dates */
    for(i = 1; i <= month; i++)
    {
        if(j++ % 7 == 0)
            {
               fprintf(fp, "\n");
            }

        fprintf(fp, "\t%2d", i);
    }

    fprintf(fp, "\n\t");

    for(i=1; i<=MAX_NO; i++)
        {
            fprintf(fp, "-");
        }

    fprintf(fp, "\n\n\t\tCreated by: GROUP 5");
    fclose(fp);
}

void PrintFile2(int M, int Y, int Z)
{
    int i, j;
    char filename[12];
    char stryear[5];
    FILE *fp;

    //strcpy(filename, months[M-1]);
    itoa(year, stryear, 10);
    //strcat(filename, stryear);
    //strcat(filename, ".txt");

    fp = fopen("MonthCalendar.txt","w");


    fprintf(fp, "\n\t\t\t%s %d\n\n\t", months[M-1], Y);

    for(i=1; i<=MAX_NO; i++)
        fprintf(fp, "-");

    fprintf(fp, "\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\t");
    for(i=1; i<=MAX_NO; i++)
        fprintf(fp, "-");

    /* setting starting position */
    fprintf(fp, "\n");
    for(i = 1; i <= Z; i++)
        fprintf(fp, "\t -");

    j = Z;

    /* printing dates */
    for(i = 1; i <= monthDay[month-1]; i++)
    {
        if(j++ % 7 == 0)
            {
               fprintf(fp, "\n");
            }

        fprintf(fp, "\t%2d", i);
    }

    fprintf(fp, "\n\t");

    for(i=1; i<=MAX_NO; i++)
        {
            fprintf(fp, "-");
        }

    fprintf(fp, "\n\n\t\tCreated by: GROUP 5");
    fclose(fp);
}
