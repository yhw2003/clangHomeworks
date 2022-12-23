int search_in_string(char *str, char key)
{
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == key)
      return i;
    i++;
  }
  return -1;
}