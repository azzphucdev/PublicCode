#include<iostream>
#include<string.h>
#include<thread>

using namespace std;
int main(){
    char a[] = "Hello World !!";
    int sizeA = sizeof(a) / sizeof(char);
    char b[sizeA];
    int z = 0;
    int min = 32;
    int max = 126;
    while(z < sizeA - 1){
        for(int i = min;i<max;i++){
            for(int i2 = 0; i2<z;i2++){
                printf("%c",b[i2]);
            }
            printf("%c\n",i);
            this_thread::sleep_for(chrono::milliseconds(1));
            if(a[z] == i){
                b[z] = i;
                z++;
                break;
            }
            
        }
    }
    return 0;
}
