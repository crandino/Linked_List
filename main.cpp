#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)
// Moverlas a un archivo utilities.h!

int main(int argc, char** argv)
{

	int i = 5;
	float *arr = new float[i];
	arr[4] = 4.5f;
	arr[0] = 4.3f;

	int a = MIN(4, 4);
	printf("%d\n", a);

	DList list1;
	list1.info();
	
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