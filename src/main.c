#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32 /* shenanigans for you windows users */
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J") /* totally did not just steal this from stackoverflow forums */
#endif

char possible_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*_+";

int get_random(int lower, int upper)
{
	return (rand() % (upper - lower + 1)) + lower;
}

char *generate_password(int password_length)
{
	char *password = malloc(password_length);
	int i;

	for (i = 0; i < password_length; i++)
	{
		int length = strlen(possible_chars);
		char random_char = possible_chars[get_random(0, (length - 1))];

		password[i] = random_char;
	}

	password[password_length] = '\0'; // Terminate string
	
	return password;
}


int run_program()
{
	srand(time(0)); /* initialize random generator */

	// Main menu
	clrscr();
	printf("##########################\n");
	printf("# quick random passwords #\n");
	printf("##########################\n");
	printf("\n");

	// Run password generation
	
	int password_length;
	printf("Desired password length: ");
	scanf("%d", &password_length);
	printf("\n");

	int password_count;
	printf("How many passwords to generate?: ");
	scanf("%d", &password_count);

	if ((password_length < 1) || (password_count < 1)) {
		return 1;
	}
	
	printf("\n");
	
	if (password_count > 1)
	{
		printf("\nPasswords:\n");
	} else {
		printf("\nPassword:\n");
	}

	int z;

	for (z = 0; z < password_count; z++)
	{
		char *password = generate_password(password_length);

		printf("%s", password);

		free(&*password); /* you wouldn't leak memory, would you? (learned this the hard way) */
		printf("\n");
	}

	return 0;
}

int main()
{
	int result = run_program();
	if (result == 1) {
		clrscr();
		/* uh oh you are bad at inputting real numbers */
		printf("Please input positive integers > 0.\n");
	}


	return 0;
}
