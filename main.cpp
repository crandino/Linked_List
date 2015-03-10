#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char** argv)
{
	SList list1;
	printf("%d\n", list1.count());

	list1.add(-23);
	list1.add(16);
	list1.add(45);
	list1.add(0);
	list1.add(-33);
	list1.del(list1.getNodeAtPos(4));
	printf("%d\n", list1.count());

	list1.delAll();
	printf("%d\n", list1.count());

	
			
	system("pause");
	return 0;
}