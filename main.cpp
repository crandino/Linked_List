#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"


int main(int argc, char** argv)
{
	DList<float> dl1;

	dl1.add(45.3f);

	dl1.del(dl1.getNodeAtPos(0));
	dl1.info();

	dl1.add(5.0f);
	dl1.add(-36.87f);
	dl1.add(0.0f);

	dl1.del(dl1.getNodeAtPos(-1));
	dl1.del(dl1.getNodeAtPos(3));
	dl1.info();
	dl1.del(dl1.getNodeAtPos(2));
	dl1.info();

	
	system("pause");
	return 0;
}