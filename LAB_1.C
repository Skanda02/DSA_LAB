#include<stdio.h> 

#include<stdlib.h> 

//#include<string.h> 

struct day 

{ 

    char* dayname; 

    int date; 

    char* activitydescription; 

}; 

  

struct day*createday() 

{ 

    struct day*newday = (struct day*)malloc(sizeof(struct day)); 

    newday->dayname = (char*)malloc(sizeof(char)); 

    newday->activitydescription = (char*)malloc(sizeof(char)); 

 

    printf("Enter day name");	 

    scanf("%s",newday->dayname); 

    printf("Enter date"); 

    scanf("%d",&(newday->date)); 

    printf("Enter activity description"); 

    scanf(" %[^\n]",newday->activitydescription); 

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

    printf("\nWeek's Activity Details"); 

    for(int i=0;i<size;i++) 

    { 

        printf("Day %d:\n",i+1); 

        printf("Day Name %s\n",calendar[i]->dayname); 

        printf("Date %d\n",calendar[i]->date); 

        printf("Activity Description %s\n",calendar[i]->activitydescription); 

        printf("\n"); 

 

    } 

} 

void freememory(struct day*calendar[],int size) 

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

    struct day* week[7]; 

    read(week,7); 

    display(week,7); 

    freememory(week,7); 

    return 0; 

} 