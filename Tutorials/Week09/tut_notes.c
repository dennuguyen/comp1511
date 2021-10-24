// Consider
char s[] = "Hello World!";
char *cp = s;
char *cp2 = &s[8]; // points to address of 8th element - 'r'

// What happens
printf("%s\n", cp); // prints whole string s
printf("%c\n", *cp); // * means get where the pointer is pointing which is 'H'
printf("%c\n", cp[6]); // gives 6th element - 'W'
printf("%s\n", cp2); // starts at 8th element and gives string "rld!"
printf("%c\n", *cp2); // gives just 'r'

