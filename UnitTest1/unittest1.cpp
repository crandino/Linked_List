#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SListConstructor)
		{
			SList<int> sl1;

			Assert::IsTrue(sl1.count() == 0);
			Assert::IsFalse(sl1.del(sl1.getNodeAtPos(0)) == true);
			Assert::IsNull(sl1.getNodeAtPos(3));

			SList<float> sl2;

			Assert::IsTrue(sl2.count() == 0);
			Assert::IsFalse(sl2.del(sl2.getNodeAtPos(0)) == true);
			Assert::IsNull(sl2.getNodeAtPos(3));
		}

		TEST_METHOD(SListCount)
		{
			SList<int> sl1;

			sl1.add(45);
			sl1.add(2);

			Assert::IsTrue(sl1.count() == 2);
			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(sl1.delAll() == true);
		}

	};
}