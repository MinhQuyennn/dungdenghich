#include<iostream>
#include<ctime>
#include<string>
#include<math.h>
#include<algorithm>
#include<string.h>

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
/*
Input: SINH_VIEN, time_t
Output: SINH_VIEN -> ref
*/
void RandomName(SINH_VIEN & sv, time_t seed)
{
    string ho[] = {"pham" , "nguyen", "ha", "tran" , "thi", "ho"};
    string tenlot[] = {"minh", "ngoc", "thu", "yen", "thanh", "thu"};
    string ten[]={"quyen", "huyen", "thao", "thanh", "vy", "thi"};
    //srand((int)time(0));
    srand(seed);
    sv.NAME = ho[0 + rand()%5]+ " " + tenlot[0 + rand()%5] + " " + ten[0 + rand()%5]; 
}
/*
Input: time_t
Output: return int ID
*/
int RandomID(time_t seed)
{
    srand(seed);
    return 100 + rand()%(900+1-100);
}
/*
Input: time_t
Output: return float GPA
*/
float RandomGPA(time_t seed)
{
    srand(seed);
    float tuso = 500;
    int mauso= 50 + rand()%(500+1-50);
    float so = tuso/(float)mauso;
    return round(so*100)/100;
}

/*
Input: SINH_VIEN, time_t
Output: SINH_VIEN -> ref
*/
void InputRandom(SINH_VIEN & sv, time_t seed)
{
    sv.ID = RandomID(seed);
    sv.GPA= RandomGPA(seed);
    RandomName(sv, seed);
}

/*
Input: SINH_VIEN, list
Output: SINH_VIEN -> ref, list->ref
*/
void Random(List &l, SINH_VIEN &sv)
{
    int sl;
    time_t tempTime = time(0);
    srand(tempTime);
    sl= 1+ rand()%15;
    for(int i=1; i<=sl; i++)
    {
        tempTime++;
        InputRandom(sv, tempTime);
        Node *p =CreateNode(sv);
        AddTail(p, l);
    }
}

//bai 8
/*
Input: List
Ouput: cout list
*/
void Output(List l)
{
    int i =1;
    for(Node* p =l.Head;p != NULL; p=p->next )
    {   
        cout <<"sinh vien thu " << i << endl; 
        cout << "Ho va ten: " << p->sv.NAME << endl;
        cout << "ID: " << p->sv.ID << endl;
        cout << "GPA: " << p->sv.GPA << endl;
        cout << "--------------" << endl;
        i++;
    }
}

//bai9
/*
Input: list, int 
Ouput: cout name hoac bao khong thay
*/
void FindID(List l, int id)
{
    int flag=0;
    for(Node *p=l.Head; p!=NULL; p=p->next)
    {
        if(p->sv.ID == id) 
        {
            cout << p->sv.NAME << endl;
            flag++;
        }
    }
    if(flag == 0) cout << "khong tim thay sv co ID " << id;
}

//bai 10
/*
input: string, char[]
output: char[]-> ref
*/
void ConvertStringtoChar(string st, char temp[])
{
    for(int i=0; i<st.size()+1; i++)
    temp[i]=st[i];
}
/*
input: list, string
output: list-> cout
*/
void FindName(List l, string name)
{
    int flag=0;
    char name1[30];
    ConvertStringtoChar(name, name1);
    cout << "Ket qua tim kiem: " << endl;
    for(Node *p = l.Head; p!= NULL; p=p->next)
    {
        string st = p->sv.NAME;
        char st1[30];
        ConvertStringtoChar(st, st1);
        if(strstr(st1, name1) != NULL)
        {
            cout << p->sv.NAME << endl;
            flag++;
        }
    }
    if(flag == 0) cout << "khong tim thay!";
}

//bai11
/*
Input: list, float
Ouput: cout name hoac bao khong thay
*/
void FindGPA(List l, float gpa)
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
    if(flag == 0) cout << "khong tim thay sv co GPA " << gpa;
}

//bai 12
/*
Input: list
Output: cout name 
*/
void FindMaxGPA(List l)
{
    float max =0;
    for(Node *p=l.Head; p!=NULL; p=p->next)
    {
        if(p->sv.GPA > max) max = p->sv.GPA;
    }
    FindGPA(l, max);
}

