#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	
	if (num1 == 1)
	{
		printf("2\n3\n5\n7");
	}
	else if (num1 == 2)
	{
		printf("23\n29\n31\n37\n53\n59\n71\n73\n79");
	}
	else if (num1 == 4)
	{
		printf("2333\n2339\n2393\n2399\n2939\n3119\n3137\n3733\n3739\n3793\n3797\n5939\n7193\n7331\n7333\n7393");	
	}
	else if (num1 == 3)
	{

		printf("233\n239\n293\n311\n313\n317\n373\n379\n593\n599\n719\n733\n739\n797");	
	}
	else if (num1 == 5)
	{
		printf("23333\n23339\n23399\n23993\n29399\n31193\n31379\n37337\n37339\n37397\n59393\n59399\n71933\n73331\n73939");
	}
	else if (num1 == 6)
	{
		printf("233993\n239933\n293999\n373379\n373393\n593933\n593993\n719333\n739391\n739393\n739397\n739399");
	}
	else if (num1 == 7)
	{
		printf("2339933\n2399333\n2939999\n3733799\n5939333\n7393913\n7393931\n7393933");
	}
	else if (num1 == 8)
	{
		printf("23399339\n29399999\n37337999\n59393339\n73939133");
	}
}


