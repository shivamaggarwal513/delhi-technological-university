#pragma once

extern char a[50];
extern char b[50];

/* Concatenates source string into destination string */
char* strCat(char*, const char*);

/* Reverses the string */
char* strRev(char*);

/* Change each character to Upper-case */
char* strUpr(char*);

/* Change each character to Lower-case */
char* strLwr(char*);

/* Returns length of string */
int strLen(const char*);

/* Compares two strings lexicographically */
int strCmp(const char*, const char*);