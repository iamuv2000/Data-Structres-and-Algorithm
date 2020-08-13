/*
	Implemention of stack using array
*/

#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
	int top;
	int arr[5];

public:
	// Initialise top variable
	Stack()
	{
		top = -1;
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if (top == 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// PUSH INTO STACK
	void push(int val)
	{
		if (isFull())
		{
			cout << "Stack overflow" << endl;
		}
		else
		{
			top++;
			arr[top] = val;
		}
	}

	// POP FROM STACK
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			int popValue = arr[top];
			top--;
			return popValue;
		}
	}

	// NUMBER OF ELEMENTS IN STACK
	int count()
	{
		return top + 1;
	}

	// DISPLAY STACK ELEMENTS
	void display()
	{
		cout << "Elements in the stack are:" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << endl;
		}
	}
};

int main()
{

	Stack s;
	int val, option, exit = 0;

	do
	{
		// ACTION MENU
		cout << "What operation would you want to perform?" << endl;
		cout << "1. Push into stack" << endl;
		cout << "2. Pop from stack" << endl;
		cout << "3. Display stack" << endl;
		cout << "4. Exit" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "Enter value to push: " << endl;
			cin >> val;
			s.push(val);
			break;
		}

		case 2:
		{
			int popped = s.pop();
			cout << popped << " popped!" << endl;
			break;
		}
		case 3:
		{
			s.display();
			break;
		}

		case 4:
		{
			exit = 1;
			break;
		}
		default:
			cout << "Please enter a valid option!" << endl;
		}

	} while (exit == 0);
	return 0;
}