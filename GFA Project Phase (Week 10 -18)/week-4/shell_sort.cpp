#include "shell_sort.h"
#include "swap.h"

std::vector<int> shellSort(std::vector<int> list, bool isAscending)
{
	
	std::vector<int> resultList = list;
	int sizeList = list.size();

	for (int gap = sizeList / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < sizeList; i++) {
			for (int j = i - gap; j >= 0; j = j - gap) {
				if (resultList[j + gap] >= resultList[j]) {
					break;
				} else {
					swap(resultList[j], resultList[j + gap]);
				}
			}
		}
	}
	if (isAscending == false) {
		for (int i = 0; i < resultList.size() / 2; i++) {
			swap(resultList[i], resultList[resultList.size() - 1 - i]);
		}
	}

	return resultList;
}
	