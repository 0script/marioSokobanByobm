#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int iNbjours[13], i;
	for(i=1;i<13;i++)
	{
		if(i==2)
			iNbjours[i]=28;
		else if((!(i%2) && i<=7) || ((i%2) && i>7))
			iNbjours[i]=30;
		else
				iNbjours[i]=31;
	}
}
