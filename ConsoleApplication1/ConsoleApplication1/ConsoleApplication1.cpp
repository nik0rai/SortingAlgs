#include <iostream>
#include <ctime>

int Partition(int arr[], int begin, int end) {
    int pivot = arr[end];
    int index = begin;

    for (int flag = begin; flag < end; flag++) {
        if (arr[flag] <= pivot) {
            std::swap(arr[flag], arr[index]);
            index++;
        }
    }
    std::swap(arr[index], arr[end]);
    return index;
}

void QuickSort(int arr[], int begin, int end) {
    if (begin < end) {
        int i = Partition(arr, begin, end);
        QuickSort(arr, begin, i - 1);
        QuickSort(arr, i + 1, end);
    }
}


void EnterArr(int arr[], int size) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < size; i++)
        arr[i] = std::rand() % 100;
}

void PrintArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


void Heapify(int arr[], int index, int n) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int max;

    if ((left < n) && (arr[left] > arr[index]))
        max = left;
    else max = index;

    if ((right < n) && (arr[right] > arr[max]))
        max = right;

    if (max != index) {
        std::swap(arr[index], arr[max]);
        Heapify(arr, max, n);
    }
}

void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2; i >= 0; i--)
        Heapify(arr, i, n);
}

void Heapsort(int arr[], int n) {
    BuildMaxHeap(arr, n);
    for (int i = n-1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        n--;
        Heapify(arr, 0, n);
    }
}


void Merge(int arr[], int begin, int end, int mid) {
    int node1 = mid - begin + 1;
    int node2 = end - mid;

    int *left = new int[node1];
    int *right = new int[node2];

    for (int i = 0; i < node1; i++)
        left[i] = arr[begin + i];
    for (int j = 0; j < node2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = begin;
    while (i<node1 && j<node2)
    {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i<node1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j<node2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, begin, end, mid);
    }
}

int main()
{
    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int *arr = new int[n];
    EnterArr(arr, n);
    std::cout << "\nCreated array: \n";
    PrintArr(arr, n);
    std::cout << "\nEnter to select\n" << "1: quicksort\n2: heapsort\n3: mergesort\n>> ";
    int decision;
    retry:
    std::cin >> decision;
    switch (decision)
    {
    default: std::cout << "Enter propper value!\n"; goto retry;
        break;
    case 1: QuickSort(arr, 0, n - 1);
        break;
    case 2: Heapsort(arr, n);
        break;
    case 3: MergeSort(arr, 0, n - 1);
        break;
    }
    std::cout << "\nSorted array: \n";
    PrintArr(arr, n);
    return 0;
}

