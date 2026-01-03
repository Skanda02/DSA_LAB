/*
2. Develop a program in c for the following operations on string
  a. Read a main string(STR), a pattern(PAT), and a replace string (REP)
  b. Perforn pattern matching operation
        Find and replace all the occurrences of PAT in STR with REP if PAT exists in STR
  c. Report suitable messages in case PAT does not exist in STR. Don't use built in function
*/




#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main() 
{ 

  int textlength,patlength,replength,i,j; 
  char* text=(char*)malloc(sizeof(char));	 
  char* pat=(char*)malloc(sizeof(char));
  char* rep=(char*)malloc(sizeof(char)); 

  printf("Enter the text\t"); 
  scanf(" %[^\n]",text); 
  printf("Enter the pattern\t"); 
  scanf(" %[^\n]",pat); 
  printf("Enter the replace pattern\t"); 
  scanf(" %[^\n]",rep); 

  textlength=strlen(text); 
  patlength=strlen(pat); 
  replength=strlen(rep); 

for(i=0;i<textlength-patlength;i++) 
{ 
  for(j=0;j<patlength;j++) 
  { 
    if(text[i+j]!=pat[j]) 
    { 
      break; 
    } 
} 
if(j==patlength) 
{ 
  printf("Possition found at %d\n",i); 
  break; 
} 
} 

if(patlength==replength) 
{ 
  for(int k=0;k<replength;k++) 
  { 
    text[i] = rep[k];
    i++; 
  } 
  printf("\n Updated text is %s\n",text);	 
} 

else 
{ 
  printf("Not possible\n"); 
} 
} 
