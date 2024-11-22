#include <iostream>
#include <string.h>

using namespace std;
struct StackNode{
    int info;
    struct StackNode *next;
};
struct Stack{
    struct StackNode *top;
};
void initStack(Stack &s){
    s.top = NULL;
} 
int isEmpty(Stack s){
    if(s.top == NULL) return 1;
    return 0;
}
void push(Stack &s,int x){
    StackNode *p;
    p = new StackNode;
    if(p == NULL){
        cout << "Khong Du Bo Nho" << endl;
        return;
    }
    p->info = x;
    p->next = s.top;
    s.top = p;
}
int pop(Stack &s){
    StackNode *p;
    int tg;
    if(isEmpty(s) == 1){
        cout << "Danh Sach Trong :((" << endl;
        return -1;
    }
    p = s.top;
    s.top = p->next;
    tg = p->info;
    delete p;
    return tg;
}
int main(){
    int n, b;
    cout << "Nhap So Nguyen n ( He TP ): ";
    cin >> n;
    cout << "Nhap He Co So b: ";
    cin >> b;
    if( b <= 0){
        cout << "Khong ton tai";
        return 1;
    }
    Stack *s = new Stack;
    initStack(*s);
    while(n > 0){
        int du = n % b;
        push(*s,du);
        n = n / b;
    }
    cout << "Ket Qua Khi Chuyen " << n << " Sang He Co So " << b << " La: ";
    while(isEmpty(*s) == 0){
        cout << pop(*s);
    }
    return 0;
}
