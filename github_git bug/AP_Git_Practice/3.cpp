#include<stdio.h>
#include<stdlib.h>
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
	node->next = NULL;
	if (!front) {
		front = node;
		rear = node;
	}
	else {
		rear->next = node;
		rear = node;
	}
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1");
	else
	{
		node = front->next;
		free(front);
		front = node;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node) {
		if (node->x == x) {
			printf("%d", counter);
			return;
		}
		node = node->next;
		++counter;
	}
		
	printf("ERROR2");
}

void rpop() {//pop last element
	alfaptr node = front;
	if (!front)
		printf("ERROR-404");
	else if (!node->next) {
		front = NULL;
		rear = NULL;
		free(node);
	}
	else {
		while (node->next->next)
			node = node->next;
		free(rear);
		rear = node;
		rear ->next = NULL;
	}
}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
		arr[i] = node->x;
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

void show()
{
	if (front) {
		for (int i = 0; i < MAX_SIZE; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	}
}

int average()
{

	alfaptr node = front;
	int sum = 0, count = 0;
	
	while (node) {
		sum += node->x;
		count++;
		node = node->next;
	}
	if (!count)
		throw 1;
	return sum / count;
}

void main()
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
		case 8://average
			try {
				int n;
				n = average();
				printf("%d", n);
			}
			catch (int) {
				printf("Empty!\n");
			}
			break;
		case 10:
			exit(0);
		}
	}
}