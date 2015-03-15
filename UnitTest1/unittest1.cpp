#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// ------------------------------------
		// Test for SList Class
		// ------------------------------------
		
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
		TEST_METHOD(SListGetNodeAtPos)
		{
			SList<int> sl1;

			sl1.add(45);

			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(sl1.count() == 0);
		}
		TEST_METHOD(SListDel)
		{
			SList<float> sl1;

			sl1.add(45.3f);

			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(sl1.count() == 0);

			sl1.add(5.0f);
			sl1.add(-36.87f);
			sl1.add(0.0f);

			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(-1)) == false);
			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(3)) == false);
			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(2)) == true);
			Assert::IsTrue(sl1.count() == 2);
			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(1)) == true);
			Assert::IsTrue(sl1.del(sl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(sl1.count() == 0);

		}
		TEST_METHOD(SListDelAll)
		{
			SList<float> sl1;

			sl1.add(45.3f);
			sl1.add(5.0f);
			sl1.add(-36.87f);
			sl1.add(0.0f);

			Assert::IsTrue(sl1.count() == 4);
			Assert::IsTrue(sl1.delAll() == true);
			Assert::IsTrue(sl1.count() == 0);
		}

		// ------------------------------------
		// Test for DList Class
		// ----------------------

		// ------------------------------------
		// Test for DynArray Class
		// ------------------------------------
	



	};
}