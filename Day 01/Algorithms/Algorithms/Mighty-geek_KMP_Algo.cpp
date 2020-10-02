// KMP algorithm finds all the occurrences of a particular sub string
// in a string which is called "Pattern Searching"

// KMP (Knuth Morris Pratt) algorithm uses degenerating property
// so that time complexity improved to O(n)

#include<bits/stdc++.h>
using namespace std;


// Prototype for function to calculate lps[] string
void computeLPSarray(char* pattern, int size_pattern, int* lps);


// Function to print occurrences of pattern in text string
void KMPsearch(char* pattern, char* text){
    int size_pattern = strlen(pattern);
    int size_text = strlen(text);

    // Step 1: Create a lps[] to hold longest prefix suffix for pattern
    int lps[size_pattern];

    // function to calculate lps[] priorly
    computeLPSarray(pattern, size_pattern, lps);

    // Initializing indexes for text[] and pattern[] respectively
    int i = 0;
    int j = 0;

    while(i < size_text) {
        if(pattern[j] == text[i]) {
            j++;
            i++;
        }

        if(j == size_pattern) {
            cout << "Pattern found at index:\t" << i-j;
            j = lps[j-1];
        }
        // mismatch after j matches
        else if(i<size_text && pattern[j] != text[i]) {
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}


void computeLPSarray(char* pattern, int size_pattern, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;

    // the loop calculates lps[i] for i = 1 to end of pattern i.e. size_pattern - 1
    int i = 1;
    while (i < size_pattern) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        // for case when -> (pattern[i] != pattern[len])
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            // index of pattern i.e. "i" is not incremented here
            }
            // for case when -> length of pattern is 0
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int main()
{
    char pattern[10000], text[10000];
    cout << "Enter string text:\t";
    gets(text);
    cout << "Enter string pattern:\t";
    gets(pattern);
    cout << endl;

    KMPsearch(pattern, text);
    return 0;
}



















