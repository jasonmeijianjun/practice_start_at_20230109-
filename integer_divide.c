#include <stdio.h>
#include <stdlib.h>

int dividecore(int divident, int divisor) 
{
	int result = 0;
	while(divident  <= divisor) {
		int value = divisor;
		int quotient = 1;
		while( value > 0xc0000000 && divident <= value + value ) {
			quotient += quotient;
			value += value;
		}
		result += quotient;
		divident -= value;
	}
	return result;
}

int main(int argc, char ** argv)
{
	int divident, divisor, value;
	int negative = 2;
	if(argc != 3 ) {
		printf("Error parameters\n");
		return -1;
	}
 
	divident = atoi(argv[1]);
	divisor = atoi(argv[2]);
	printf("divident = %d divisor = %d\n",divident, divisor);

	/*overflow: divident = 0x80000000 && divisor = -1 */
	if(divident == 0x80000000 && divisor == -1) {
		value = 0x7fffffff;
		printf("value = %d\n",value);
		return value;
		
	}

	if(divident > 0) {
		negative--;
		divident = -divident;
	}

	if(divisor > 0) {
		negative--;
		divisor = -divisor;
	}

	value = dividecore(divident, divisor);

	value = (negative == 1)?-value:value;

	printf("value = %d\n",value);
}
