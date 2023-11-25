using namespace std;
#include<iostream>
struct node
{
	int info;
	node* link;
};
node* front = 0, * rear = 0;

void enqueue(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = 0;
	if (front == 0 && rear == 0)
		front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}
	return;
}

int dequeue()
{
	int x;
	node* p;
	if (front == 0 && rear == 0)
	{
		cout << "Queue is empty........! " << endl;
		return -1;
	}
	x = front->info;
	p = front;
	if (front == rear)
		front = rear = 0;
	else
		front = front->link;
	delete p;
	return x;

}

void display()
{
	node* t;
	t = front;
	if (t == 0)
	{
		cout << "Queue is Empty........! " << endl;
		return;
	}
	cout << "All the Elem in Queue is : " << endl;
	while (t != 0)
	{
		cout << t->info << endl;
		t = t->link;
		
	}
	return;
}

int main()
{
	int v, ch;
	do
	{
		cout << "1.Enqueue \n2.Dequeue \n3.Display \n4.Exit" << endl;
		cout << "Enter the choice : ";      cin >> ch;     
		switch (ch)
		{
		case 1:cout << "Enter Enqueue Elem : " << endl;
			cin >> v;    enqueue(v);   break;
		case 2:v = dequeue();
			cout << "The value is  deleted : " << v << endl;   break;
		case 3:display();   break;
		default:cout << "Exiting" << endl;
		ch = 4;
		}
	} while (ch != 4);
}