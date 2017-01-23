/* Remove 3 consecutive duplicates from string 
For eg, Input: aabbbaccddddc
        Output: ccdc */

#include <stdio.h>
#include <string.h>
void remove_dupe (char *s)
{
    int curr=0, prev=0;
    char *dstr, *sstr;
    char p=' ';

    while (*s) {
        if (*s != p) {
            prev = curr;
            curr = 1;
        } else {
            curr++;
            if (curr >= 3) {
                // replace curr with the prev
                curr = prev;
                // shift left the remaining string
                sstr = s+1;
                dstr = s-2;
                while (*sstr) {
                    *dstr = *sstr;
                    dstr++; 
                    sstr++;
                }
                *dstr = '\0';
                // move back curr ptr by the prev repeating count
                s -= (prev+1);
            }
        }
        p = *s;
        s++;
    }
}

int main() {
    char a[] = "aabbccdddc";
    char *b = strdup(a);
    remove_dupe(a);
    printf("String before %s, after %s\n", b, a);
    return 0;
}
