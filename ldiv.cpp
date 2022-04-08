// ldiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void divs(int x, int y)
{
	int res = 0;
	int count = 0;
	bool recurse = false;
	static int recursecount = 0;

	while (res < y)
	{
		count++;
		res = count * x;
	}

	// check for remainder
	if( (res > y) && (recursecount <10))
	{
		recursecount++;
		recurse = true;
		count--;
		res = count*x;
		fprintf(stderr, "%d", count);
		if (recursecount == 1)
		{
			fprintf(stderr, ".", count);
		}
		divs(x, (y - res) * 10);
	}

	if (!recurse)
	{
		fprintf(stderr, "%d", count);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x[2] = { 3, 1 };
	divs(x[0], x[1]);

	return 0;
}

