#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int tos;
    int size;
    int *s;
};

struct stack st;

int isfull()
{
    if(st.tos == st.size-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(st.tos == -1)
        return 1;
    else
        return 0;
}

void push(int n) 
{
    if(isfull()){ 
        printf("Stack is full! Can't add %d\n", n);
    }
    else{
        st.s[++st.tos] = n;
        printf("Pushed %d\n", n);
    }
}

int pop()
{
    int x = -1;
    if(isempty()){ 
        printf("Stack is empty!\n");
    }
    else{
        x = st.s[st.tos--]; 
        printf("Popped %d\n", x);
    }
    return x;
}

int peek()
{
    int x = -1;
    if(isempty()){ 
        printf("Stack is empty! Can't peek\n");
    }
    else{
        x = st.s[st.tos];
        printf("Peeked %d\n", x);
    }
    return x;
}

void display()
{
    if(isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements (top to bottom):\n");
        for(int i = st.tos ; i>=0 ; i--){
            printf("%d\n", st.s[i]); 
        }
    }
}


int main()
{
    st.tos = -1;
    st.size = 0;
    st.s = NULL;
    
    printf("Enter the size of stack you want: ");
    scanf("%d",&st.size);

    st.s = (int*)malloc(sizeof(int)*st.size);

    while(1){
        int op;
        printf("Enter the function you want to perform!\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                int val;
                printf("Enter the value you want to push\n");
                scanf("%d",&val);
                push(val);
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                free(st.s);
                exit(1);
        }
    }
    return 0;
}
