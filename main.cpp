#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "Utilities.h"

int main(int argc, char** argv)
{
	DynArray<int> Arr1(4);

	printf("%p\n", Arr1.data);
	printf("%d\n", Arr1.allocated_memory);
	printf("%d\n", Arr1.num_elements);
	printf("%s\n", "-----------------------");

	Arr1.reallocate(10);
	//Arr1.pushBack(7);
	//Arr1.pushBack(300);

	
	
	system("pause");
	return 0;
}