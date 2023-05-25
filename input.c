#include <stdlib.h>

unsigned int calcu_absolute_value(int);
char *conv_string(int num);
void fill_buffer_with_base(unsigned int num, unsigned int base, char *buff, int buff_size);
int calcu_buffer_length(unsigned int num, unsigned int base);

/**
 * fill_buffer_with_base: This function will fills buffer with correct numbers.
 * @buff: buffer to fill the buffer.
 * @base: base of number used in conversion, only works up to base 36.
 * @buff_size: this one is the size of buffer.
 * @num: This is a number to convert to string given base
 * Author: Mikiashailu and Abdiali.
 */
void fill_buffer_with_base(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int F_rem,
	    k = buff_size - 1;
	buff[buff_size] = '\0';
	while (k >= 0)
	{
		F_rem = num % base;
		if (F_rem > 9)
			buff[k] = F_rem + 87;
		else
			buff[k] = F_rem + '0';
		num /= base;
		k--;
	}
}

/**
 * conv_string: This funciton will gets a character pointer to new string containing int
 * @num: This parameter is a number.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return to the new string that is created.
 */
char *conv_string(int num)
{
	unsigned int tempo;
	int size = 0;
	long number_0 = 0;
	char *our_ret;


	tempo = calcu_absolute_value(num);
	size = calcu_buffer_length(tempo, 10);


	if (num < 0 || number_0 < 0)
		size++;
	our_ret = malloc(size + 1);
	if (!our_ret)
		return (NULL);


	fill_buffer_with_base(tempo, 10, our_ret, size);
	if (num < 0 || number_0 < 0)
		our_ret[0] = '-';


	return (our_ret);
}

/**
 * calcu_buffer_length: This fucntion will gets length of.
 * @base: This base of number representation used by buffer.
 * @num: This number to get length needed for.
 * Author: Mikiashailu and Abdiali.
 * Return: this will return integer containing length of buffer needed.
 */
int calcu_buffer_length(unsigned int num, unsigned int base)
{
	int length_1 = 1;

	while (num > base - 1)
	{
		length_1++;
		num /= base;
	}
	return (length_1);
}

/**
 * calcu_absolute_value: This function will gets the absolute value of a number.
 * Author: Mikiashailu and Abdiali.
 * @i: This parameter is an integer to get absolutevalue.
 * Return: will return to the correct unsigned integer.
 */
unsigned int calcu_absolute_value(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
