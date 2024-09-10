#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

void main() 
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
