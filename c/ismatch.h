#ifndef _ISMATCH_H_
#define _ISMATCH_H_

bool isMatch(char *s, char *p)
{
  int j = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (p[j] == '.')
    {
      j++;
      continue;
    }
    else if (s)
  }
  return true;
}

#endif // _ISMATCH_H_
