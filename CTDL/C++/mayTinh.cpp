#include <math.h>
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
template<typename T> struct StackNode {
    T data;
    struct StackNode<T> *next;
    StackNode() : next(NULL) {};
};
template<typename T> struct Stack {
    private:
        struct StackNode<T> *top;
    public:
        Stack() : top(NULL) {};
        bool isEmpty(){
            return this->top == NULL;
        }
        T pop(){
            if(isEmpty()){
                return T();
            }
            StackNode<T> *p = this->top;
            T tg = p->data;
            if(this->top->next != NULL){
                this->top = this->top->next;
            } else {
                this->top = NULL;
            }
            delete p;
            return tg;
        }
        T peek(){
            if(isEmpty()){
                return T();
            }
            T p = this->top->data;
            return p;
        }
        bool push(T data){
            struct StackNode<T> *node = new StackNode<T>;
            if(node == NULL){
                cout << "K Du Bo Nho";
                return false;
            }
            node->data = data;
            if(!isEmpty()){
                node->next = this->top;
            }
            this->top = node;
            return true;
        }
};
int doUuTien(char toanTu){
    switch (toanTu) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    };
}
string toHauTo(string str, int size){
    string result = "";
    Stack<char> *stack = new Stack<char>;
    if(stack == NULL){
        cout << "Khong Cap Phap Dc Bo Nho" << endl;
        return result;
    }
    int s = 0;
    for(int i = 0;i < size; i++){
        char c = str[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(c)){
            string num = "";
            num += c;
            int z = 0;
            for(int j=i+1;j<size;j++){
                int d = str[j];
                if(d >= 48 && d <= 57){
                    num += str[j];
                    z++;
                } else {
                    break;
                }
            }
            result += num;
            result += ' ';
            i += z;
        } else if(c == '(') {
            stack->push(c);
        } else if(c == ')'){
            while(!stack->isEmpty() && stack->peek() != '('){
                result += stack->pop();
                result += ' ';
            }
            stack->pop();
        } else {
            while(!stack->isEmpty() && doUuTien(c) <= doUuTien(stack->peek())){
                result += stack->pop();
                result += ' ';
            }
            stack->push(c);
        }
    }
    while(!stack->isEmpty()){
        result += stack->pop();
        result += ' ';
     }
    return result;
}
double tinhToan(string hauTo, int size){
    Stack<double> *stack = new Stack<double>;
    if(stack == NULL){
        cout << "Khong Du Bo Nho" << endl;
        return -1;
    }
    int countCaculator = 0;
    for(int i = 0;i < size;i++){
        char c = hauTo[i];
        if(c == ' '){
            continue;
        }
        if(isdigit(c)){
            double num = 0;
            int z = 0;
            for(int j=i+1;j<size;j++){
                int d = hauTo[j];
                if(d >= 48 && d <= 57){
                    z++;
                } else {
                    break;
                }
            }
            if(z != 0){
                int mO = 0;
                for(int o = (i + z);o >= i; o--){
                    int m = hauTo[o] - '0';
                    num += (m * (pow(10,mO)));
                    mO ++;
                }
            } else {
                num += (c - '0');
            }
            stack->push(num); // cho ve double ( char )
            i += z;
        } else {
            double r = 0;
            double v2 = stack->pop();
            double v1 = stack->pop();
            switch (c)
            {
            case '+':
                r = v1 + v2;
                break;
            case '-':
                r = v1 - v2;
                break;
            case '*':
                r = v1 * v2;
                break;
            case '/':
                r = v1 / v2;
                break;
            case '^':
                r = pow(v1, v2);
                break;
            default:
                r = -1;
                break;
            };
            countCaculator ++;
            cout << "Caculator: "<< countCaculator << ". " << v1 << " " << c << " " << v2 << " = " << r << endl;
            stack->push(r);
        }
    }
    return stack->pop();
}
int main(){
    string str = "173 - (99 + 10 ^ 11 / (10000 - 5) * (115664 / 10 ^ 10)^9)";
    //cout << "Enter Phep Tinh: ";
    //getline(cin,str);
    cout << "Phep Tinh: " << str << endl;
    int size = str.size();
    string strHauTo = toHauTo(str,size);
    cout << "Phep Tinh Hau To: " <<strHauTo << endl;
    double tinhToanStr = tinhToan(strHauTo,strHauTo.size());
    cout << "Ket Qua Phep Tinh: " << tinhToanStr << endl;
    return 0;
}
