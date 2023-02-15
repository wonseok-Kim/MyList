#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include <list>

#include "List.h"

using Item = int;
using ListType = List<Item>;
using Func = void(*)(Item*);
// using ListType = std::list<int>;

class Integer
{
  public:
    Integer(int initValue)
    {
        m_int = initValue;
    }

    int GetInt() const
    {
        return m_int;
    }

  private:
    int m_int;
};

void PrintList1(ListType& sampleList)
{
    ListType::iterator iter = sampleList.begin();
    ListType::iterator iterEnd = sampleList.end();

    wprintf(L"\n");
    for (; iter != iterEnd; ++iter)
    {
        wprintf(L"%d ", *iter);
    }
    wprintf(L"\n\n");
}

void PrintList2(ListType& sampleList)
{
    ListType::const_iterator iter = sampleList.begin();
    ListType::const_iterator iterEnd = sampleList.end();

    wprintf(L"\n");
    for (; iter != iterEnd; ++iter)
    {
        wprintf(L"%d ", *iter);
    }
    wprintf(L"\n\n");
}

void AddOne(Item* pItem)
{
    ++(*pItem);
}

void Traverse(ListType& sampleList, Func func)
{
    ListType::iterator iter = sampleList.begin();
    ListType::iterator iterEnd = sampleList.end();

    for (; iter != iterEnd; ++iter)
    {
        func(&(*iter));
    }
}

int wmain()
{
    {
        ListType aList;
        for (int i = 1; i <= 9; ++i)
            aList.push_back(i);

        auto iter = aList.begin();
        for (;;iter++)
        {
            wprintf(L"%d ", *iter);
        }
    }

    _wsetlocale(LC_ALL, L"");

    ListType sampleList;

    for (int i = 0;; ++i)
    {
        wprintf(L"1. push_back()\n");
        wprintf(L"2. push_front()\n");
        wprintf(L"3. pop_back()\n");
        wprintf(L"4. pop_front()\n");
        wprintf(L"5. traverse add\n");

        int input = _getch() - '0';
        wprintf(L"\n");

        int value;
        switch (input)
        {
        case 1: {
            wprintf(L"value: ");
            wscanf_s(L"%d", &value);

            sampleList.push_back(value);
        }
        break;

        case 2: {
            wprintf(L"value: ");
            wscanf_s(L"%d", &value);

            sampleList.push_front(value);
        }
        break;

        case 3: {
            value = sampleList.back();
            wprintf(L"value: %d\n", value);
            sampleList.pop_back();
        }
        break;

        case 4: {
            value = sampleList.front();
            wprintf(L"value: %d\n", value);
            sampleList.pop_front();
        }
        break;

        case 5: {
            //ListType::iterator iter = sampleList.begin();
            //ListType::iterator iterEnd = sampleList.end();
            //for (; iter != iterEnd; ++iter)
            //{
            //    ++(*iter);
            //}
            Traverse(sampleList, AddOne);
        }
        break;

        case 6: {
            wprintf(L"value: ");
            wscanf_s(L"%d", &value);
            sampleList.remove(value);
        }

        default:
            break;
        }

        if (i & 1)
            PrintList1(sampleList);
        else
            PrintList2(sampleList);
    }

    return 0;
}