#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include <iostream>

int main(int argc, char** argv)
{
	DynArray<int> Arr1;

	Arr1.insert(0, 0);
	Arr1.info();
	
	
	

	system("pause");
	return 0;
}