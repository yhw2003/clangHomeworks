int strlen(const char *s)
{
  const char *p = s;
  while (*p) p++;
  return p - s;
}

int strcpy(char *dest, const char *src)
{
  char *p = dest;
  while (*src) *p++ = *src++;
  *p = 0;
  return p - dest;
}

int strcmp(const char *s1, const char *s2)
{
  while (*s1 && *s2 && *s1 == *s2)
  {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}