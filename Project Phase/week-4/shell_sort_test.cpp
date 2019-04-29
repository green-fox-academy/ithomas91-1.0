#include "gtest/gtest.h"
#include "../opencv/shell_sort.cpp"
#include <time.h>
#include <opencv2/opencv.hpp>

class TestShellSort : public testing::Test
{
protected:

	std::vector<int> randomList;
	std::vector<int> nearlySortedList;
	std::vector<int> reversedList;
	std::vector<int> fewUniqueList;

	virtual void SetUp()
	{
		srand(time(NULL));
		int numberOfElements = rand() % 400 + 100;
		for (int i = 0; i < numberOfElements; i++) {
			randomList.push_back(rand());
		}
		for (int i = 0; i < numberOfElements; i++) {
			nearlySortedList.push_back(i);
			if (i % 4 == 0) {
				nearlySortedList.at(i) = i + 3;
			}
		}
		for (int i = numberOfElements; i > 0; i--) {
			reversedList.push_back(i);
		}
		for (int i = 0; i < numberOfElements; i++) {
			int number = i % 4;
			fewUniqueList.push_back(number);
		}
	}
};

TEST_F(TestShellSort, isResultSizeSame) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = shellSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestShellSort, isAscendingTrue) {
	std::vector<int>resultList = shellSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestShellSort, isDescendingTrue) {
	std::vector<int>resultList = shellSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestShellSort, isAscTheOppositeOfDesc) {
	std::vector<int> resultAsc = shellSort(randomList, true);
	std::vector<int> resultDesc = shellSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestShellSort, sortingNearlySortedList) {
	std::vector<int>resultList = shellSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestShellSort, sortingReversedList) {
	std::vector<int>resultList = shellSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestShellSort, sortingFewUniqueList) {
	std::vector<int>resultList = shellSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
