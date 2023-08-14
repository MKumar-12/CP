//Stack Implmentation
//T.C. 
//S.C. 

#include<iostream>
using namespace std;
int stack_top = -1;
const int MAX_SIZE = 100;
int arr[MAX_SIZE];

class Stack {
    public:
        void push(int* arr, int n, int x) {
            if((stack_top+1) == (n-1))
                cout<<"\nSorry, OVERFLOW!!";
            else {
                arr[++stack_top] = x;
                cout<<"\nElement added to stack successfully!!!";
            }
        }

        int pop() {
            if(stack_top == -1)
                cout<<"\nSorry, UNDERFLOW!!";
            else {
                int top =  arr[stack_top--]; 
                cout<<"\nElement removed is : "<<top;
            }
        }

        int top() {
            return arr[stack_top];
        }

        int size() {
            return stack_top + 1;
        }

        void display_stack() {
            if(stack_top == -1)
                cout<<"\nStack is empty!!";
            else
            {
                for(int i = 0; i<=stack_top; i++)
                    cout<<arr[i]<<endl;
            }
        }
};

int main()
{
    int n, x, ch;

    Stack s;
    ag:
    cout<<"\nEnter the operation u wish to perform onto stack : ";
    cout<<"\nPress 1. for PUSH operation.";
    cout<<"\n2. for POP operation.";
    cout<<"\n3. for obtaining HEAD.";
    cout<<"\n4. for obtaining stack size.";
    cout<<"\n5. to display stack content.";
    cout<<"\n6. to continue.";
    cout<<"\n0. to Exit.";
    cout<<"\n\nYour choice : ";
    cin>>ch;
    switch (ch)
    {
    case 1: cout<<"\nEnter value : ";
            cin>>x;
            s.push(arr,n,x);
            break;
    
    case 2: s.pop();
            break;

    case 3: cout<<"\nCurrent Stack top is : "<<s.top();
            break;

    case 4: cout<<"\nCurrent Stack size is : "<<s.size();
            break;

    case 5: cout<<"\nStack is as follows :";
            s.display_stack();
            break;

    case 6: cout<<"\n\n";
            goto ag;
            break;
    
    case 0: exit(0);

    default:cout<<"No option choosen, exiting...";
            break;
    }
    return 0;
}