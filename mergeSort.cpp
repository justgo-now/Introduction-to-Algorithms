/*************************************************************************
	> File Name: mergeSort.cpp
	> Author: jief
	> Mail: foreverlovemichael@gmail.com
	> Created Time: Tue 02 Jun 2015 04:59:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void printVector(vector<int> &nums)
{
  vector<int>::iterator it = nums.begin();
  for(; it != nums.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

void merge(vector<int> &nums, int left, int mid, int right)
{
  vector<int> larr, rarr;
  larr.clear();
  rarr.clear();
  for(int i = 0; i < mid - left + 1; ++i)
  {
    larr.push_back(nums[left + i]);
  }
  for(int i = 0; i < right - mid; ++i)
  {
    rarr.push_back(nums[mid + 1 + i]);
  }

  int i = 0, j = 0;
  int k = left;
  while((i < mid - left + 1) && (j < right - mid))
  {
    if (larr[i] < rarr[j])
    {
      nums[k++] = larr[i++];
    }
    else
    {
      nums[k++] = rarr[j++];
    }
  }
  while(i < mid - left + 1)
  {
    nums[k++] = larr[i++];
  }
  while(j < right - mid)
  {
    nums[k++] = rarr[j++];
  }
}

void mergeSortHelper(vector<int> &nums, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    mergeSortHelper(nums, left, mid);
    mergeSortHelper(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }
}

void mergeSort(vector<int> &nums)
{
  mergeSortHelper(nums, 0, nums.size() - 1);
}


int main()
{
  srand(0);
  const int guardNum = 10;
  vector<int> nums;
  for(int i = 0; i < guardNum; ++i)
  {
    nums.push_back(random() % guardNum);
  }
  printVector(nums);
  mergeSort(nums);
  printVector(nums);

  return 0;
}
