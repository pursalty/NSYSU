// Author: B133040049 李梓銜
// Date: 2025/10/9
// Purpose: 設計一個程式，可以處理兩個多項式之加法與乘法
//          每個多項式可用一個linked list來儲存，
//          其每個node的結構有三個欄位(field)，
//          分別為coefficient, exponent, next node address



#include <bits/stdc++.h>
using namespace std;

//建立一個class 來儲存每個polynominal的每項資料
class Node
{
public:
    //負責儲存係數
    int coefficient;
    //負責儲存次方
    int exponent;
    //負責儲存下一個Node的地址
    Node *next;
    Node(int coe, int exp, Node *nxt)
    {
        coefficient = coe;
        exponent = exp;
        next = nxt;
    }
};

//建立一個class用來執行linked list
class Poly
{
protected:
    //用來記錄整個linked list的開頭地址
    Node *head = nullptr;

public:
    //建立一個function用來判斷P, Q是否為0，以及輸入資料
    bool input(int n)
    {
        //方別輸入係數，次方
        int c, e;
        //n若為0，則回報false
        if (n == 0)
            return false;
        //n若不為0，則輸入規定的資料數量
        else
        {
            while (n--)
            {
                cin >> c >> e;
                insert(c, e);
            }
            return true;
        }
    }

    //建立一個function來插入個個項次，並確保他們從次方大到次方小排列
    void insert(int a, int b)
    {
        //建立一個新的node來除村要插入的資料
        Node *newNode = new Node(a, b, nullptr);
        //當整個linked list還是空的時候，新創立的node即為整個linked list的開頭
        if (!head)
        {
            head = newNode;
            return;
        }
        //若原本linked list的開頭次方小於要插入的資料次方，則將新插入的資料插入到開頭
        if (head->exponent < b)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        //若原本的linked list的開頭資料等於要插入的資料次方，則將插入資料的係數加入即可
        if (head->exponent == b)
        {
            head->coefficient += a;
            //因為只有加入係數，故不需要再建立一個node，故將其刪除
            delete newNode;
            return;
        }

        //若以上條件皆不符合，則建立一個指向Node的地址來記錄目前的位置
        Node *pos = head;
        //若pos指到的下一個位置的次方大於要插入的資料，則將pos指到linked list的下一個node
        while (pos->next && pos->next->exponent > b)
            pos = pos->next;

        //若相等，則將係數加入即可
        if (pos->next && pos->next->exponent == b)
        {
            pos->next->coefficient += a;
            //因為只有加入係數，故不需要再建立一個node，故將其刪除
            delete newNode;
        }
        //若走到這則代表pos指到的node的次方大於要插入的，pos指到的下一個次方本身又小於要插入的，故要將新插入的資料插入pos指到的係數之後一個
        else
        {
            newNode->next = pos->next;
            pos->next = newNode;
        }
    }

    // operator * overloading (multiplication)
    friend Poly operator*(const Poly &a, const Poly &b)
    {
        //建立一個Poly result來記錄結果
        Poly result;
        //要相乘的多項式的每個次方係數相乘，並插入到result中
        for (Node *p1 = a.head; p1; p1 = p1->next)
        {
            for (Node *p2 = b.head; p2; p2 = p2->next)
            {
                result.insert(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
            }
        }
        //最後回傳結果
        return result;
    }

    // operator * overloading (addition)
    friend Poly operator+(const Poly &a, const Poly &b)
    {
        //建立p1, p2來記錄現在執行到的地方
        Node *p1 = a.head;
        Node *p2 = b.head;
        //建立一個Poly result來記錄結果
        Poly result;
        //若兩個多項式皆未執行到末尾，則繼續檢查
        while (p1 && p2)
        {
            //若p1指到的次方跟p2相同，則插入到result中
            if (p1->exponent == p2->exponent)
            {
                //用來記錄兩係數之和
                int sum = p1->coefficient + p2->coefficient;
                //若係數不為0，則插入到result中
                if (sum != 0)
                {
                    result.insert(sum, p1->exponent);
                }
                //將p1, p2指到下一個node
                p1 = p1->next;
                p2 = p2->next;
            }
            //若p1指到的次方大於p2，則插入p1的資料
            else if (p1->exponent > p2->exponent)
            {
                result.insert(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            //反之插入p2的資料
            else
            {
                result.insert(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }
        //p2已指到多項式的末尾，則將p1剩餘的資料插入到result中
        while (p1)
        {
            result.insert(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        //反之則為將p2剩餘的資料插入到result中
        while (p2)
        {
            result.insert(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        //回傳result
        return result;
    }

    // 輸出串流，以便之後可以更方便的輸出，且符合輸出格式
    friend ostream &operator<<(ostream &out, const Poly &c)
    {
        //建立一個指向Node的地址來記錄目前的位置
        Node *pos = c.head;
        //若此linkde list為空，代表此多項視為0，則輸出0
        if (pos == nullptr)
        {
            out << 0 << endl;
        }
        //若不為0，則依照規定輸出
        else
        {
            while (pos != nullptr)
            {
                out << pos->coefficient << " " << pos->exponent << endl;
                pos = pos->next;
            }
        }
        return out;
    }
};

int main()
{
    //用來記錄現在執行的case數
    int kase = 1;
    //若P且Q不為0，則程式一直執行
    while (1)
    {
        //用來記錄P，Q要輸入的資料數
        int p, q;
        //用來記錄兩個多項式
        Poly P, Q;
        cin >> p;
        //判斷P多項式是否為0
        bool input1 = P.input(p);
        cin >> q;
        //判斷Q多項式是否為0
        bool input2 = Q.input(q);
        //判斷程式是否要結束
        if (!input1 && !input2)
        {
            break;
        }
        //用來記錄兩多項式相加、相乘的結果
        Poly add, mul;
        //用operator overloading 來計算相加、相乘
        add = P + Q;
        mul = P * Q;
        //輸出
        cout << "Case" << kase++ << ":" << endl;
        cout << "ADD" << endl;
        cout << add << endl;
        cout << "MULTIPLY" << endl;
        cout << mul << endl;
    }
    return 0;
}

/*
測資:
0
3
1 2
1 1
1 0
3
3 5
1 1
1 1
2
-2 1
1 2
2
5 1
-7 0
2
-5 1
7 0
0
0
*/