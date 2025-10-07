//  Author: B133040049 李梓銜
//  Date: 2025/09/19
/*  Purpose: 以C++製作一個「集合」類別 (set class)，使其能進行「聯集」、「交集」、「差集」、「包含」、「屬於」等五種運算。
    Pascal本身有提供集合運算，但是C語言並沒有，故請你製作集合類別，以利進行集合運算。集合運算符號與Pascal相同。

    假設A與B均為集合，則以下列符號表示各種運算：

    A與B聯集 (union)        記做 A + B
    A與B交集 (intersection) 記做 A * B
    A與B差集 (difference)   記做 A - B
    A包含 (contain) B       記做 A >= B
    x屬於 (belong to) A     記做 x in A
*/

#include <bits/stdc++.h>
using namespace std;

// 宣告一個class名為Tset，用來處理運算
class Tset
{
public:
    // 用來儲存輸入的字元，用以比較
    char arr[256];

    // 輸入串流，以便之後的輸入
    friend istream &operator>>(istream &in, Tset &c)
    {
        // 輸入資料
        in.getline(c.arr, 256);
        int len = strlen(c.arr);
        // 將輸入資料從排列
        sort(c.arr, c.arr + len);

        // 刪除重複的元素(因為是set)
        int k = 0; // 用來計算c.arr目前到哪
        for (int i = 0; i < len; i++)
        {
            if (i == 0 || c.arr[i] != c.arr[i - 1])
            {
                c.arr[k++] = c.arr[i];
            }
        }
        c.arr[k] = '\0';
        return in;
    }

    // 輸出串流，以便之後可以更方便的輸出，且符合輸出格式
    friend ostream &operator<<(ostream &out, Tset &c)
    {
        out << "{" << c.arr << "}" << endl;
        return out;
    }

    // operator * overloading (intersection)
    friend Tset operator*(const Tset &a, const Tset &b)
    {
        // 宣告i, j, k用來記錄a.arr, b.arr, result.arr
        int i = 0, j = 0, k = 0;
        // 用來儲存a intersection b的答案
        Tset result;
        int la = strlen(a.arr), lb = strlen(b.arr);
        // 計算a和b的intersection，並回傳答案result
        while (i < la && j < lb)
        {
            // 若一樣，就加入
            if (a.arr[i] == b.arr[j])
            {
                result.arr[k] = a.arr[i];
                i++;
                j++;
                k++;
            }
            // 不一樣，就先將ASCII較小的arr[x]+1，用以之後比較
            else if (a.arr[i] > b.arr[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        result.arr[k] = '\0';
        return result;
    }

    // operator - overloading (difference)
    friend Tset operator-(const Tset &a, const Tset &b)
    {
        // 宣告i, j, k用來記錄a.arr, b.arr, result.arr
        int i = 0, j = 0, k = 0;
        // 用來儲存a difference b的答案
        Tset result;
        // 紀錄a.arr, b.arr的長度
        int la = strlen(a.arr), lb = strlen(b.arr);
        // 用來計算a difference b的答案
        while (i < la && j < lb)
        {
            // 計算a有，b沒有的元素
            if (a.arr[i] < b.arr[j])
            {
                result.arr[k] = a.arr[i];
                k++;
                i++;
            }
            else if (a.arr[i] > b.arr[j])
            {
                j++;
            }
            // 若a.arr[i] == b.arr[j]，則不符合，所以i ++, j ++
            else
            {
                i++;
                j++;
            }
        }

        // 將a剩下的元素加入
        while (i < la)
            result.arr[k++] = a.arr[i++];
        result.arr[k] = '\0';
        return result;
    }

    // operator + overloading (union)
    friend Tset operator+(const Tset &a, const Tset &b)
    {
        // 宣告i, j, k用來記錄a.arr, b.arr, result.arr
        int i = 0, j = 0, k = 0;
        // 用來儲存a union b的答案
        Tset result;
        // 紀錄a.arr, b.arr的長度
        int la = strlen(a.arr), lb = strlen(b.arr);
        // 用來計算a union b的答案
        while (i < la && j < lb)
        {
            // 若a.arr[i] == b.arr[j]，則加入result.arr
            if (a.arr[i] == b.arr[j])
            {
                result.arr[k] = a.arr[i];
                i++;
                j++;
                k++;
            }
            // 若不一樣，則把ASCII小的加入result
            else if (a.arr[i] < b.arr[j])
            {
                result.arr[k++] = a.arr[i];
                i++;
            }
            else
            {
                result.arr[k++] = b.arr[j];
                j++;
            }
        }
        // 將a, b剩下的也加入result
        while (i < la)
            result.arr[k++] = a.arr[i++];
        while (j < lb)
            result.arr[k++] = b.arr[j++];
        result.arr[k] = '\0';
        return result;
    }

    // operator >= overloading (contain)
    friend bool operator>=(const Tset &a, const Tset &b)
    {
        // 直接用operator - overloading計算
        Tset tmp = b - a;
        return (strlen(tmp.arr) == 0);
    }

    // operator in (belong to)
    bool in(char c) const
    {
        // 找c是否在arr內
        for (int i = 0; i < strlen(arr); i++)
        {
            if (arr[i] == c)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // 用來輸入有幾個測試數據
    int num;
    cin >> num;
    cin.ignore();
    // 用來計算並生成一個個的測試數據
    for (int i = 1; i <= num; i++)
    {
        if (i != 1)
            cin.ignore();

        // 輸入測資
        Tset A;
        Tset B;
        cin >> A >> B;
        char ch;
        cin >> ch;
        Tset C = A + B;
        Tset D = A * B;
        Tset E = A - B;
        Tset F = B - A;

        // 根據輸出要求生成output
        cout << "Test Case " << i << ":\n";
        cout << "A: " << A;
        cout << "B: " << B;
        cout << "A + B: " << C;
        cout << "A * B: " << D;
        cout << "A - B: " << E;
        cout << "B - A: " << F;
        if (A >= B)
        {
            cout << "A contains B\n";
        }
        else
        {
            cout << "A doesn't contain B\n";
        }

        if (B >= A)
        {
            cout << "B contains A\n";
        }
        else
        {
            cout << "B doesn't contain A\n";
        }

        if (A.in(ch))

        {
            cout << "'" << ch << "' is in A\n";
        }
        else
        {
            cout << "'" << ch << "' is not in A\n";
        }

        if (B.in(ch))

        {
            cout << "'" << ch << "' is in B\n\n";
        }
        else
        {
            cout << "'" << ch << "' is not in B\n\n";
        }
    }
    return 0;
}