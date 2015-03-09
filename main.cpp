#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char** argv)
{
	SList list1;
	printf("%d\n", list1.count());

	list1.add(45);
	list1.add(-33);
	list1.add(2);
	printf("%d\n", list1.count());
	
	printf("%p\n", list1.getNodeAtPos(0));
	printf("%p\n", list1.getNodeAtPos(1));
	printf("%p\n", list1.getNodeAtPos(2));
	printf("%p\n", list1.getNodeAtPos(-34));
	printf("%p\n", list1.getNodeAtPos(10));
	printf("%p\n", list1.getNodeAtPos(32));
	printf("%p\n", list1.getNodeAtPos(35));
		
	printf("%s\n", "---------------------");
	list1.del(list1.getNodeAtPos(1));
	printf("%p\n", list1.getNodeAtPos(0));
	printf("%p\n", list1.getNodeAtPos(1));
	printf("%p\n", list1.getNodeAtPos(2));
	printf("%d\n", list1.count());

		
	system("pause");
	return 0;
}