/*
1. Develop a Structure Program in c for the following:
    a. Declare a calender as an array if 7 elements(A dynamically Created array) to represent 7 days of a week. Each Elementof the array is a structure haveing three fields
        The first field is the name of the Day(A dynamically allocated String)
        The second field is the date of the Day(A integer)
        Third field is description of the activity for a perticular day (A dynamically allocated String)
    b. Write functions create(), read() and display() to create the calender, to read the data from the keyboard and to print weeks activity details report on screen.
*/

#include<stdio.h> 
#include<stdlib.h> 

struct day 
{ 
    char* dayname; 
    int date; 
    char* activitydescription; 
}; 
  
struct day* createday() 
{ 
    struct day*newday = (struct day*)malloc(sizeof(struct day)); 
    newday->dayname = (char*)malloc(sizeof(char)); 
    newday->activitydescription = (char*)malloc(sizeof(char)); 

    printf("Enter day name : ");	 
    scanf("%s",newday->dayname); 

    printf("Enter date : "); 
    scanf("%d",&(newday->date)); 

    printf("Enter activity description : "); 
    scanf(" %[^\n]",newday->activitydescription); 
    printf("\n");

    return newday; //To solve segmentation error
} 


void read(struct day* calendar[], int size) 
{ 
    for(int i=0;i<size;i++) 
    { 
        printf("Enter details for day %d:\n",i+1); 
        calendar[i]=createday(); 
    } 
} 
 

void display(struct day*calendar[],int size) 
{ 
    printf("___________________________\n");
    printf("\nWeek's Activity Details\n"); 
    printf("___________________________\n");

    for(int i=0;i<size;i++) 
    { 
        printf("Day %d:\n",i+1); 
        printf("Day Name : %s\n",calendar[i]->dayname); 
        printf("Date : %d\n",calendar[i]->date); 
        printf("Activity Description : %s\n",calendar[i]->activitydescription); 
        printf("\n"); 
    } 
} 

void freememory(struct day* calendar[], int size) 
{ 
    for(int i=0;i<size;i++) 
    { 
        free(calendar[i]->dayname); 
        free(calendar[i]->activitydescription); 
        free(calendar[i]); 
    } 
} 

int main() 
{ 
    int no_days;
    printf("Enter the number of days :");
    scanf("%d",&no_days);
    printf("\n");
    struct day* week[no_days]; 
    read(week,no_days); 
    display(week,no_days); 
    freememory(week,no_days); 
    return 0; 
} 