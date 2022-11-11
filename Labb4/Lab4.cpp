// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Header.h"

List<int> operator+(List<int> num1, List<int> num2)
{
    List<int> n1 = num1.Copy();
    List<int> n2 = num2.Copy();

    Node<int>* ptr1 = n1.Begin();
    Node<int>* ptr2 = n2.Begin();
    List<int> ans;

    int promotion = 0;
    while (ptr1 != n1.End() && ptr2 != n2.End())
    {
        ans.PushBack((promotion + ptr1->value + ptr2->value) % 10);
        promotion = (promotion + ptr1->value + ptr2->value) / 10;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1 != n1.End())
    {
        ans.PushBack((promotion + ptr1->value) % 10);
        promotion = (promotion + ptr1->value) / 10;

        ptr1 = ptr1->next;
    }

    while (ptr2 != n2.End())
    {
        ans.PushBack((promotion + ptr2->value) % 10);
        promotion = (promotion + ptr2->value) / 10;

        ptr2 = ptr2->next;
    }
    if (promotion != 0)
        ans.PushBack(promotion);

    n1.Clear(); n2.Clear();

    return ans;
}

List<int> operator*(List<int> num1, List<int> num2)
{
    List<int> n1 = num1.Copy();
    List<int> n2 = num2.Copy();

    Node<int>* ptr2 = n2.Begin();
    List<int> ans;
    List<int> sup;
    List<int> buf;
    int countZero = 0;

    while (ptr2 != n2.End())
    {
        int promotion = 0;
        Node<int>* ptr1 = n1.Begin();
        while (ptr1 != n1.End())
        {
            sup.PushBack((promotion + ptr1->value * ptr2->value) % 10);
            promotion = (promotion + ptr1->value * ptr2->value) /10;

            ptr1 = ptr1->next;
        }

        if (promotion != 0)
            sup.PushBack(promotion);

        for (int i = 0; i < countZero; i++)
            sup.PushFront(0);

        buf = ans + sup;
        ans.Clear();
        ans = buf.Copy();
        buf.Clear();
        sup.Clear();
        countZero++;
        ptr2 = ptr2->next;
    }
    n1.Clear(); n2.Clear();

    return ans;
}

template<typename T>
bool operator>(List<T> num1, List<T> num2)
{
    List<T> n1 = num1.Copy();
    Reverse(n1);
    List<T> n2 = num2.Copy();
    Reverse(n1);

    if (num1.Size() > num2.Size())
        return true;
    else
        return false;
    if (num1.Size() == 0 || num2.Size() == 0)
        return num1.Size() > num2.Size();

    Node<T>* ptr1 = n1.Begin();
    Node<T>* ptr2 = n2.Begin();
    for (; ptr1 != num1.End() && ptr2 != num2.End();
        ptr1 = ptr1->next, ptr2 = ptr2->next)
    {
        if (ptr1->value > ptr2->value)
            return true;
        else
            return false;
    }
    n1.Clear(); n2.Clear();

    return false;
};

template<typename T>
bool operator<(List<T> num1, List<T> num2)
{
    List<T> n1 = num1.Copy();
    Reverse(n1);
    List<T> n2 = num2.Copy();
    Reverse(n1);

    if (num1.Size() > num2.Size())
        return false;
    else
        return true;
    if (num1.Size() == 0 || num2.Size() == 0)
        return num1.Size() > num2.Size();

    Node<T>* ptr1 = n1.Begin();
    Node<T>* ptr2 = n2.Begin();
    for (; ptr1 != num1.End() && ptr2 != num2.End();
        ptr1 = ptr1->next, ptr2 = ptr2->next)
    {
        if (ptr1->value < ptr2->value)
            return true;
        else
            return false;
    }
    n1.Clear(); n2.Clear();

    return false;
};

template<typename T>
bool operator<=(List<T> num1, List<T> num2)
{
    return !(num1 > num2);
};

template<typename T>
bool operator>=(List<T> num1, List<T> num2)
{
    return !(num1 < num2);
};

List<int> operator-(List<int> n1, List<int> n2)
{
    List<int> num1 = n1.Copy();
    List<int> num2 = n2.Copy();

    Node<int>* ptr1 = num1.Begin();
    Node<int>* ptr2 = num2.Begin();
    List<int> ans;

    int promotion = 0;
    while (ptr1 != num1.End() && ptr2 != num2.End())
    {
        if (ptr1->value >= ptr2->value)
            ans.PushBack(ptr1->value - ptr2->value);
        else if (ptr1->value < ptr2->value)
        {
            ans.PushBack(ptr1->value - ptr2->value + 10);
            Node<int>* sup = ptr1;
            sup = sup->next;
            while (sup->value == 0)
            {
                sup->value = 9;
                sup = sup->next;
            }
            sup->value--;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1 != num1.End() && ptr1->value != 0)
    {
        ans.PushBack(ptr1->value);

        ptr1 = ptr1->next;
    }

    return ans;
};

List<int> Factorial(int n)
{
    List<int> ans;
    ans.PushBack(1);
    List<int> sup;
    List<int> buf;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x != 0)
        {
            sup.PushBack(x % 10);
            x = x / 10;
        }
        
        buf = ans * sup;
        ans.Clear();
        sup.Clear();
        ans = buf.Copy();
        buf.Clear();
    }
    return ans;
}
/*
List<int> operator/(List<int> n1, List<int> n2)
{
    List<int> num1 = n1.Copy();
    List<int> num2 = n2.Copy();

    List<int> ans;

    
}*/

int main()
{
    List<int> list1;
    list1.PushFront(8);



    List<int> list2;
    list2.PushFront(3);


    //PrintReverse(list1);
    //PrintReverse(list2);

    List<int> list3;
    if (list1 > list2)
        list3 = list1 - list2;
    else
        list3 = list2 - list1;

    List<int> fact = Factorial(200);

    List<int> m = list1 * list2;
    PrintReverse(m);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
