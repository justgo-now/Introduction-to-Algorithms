/*************************************************************************
	> File Name: quickSort.cpp
	> Author: jief
	> Mail: foreverlovemichael@gmail.com
	> Created Time: Tue 02 Jun 2015 10:13:52 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void printVector(vector<int> &vec)
{
  vector<int>::iterator it = vec.begin();
  for(;it != vec.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}
void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int partition(vector<int> &vec, int p, int r)
{
  int pivot = vec[r];
  int i = p - 1;
  for(int j = p; j < r; ++j)
  {
    if (vec[j] <= pivot)
    {
      ++i;
      swap(vec[i], vec[j]);
    }
  }
  swap(vec[i + 1], vec[r]);
  return i + 1;
}

void quickSortHelper(vector<int> &vec, int p, int r)
{
  if (p < r)
  {
    int q = partition(vec, p, r);
    printVector(vec);
    quickSortHelper(vec, p, q - 1);
    quickSortHelper(vec, q + 1, r);
  }
}

void quickSort(vector<int> &vec)
{
  quickSortHelper(vec, 0, vec.size() - 1);
}



int main()
{
  vector<int> nums;

  const int guardNum = 10;
  srand(0);
  for(int i = 0; i < guardNum; ++i)
  {
    nums.push_back(random() % guardNum);
  }
  printVector(nums);
  quickSort(nums);
  printVector(nums);
  
  return 0;
}
