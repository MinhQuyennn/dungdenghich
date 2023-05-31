#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;
//bai 1
struct Node
{
    int data;
    Node * next;
};

struct List
{
    Node * Head;
    Node * Tail;
};
// input: node, head, tail
//output: list


//bai 2
void CreateList(List & l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

Node * CreateNode(int x)
{
    Node * p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

//bai 3
void AddHead(Node * p, List & l)
{
    if(l.Head == NULL)
    {
        l.Head=p;
        l.Tail = l.Head;
    }
    else
    {
        p->next = l.Head;
        l.Head = p;
    }
}
//input: Node, list
//ouput: List duoc them vao dau

//bai 4
void AddTail(Node * p, List & l)
{
    if(l.Head == NULL)
    {
        l.Head = p;
        l.Tail = l.Head;
    }
    else
    {
        l.Tail->next = p;
        l.Tail = p;
    }
}
//input: Node, list
//ouput: List duoc them vao cuoi

void Output(List l)
{
    int i =1;
    for(Node* p =l.Head;p != NULL; p=p->next )
    {   
        cout <<"gia tri node " << i << ": " << p->data << " " << endl;
        i++;
    }
}

/*
Input:  x
        list
Output: return bool*/

bool FindX(int x, List l)
{
    for(Node *p=l.Head; p!=NULL; p=p->next)
    {
        if(p->data == x) return true;
    }
    return false;
    
}


/*
Input:  list
Ouput: list ->ref*/
void XoaDau(List &l)
{
    Node *p=new Node;
    p=l.Head;
    l.Head= l.Head->next;
    delete p;
}

/*Input:    list
Output:     List-> ref
            return true*/
bool XoaDauu(List &l)
{
    Node *p=new Node;
    p=l.Head;
    l.Head= l.Head->next;
    delete p;
    return true;
}

int main()
{
    List l;
    CreateList(l);
    int n;
    do
    {
        cin >> n;
        if(n==0) break;
        Node * p =CreateNode(n);
        AddTail(p, l);
    } while (n!=0);
    cout << "mang l: " << endl;
    Output(l);
    
    
    
}