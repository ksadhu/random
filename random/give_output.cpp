#include <stdio.h>
int main()
{
	int x=10 , y=10, z=10;
	x &= x|3;
	y = y&y|3;
	z &= z|= 3;
	printf("%d %d %d\n",x,y,z);
	return 0;
}
