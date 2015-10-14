#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

/*
 *      This function clears the screen
 */
void clear(void)
{
        // tbh, no idea how this works. Found it on Stack Exchange
        printf("\033[2J\033[1;1H");
}

int main(void)
{
	
	clear();
	
	printf("Enter a height: ");
	int height = GetInt(); // get the height from the user

	// yay, matracies!
	// first allocate a height long array of pointers
	char** pyramid = malloc(sizeof(char*) * height);
	for (int i = 0; i < height; i++)
	{
		// then point each of those pointers to a height long array of chars
		pyramid[i] = malloc(sizeof(char) * height);
	}

	// for every row
	for (int i = 0; i < height; i++)
	{

		// and every collumn
		for (int j = 0; j < height; j++)
		{

			// if the collumn is less then the height minus the row
			// i.e. if its the 5th row and less then the 5th collumn
			if (j < (height-i-1))
				pyramid[i][j] = ' '; // make it a space

			// otherwise
			// i.e. if its the 5th row and the 5th or more collumn
			else
				pyramid[i][j] = '#'; // make it a hash
		}
	}

	printf("\n"); // make it look pretty
	
	// for every row
	for (int i = 0; i < height; i++)
	{
		// for every collumn in order
		for (int j = 0; j < height; j++)
			// print out the block in order
			printf("%c", pyramid[i][j]);

		printf(" "); // little gap
		
		// for every collumn in reverse order
		for (int j = height-1; j >= 0; j--)
			// print out the block in reverse order
			printf("%c", pyramid[i][j]);

		printf("\n");
	}

	// LET MY PEOPLE GO!
	for (int i = 0; i < height; i++)
	{
		free(pyramid[i]);
	}
	free(pyramid);

	return 0;
}
