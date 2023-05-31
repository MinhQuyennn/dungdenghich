#include<iostream>
#include<ctime>
#include<string>
#include<math.h>

using namespace std;

//bai 1
struct SINH_VIEN
{
    int ID;
    string NAME;
    float GPA;
};

//bai 2
struct Node
{
    SINH_VIEN sv;
    Node * next;
};

struct List
{
    Node * Head;
    Node * Tail;
};


//bai 3
void CreateList(List & l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

Node * CreateNode(SINH_VIEN sv)
{
    Node * p = new Node;
    p->sv = sv;
    p->next = NULL;
    return p;
}

//bai 4
/*
Input: Node, list
Output: List
*/
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

//bai 5
/*
Input: Node, list
Output: List
*/
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




//bai 6
/*
Input: sinh_vien , list, int
Output: list->ref, sinh_vien->ref
*/
void Input(SINH_VIEN &sv)
{
    cout << "ID: ";
    cin >> sv.ID;
    fflush(stdin);
    cout << "NAME: ";
    getline(cin, sv.NAME);
    fflush(stdin);
    cout << "GPA: ";
    cin >> sv.GPA;
}

void NhapSV(List &l, SINH_VIEN sv, int choice)
{
    int sl;
    cout << "so luong sinh vien nhap la: " ;
    cin >> sl;
    for(int i=1; i<= sl; i++)
    {
        cout << "sinh vien thu " << i <<endl;
        Input(sv);
        Node *p =CreateNode(sv);
        if(choice == 5)
        AddTail(p, l);
        else AddHead(p,l);
    }
}

//bai 7
void RandomName(SINH_VIEN & sv)
{
    string ho[] = {"pham" , "nguyen", "ha", "tran" , "thi", "ho"};
    string tenlot[] = {"minh", "ngoc", "thu", "yen", "thanh", "thu"};
    string ten[]={"quyen", "huyen", "thao", "thanh", "vy", "thi"};
    srand((int)time(0));
    sv.NAME = ho[0 + rand()%5]+ " " + tenlot[0 + rand()%5] + " " + ten[0 + rand()%5]; 
}

int RandomID()
{
    srand((int)time(0));
    return 100 + rand()%(300+1-100);
}
float RandomGPA()
{
    srand((int)time(0));
    float tuso = 500;
    int mauso= 50 + rand()%(500+1-50);
    float so = tuso/(float)mauso;
    return round(so*100)/100;
}

void InputRandom(SINH_VIEN & sv)
{
    sv.ID = RandomID();
    sv.GPA= RandomGPA();
    RandomName(sv);
}

void Random(List &l, SINH_VIEN &sv)
{
    int sl;
    srand((int)time(0));
    sl= 1+ rand()%15;
    for(int i=1; i<=sl; i++)
    {
        InputRandom(sv);
        Node *p =CreateNode(sv);
        AddTail(p, l);
    }
}

void Output(List l)
{
    int i =1;
    for(Node* p =l.Head;p != NULL; p=p->next )
    {   
        cout <<"sinh vien thu " << i << endl; 
        cout << "Ho va ten: " << p->sv.NAME << endl;
        cout << "ID: " << p->sv.ID << endl;
        cout << "GPA: " << p->sv.GPA << endl;
        i++;
    }
}

void FindID(List l, float gpa)
{
    int flag=0;
    for(Node *p=l.Head; p!=NULL; p=p->next)
    {
        if(p->sv.GPA == gpa) 
        {
            cout << p->sv.NAME << endl;
            flag++;
        }
    }
    if(flag == 0) cout << "khong tim thay sv co gpa " << gpa;

}




int main()
{
    int choice;   
    SINH_VIEN sv;
    List l;
    CreateList(l);
    cout << "xin chao!" << endl;
    menu: 
    {
        cout << "6. Nhap sinh vien bang phuong phap thu cong: " << endl;
        cout << "7. tao danh sach sinh vien bang phuong phap tu dong: " << endl;


        do
        {
            cout << "\nmoi ban chon so: ";
            cin >> choice;
        } while (choice <6 || choice > 15);
    }
    if(choice == 6)
    {
        int x;
        cout << "\nban muon nhap dau hay cuoi list: ";
        cout << "\nnhap dau chon 4, nhap cuoi chon 5: ";
        cout << "\nchon: ";
        cin >> x;
        NhapSV(l, sv, choice);
    }
    else if(choice == 7)
    {
        Random(l, sv);    Output(l);
    }
    else;
    int choicee;
    cout << "ban co muon tiep tuc? ";
    cout << "\n1. co";
    cout << "\n2. khong";
    cout << "\nChon: ";
    cin >> choicee;
    if(choicee == 1) goto menu;
    else cout << "chao tam biet!";



}