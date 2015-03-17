#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SList.h"
#include "../DList.h"
#include "../DynArray.h"

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
		TEST_METHOD(DListConstructor)
		{
			DList<int> dl1;

			Assert::IsTrue(dl1.count() == 0);
			Assert::IsFalse(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsNull(dl1.getNodeAtPos(3));

			SList<float> dl2;

			Assert::IsTrue(dl2.count() == 0);
			Assert::IsFalse(dl2.del(dl2.getNodeAtPos(0)) == true);
			Assert::IsNull(dl2.getNodeAtPos(3));
		}

		TEST_METHOD(DListCount)
		{
			DList<int> dl1;

			dl1.add(45);
			dl1.add(2);

			Assert::IsTrue(dl1.count() == 2);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.delAll() == true);
		}
		TEST_METHOD(DListGetNodeAtPos)
		{
			DList<int> dl1;

			dl1.add(45);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);
		}
		TEST_METHOD(DListDel)
		{
			DList<float> dl1;

			dl1.add(45.3f);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);

			/*dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);*/

			/*Assert::IsTrue(dl1.del(dl1.getNodeAtPos(-1)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(3)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(2)) == true);
			Assert::IsTrue(dl1.count() == 2);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(1)) == true);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);*/

		}
		TEST_METHOD(DListDelAll)
		{
			DList<float> dl1;

			dl1.add(45.3f);
			dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);

			Assert::IsTrue(dl1.count() == 4);
			Assert::IsTrue(dl1.delAll() == true);
			Assert::IsTrue(dl1.count() == 0);
		}

		// ------------------------------------
		// Test for DynArray Class
		// ------------------------------------
		TEST_METHOD(DynArrayConstruct1)
		{
			DynArray<int> dyn1;

			Assert::IsTrue(dyn1.getMemory() == 0);
			Assert::IsTrue(dyn1.getNumElements() == 0);
		}
		TEST_METHOD(DynArrayConstruct2)
		{
			DynArray<int> dyn1(5);

			Assert::IsTrue(dyn1.getMemory() == 5);
			Assert::IsTrue(dyn1.getNumElements() == 0);
		}
		TEST_METHOD(DynArrayPushBack)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(13);
			Assert::IsTrue(dyn1.getMemory() == 1);
			Assert::IsTrue(dyn1.getNumElements() == 1);

			DynArray<double> dyn2(1);
			dyn2.pushBack(13.99823);
			dyn2.pushBack(13.29234);
			Assert::IsTrue(dyn2.getMemory() == 2);
			Assert::IsTrue(dyn2.getNumElements() == 2);

			DynArray<double> dyn3(4);
			dyn3.pushBack(13.99823);
			dyn3.pushBack(13.29234);
			Assert::IsTrue(dyn3.getMemory() == 4);
			Assert::IsTrue(dyn3.getNumElements() == 2);
		}
		TEST_METHOD(DynArrayPop)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(13);
			dyn1.pop();
			Assert::IsTrue(dyn1.getMemory() == 1);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			dyn1.pop();
			Assert::IsTrue(dyn1.getMemory() == 1);
			Assert::IsTrue(dyn1.getNumElements() == 0);

			DynArray<float> dyn2;
			Assert::IsTrue(dyn2.pop() == -1);
			Assert::IsTrue(dyn2.getMemory() == 0);
			Assert::IsTrue(dyn2.getNumElements() == 0);

			DynArray<float> dyn3(6);
			dyn3.pushBack(3);
			dyn3.pushBack(4);
			dyn3.pushBack(5);
			Assert::IsTrue(dyn3.pop() == 5);
			Assert::IsTrue(dyn3.getMemory() == 6);
			Assert::IsTrue(dyn3.getNumElements() == 2);
		}
		TEST_METHOD(DynArrayInsert)
		{
			DynArray<int> dyn1;
			Assert::IsTrue(dyn1.insert(13,1) == false);
			Assert::IsTrue(dyn1.getMemory() == 0);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.getMemory() == 1);
			Assert::IsTrue(dyn1.getNumElements() == 1);
			dyn1.pushBack(11);
			dyn1.pushBack(12);
			dyn1.pushBack(13);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.insert(12, 2) == true);
			Assert::IsTrue(dyn1.getMemory() == 6);
			Assert::IsTrue(dyn1.getNumElements() == 6);	
		}
		TEST_METHOD(DynArrayOperatorClaudator)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(8);
			Assert::IsTrue(dyn1[0] == 8);
		}

	};
}