//bai 13
/*
Input: list, float
Ouput: cout name
*/
void FindMinGPA(List l)
{
    float min =10;
    for(Node *p=l.Head; p!=NULL; p=p->next)
    {
        if(p->sv.GPA < min) min = p->sv.GPA;
    }
    FindGPA(l, min);
}

//bai 14
// input: List
// ouput: cout list 
void Sort10SV(List l)
{
    for(Node * p=l.Head; p!=NULL ; p=p->next)
    {
        for(Node *k=p->next; k!=NULL; k=k->next)
        {
            if(p->sv.GPA < k->sv.GPA) swap(p->sv, k->sv);
        }
    }
    int i=1;
    for(Node* p =l.Head;p != NULL; p=p->next )
    {
        if(i == 11) break;
        cout << "Danh sach 10 sinh vien co GPA cao nhat: " << endl;
        cout << "sinh vien thu " << i << endl; 
        cout << "Ho va ten: " << p->sv.NAME << endl;
        cout << "ID: " << p->sv.ID << endl;
        cout << "GPA: " << p->sv.GPA << endl;
        cout << "--------------" << endl;
        i++;
    }
}

//bai 15
//input: list
//ouput: list-> ref
void XoaDau(List &l)
{
    Node *p=new Node;
    p=l.Head;
    l.Head= l.Head->next;
    delete p;
}
//input: list
//ouput: list-> ref
void XoaCuoi(List &l)
{
    for(Node *k = l.Head; k != NULL; k = k ->next)
    {
        if(k->next == l.Tail)
        {
            delete l.Tail;
            k->next = NULL;
            l.Tail = k;
        }
    }
}

//input: list
//ouput: update list
void DeleAtID(List &l)
{
    int id;
    cout << "ID ban muon xoa la: " ;
    cin >> id;
    for(Node * k =l.Head; k != NULL; k = k->next)
    {
        Node * h = k->next;
        if(h == NULL) break;
        if(id == l.Tail->sv.ID)
        {
            XoaCuoi(l);
        }
        if(id == l.Head->sv.ID)
        {
            XoaDau(l);
        }
        if(h->sv.ID == id)
        {
            k->next = h->next;
            delete h; 
        }
    }
    cout << "\nDa xoa thanh cong!" << endl;
    Output(l);
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
        cout << "7. Tao danh sach sinh vien bang phuong phap tu dong: " << endl;
        cout << "8. In danh sach" << endl;
        cout << "9. Tim sinh vien theo ID" << endl;
        cout << "10. Tim sinh vien theo Ten" << endl;
        cout << "11. Tim sinh vien theo GPA" << endl;
        cout << "12. Sinh vien co GPA cao nhat" <<endl;
        cout << "13. Sinh vien co GPA thap nhat" <<endl;
        cout << "14. Xuat 10 sinh vien co GPA cao nhat" << endl;
        cout << "15. Xoa sinh vien theo ID" << endl;
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
        Random(l, sv); 
        Output(l);
    }
    else if(choice == 8) Output(l);
    else if(choice == 9)
    {
        int id;
        cout << "nhap ID ban muon tim sv: ";
        cin >> id;
        FindID(l,id);
    }
    else if(choice == 10)
    {
        string name;
        cout << "nhap ten ban muon tim: ";
        cin.ignore();
        getline(cin, name);
        FindName(l,name);

    }
    else if(choice ==11)
    {
        float gpa;
        cout << "nhap GPA ban muon tim sv: ";
        cin >> gpa;
        FindGPA(l,gpa);
    }
    else if(choice == 12)
    {
        FindMaxGPA(l);
    }
    else if(choice == 13)
    {
        FindMinGPA(l);
    }
    else if(choice ==14)
    {
        Sort10SV(l);
    }
    else if(choice ==15)
    {
        DeleAtID(l);
    }
    int choicee;
    cout << "\nban co muon tiep tuc? ";
    cout << "\n1. co";
    cout << "\n2. khong";
    cout << "\nChon: ";
    cin >> choicee;
    if(choicee == 1) goto menu;
    else cout << "chao tam biet!";
}
// STT: 19
// Ho va ten: Pham Ha Minh Quyen
// Buoi 2 - bai 2
