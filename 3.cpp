#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long int x;
	alfaptr next;
};
alfaptr rear = NULL, front = NULL, tail = NULL;
void push(long long int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	if (!front) {
		rear = tail = front = node;
		node->next = NULL;
	}
	else {
		rear = node;
		rear->next = tail;
		tail = rear;
	}
}

void pop()
{
	if (!front) {
		printf("ERROR1");
		return;
	}
	if (front == rear) {
		front = rear = tail = NULL;
		return;
	}
	alfaptr tmp = rear;
	for  (; tmp->next != front; tmp = tmp->next){}
	tmp->next = NULL;
	front = tmp;
}
int search(long long int x)
{
	alfaptr node = rear;
	int counter = 0;
	while (node) {
		if (node->x == x)
			counter++;
		node = node->next;
	}
	return counter;
}

void rpop() {//pop last element
	alfaptr tmp = rear;
	tail = rear = tmp->next;
	free(tmp);
}

void set()
{
	alfaptr node = rear;
	for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
		arr[i] = node->x;
}

int size()
{
	alfaptr node = rear;
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
		alfaptr node = rear;
		for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
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
	return sum / count;
}

void main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf_s("%d", &cmd);
		switch (cmd)
		{
		case 1://push
			scanf_s("%lld", &x);
			push(x);
			break;
		case 2://pop
			pop();
			break;
		case 3://rpop
			rpop();
			break;
		case 4://search
			scanf_s("%lld", &x);
			printf("%d\n", search(x));
			break;
		case 5://set
			set();
			break;
		case 6://show
			show();
			break;
		case 7://size
			printf("%d\n", size());
			break;
		case 10:
			exit(0);
		}
	}
}