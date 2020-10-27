/**
 * A lexical analyser for C Language made with C
 * Author : Aromal Anil
 * Date : 29 September 2020
 */

#include <stdio.h>
#include <string.h>

/**
 * Function to check if the given word is a keyword
 */
int isKeyWord(char word[])
{
  int isKeyWord = 0;
  char keywords[][10] = {"auto",
                         "break",
                         "case",
                         "char",
                         "const",
                         "continue",
                         "default",
                         "do",
                         "double",
                         "else",
                         "enum",
                         "extern",
                         "float",
                         "for",
                         "goto",
                         "if",
                         "int",
                         "long",
                         "register",
                         "return",
                         "short",
                         "signed",
                         "sizeof",
                         "static",
                         "struct",
                         "switch",
                         "typedef",
                         "union",
                         "unsigned",
                         "void",
                         "volatile",
                         "while"};

  for (int i = 0; i < sizeof(keywords); i++)
  {
    if (strcmp(keywords[i], word) == 0)
    {
      isKeyWord = 1;
      break;
    }
  }
  return isKeyWord;
}

/**
 * Function to check if given character is an operator
 */
int isOperator(char c)
{
  char operators[] = "+-*/%=&";
  int isOperator = 0;

  for (int i = 0; i < strlen(operators); i++)
  {
    if (c == operators[i])
    {
      isOperator = 1;
      break;
    }
  }
  return isOperator;
}

/**
 * Function to check if given character is a special Symbol
 */
int isSpecialSymbol(char c)
{
  char specialSymbols[] = "#;(),<>{}@#$_&/*\"\':;!?\\";
  int isSpecialSymbol = 0;

  for (int i = 0; i < strlen(specialSymbols); i++)
  {
    if (c == specialSymbols[i])
    {
      isSpecialSymbol = 1;
      break;
    }
  }
  return isSpecialSymbol;
}

/**
 * Main Function
 */
void main()
{
  char fileName[50], ch, word[15];
  FILE *fp;
  int j = 0;

  printf("Enter File Name : ");
  scanf("%s", fileName);

  fp = fopen(fileName, "r");

  if (fp == NULL)
  {
    printf("Error reading the file");
    return;
  }

  while ((ch = fgetc(fp)) != EOF)
  {

    if (ch == ' ' || ch == '\n' || isOperator(ch) == 1 || isSpecialSymbol(ch) == 1)
    {
      if (isOperator(ch) == 1)
      {
        printf("%c is a operator\n", ch);
      }

      else if (isSpecialSymbol(ch) == 1)
      {
        printf("%c is a special symbol\n", ch);
      }

      if (j != 0)
      {
        word[j] = '\0';
        if (isKeyWord(word))
        {
          printf("%s is a keyword\n", word);
        }
        else
        {
          printf("%s is an identifier\n", word);
        }

        j = 0;
      }
    }
    else
    {
      word[j] = ch;
      j++;
    }
  }

  fclose(fp);
}