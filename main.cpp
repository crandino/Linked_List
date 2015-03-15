#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include "Utilities.h"

int main(int argc, char** argv)
{
	DynArray<int> Arr1;

	Arr1.pushBack(7);
	Arr1.pushBack(11);
	Arr1.pop();
	Arr1.pop();
	
	/*printf("%p\n", Arr1.data);
	printf("%d\n", Arr1.allocated_memory);
	printf("%d\n", Arr1.num_elements);
	printf("%s\n", "-----------------------");	*/

	system("pause");
	return 0;
}