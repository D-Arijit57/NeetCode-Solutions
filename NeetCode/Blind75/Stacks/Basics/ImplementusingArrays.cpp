#include<bits/stdc++.h>
using namespace std;
 // stack<int>st;
 /*
 st.Push(); -> 0
 st.pop(); -> 1
 st.top(); -> 2
 st.size(); -> 3
 */
// implementing stack using arrays
// keep a top pointer 
// modify it on the basis of each operation done in the stack
class Stack{
    int size;
    int *arr;
    int top;
    public :
    Stack(){
        top  = -1;
        size  = 1000;
        arr = new int[size];
    }
    void Push(int x){
        top = top + 1;
        arr[top] = x;
    }
    int Pop(){
        int x = arr[top];
        top = top - 1;
        return x;
    }
    int Top(){
        return arr[top];
    }
    int Size(){
        return top + 1;
    }
};
int main(){
    Stack s;
    s.Push(6);
    s.Push(5);
    s.Push(4);
cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.Pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;

}