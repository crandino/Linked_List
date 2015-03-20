#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"


int main(int argc, char** argv)
{
	DList<float> dl1;

	dl1.add(5.0f);
	dl1.add(-36.87f);
	dl1.add(0.0f);
	
	dl1.del(dl1.getNodeAtPos(0));
	printf("%d", dl1.count());

	system("pause");
	return 0;
}