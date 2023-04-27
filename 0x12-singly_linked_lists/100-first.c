#include <stdio.h>

void __attribute__((constructor)) before_main(void);

/**
 * before_main - function that executes before the main and prints a message
 */
void before_main(void)
{
	write(1, "You're beat! and yet, you must allow,\n", 39);
    write(1, "I bore my house upon my back!\n", 30);
}
