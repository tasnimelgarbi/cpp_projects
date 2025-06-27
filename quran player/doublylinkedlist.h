#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED
#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList
{
public:
    struct Node
    {
        T item;
        Node* next;
        Node* prev;
        Node(T val) : item(val), next(NULL), prev(NULL) {}
        bool operator == (const T& other )
        {
            return item == other ;
        }

    };

    DoublyLinkedList() : first(NULL), last(NULL), count(0) {}

    ~DoublyLinkedList()
    {
        clear () ;
    }

    Node * getFirst ()
    {
        return first ;
    }
    Node * getLast ()
    {
        return last ;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    void clear()
    {
        Node* current = first;
        while (current != first && count > 0)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
            count--;
        }
        first = last = nullptr;
    }

    void append(T value)
    {
        Node* newNode = new Node(value);
        if (!first) // القائمة فارغة
        {
            first = last = newNode;
            first->next = first;
            first->prev = first;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
            newNode->next = first;
            first->prev = newNode;
            last = newNode;
        }
        count++;
    }

    void Add(int pos, T value)
    {
        if (pos < 0 || pos > count)
        {
            cout << "Position out of range.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 0) // إضافة في البداية
        {
            if (isEmpty())
            {
                first = last = newNode;
                first->next = first;
                first->prev = first;
            }
            else
            {
                newNode->next = first;
                newNode->prev = last;
                first->prev = newNode;
                last->next = newNode;
                first = newNode;
            }
        }
        else if (pos == count) // إضافة في النهاية
        {
            append(value);
            return;
        }
        else
        {
            Node* current = first;
            for (int i = 0; i < pos; ++i)
            {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        count++;
    }

    void Delete(T value)
{
    if (isEmpty())
    {
        cout << "List is empty.\n";
        return;
    }

    Node* current = first;
    do
    {
        if (current->item == value)
        {
            // إذا كانت العقدة هي الوحيدة
            if (current == first && current == last)
            {
                first = last = nullptr;
            }
            else
            {
                // تعديل الروابط
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;

                // تحديث المؤشرات الأولية
                if (current == first)
                    first = current->next;
                if (current == last)
                    last = current->prev;

                // الحفاظ على الروابط الدائرية
                if (first && last)
                {
                    first->prev = last;
                    last->next = first;
                }
            }

            delete current;
            count--;
            return;
            cout << "Item Deleted.\n";
        }

        current = current->next;
    } while (current != first);

    cout << "Item not found.\n";
}

    void Display() const
    {
        if (isEmpty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node* current = first;
        while (current != last)
        {
            cout <<endl<< setw (55)<< current->item << endl ;
            current = current->next;
        }
        // عرض آخر عنصر
        cout <<endl<< setw (55)<< last->item << endl;
        cout <<endl<< setw (84)<< "==================================="<< endl;
    }

    void reversedDisplay() const
    {
        if (isEmpty())
        {
            cout << "List is empty.\n";
            return;
        }

        Node* current = last;
        while (current != first)
        {
            cout << current->item << endl;
            current = current->prev;
        }
        // عرض أول عنصر
        cout << first->item << endl;
    }

    int getsize() const
    {
        return count;
    }

    void update_pos_of_Value (int pos , T value)
    {
     T temp = value ;
     Delete (value) ;
     Add (pos,value) ;
    }



private:
    Node* first;
    Node* last;
    int count;
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
