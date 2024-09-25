#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void readString(char *str) {
    printf("Enter the string: ");
    if (fgets(str, MAX_SIZE, stdin)==NULL) {
        fprintf(stderr, "Error reading string.\n");
        str[0]='\0';
    }
}
void readPattern(char *pat) {
    printf("Enter the pattern string: ");
    if (fgets(pat, MAX_SIZE, stdin)==NULL) {
        fprintf(stderr, "Error reading pattern.\n");
        pat[0]='\0';
    }
}
void readReplace(char *rep) {
    printf("Enter the replace string:");
    if (fgets(rep, MAX_SIZE, stdin)==NULL) {
        fprintf(stderr,"Error reading replace string.\n");
        rep[0]='\0';
    }
}
void findAndReplace(char *str, const char *pat, const char *rep) {
    char result[MAX_SIZE];
    int i=0,j=0;
    int strLen=strlen(str);
    int patLen=strlen(pat);
    int repLen=strlen(rep);
  
    if (str[strLen-1]=='\n') strLen--;
    if (pat[patLen-1]=='\n') patLen--;
    if (rep[repLen-1]=='\n') repLen--;

    while (i < strLen) {
        bool found=true;
        for(int k = 0; k < patLen; k++) {
            if (i+k>=strLen||str[i+k]!=pat[k]) {
                found=false;
                break;
            }
        }
        if (found) {
            if (j+repLen<MAX_SIZE) {
                strncpy(result+j, rep, repLen);
                j+=repLen;  
            }
            i+=patLen;  
        } else {
            if (j<MAX_SIZE-1) {
                result[j++]=str[i++]; 
            } else {
                break; 
            }
        }
    }

    result[j]='\0'; 
    strncpy(str, result, MAX_SIZE); 
    str[MAX_SIZE-1]='\0'; 
}

int main() {
    printf("Ashish's(1AY23CS040) Program!\n\n");
    char str[MAX_SIZE], pat[MAX_SIZE], rep[MAX_SIZE];

    readString(str);
    readPattern(pat);
    readReplace(rep);

    findAndReplace(str, pat, rep);

    if (str[0] != '\0') {
        printf("Modified string: %s\n", str);
    } else {
        printf("Pattern does not exist in the main string.\n");
    }
    return 0;
}
