#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"


int main(int argc, char** argv)
{
	DList<int> d;

	d.add(5);
	d.add(4);
	d.add(10);
	d.add(8);
	d.add(3);
	d.add(3);
	d.add(-63);
	d.add(22);
	d.add(0);
	d.add(16);
	d.add(-9);
	d.add(-6);
	d.add(15);
	d.add(1);
	d.add(0);

	d.sort_reference();

	d.info();

	
	system("pause");
	return 0;
}