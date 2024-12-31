#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define NUM_CITIES 7
void digi_clock(void);
void stop_watch(void);
void ring_alarm(void);
void world_clock(void);
//Main function
int main()
{
int n;
char ch;
printf("*********************TIMING*********************\n\n");
do
{
printf("\n\nHello! This program offers following time services:\n");
 printf("\nPress 1: for starting a digital clock");
 printf("\nPress 2: for starting a stop watch");
printf("\nPress 3: for setting an alarm and ringing it");
printf("\nPress 4: for world clock");
 
printf("\nPlease enter any option number (1-4): ");
scanf("%d",&n);
 if (n==1)
 {
 digi_clock();
 }
 else if(n==2)
 {
stop_watch();
Complex Engineering Problem 2
 }
 else if (n==3)
 {
ring_alarm();
 }
 else if(n==4)
 {
world_clock();
 }
 else
 {
printf("\nInvalid Input!!!");
 }
printf("\nIf you want to use any other timing services press 'y' otherwise press 'e' to exit program: ");
ch = getche();
 } while(ch=='y' && ch!='e');
printf("\n\nHave a nice day.\nAllah Hafiz!");
getch();
} //End of main function
//Digital clock function
void digi_clock()
{
int hr, min, sec;
char ch;
printf("\nWhat is the time now? Enter 2 digits for hours, minutes and seconds. (Please note it is 24 hours 
clock): ");
scanf("%d:%d:%d",&hr,&min,&sec);
printf("\nPress any key to start digital clock");
 getch();
 printf("\nHere starts your clock (hit any key to stop the clock)\n");
Complex Engineering Problem 3
printf("\t\tHours : Min : Sec\n\t\t");
 while(!kbhit())
{
system("cls");
printf(" %02d : %02d : %02d ",hr,min,sec);
sec++;
if(sec==60)
{
min+=1;
sec=0;
}
if(min==60)
{
hr+=1;
min=0;
}
if(hr==24)
{
hr=0;
min=0;
sec=0;
}
sleep(1);
}
getch();
} //End of digital clock function
Complex Engineering Problem 4
//Stop watch function
void stop_watch()
{
int hh=0,mm=0,ss=0,ms=0;
 printf("\n\t\t\t STOP WATCH");
 printf("\n\n\n\n\t\t\t%2d : %02d : %02d : %02d\n\n",hh,mm,ss,ms);
 printf("\nPress any key to start the stop watch");
 getch();
while(!kbhit())
{
Sleep(50);
 ms++;
 if(ms==10)
 {
 ss++; 
ms=0;
}
 if(ss==60)
 {
 mm++;
 ss=0;
}
 if(mm==60)
 {
 hh++;
mm=0;
}
 system("cls");
 printf("\n\n\n\n\t\t\t%d : %02d : %02d . %02d\n\n\nPess any key to stop",hh,mm,ss,ms);
 }
 getch();
} //End of stop watch function
Complex Engineering Problem 5
//Alarm function
void ring_alarm()
{
int h,m,s,a,b,c,x,y,z;
printf("\nPlease enter current time (Remember it's a 24 hour clock format): ");
scanf("%d:%d:%d",&h,&m,&s);
printf("\nSet alarm time (Remember it's a 24 hour clock format): " );
scanf("%d:%d:%d",&a,&b,&c);
for (x=h;x<=24;x++)
{
for(y=m;y<60;y++)
{
for(z=s;z<60;z++)
{
Sleep(1000);
system("cls");
printf("%d:%d:%d\t",x,y,z);
if(a==x && b==y && c==z)
{
while(!kbhit())
{
printf("\n\nWAKE UP!!!!");
Beep(550, 5000);
Sleep(1000);
}
} if(kbhit())
break;
} if(kbhit())
break;
} if(kbhit())
Complex Engineering Problem 6
break;
}
getch();
} //End of alarm function
//World Clock function
void world_clock()
{
int i;
const char *CITIES[NUM_CITIES] = { "PAKISTAN", "USA", "ENGLAND", "JAPAN", "AUSTRALIA", "CHINA", 
"RUSSIA"};
const int TIME_ZONES[NUM_CITIES] = { 0, 14, 7, 4, 6, 3, -2 };
time_t current_time = time(NULL);
printf("\n\t\t\t\t***WORLD CLOCK***\n");
for (i = 0; i < NUM_CITIES; i++) 
{
 time_t local_time = current_time + TIME_ZONES[i] * 3600;
 struct tm *tm = localtime(&local_time);
 printf("%s: %02d:%02d:%02d\n", CITIES[i], tm->tm_hour, tm->tm_min,tm->tm_sec);
 }
} //End of world clock function
