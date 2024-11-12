#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 10.2 A/01A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My102
{
	TEST_CLASS(My102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student students[3] = {
				{"��������", 2, COMPUTER_SCIENCE, 4, 4, 4},
				{"�������", 1, PHYSICS, 3, 5, 3},
				{"�������", 2, MATH, 5, 3, 5}
			};

			int* indexArray = IndexSort(students, 3);

			Assert::AreEqual(students[indexArray[0]].lastName, string("�������"));   
			Assert::AreEqual(students[indexArray[1]].lastName, string("��������"));  
			Assert::AreEqual(students[indexArray[2]].lastName, string("�������"));   

			delete[] indexArray;
		}
	};
}
