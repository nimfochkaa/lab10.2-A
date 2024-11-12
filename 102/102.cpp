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
				{"Стефурак", 2, COMPUTER_SCIENCE, 4, 4, 4},
				{"Строган", 1, PHYSICS, 3, 5, 3},
				{"Котович", 2, MATH, 5, 3, 5}
			};

			int* indexArray = IndexSort(students, 3);

			Assert::AreEqual(students[indexArray[0]].lastName, string("Строган"));   
			Assert::AreEqual(students[indexArray[1]].lastName, string("Стефурак"));  
			Assert::AreEqual(students[indexArray[2]].lastName, string("Котович"));   

			delete[] indexArray;
		}
	};
}
