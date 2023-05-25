#include <stdlib.h>



int dis_get_word_length(char *str, char *delims);
char *get_nxt_wd(char *str, char *delims);
int dis_is_delim(char ch, char *delims);
char **struct_tow(char *str, char *delims);
int dis_get_word_count(char *str, char *delims);

/**
 * struct_tow: This function will print a string and seperates its words
 * @str: THis will separate string to seperate into words.
 * Author: Mikiashailu and Abdiali.
 * @delims: delimitors to use to delimit words.
 */

char **struct_tow(char *str, char *delims)
{
	int ck,
	    wordLength,
	    m,
	    z = 0;
	char **words = NULL;

	if (str == NULL || !*str)
		return (NULL);
	ck = dis_get_word_count(str, delims);

	if (ck == 0)
		return (NULL);
	words = malloc((ck + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);
	while (z < ck)
	{
		wordLength = dis_get_word_length(str, delims);
		if (dis_is_delim(*str, delims))
		{
			str = get_nxt_wd(str, delims);
		}
		words[z] = malloc((wordLength + 1) * sizeof(char));
		if (words[z] == NULL)
		{
			while (z >= 0)
			{
				z--;
				free(words[z]);
			}
			free(words);
			return (NULL);
		}
		m = 0;
		while (m < wordLength)
		{
			words[z][m] = *(str + m);
			m++;
		}
		words[z][m] = '\0';
		str = get_nxt_wd(str, delims);
		z++;
	}
	words[z] = NULL;
	return (words);
}


/**
 * get_nxt_wd: This function will gets the next word in a string
 * @delims: delimitors to use to delimit words
 * @str: string to get next word from
 * Author: Mikiashailu and Abdiali.
 */

char *get_nxt_wd(char *str, char *delims)
{
	int pend = 0;
	int z = 0;

	while (*(str + z))
	{
		if (dis_is_delim(str[z], delims))
			pend = 1;
		else if (pend)
			break;
		z++;
	}
	return (str + z);
}

/**
 * dis_get_word_length: This function wil gets the word length
 * Author: Mikiashailu and Abdiali.
 * @delims: This is delimitors to use to delimit words
 * @str: THis is a string to get word length from current word
 */

int dis_get_word_length(char *str, char *delims)
{
	int wrd_size = 0,
	    pend = 1,
	    z = 0;

	while (*(str + z))
	{
		if (dis_is_delim(str[z], delims))
			pend = 1;
		else if (pend)
		{
			wrd_size++;
		}
		if (wrd_size > 0 && dis_is_delim(str[z], delims))
			break;
		z++;
	}
	return (wrd_size);
}

/**
 * dis_get_word_count: This function will gets the word count of a str.
 * Author: Mikiashailu and Abdiali.
 * @delims: This is a delimitors to use to delimit words.
 * @str: This is a string to get word count from.
 */

int dis_get_word_count(char *str, char *delims)
{
	int ck = 0,
	    z = 0,
	    pend = 1;

	while (*(str + z))
	{
		if (dis_is_delim(str[z], delims))
			pend = 1;
		else if (pend)
		{
			pend = 0;
			ck++;
		}
		z++;
	}
	return (ck);
}

/**
 * dis_is_delim: This funciton will checks if stream has delimitor char.
 * @ch: This is acharacter in stream.
 * Author: Mikiashailu and Abdiali.
 * @delims: This is a pointer Pointer to null terminated array of del.
 */

int dis_is_delim(char ch, char *delims)
{
	int z = 0;

	while (delims[z])
	{
		if (delims[z] == ch)
			return (1);
		z++;
	}
	return (0);
}
