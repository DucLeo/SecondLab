#include<iostream>
#include "SortingAlgorithm.h"
using namespace std;

int main() {
	int* array = new int[10]{ 11, 19, 20, 33, 41, 41, 52, 78, 79, 93 };
	cout << "Array:  ";
	for (int i = 0; i < 10; i++) cout << array[i] << "  ";
	cout << "\nElement 33 is at position: " << BinarySearch(array, 10, 33) << endl;
	delete[] array;

	array = new int[15]{ 29, 16, 11, 66, 17, 13, 14, 27, 25, 16, 18 ,45, 40, 36, 10};
	cout << "\nArray before using QuickSort: ";
	for (int i = 0; i < 15; i++) cout << array[i] << "  ";
	QuickSort(array, 1, 13);
	cout << "\nArray after  using QuickSort: ";
	for (int i = 0; i < 15; i++) cout << array[i] << "  ";
	cout << endl;
	delete[] array;

	array = new int[5]{ 19, 12, 14, 12, 21 };
	cout << "\nArray before using BubbleSort: ";
	for (int i = 0; i < 5; i++) cout << array[i] << "  ";
	BubbleSort(array, 5);
	cout << "\nArray after  using BubbleSort: ";
	for (int i = 0; i < 5; i++) cout << array[i] << "  ";
	cout << endl;
	delete[] array;

	array = new int[10]{ 25, 42, 74, 26, 13, 56, 42, 37, 50, 10};
	cout << "\nArray before using BogoSort: ";
	for (int i = 0; i < 10; i++) cout << array[i] << "  ";
	BogoSort(array, 10);
	cout << "\nArray after  using BogoSort: ";
	for (int i = 0; i < 10; i++) cout << array[i] << "  ";
	cout << endl;
	delete[] array;

	string char_array = "spiderman";
	cout << "\nThe string before using CountingSort:  " << char_array << endl;
	CountingSort(char_array);
	cout << "The string after  using CountingSort:  " << char_array << endl;

	cout << "\nCompare Quicksort and BubbleSort:" << endl << endl;
	CompareQuickSortAndBubbleSort();

	return 0;
}

