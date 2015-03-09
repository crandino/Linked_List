#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "LinkedList.h"


int main(int argc, char** argv)
{
	SList list1;
	printf("%d\n", list1.count());
	list1.add(45);
	list1.add(-33);
	list1.add(2);
	printf("%d\n", list1.count());
	int a = 40;
	int *p = &a;
	int *t = p;
	std::cout << p << " " << t << std::endl;

	
	system("pause");
	return 0;
}