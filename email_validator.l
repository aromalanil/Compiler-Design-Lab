 /**
  * Lex program to validate email address.
  * Author : Aromal Anil
  * Date : 27 October 2020
  */

%{ 
  #include<stdio.h>
 
  int isValid = 0;
%}
 
 // Regex to check for email
%%
[^@ \t\r\n]+@[^@ \t\r\n]+\.[^@ \t\r\n]+ {isValid=1; return 0;}
.+ {return 0;}
%%
 
void main() 
{  
  printf("Enter the email : ");
 
  yylex();
 
  // Checking if isValid flag is set.
  if(isValid==1){
    printf("Email id is valid\n");
  }else{
    printf("Email id is not valid\n");
  }
} 
 
int yywrap()
{
  return 1;
}