#include "pch.h"
#include "gtest/gtest.h"
#include "../SecondLab/SortingAlgorithm.h"

using namespace std;

class Test_Algorithm : public ::testing::Test {
protected:
	int array_size = 10;
public:
	int* NewRandomArray() {
		int* array = new int[array_size];
		for (int i = 0; i < array_size; i++) array[i] = rand() % 100;
		return array;
	}

	int* NewSortedArray() {
		int* array = new int[array_size];
		for (int i = 0; i < array_size; i++) array[i] = i;
		return array;
	}
};


TEST_F(Test_Algorithm, Test_BinarySearch) {
	int* array = new int[array_size];
	array = NULL;
	//When array is NULL
	ASSERT_THROW(BinarySearch(array, array_size, 0), runtime_error);

	array = NewSortedArray();
	//Current array: 0 1 2 3 4 5 6 7 8 9, array is sorted
	//When size of array <= 0
	ASSERT_THROW(BinarySearch(array, 0, 5), invalid_argument);

	for (int i = 0; i < array_size; i++) ASSERT_EQ(BinarySearch(array, array_size, i), i);
	//When there are no elements in the array with the serch_value
	ASSERT_THROW(BinarySearch(array, array_size, 100), invalid_argument);

	array[9] = 0;
	//Current array: 0 1 2 3 4 5 6 7 8 0, array is not sorted
	ASSERT_THROW(BinarySearch(array, 4, 4), logic_error);

	delete[] array;
}

TEST_F(Test_Algorithm, Test_QuickSort) {
	int* array = new int[array_size];
	array = NULL;
	//When array is NULL
	ASSERT_THROW(QuickSort(array, 0, 7), runtime_error);
	
	array = NewRandomArray();
	//Current array may not be sorted
	//When low < 0
	ASSERT_THROW(QuickSort(array, -1, 5), invalid_argument);
	//When high < 0
	ASSERT_THROW(QuickSort(array, 0, -3), invalid_argument);
	//When low > high
	ASSERT_THROW(QuickSort(array, 3, 0), invalid_argument);

	ASSERT_NO_THROW(QuickSort(array, 0, array_size - 1));
	//Current array is definitely sorted
	for (int i = 0; i < array_size - 1; i++) ASSERT_LE(array[i], array[i + 1]);

	delete[] array;
}

TEST_F(Test_Algorithm, Test_BubbleSort) {
	int* array = new int[array_size];
	array = NULL;
	//When array is NULL
	ASSERT_THROW(BubbleSort(array, array_size), runtime_error);

	array = NewRandomArray();
	//Current array may not be sorted
	//When size of array <= 0
	ASSERT_THROW(BubbleSort(array, 0), invalid_argument);
	
	ASSERT_NO_THROW(BubbleSort(array, array_size));
	//Current array is definitely sorted
	for (int i = 0; i < array_size - 1; i++) ASSERT_LE(array[i], array[i + 1]);

	array[0] = 1;
	array[1] = 0;
	array[2] = 3;
	//Current array 1 0 3 ......., is not definitely sorted
	ASSERT_NO_THROW(BubbleSort(array, array_size));
	//Current array is definitely sorted
	for (int i = 0; i < array_size - 1; i++)
		ASSERT_LE(array[i], array[i + 1]);

	delete[] array;
}

TEST_F(Test_Algorithm, Test_BogoSort) {
	int* array = new int[array_size];
	array = NULL;
	//When array is NULL
	ASSERT_THROW(BogoSort(array, array_size), runtime_error);

	array = NewRandomArray();
	//Current array may not be sorted
	//When size of array <= 0
	ASSERT_THROW(BogoSort(array, 0), invalid_argument);

	ASSERT_NO_THROW(BogoSort(array, array_size));
	//Current array is definitely sorted
	for (int i = 0; i < array_size - 1; i++) ASSERT_LE(array[i], array[i + 1]);
 
	array[0] = 1;
	array[1] = 0;
	array[2] = 3;
	//Current array 1 0 3 ......., is not definitely sorted
	ASSERT_NO_THROW(BogoSort(array, array_size));
	//Current array is definitely sorted
	for (int i = 0; i < array_size - 1; i++)
		ASSERT_LE(array[i], array[i + 1]);

	delete[] array;
}

TEST_F(Test_Algorithm, Test_CountingSort) {
	string array = "hello";
	CountingSort(array);
	// Current array "ehllo"
	ASSERT_EQ(array[0], 'e');
	ASSERT_EQ(array[1], 'h');
	ASSERT_EQ(array[2], 'l');
	ASSERT_EQ(array[3], 'l');
	ASSERT_EQ(array[4], 'o');
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
