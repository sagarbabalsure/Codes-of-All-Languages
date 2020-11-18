#include <stdio.h>

void printthefunc()
{
        static int x = 0;
	printf("%d\n", x);
	x++;
}

int main()
{
	printthefunc();
	printthefunc();
	printthefunc();
	printthefunc();

}
