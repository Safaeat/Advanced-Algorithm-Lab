#include<iostream>
#include<cctype>
#include<fstream>
#include<cstdlib>
#include<istream>
using namespace std;

struct NodeType;
typedef NodeType* Nodeptr;
typedef char StackType;

class Stack
{
    public:
           bool IsEmpty()const;
           bool IsFull() const;
           void Push(StackType newItem);
           StackType StackTop() const;
           void Pop();
           Stack();
           ~Stack();

    private:
            Nodeptr top;
};

struct NodeType
{
    StackType item;
    Nodeptr link;
};

// Function declarations
void describeProgram();
void read_expression(char expression[60]);
void check_expression(char expression[60], bool& valid);
void report_result(char expression[60], bool valid);

int main()
{
    char expression[60];  //Expression to be read from the keyboard
    bool valid;           //true id expression is valid, false otherwise

        read_expression(expression);
        check_expression(expression, valid);
        report_result(expression, valid);

    return 0;
}


Stack::Stack()
{
   top = NULL;
}

Stack::~Stack()
{
   Nodeptr p;
   while(top != NULL)
   {
      p = top;
      top = top->link;
      delete p;
   };
   return;
}

bool Stack::IsEmpty() const
{
   return (top == NULL);
}

bool Stack::IsFull() const
{
    int* p;
   return (!(p = new int));
}

void Stack::Push(StackType newItem)
{
   Nodeptr q;
   q = new NodeType;
   q->item = newItem;
   q->link = top;
   top = q;
   return;
}

StackType Stack::StackTop() const
{
   return top->item;
}

void Stack::Pop()
{
   Nodeptr p;
   p = top;
   top = top->link;
   delete p;
   return;
}

void read_expression(char expression[60])
{
    cout << "Enter your mathematical expression: \n";
    cin.ignore();
    cin.getline(expression,60);

    while(expression == NULL)
    {
        cout << "Please enter a valid expression: \n";
        cin.ignore();
        cin.getline( expression,60);
    }
    return;
}

void check_expression(char expression[60], bool& valid)
{
    Stack symbStack;
    char symbol, top_symb;
    int i = 0;

    valid = true;
    symbol = expression[i];

    while(symbol != '\0')
    {
        if( symbol == '{' || symbol == '[' || symbol == '(' )
        {
            symbStack.Push(symbol);
        }

        else if( symbol == '}' || symbol == ']' || symbol == ')' )
        {
            if(symbStack.IsEmpty())
            {
                cout << "Expression is invalid! \n";
                valid = false;
                return;
            }

            else
            {
                top_symb = symbStack.StackTop();
                symbStack.Pop();
            }

            if(  (top_symb != '(' && symbol == ')') ||
                 (top_symb != '[' && symbol == ']') ||
                 (top_symb != '{' && symbol == '}')  )
            {
                valid = false;
            }
        }
        i++;
        symbol = expression[i];
    }

    if(!(symbStack.IsEmpty()))
        valid = false;
    return;
}

void report_result(char expression[60], bool valid)
{
    ofstream toFile;
    toFile.open("scope.txt",ios::out);

    if(!valid)
    {
        cout << "\n The expression was an invalid expression \n";
        toFile << "\n The expression was an invalid expression \n";
    }

    else
    {
        cout << "\n The expression was a valid expression \n";
        toFile << "\n The expression was a valid expression \n";
    }
    toFile.close();

    return;
}
