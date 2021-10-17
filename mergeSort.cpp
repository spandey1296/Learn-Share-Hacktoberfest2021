#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low, z[20];
  while (i <= mid && j <= high)
  {
    if (arr[i] <= arr[j])
      z[k++] = arr[i++];
    else
      z[k++] = arr[j++];
  }
  while (i <= mid)
    z[k++] = arr[i++];
  while (j <= high)
    z[k++] = arr[j++];
  for (i = low; i <= high; i++)
    arr[i] = z[i];
}
void mergeSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);

    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}
int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  mergeSort(arr, 0, n - 1);
  cout << "Sorted array is" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}
