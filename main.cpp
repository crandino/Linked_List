#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "DList.h"
#include "DynArray.h"
#include <iostream>

int main(int argc, char** argv)
{
	DynArray<int> Arr1;

	Arr1.pushBack(7);
	Arr1.info();
	Arr1.pushBack(29);
	Arr1.info();
	Arr1.insert(99, 0);
	Arr1.info();
	Arr1.insert(1000, 20);
	Arr1.info();
	Arr1.pop();
	Arr1.info();
	Arr1.insert(100, 2);
	Arr1.info();
	Arr1[1] = 777;
	std::cout << Arr1[1] << std::endl;
	printf("%d\n", Arr1[1]);
	
	
	

	system("pause");
	return 0;
}