#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SList.h"
#include "../DList.h"
#include "../DynArray.h"
#include "../String.h"
#include "../String.cpp"
#include "../Point2d.h"
#include "../Point2d.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		// ----------------------------
		// Tests for Point2d Class
		// ----------------------------

		TEST_METHOD(Point2dSum)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p3 = p1 + p2;

			Assert::IsTrue(p3.x == 2.f && p3.y == 4.f);
		}
		TEST_METHOD(Point2dDiff)
		{
			Point2d p1, p2, p3;
			p1.x = p1.y = 1.f;
			p2.x = p2.y = 2.f;

			p3 = p1 - p2;
			Assert::IsTrue(p3.x == -1.f && p3.y == -1.f);
			p3 = p2 - p1;
			Assert::IsTrue(p3.x == 1.f && p3.y == 1.f);
		}
		TEST_METHOD(Point2dSumAssig)
		{
			Point2d p1, p2;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p1 += p2;
			Assert::IsTrue(p1.x == 2.f && p1.y == 4.f);
			p2 += p1;
			Assert::IsTrue(p2.x == 3.f && p2.y == 6.f);
		}
		TEST_METHOD(Point2dDiffAssig)
		{
			Point2d p1, p2;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p1 -= p2;
			Assert::IsTrue(p1.x == 0.f && p1.y == 0.f);
			p2 -= p1;
			Assert::IsTrue(p2.x == 1.f && p2.y == 2.f);
		}
		TEST_METHOD(Point2dEquality)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsTrue(p1 == p2);
			Assert::IsFalse(p1 == p3);
		}
		TEST_METHOD(Point2dInequality)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsFalse(p1 != p2);
			Assert::IsTrue(p1 != p3);
		}
		TEST_METHOD(Point2dSetZero)
		{
			Point2d p1;
			p1.setZero();

			Assert::IsTrue(p1.x == 0 && p1.y == 0);
			Assert::IsFalse(p1.x != 0 && p1.y != 0);
		}
		TEST_METHOD(Point2dIsBothZero)
		{
			Point2d p1;
			p1.setZero();

			Assert::IsTrue(p1.isBothZero());
			p1.x = 2;
			Assert::IsFalse(p1.isBothZero());
		}
		TEST_METHOD(Point2dDistanceTo)
		{
			Point2d p1, p2;
			p1.setZero();
			p2.x = 3;
			p2.y = -4;

			Assert::IsTrue(p1.distanceTo(p2) == 5.f);
		}

		// ----------------------------
		// Tests for String Class
		// ----------------------------

		TEST_METHOD(StringConstrEmpty)
		{
			String s1;

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringConstrChar)
		{
			String s1("Hello");
			char *p2 = "Dog";
			String s2 = p2;
			char *p3 = NULL;
			String s3 = p3;
			String s4("%s %d %s", "I am", 27, "years old");

			Assert::IsTrue(s1 == "Hello");
			Assert::IsTrue(s2 == "Dog");
			Assert::IsTrue(s3 == "");
			Assert::IsTrue(s4 == "I am 27 years old");
		}
		TEST_METHOD(StringConstrString)
		{
			String s1;
			String s2(s1);
			String s3("Hello");
			String s4(s3);

			Assert::IsTrue(s1 == "");
			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s3 == "Hello");
			Assert::IsTrue(s3 == s4);
		}
		TEST_METHOD(StringEqualityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello";

			Assert::IsTrue(s1 == "Hello");
			Assert::IsFalse(s1 == p1);
			Assert::IsTrue(s1 == p2);
		}
		TEST_METHOD(StringInequalityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello, darling";

			Assert::IsTrue(s1 != "Hello, darling");
			Assert::IsTrue(s1 != p1);
			Assert::IsTrue(s1 != p2);
		}
		TEST_METHOD(StringEqualityString)
		{
			String s1("Hello");
			String s2("Hello");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(StringInequalityString)
		{
			String s1("Hello");
			String s2("Hello, darling...");

			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(StringAssignChar)
		{
			String s1("Hello");
			String s2 = "Hello, darling...";
			char *p = NULL;
			String s3 = p;
			String s4 = "Hello";

			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s3);
			Assert::IsTrue(s1 == s4);
		}
		TEST_METHOD(StringAssignString)
		{
			String s1("Hello");
			String s2 = s1;
			String s3("Hello, darling...");
			String s4 = s3;

			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s1 != s4);
		}
		TEST_METHOD(StringConcatChar)
		{
			String s1("Hello");
			s1 += "world";
			Assert::IsTrue(s1 == "Helloworld");
			char *p = NULL;
			s1 += p;
			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(StringConcatString)
		{
			String s1("Hello");
			String s2("world");
			s1 += s2;
			Assert::IsTrue(s1 == "Helloworld");
		}
		TEST_METHOD(StringGetLength)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.getLength() == 5);
			Assert::IsTrue(s2.getLength() == 0);
		}
		TEST_METHOD(StringCapacity)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.capacity() == 6);
			Assert::IsTrue(s2.capacity() == 1);
		}
		TEST_METHOD(StringGetString)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(strcmp(s1.getString(), "Hello") == 0);
			Assert::IsTrue(strcmp(s2.getString(), "") == 0);
		}
		TEST_METHOD(StringClear)
		{
			String s1("Hello");
			s1.clear();

			Assert::IsTrue(strcmp(s1.getString(), "") == 0);
		}

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
			//Assert::IsTrue(dl1.clear() == true);
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

			dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);

			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(-1)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(3)) == false);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(2)) == true);
			Assert::IsTrue(dl1.count() == 2);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(1)) == true);
			Assert::IsTrue(dl1.del(dl1.getNodeAtPos(0)) == true);
			Assert::IsTrue(dl1.count() == 0);

		}
		TEST_METHOD(DListDelAll)
		{
			DList<float> dl1;

			dl1.add(45.3f);
			dl1.add(5.0f);
			dl1.add(-36.87f);
			dl1.add(0.0f);

			Assert::IsTrue(dl1.count() == 4);
			dl1.clear();
			Assert::IsTrue(dl1.count() == 0);
		}
		TEST_METHOD(DListGetFirst)
		{
			DList<float> dl1;
			Assert::IsNull(dl1.getFirst());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getFirst());

			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::IsNotNull(dl1.getFirst());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getFirst());
		}
		TEST_METHOD(DListGetLast)
		{
			DList<float> dl1;
			Assert::IsNull(dl1.getLast());
			Assert::IsTrue(dl1.getNodeAtPos(0) == dl1.getLast());

			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::IsNotNull(dl1.getLast());
			Assert::IsTrue(dl1.getNodeAtPos(1) == dl1.getLast());
		}
		TEST_METHOD(DListOperatorSquareBrackets)
		{
			DList<float> dl1;
			dl1.add(2.0f);
			dl1.add(3.0f);

			Assert::AreEqual(dl1[0], 2.0f);
			Assert::AreEqual(dl1[1], 3.0f);
		}

		TEST_METHOD(DListSortingCopy)
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

			d.sort_copy();

			for (unsigned int i = 0; i < d.count() - 1; i++)
				Assert::IsTrue(d[i] <= d[i + 1]);
		}

		/*TEST_METHOD(DListSortingReference)
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

			for (unsigned int i = 0; i < d.count() - 1; i++)
				Assert::IsTrue(d[i] <= d[i + 1]);
		}*/


		// ------------------------------------
		// Test for DynArray Class
		// ------------------------------------
		TEST_METHOD(DynArrayConstruct1)
		{
			DynArray<int> dyn1;

			Assert::IsTrue(dyn1.getMemory() == 16);
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
			Assert::IsTrue(dyn1.getMemory() == 16);
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
			int a;
			DynArray<int> dyn1;
			dyn1.pushBack(13);
			dyn1.pop(a);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			dyn1.pop(a);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);

			float b;
			DynArray<float> dyn2;
			Assert::IsFalse(dyn2.pop(b));
			Assert::IsTrue(dyn2.getMemory() == 16);
			Assert::IsTrue(dyn2.getNumElements() == 0);

			DynArray<float> dyn3(6);
			dyn3.pushBack(3);
			dyn3.pushBack(4);
			dyn3.pushBack(5);
			Assert::IsTrue(dyn3.pop(b));
			Assert::IsTrue(dyn3.getMemory() == 6);
			Assert::IsTrue(dyn3.getNumElements() == 2);
		}
		TEST_METHOD(DynArrayInsert)
		{
			DynArray<int> dyn1;
			Assert::IsTrue(dyn1.insert(13,1) == false);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 0);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 1);
			dyn1.pushBack(11);
			dyn1.pushBack(12);
			dyn1.pushBack(13);
			Assert::IsTrue(dyn1.insert(12, 0) == true);
			Assert::IsTrue(dyn1.insert(12, 2) == true);
			Assert::IsTrue(dyn1.getMemory() == 16);
			Assert::IsTrue(dyn1.getNumElements() == 6);	
		}
		TEST_METHOD(DynArrayOperatorClaudator)
		{
			DynArray<int> dyn1;
			dyn1.pushBack(8);
			Assert::IsTrue(dyn1[0] == 8);
		}

		TEST_METHOD(DynArrayFlip)
		{
			DynArray<unsigned int> dyn1;
			dyn1.pushBack(1);
			dyn1.pushBack(2);
			dyn1.pushBack(3);
			dyn1.pushBack(4);
			dyn1.pushBack(5);
			dyn1.pushBack(6);
			dyn1.pushBack(7);

			dyn1.flip();
			
			for (unsigned int i = 0, j = 7; i < dyn1.getNumElements(); i++, j--)
				Assert::AreEqual(dyn1[i], j);
		}

	};
}