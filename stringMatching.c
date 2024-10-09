/*
EXPLANATION:

Initialization: The variables i, m, c, and j are initialized to 0. These variables are used to keep track of positions in the pattern (pat), the main string (str), and the answer array (ans).

Main Loop: The while loop iterates through the main string str until the null terminator ('\0') is encountered.

Character Matching: Inside the loop, the if statement checks if the current character in the string matches the current character in the pattern. If they match, both indices i and m are incremented.

Pattern Match Found: If the end of the pattern is reached (pat[i] == '\0'), it indicates that a match is found. The flag is set to 1, and the matched substring in str is replaced with the replacement string rep.

Replacement Loop: The for loop copies the replacement string rep into the answer array ans. After copying, the pattern index i is reset to 0, and the current position in the string c is updated to m.

Character Mismatch: If the characters do not match, the current character from the string is copied to the answer array, and the indices j, c, and m are updated accordingly.

Null-Termination: Finally, the answer array ans is null-terminated to mark the end of the string.


p: Index for pat (pattern string).
s1: Index for str (main string) during matching.
s2: Index for str (main string) during traversal.
a: Index for ans (answer array).
r: Index for rep (replacement string).
flag: Indicates if a match is found.*/

#include <stdio.h>
#include <stdlib.h>
char str[50], pat[25], rep[25], ans[50];
int p, a, s1, r, flag = 0, s2;

void stringMatch()
{
    // Initialize indices and counters
    p = s1 = s2 = a = 0;

    // Loop through the input string until the null terminator is reached
    while (str[s2] != '\0')
    {
        // Check if the current character in the pattern matches the current character in the string
        if (str[s1] == pat[p])
        {
            p++;  // Move to the next character in the pattern
            s1++; // Move to the next character in the string

            // If the end of the pattern is reached, a match is found
            if (pat[p] == '\0')
            {
                flag = 1; // Set the flag to indicate a match

                // Replace the matched substring with the replacement string
                for (r = 0; rep[r] != '\0'; r++, a++)
                {
                    ans[a] = rep[r]; // Copy the replacement string to the answer array
                }

                // Reset pattern index and update the current position in the string
                p = 0;
                s2 = s1;
            }
        }
        else
        {
            // If characters do not match, copy the current character from the string to the answer array
            ans[a] = str[s2];
            a++;     // Move to the next position in the answer array
            s2++;    // Move to the next character in the string
            s1 = s2; // Reset the match index to the current position
        }
    }

    // Null-terminate the answer string
    ans[a] = '\0';
}

void main()
{
    printf("Enter String: ");
    gets(str);
    printf("Enter Pattern: ");
    gets(pat);
    printf("Enter replacing String: Ad");
    gets(rep);
    stringMatch();
    if (flag == 1)
    {
        printf("Answer is \"%s\"", ans);
    }
    else
    {
        printf("Pattern not found!");
    }
}