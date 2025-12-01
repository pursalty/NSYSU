// Author: B133040049 李梓銜
// Date: 2025/11/26
/*
Purpose:

    測試五種排序 Sorting 演算法的執行效率

    1. A 類排序法
        -> 插入排序法 Insertion Sort
    2. B 類排序法
        -> 合併排序法 Merge Sort
    3. C 類排序法
        -> 快速排序法 Quick Sort
    4. D 類排序法
        -> <stdlib.h> qsort()
    5. E 類排序法
        -> <algorithm> sort()

    給予不同資料量 並 測量其執行時間

*/

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <time.h>
#include <vector>
#include <iomanip>
using namespace std;

// A function to generate input.txt and large test data file testInput.txt
void generateTestFile()
{

    srand(time(NULL));
    ofstream in("input.txt");
    const int num = 300;
    in << num << endl;
    for (int i = 0; i < num; i++)
    {
        in << rand() * rand() << endl;
    }
    in.close();

    ofstream test("testInput.txt");
    int testCase[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000};
    for (int j : testCase)
    {
        int testTime = 1;
        for (int k = 0; k < 10; k++)
        {
            test << j << " " << testTime++ << endl;
            for (int i = 0; i < j; i++)
            {
                test << rand() * rand() << " ";
            }
            test << endl;
        }
    }
    test.close();
    cout << "Generation Complete!\n\n";
}

template <class T>
void InsertionSort(T *a, int n)
{
    // Loop over the array starting from the second element
    for (int j = 1; j < n; j++)
    {
        T key = a[j];  // The element to be inserted into the sorted part
        int i = j - 1; // Index of the last element in the sorted part

        // Shift elements of the sorted part that are greater than key one position to the right
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i]; // Move element one step to the right
            i--;
        }

        // Insert key into its correct position
        a[i + 1] = key;
    }
}

template <class T>
void merge(T *a, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays
    T *L = new T[n1];
    T *R = new T[n2];

    // Copy data into the left temp array L[]
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    // Copy data into the right temp array R[]
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    // Merge the temporary arrays back into a[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) // Take the smaller element from L or R
        {
            a[k++] = L[i++]; // Copy from L and move indices
        }
        else
        {
            a[k++] = R[j++]; // Copy from R and move indices
        }
    }

    // Copy any remaining elements of L[], if any
    while (i < n1)
    {
        a[k++] = L[i++];
    }

    // Copy any remaining elements of R[], if any
    while (j < n2)
    {
        a[k++] = R[j++];
    }

    // Release temporary arrays
    delete[] L;
    delete[] R;
}

template <class T>
void mergeSort(T *a, int left, int right)
{
    // Continue only if the subarray has more than one element
    if (left < right)
    {
        // Find the middle point to split the array
        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);      // Recursively sort the left half
        mergeSort(a, mid + 1, right); // Recursively sort the right half
        merge(a, left, mid, right);   // Merge the two sorted halves
    }
}

template <class T>
void QuickSort(T *a, int left, int right)
{
    // Continue only if the current subarray has more than one element
    if (left < right)
    {
        int i = left;      // Left scan index
        int j = right + 1; // Right scan index (start one past 'right')
        T pivot = a[left]; // Choose the leftmost element as the pivot

        // Partition the array around the pivot
        do
        {
            // Move i to the right until an element >= pivot is found
            do
            {
                i++;
            } while (i <= right && a[i] < pivot);

            // Move j to the left until an element <= pivot is found
            do
            {
                j--;
            } while (a[j] > pivot);

            // If i is still left of j, swap the elements
            if (i < j)
            {
                swap(a[i], a[j]);
            }
        } while (i < j);

        // Place the pivot element into its correct sorted position
        swap(a[left], a[j]);

        // Recursively sort the subarray to the left of the pivot
        QuickSort(a, left, j - 1);

        // Recursively sort the subarray to the right of the pivot
        QuickSort(a, j + 1, right);
    }
}

// A comparison function to be used with qsort()
int cmp(const void *a, const void *b)
{
    // Cast the void pointers to int pointers and dereference to get the values
    int A = *(const int *)a;
    int B = *(const int *)b;

    // Return negative if A should come before B
    if (A < B)
        return -1;

    // Return positive if A should come after B
    if (A > B)
        return 1;

    // Return 0 if A and B are equal
    return 0;
}

