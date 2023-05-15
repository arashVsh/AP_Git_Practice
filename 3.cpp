#include<stdio.h> 
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long x;
	alfaptr next;
};
alfaptr rear = NULL, front = NULL;
void push(int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	if (front == NULL)
		front = node;
	node->next = NULL;
	if (rear != NULL)
		rear->next = node;
	rear = node;
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1");
	else
	{
		node = front;
		front = front->next;
		free(node);
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node) {
		if (node->x == x) {
			counter++;
			printf("%d\t", counter);
		}
		else if(node ==NULL && counter==0)  {
			printf("ERROR2");
			break;
		}
		node = node->next;
	}
	
}

void rpop() {
	alfaptr node = front;
	while (node->next != rear)
		node = node->next;
	free(rear);
	rear = node;
	rear->next = NULL;
}
int size()
{
	alfaptr node = front;
	int count = 0;
	while (node) {
		count++;
		node = node->next;
	}
	return count;
}
void set()
{
	alfaptr node = front;
	for (int i = 0; i < size() && node; i++, node = node->next)
		arr[i] = node->x;
}
void show()
{
	if (front) {
		for (int i = 0; i < size(); i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	}
}

// here is a better implementaion of the show function
//void show()
//{
//	if (front) {
//		alfaptr node = front;
//		while (node) {
//			printf("%lld ", node->x);
//			node = node->next;
//		}
//	}
//	else {
//		for (int i = 0; i < MAX_SIZE; i++)
//			printf("%d ", arr[i]);
//	}
//}

int average()
{
	alfaptr node = front;
	int sum = 0;
	int count = 0;
	while (node) {
		sum += node->x;
		count++;
		node = node->next;
	}
	return sum / count;
}

int  main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1://push  
			scanf("%lld", &x);
			push(x);
			break;
		case 2://pop  
			pop();
			break;
		case 3://rpop  
			rpop();
			break;
		case 4://search  
			scanf("%lld", &x);
			search(x);
			break;
		case 5://set  
			set();
			break;
		case 6://show  
			show();
			break;
		case 7://size  
			printf("%d", size());
			break;
		case 10:
			exit(0);
		}
	}
}