#include "gtest/gtest.h"
#include "../opencv/sorting_algorithms.cpp"
#include "../opencv/swap.cpp"
#include <time.h>
#include <opencv2/opencv.hpp>

class TestSortingAlgorithms : public testing::Test
{

protected:

	std::vector<int> randomList;
	std::vector<int> nearlySortedList;
	std::vector<int> reversedList;
	std::vector<int> fewUniqueList;

	virtual void SetUp()
	{
		srand(time(NULL));
		int randomListSize = rand() % 400 + 100;
		for (int i = 0; i < randomListSize; i++) {
			randomList.push_back(rand());
		}

		for (int i = 0; i < randomListSize; i++) {
			nearlySortedList.push_back(i);
			if (i % 4 == 0) {
				nearlySortedList.at(i) = i + 3;
			}
		}

		for (int i = randomListSize; i > 0; i--) {
			reversedList.push_back(i);
		}

		for (int i = 0; i < randomListSize; i++) {
			int number = i % 4;
			fewUniqueList.push_back(number);

		}
	}
};

TEST_F(TestSortingAlgorithms, isAscendingTrueBubbleSort)
{
	std::vector<int> resultList = bubbleSort(randomList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueBubbleSort)
{
	std::vector<int> resultList = bubbleSort(randomList, false);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isSameSizeTrueBubbleSort)
{
	std::vector<int> resultListAsc = bubbleSort(randomList, true);
	std::vector<int> resultListDesc = bubbleSort(randomList, false);

	EXPECT_TRUE(resultListAsc.size() == randomList.size());
	EXPECT_TRUE(resultListDesc.size() == randomList.size());
}

TEST_F(TestSortingAlgorithms, isSameSumTrueBubbleSort)
{
	std::vector<int> resultListAsc = bubbleSort(randomList, true);
	std::vector<int> resultListDesc = bubbleSort(randomList, false);
	int sumAsc = 0;
	int sumDesc = 0;
	int sumOrigin = 0;
	for (int i = 0; i < randomList.size(); i++) {
		sumAsc += resultListAsc[i];
		sumDesc += resultListDesc[i];
		sumOrigin += randomList[i];
	}

	EXPECT_TRUE(sumAsc == sumDesc);
	EXPECT_TRUE(sumAsc == sumOrigin);
	EXPECT_TRUE(sumDesc == sumOrigin);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescBubbleSort) {
	std::vector<int> resultAsc = bubbleSort(randomList, true);
	std::vector<int> resultDesc = bubbleSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectorsBubbleSort)
{
	std::vector<int> resultListNearlySorted = bubbleSort(nearlySortedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListNearlySorted[i] <= resultListNearlySorted[i + 1]);
	}

	EXPECT_TRUE(resultListNearlySorted[0] < resultListNearlySorted[resultListNearlySorted.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectors2BubbleSort)
{
	std::vector<int> resultListReversed = bubbleSort(reversedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListReversed[i] <= resultListReversed[i + 1]);
	}

	EXPECT_TRUE(resultListReversed[0] < resultListReversed[resultListReversed.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectors3BubbleSort)
{
	std::vector<int> resultListFewUnique = bubbleSort(fewUniqueList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListFewUnique[i] <= resultListFewUnique[i + 1]);
	}

	EXPECT_TRUE(resultListFewUnique[0] < resultListFewUnique[resultListFewUnique.size() - 1]);
}

TEST_F(TestSortingAlgorithms, vectorSameSizeCountingSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = countSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, vectorAscendingTrueCountingSort) {
	std::vector<int>resultList = countSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, vectorDescendingTrueCountingSort) {
	std::vector<int>resultList = countSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescCountingSort) {
	std::vector<int> resultListAsc = countSort(randomList, true);
	std::vector<int> resultListDesc = countSort(randomList, false);
	for (int i = 0; i < resultListAsc.size() - 1; i++) {

		EXPECT_EQ(resultListAsc[i], resultListDesc[resultListDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListCountingSort) {
	std::vector<int>resultList = countSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListCountingSort) {
	std::vector<int>resultList = countSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListCountingSort) {
	std::vector<int>resultList = countSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSameHeapSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = heapSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueHeapSort) {
	std::vector<int>resultList = heapSort(randomList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueHeapSort) {
	std::vector<int>resultList = heapSort(randomList, false);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescHeapSort) {
	std::vector<int> resultAsc = heapSort(randomList, true);
	std::vector<int> resultDesc = heapSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListHeapSort) {
	std::vector<int>resultList = heapSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListHeapSort) {
	std::vector<int>resultList = heapSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListHeapSort) {
	std::vector<int>resultList = heapSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSameInsertionSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = insertionSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueInsertionSort) {
	std::vector<int>resultList = insertionSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueInsertionSort) {
	std::vector<int>resultList = insertionSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescInsertionSort) {
	std::vector<int> resultAsc = insertionSort(randomList, true);
	std::vector<int> resultDesc = insertionSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListInsertionSort) {
	std::vector<int>resultList = insertionSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListInsertionSort) {
	std::vector<int>resultList = insertionSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListInsertionSort) {
	std::vector<int>resultList = insertionSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueMergeSort)
{
	std::vector<int> resultList = mergeSort(randomList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueMergeSort)
{
	std::vector<int> resultList = mergeSort(randomList, false);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isSameSizeTrueMergeSort)
{
	std::vector<int> resultListAsc = mergeSort(randomList, true);
	std::vector<int> resultListDesc = mergeSort(randomList, false);

	EXPECT_TRUE(resultListAsc.size() == randomList.size());
	EXPECT_TRUE(resultListDesc.size() == randomList.size());
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescMergeSort) {
	std::vector<int> resultAsc = mergeSort(randomList, true);
	std::vector<int> resultDesc = mergeSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectorsMergeSort)
{
	std::vector<int> resultListNearlySorted = mergeSort(nearlySortedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListNearlySorted[i] <= resultListNearlySorted[i + 1]);
	}

	EXPECT_TRUE(resultListNearlySorted[0] < resultListNearlySorted[resultListNearlySorted.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectors2MergeSort)
{
	std::vector<int> resultListReversed = mergeSort(reversedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListReversed[i] <= resultListReversed[i + 1]);
	}

	EXPECT_TRUE(resultListReversed[0] < resultListReversed[resultListReversed.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueOtherTypeOfVectors3MergeSort)
{
	std::vector<int> resultListFewUnique = mergeSort(fewUniqueList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListFewUnique[i] <= resultListFewUnique[i + 1]);
	}

	EXPECT_TRUE(resultListFewUnique[0] < resultListFewUnique[resultListFewUnique.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSamePancakeSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = pancakeSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTruePancakeSort) {
	std::vector<int>resultList = pancakeSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTruePancakeSort) {
	std::vector<int>resultList = pancakeSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescPancakeSort) {
	std::vector<int> resultAsc = pancakeSort(randomList, true);
	std::vector<int> resultDesc = pancakeSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListPancakeSort) {
	std::vector<int>resultList = pancakeSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListPancakeSort) {
	std::vector<int>resultList = pancakeSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListPancakeSort) {
	std::vector<int>resultList = pancakeSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSameQuickSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = quickSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueQuickSort) {
	std::vector<int>resultList = quickSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}
}

TEST_F(TestSortingAlgorithms, isDescendingTrueQuickSort) {
	std::vector<int>resultList = quickSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescQuickSort) {
	std::vector<int> resultAsc = quickSort(randomList, true);
	std::vector<int> resultDesc = quickSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListQuickSort) {
	std::vector<int>resultList = quickSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListQuickSort) {
	std::vector<int>resultList = quickSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListQuickSort) {
	std::vector<int>resultList = quickSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, vectorSameSizeSelectionSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = selectionSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, vectorAscendingTrueSelectionSort) {
	std::vector<int>resultList = selectionSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, vectorDescendingTrueSelectionSort) {
	std::vector<int>resultList = selectionSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescSelectionSort) {
	std::vector<int> resultListAsc = selectionSort(randomList, true);
	std::vector<int> resultListDesc = selectionSort(randomList, false);
	for (int i = 0; i < resultListAsc.size() - 1; i++) {

		EXPECT_EQ(resultListAsc[i], resultListDesc[resultListDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListSelectionSort) {
	std::vector<int>resultList = selectionSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListSelectionSort) {
	std::vector<int>resultList = selectionSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListSelectionSort) {
	std::vector<int>resultList = selectionSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSameShakerSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = shakerSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueShakerSort) {
	std::vector<int>resultList = shakerSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueShakerSort) {
	std::vector<int>resultList = shakerSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescShakerSort) {
	std::vector<int> resultAsc = shakerSort(randomList, true);
	std::vector<int> resultDesc = shakerSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListShakerSort) {
	std::vector<int>resultList = shakerSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListShakerSort) {
	std::vector<int>resultList = shakerSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListShakerSort) {
	std::vector<int>resultList = shakerSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isResultSizeSameShellSort) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = shellSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSortingAlgorithms, isAscendingTrueShellSort) {
	std::vector<int>resultList = shellSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isDescendingTrueShellSort) {
	std::vector<int>resultList = shellSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isAscTheOppositeOfDescShellSort) {
	std::vector<int> resultAsc = shellSort(randomList, true);
	std::vector<int> resultDesc = shellSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestSortingAlgorithms, sortingNearlySortedListShellSort) {
	std::vector<int>resultList = shellSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, sortingReversedListShellSort) {
	std::vector<int>resultList = shellSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSortingAlgorithms, sortingFewUniqueListShellSort) {
	std::vector<int>resultList = shellSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSortingAlgorithms, isSwapping) {
	int a = 10;
	int b = 20;
	swap(a, b);

	EXPECT_EQ(a, 20);
	EXPECT_EQ(b, 10);
}