// 用來排序固定數量的測資並輸出結果
void solve(char ch)
{
    // 用來儲存讀進來的測資筆數
    int n;
    // 開啟 input.txt 準備讀取資料
    ifstream in("input.txt");
    // 讀進測資筆數
    in >> n;
    // 動態宣告一個新的陣列來儲存讀進來的資料
    int *arr = new int[n];
    // 開始一一把資料讀進陣列 arr 中
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }

    // 根據使用者指定的排序方法 ch，選擇要使用的排序演算法
    switch (ch)
    {
    // 若為 case 'A'，則執行 insertion sort
    case 'A':
    {
        // 呼叫 insertion sort 函式對陣列進行排序
        InsertionSort(arr, n);
        // 開啟輸出檔案，用來輸出排序後的結果
        ofstream fout("outputA.txt");
        // 在檔案開頭先輸出本次使用的排序方法名稱
        fout << "Insertion Sort:\n\n";
        // 將排序結果一一輸出到檔案中
        for (int i = 0; i < n; i++)
        {
            fout << arr[i] << endl;
        }
        // 輸出完成後關閉檔案
        fout.close();
        break;
    }

    // 若為 case 'B'，則執行 merge sort
    case 'B':
    {
        // 使用 merge sort 對陣列 arr[0..n-1] 進行排序
        mergeSort(arr, 0, n - 1);
        // 開啟輸出檔案
        ofstream fout("outputB.txt");
        // 輸出本次使用的排序方法名稱
        fout << "Merge Sort:\n\n";
        // 將排序結果寫入檔案
        for (int i = 0; i < n; i++)
        {
            fout << arr[i] << endl;
        }
        // 關閉檔案
        fout.close();
        break;
    }

    // 若為 case 'C'，則執行 quick sort
    case 'C':
    {
        // 使用 quick sort 對陣列 arr[0..n-1] 進行排序
        QuickSort(arr, 0, n - 1);
        // 開啟輸出檔案
        ofstream fout("outputC.txt");
        // 輸出本次使用的排序方法名稱
        fout << "Quick Sort:\n\n";
        // 將排序結果寫入檔案
        for (int i = 0; i < n; i++)
        {
            fout << arr[i] << endl;
        }
        // 關閉檔案
        fout.close();
        break;
    }

    // 若為 case 'D'，則使用 C 語言的 qsort()
    case 'D':
    {
        // 使用 C 標準函式庫的 qsort() 排序，
        // 第四個參數 cmp 為比較函式
        qsort(arr, n, sizeof(int), cmp);
        // 開啟輸出檔案
        ofstream fout("outputD.txt");
        // 輸出本次使用的排序方法名稱
        fout << "C qsort():\n\n";
        // 將排序結果寫入檔案
        for (int i = 0; i < n; i++)
        {
            fout << arr[i] << endl;
        }
        // 關閉檔案
        fout.close();
        break;
    }

    // 若為 case 'E'，則使用 C++ STL 的 sort()
    case 'E':
    {
        // 使用 C++ 標準函式庫的 sort() 排序 [arr, arr + n)
        sort(arr, arr + n);
        // 開啟輸出檔案
        ofstream fout("outputE.txt");
        // 輸出本次使用的排序方法名稱
        fout << "C++ sort():\n\n";
        // 將排序結果寫入檔案
        for (int i = 0; i < n; i++)
        {
            fout << arr[i] << endl;
        }
        // 關閉檔案
        fout.close();
        break;
    }
    }

    delete[] arr; // 釋放動態配置的記憶體
}

// 用來計算執行時間
double runSortOnce(char ch, int *src, int n)
{
    // 宣告一個新array來儲存要排序的測資
    int *a = new int[n];
    // 將測資輸入array
    for (int i = 0; i < n; i++)
    {
        a[i] = src[i];
    }

    // 計算時間的開頭
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // 用來執行個個排序
    switch (ch)
    {
    case 'A':
        InsertionSort(a, n);
        break;
    case 'B':
        mergeSort(a, 0, n - 1);
        break;
    case 'C':
        QuickSort(a, 0, n - 1);
        break;
    case 'D':
        qsort(a, n, sizeof(int), cmp);
        break;
    case 'E':
        sort(a, a + n);
        break;
    }

    // 計算時間結束
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // 將結果計算出來並儲存
    chrono::duration<double> diff = end - start;
    // 用儲存結果
    double seconds = diff.count();

    // 以上動作皆做完後則刪除array
    delete[] a;
    // 回傳結果
    return seconds;
}

