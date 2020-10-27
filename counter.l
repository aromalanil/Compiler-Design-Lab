 /**
  * Lex program to count the No. of Characters, No. of Words and No. of Lines in a file.
  * Author : Aromal Anil
  * Date : 27 October 2020
  */


%{ 
  #include<stdio.h> 

  int lines=0,words=0,characters=0; 
%}
  

%% 

\n {lines++; words++;}
[\t ' '] words++;
[a-zA-Z0-9] characters++;

%% 
  

  
void main() 
{  
  char fileName[50];

  printf("Enter File Name : ");
  scanf("%s", fileName);
  yyin = fopen(fileName, "r");  
  
  yylex();
  printf("\n===========File Analysis===========\n\n"); 
  printf("No of Lines : %d\n",lines);
  printf("No of Words : %d\n",words);
  printf("No of Characters : %d\n",characters);
} 

int yywrap()
{
  return 1;
}


