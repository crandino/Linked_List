#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"


int main(int argc, char** argv)
{
	DList list1;
	
	list1.add(23);
	list1.add(16);
	list1.add(10);
	list1.add(99);
	list1.info();

	list1.del(list1.getNodeAtPos(2));

	list1.info();
	
				
	system("pause");
	return 0;
}