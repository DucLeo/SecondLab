#include <iostream>
#include <random>
#include <chrono>
#include <string>


using namespace std;

void swap(int* x, int* y) {
	int temp = *y;
	*y = *x;
	*x = temp;
}


bool isSorted(int* array, int array_size) {
	bool reply = 1;
	for (int i = 0; i < array_size - 1; i++) {
		if (array[i] > array[i + 1]) reply = 0;
	}
	return reply;
}


int BinarySearch(int* array, int array_size, int search_value) {
	if (array == NULL) throw std::runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0) throw std::invalid_argument("Size of array is less than zero.");
	if (!isSorted(array, array_size)) throw std::logic_error("Array is not sorted in ascending order.");
	int left = 0, right = array_size - 1;
	int mid = (left + right) / 2;
	bool found = 0;
	while ((!found) && (left <= right)) {
		if (array[mid] == search_value) found = 1;
		else {
			if (array[mid] < search_value) left = mid + 1;
			else right = mid - 1;
			mid = (left + right) / 2;
		}
	}
	if (found == 1) return mid;
	else throw std::invalid_argument("There are no elements in the array with the value you requested!");
}

void QuickSort(int* array, int low, int high) {
	if (array == NULL) throw runtime_error("Pointer to array is nullptr.");
	if (low < 0 || high <= 0) throw invalid_argument("Index low or index high is less than zero.");
	if (low > high) throw invalid_argument("Index low is more than index high.");
	int left = low, right = high;
	int mid = (left + right) / 2;
	int pivot = array[mid];
	while (left <= right) {
		while (array[left] < pivot) left++;
		while (array[right] > pivot) right--;
		if (left <= right) {
			swap(&array[left], &array[right]);
			left++;
			right--;
		}
	}
	if (right > low) QuickSort(array, low, right);
	if (left < high) QuickSort(array, left, high);
}


void BubbleSort(int* array, int array_size) {
	if (array == NULL) throw runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0) throw invalid_argument("Size of array is less than zero.");
	bool haveSwap = false;
	for (int i = 0; i < array_size - 1; i++) {
		haveSwap = false;
		for (int j = 0; j < array_size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false) break;
	}
}


void BogoSort(int* array, int array_size) {
	if (array == NULL) throw runtime_error("Pointer to array is nullptr.");
	if (array_size <= 0) throw invalid_argument("Size of array is less than zero.");
	while (!isSorted(array, array_size)) {
		for (int i = 0; i < array_size; i++)
			swap(&array[i], &array[rand() % array_size]);
	}
}

void CountingSort(string& input_array) {
	char* output_array = new char[input_array.length()];
	int count_array[256], i;
	fill_n(count_array, 256, 0);
	for (i = 0; input_array[i]; ++i) ++count_array[input_array[i]];
	for (i = 1; i < 256; ++i) count_array[i] += count_array[i - 1];
	for (i = 0; input_array[i]; ++i) {
		output_array[count_array[input_array[i]] - 1] = input_array[i];
		--count_array[input_array[i]];
	}
	for (i = 0; input_array[i]; ++i) input_array[i] = output_array[i];

	delete[] output_array;
}


void CompareQuickSortAndBubbleSort() {
	int data_size = 10;
	int array_size = 100000;
	int* array_QuickSort = new int[array_size];
	int* array_BubbleSort = new int[array_size];

	while (data_size <= 100000) {
		double time_QuickSort = 0;
		double time_BubbleSort = 0;
		for (int i = 0; i < 10; i++) {
			mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
			uniform_int_distribution<> range(-data_size, data_size);

			for (int i = 0; i < data_size; i++) {
				array_QuickSort[i] = range(generator);
				array_BubbleSort[i] = array_QuickSort[i];
			}

			auto start = chrono::high_resolution_clock::now();

			QuickSort(array_QuickSort, 0, array_size - 1);

			auto finish = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start);

			time_QuickSort += finish.count();

			start = chrono::high_resolution_clock::now();

			BubbleSort(array_BubbleSort, array_size);

			finish = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start);

			time_BubbleSort += finish.count();
		}

		cout << "Size of data: [" << -data_size << ";" << data_size << "]" << endl;
		cout << "Time of QuickSort : " << time_QuickSort / 10000000000  << " (s)" << endl;
		cout << "Time of BubbleSort: " << time_BubbleSort / 10000000000  <<" (s)" << endl;
		cout << endl;
		data_size *= 10;
	}
}
