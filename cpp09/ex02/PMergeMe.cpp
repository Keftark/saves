#include "PMergeMe.hpp"

bool IsPositiveNumber(const char* str)
{
    for (int i = 0; str[i] != '\0'; ++i)
	{
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int PMergeMe::CheckNumbers(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
	{
        if (!IsPositiveNumber(argv[i]))
		{
            std::cout << ERRCOLOR << "Error: Argument at index " << i << " is not a positive number." << RESET << std::endl;
            return 1;
        }
    }
	return 0;
}

void PMergeMe::SaveNumbers(int argc, char *argv[])
{
    int curNb;
    for (int i = 1; i < argc; i++)
    {
        curNb = atoi(argv[i]);
        myList.push_back(curNb);
        myVector.push_back(curNb);
    }
}

void PMergeMe::ShowNumbers()
{
    int i = 0;
    for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it)
	{
        i++;
        if (i == 5)
            std::cout << "[...]";
        else if (i < 5)
            std::cout << *it << " ";
    }
    std::cout << RESET << std::endl;
}

void mergeList(std::list<int>::iterator low, std::list<int>::iterator mid, std::list<int>::iterator high)
{
    std::list<int> merged;
    std::list<int>::iterator left = low;
    std::list<int>::iterator right = mid;

    while (left != mid && right != high)
    {
        if (*left <= *right)
        {
            merged.push_back(*left);
            ++left;
        }
        else
        {
            merged.push_back(*right);
            ++right;
        }
    }
    while (left != mid)
    {
        merged.push_back(*left);
        ++left;
    }
    while (right != high)
    {
        merged.push_back(*right);
        ++right;
    }
    std::copy(merged.begin(), merged.end(), low);
}

void insertionSortList(std::list<int>::iterator low, std::list<int>::iterator high)
{
    for (std::list<int>::iterator i = low; i != high; ++i)
    {
        int key = *i;
        std::list<int>::iterator j = i;
        while (j != low && *(--j) > key)
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = *j;
        }
        std::list<int>::iterator nextJ = j;
        ++nextJ;
        *nextJ = key;
    }
}

void mergeInsertionSortHelperList(std::list<int>::iterator low, std::list<int>::iterator high)
{
    if (std::distance(low, high) > 1)
    {
        if (std::distance(low, high) <= 10)
            insertionSortList(low, high);
        else
        {
            std::list<int>::iterator mid = low;
            std::advance(mid, std::distance(low, high) / 2);
            mergeInsertionSortHelperList(low, mid);
            mergeInsertionSortHelperList(mid, high);
            mergeList(low, mid, high);
        }
    }
}

void mergeInsertionSortList(std::list<int> &lst)
{
    mergeInsertionSortHelperList(lst.begin(), lst.end());
}

void merge(std::vector<int> &vec, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[low + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vec[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            vec[k++] = L[i++];
        else
            vec[k++] = R[j++];
    }
    while (i < n1)
        vec[k++] = L[i++];
    while (j < n2)
        vec[k++] = R[j++];
}

void insertionSort(std::vector<int> &vec, int low, int high)
{
    for (int i = low + 1; i <= high; ++i)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= low && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void mergeInsertionSortHelper(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        if (high - low <= 10)
            insertionSort(vec, low, high);
        else
        {
            int mid = low + (high - low) / 2;
            mergeInsertionSortHelper(vec, low, mid);
            mergeInsertionSortHelper(vec, mid + 1, high);
            merge(vec, low, mid, high);
        }
    }
}

void mergeInsertionSort(std::vector<int> &arr)
{
    mergeInsertionSortHelper(arr, 0, arr.size() - 1);
}

void PMergeMe::DoSort()
{
    std::clock_t start;
    std::clock_t end;

    start = std::clock();
    mergeInsertionSort(myVector);
    end = std::clock();
    vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    start = std::clock();
    mergeInsertionSortList(myList);
    end = std::clock();
    listTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PMergeMe::ShowTimers()
{
    std::cout << GOLD << "[list]" << TEAL << "\t\tElapsed time: \t" << std::fixed << std::setprecision(6) << CORAL << listTime << TEAL << " us" << std::endl;
    std::cout << GOLD << "[vector]" << TEAL << "\tElapsed time: \t" << std::fixed << std::setprecision(6) << CORAL << vectorTime << TEAL << " us" << RESET << std::endl;}