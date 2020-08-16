/*
	Implemention of circular queue using array
*/

#include <iostream>
#include <string>

using namespace std;

class CircularQueue{
	private:
		int arr[5];
		int front;
		int rear;
	public:

		CircularQueue(){
			front = -1;
			rear = -1;
		}

		bool isEmpty(){
			if(front == -1 && rear == -1){
				return true;
			}
			else{
				return false;
			}
		}

		bool isFull(){
			if((rear+1)%5 == front){
				return true;
			}
			else{
				return false;
			}
		}

		void Enqueue(int val){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
			else if(isEmpty()){
				rear = 0;
				front = 0;
			}
			else{
				rear = (rear+1)%5;
			}

			arr[rear] =  val;
		}

		int Dequeue(){
			int x = 0;
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
			}
			else if(front == 0 && rear == 0){
				x = arr[front];
				rear=-1;
				front = -1;
			}
			else{
				x = arr[front];
				front = (front+1)%5;
			}
			return x;
		}

		int count(){
			return (rear - front + 1);
		}

		void display(){
			cout<<"The elements of the queue are: "<<endl;
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<endl;
			}
		}
};

int main()
{

	CircularQueue q;
	int val, option, exit = 0;

	do
	{
		// ACTION MENU
		cout << "What operation would you want to perform?" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display queue" << endl;
		cout << "4. Exit" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "Enter value to enqueue: " << endl;
			cin >> val;
			q.Enqueue(val);
			break;
		}

		case 2:
		{
			int rem = q.Dequeue();
			cout << rem << " dequeued!" << endl;
			break;
		}
		case 3:
		{
			q.display();
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