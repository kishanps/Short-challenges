/* Given a list of strings, convert to a single string and then back to the orig strings */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void encode (char *a, char **str, int n)
{
   int i, len;
   char t[100];

   for (i=0; i<n; i++) {
       len = strlen(str[i]);
       memset(t, 0, 100);
       snprintf(t, 100, "%d#", len);
       strncat(a, t, strlen(t));
       strncat(a, str[i], strlen(str[i]));
   }
}

int convert_str_num(char *s)
{
    int len = strlen(s);
    int n = 0, j, i=0, mult=1;
 
    for (j=len-1; j>=0; i++, j--) {
        if (i == 0) 
            mult = 1;
        else
            mult *= 10; 
        n += (s[j]-'0')*(mult);
    }


    return n;
}

void decode (char *a, char *str[], int *n)
{
    int i=0;
    char *t = a;
    int len = 0, slen;
    char t1[100] = {0};
    
    while (*a) {
        if (*a == '#') { 
            strncpy(t1, t, len);
            t1[len]='\0';
            slen = convert_str_num(t1);
            str[i] = calloc(slen+1, 1);
            strncpy(str[i], a+1, slen);
            str[i][slen]='\0';
            a += slen+1;
            i++;
            len = 0;
            t = a;
        } else {
            len++;
            a++;
        }
     }
     *n = i;
}

int main()
{
    char *a[3] = { "one", "two", "three" };     
    char b[100] = {0};
    char *c[10];
    int i, len = 0;

    encode(b, a, 3);
    printf("Encoded string %s\n", b);
    decode(b, c, &len);
    printf("Decode string len %d\n", len);
    for (i=0; i<len; i++) 
        printf("String %d is %s\n", i, c[i]);
    return 0;
}