// 用來執行多筆測資的時間計算，並將結果輸出
void testLarge()
{
    cout << "執行中" << endl;
    // 開啟檔案用以執行多筆測資並計算時間
    ifstream in("testInput.txt");

    // 宣告變數用來儲存排序種類的數量
    const int sortNum = 5;
    // 宣告變數用來儲存有幾種測資數量
    const int caseNum = 8;
    // 宣告一個array來儲存個個測資數量
    int cs[caseNum] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000};
    // 宣告一個array用來儲存不同的case代號
    char sorts[sortNum] = {'A', 'B', 'C', 'D', 'E'};
    // 宣告一個array用來儲存不同的排序名稱
    string sortName[sortNum] = {"Insertion Sort", "Merge Sort", "Quick Sort", "C qsort()", "C++ sort()"};
    // 宣告一個2D-array來儲存不同排序的執行總時間
    double sumTestTime[sortNum][caseNum];
    // 宣告一個2D-array來儲存不同排序同樣數量的測資的測試數量
    int countTestTime[sortNum][caseNum];

    // 先初始化兩個array
    for (int i = 0; i < sortNum; i++)
        for (int j = 0; j < caseNum; j++)
            sumTestTime[i][j] = 0.0, countTestTime[i][j] = 0;

    // 宣告兩個變數用來儲存測資數量，第幾次
    int type, cnt;
    // 用來讀入測資數量，第幾次並執行相關動作
    while (in >> type >> cnt)
    {
        // 宣告一個變數用來儲存現在要測試的測資數
        int idx = -1;
        // 嫆來尋找現在要測試的測資數
        for (int i = 0; i < caseNum; i++)
        {
            if (cs[i] == type)
            {
                idx = i;
                break;
            }
        }
        // 建立一個新的array用來儲存輸入的測資
        int *arr = new int[type];
        // 輸入測資
        for (int i = 0; i < type; i++)
            in >> arr[i];

        // 用來測量測試時間並記錄下來
        for (int i = 0; i < sortNum; i++)
        {
            // 用來儲存測量的執行時間結果
            double second = runSortOnce(sorts[i], arr, type);
            // 將測量結果儲存下來並將測試次數加一
            sumTestTime[i][idx] += second;
            countTestTime[i][idx]++;
        }

        // 以上動作都做完後則刪除array
        delete[] arr;
    }

    // 關閉檔案
    in.close();

    // 接下來的程式用來輸出測試結果
    cout << fixed << setprecision(3);
    cout << "資料量\t";
    for (int a = 0; a < sortNum; a++)
        cout << sortName[a] << "\t";
    cout << "\n";

    for (int i = 0; i < caseNum; i++)
    {
        cout << fixed << setprecision(6) << cs[i] << "\t";

        for (int a = 0; a < sortNum; a++)
        {

            // 用來計算平均執行時間
            double avg = sumTestTime[a][i] / countTestTime[a][i];

            // 若超過5分鐘，則輸出超時
            if (avg > 300.0)
                cout << "TLE\t";
            else
                cout << avg << "\t";
        }
        cout << "\n";
    }

    cout << "註:時間單位為秒，TLE 表示時間大於5分鐘。\n\n";
}

int main()
{
    // 用來輸入整數來執行不同的動作
    int num;

    while (true)
    {
        cout << "Please choose the action you want to do:\n1.Generate the test files and check the sort\n2. Do the large test data\n"
             << endl;
        cin >> num;
        cout << endl;

        // 若輸入1則執行生成測試檔案的測資並將排序好的測資輸出到不同檔案中
        if (num == 1)
        {
            generateTestFile();
            solve('A');
            solve('B');
            solve('C');
            solve('D');
            solve('E');
        }

        // 若輸入2則執行多筆測資以測試執行速度
        else if (num == 2)
        {
            testLarge();
        }
    }
    return 0;
}
