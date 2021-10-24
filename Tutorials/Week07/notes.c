// A struct is a group of arrays
// When to use array or struct:
// 1. Do we have same datatype or differenty datatype
// 
// Can have a struct of arrays
// Can have an array of structs
// 

// compares strings
if (strcmp(s1,s2) == 0) {}

// checks if memory of s1 is same as memory of s2
if (s1 == s2) {}






int n;
int *p, *q;

// & = "address"
// p is a pointer and points to address of n
p = &n;

// dereference p and assign 5
*p = 5;

// Will cause an error because q is unassigned
*q = 17;

// Change the pointer
q = p;

// dereference q and assign 8
*q = 8;