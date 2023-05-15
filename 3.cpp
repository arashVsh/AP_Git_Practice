#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa *alfaptr;

struct alfa
{
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
	if (!front)
	{
		front = node;
		rear = node; // rear should point to node too.
		rear->next = NULL;
	}
	else
	{
		rear->next = node;
		rear = node;
		rear->next = NULL;
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
	while (node)
	{
		if (node->x == x)
		{
			printf("%d", counter);
			return;
		}
		node = node->next;
		counter++; // should count every loop.
	}
	printf("ERROR2");
	// conditons should be in loop.
}

void rpop() // pop last element
{
	alfaptr node;
	node = front; // dont't change front position.
	while (node->next->next)
		node = node->next;
	free(rear);
	rear = node;
	rear->next = NULL;
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
	int count = 0; // should be zero .
	while (node)
	{
		node = node->next; // should be in loop.
		count++;
	}
	return count;
}

void show()
{
	if (front) // we don't need !
	{
		for (int i = 0; i < size(); i++) // i don't know that array is full or not.
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
	while (node)
	{
		sum += node->x;
		count++;
		node = node->next;
	}
	return sum / count;
}

int main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1: // push
			scanf("%lld", &x);
			push(x);
			break;
		case 2: // pop
			pop();
			break;
		case 3: // rpop
			rpop();
			break;
		case 4: // search
			scanf("%lld", &x);
			search(x);
			break;
		case 5: // set
			set();
			break;
		case 6: // show
			show();
			break;
		case 7: // size
			printf("%d", size());
			break;
		case 10:
			exit(0);
		}
	}
}