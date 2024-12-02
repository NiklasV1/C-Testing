#include <stdio.h>

char *
charSplitv2(char * string, char separator)
{
  static char * pString;
  static int index;
  static int prevStart;
  static char end;
  if (string != NULL)
  {
    pString = string;
    index = 0;
    prevStart = 0;
    end = 0;
  }
  prevStart = index;
  while (pString[index] != '\0')
  {
    if (pString[index] == separator)
    {
      pString[index] = '\0';
      index++;
      return &pString[prevStart];
    }
    else
    {
      index++;
    }
  }
  if (end == 0)
  {
    end = 1;
    return &pString[prevStart];
  }
  else
  {
    return NULL;
  }
}

char *
charSplit(char * start, char separator)
{
  char value = start[0];
  int counter = 0;
  char * result = NULL;
  while (value != '\0')
  {
    if (value == separator)
    {
      start[counter] = '\0';
      result = &start[counter + 1];
      return result;
    }
    else
    {
      value = start[++counter];
    }
  }
  return result;
}

int
main()
{
  char test1[64] = "Hello this is a test!";
  char test2[64] = "1 2 30 593 20 923 01 92";
  
  char * lastWord = test1;
  char * token1 = charSplit(test1, ' ');

  while (token1 != NULL)
  {
    printf("%s\n", lastWord);
    lastWord = token1;
    token1 = charSplit(token1, ' ');
  }
  printf("%s\n", lastWord);

  char * token2 = charSplitv2(test2, ' ');

  while (token2 != NULL)
  {
    printf("%s\n", token2);
    token2 = charSplitv2(NULL, ' ');
  }

}
