#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using std::cout, std::endl, std::string;


template <typename Data>
struct list
{
private:
    typedef struct node 
    {
        Data val;
        struct node* next;
    } Node;
    Node* head;
    size_t size;
    
    Node* step_p (int number)
    {
        if (number < 0 || number > size)
            return NULL;
        
        Node* result = head;
        for (int i = 1; i < number; i++)
        {
            result = result -> next; 
        }
        
        return result;
    }
    
public:
    list()
    {
        head = NULL;
        size = 0;
    }
    
    list (std::initializer_list<Data> il)
    {
        head = NULL;
        size = 0;
        Data* values = new Data[il.size()];
        std::copy(il.begin(), il.end(), values);
        for (size_t i = il.size() - 1; i > 0; i--)
            push_front (values[i]);
        push_front (values[0]);
        
        delete values;
    }
    
    void push_front(Data x)
    {
        // Выделяем новый элемент и задаём его значения
        Node* p_new_node = new Node();
        p_new_node->val = x;
        p_new_node->next = head;

        // Изменяем head
        head = p_new_node;
        size++;
    }
    
    Data pop_front ()
    {
        if (head == NULL)
        {
            cout << "Error! Can't remove an element. List is empty!" << endl;
            exit(1);
        }
        // Запоминаем result, чтобы вернуть это значение и temp, чтобы освободить эту память в конце функции
        Node* temp = head;
        Data result = temp->val;

        // head должен указывать на 2-й элемент
        head = head->next;
        free(temp);

        size--;
        return result;
    }
    
    void insert_after(int n_node, Data x)
    {
        Node* p_node = step_p (n_node);
        Node* p_new_node = new Node ();
        p_new_node->val = x;
        p_new_node->next = p_node->next;

        p_node->next = p_new_node;
        size++;
    }
    Data erase_after(int n_node)
    {
        Node* p_node = step_p (n_node);
        
        if (p_node == NULL || p_node->next == NULL)
            cout << "Error! Can't erase element from list" << endl;

        Node* temp = p_node -> next;
        Data temp_value = p_node -> next -> val;

        p_node -> next = p_node -> next -> next;
        delete temp;
        size--;
        return temp_value;
    }
    
    void print () const
    {
        cout << "List: size = " << size << ", elements = { ";
        Node* ptr = head;
        while (ptr)
        {
            cout << ptr->val << ", ";
            ptr = ptr->next;
        }
        cout << "\b\b }" << endl;
    }
    
    size_t get_size () const
    {
        return size;
    }
    
    Data get_elem (int number)
    {
        if (number < 0 || number > size)
            cout << "Error of get_elem: number < 0 or number > size" << endl;
        else
        {
            Node* walker = head;
            for (int i = 1; i < number; i++)
            {
                walker = walker -> next; 
            }
            
            return walker -> val;
        }
        
        return 0;
    }
    
    list& operator=(list& right)
    {
        // Проверяем на случай a = a
        if (&right == this)
            return *this;

        Node* ptr = head;
        Node* ptr_next;
        while (ptr != NULL)
        {
            ptr_next = ptr->next;
            delete ptr;
            ptr = ptr_next;
        }
        head = NULL;
        
        size = 0;
        push_front (right.get_elem(1));
        for (size_t i = 1; i < right.size; i++)
        {
            insert_after (i, right.get_elem(i + 1));
        }
        return *this;
    }
    
    ~list ()
    {
        Node* ptr = head;
        Node* ptr_next;
        while (ptr != NULL)
        {
            ptr_next = ptr->next;
            delete ptr;
            ptr = ptr_next;
        }
        head = NULL;
    }

};

int main()
{
    /*
    list<int> a;

    for (int i = 0; i < 10; ++i)
        a.push_front(i * i);

    a.print();

    a.insert_after(3, 123);
    a.insert_after(3, 654);

    a.print();

    a.erase_after (3);
    a.erase_after (3);
    
    list<char> b;
    
    cout << b.get_elem (-1) << endl;

    a.print();
    */
    list<int> a = {1, 2};
    
    list<int> b = {3, 4};
    
    b = a;
    cout << b.get_elem (1) << endl;
    
    b.print();
}
