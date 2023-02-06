#include <stdio.h>
#include <stdlib.h>
#include "rothelper.h"
#include "rot13.h"

char rotate(char in, int howmuch)
{
	if (!( (in >= 'a' && in <= 'z') || (in >= 'A' && in < 'Z')))
		return in;

	howmuch = howmuch % 26;

	int wraparound = 0;
	int ret = ((int) in + howmuch);
	if (in >= 'a' && in <= 'z')
    {
		if (ret > (int) 'z')
			wraparound = 1;
	}
	if (in >= 'A' && in <= 'Z')
	{
		if (ret > (int) 'Z')
			wraparound = 1;
	}
	if (wraparound)
	{
		ret = ret - 26;
	}
	return((char)ret);
}

char* rotate_words(char input[], int howmuch)
{
	int len = stringlength(input);
	char* output = (char*) malloc (sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
		output[i] = rotate(input[i], howmuch);
	output[len] = 0;
	return (output);
}

char* rot13(char input[])
{
	return rotate_words(input, 13);
}
