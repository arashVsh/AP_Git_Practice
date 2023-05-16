
#include <stdio.h>
#include <stdlib.h>


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
	node->next = NULL; /// next => null
	if (front == NULL) /// added null
		front = node;
	else {
		/// change somthing
		alfaptr curr = front;
		for (; curr->next != NULL; curr = curr->next);
		curr->next = node;
	}
}

void pop()
{
	alfaptr node;
	if (front == NULL)/// added null
		printf("ERROR1");
	else
	{
		node = front->next;
		front = node;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node != NULL) {///aded Null
		if (node->x == x) {
			printf("%d\n", counter);
			return;
		}
		++counter;
		node = node->next;   ///remove something
	}
	printf("ERROR2");
}

void rpop() {//pop last element
	alfaptr node = front;
	if (front == NULL) {
		printf("ERROR4");
		return;
	}
	if (node->next == NULL) {
		pop();
		return;
	}
	while (node->next->next != NULL)
		node = node->next;
	node->next = NULL;

	while (node->next != NULL)
		node = node->next;
	rear = node;

}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE && (node != NULL); i++, node = node->next)
		arr[i] = node->x;
}

int size()
{
	alfaptr node = front;
	int count = 0;///initialize vrb count = 0
	while (node != NULL) {
		count++;
		node = node->next;
	}
	return count;
}

void show()
{
	if (front != NULL) {
		alfaptr node = front;
		//for (int i = 0; i < MAX_SIZE && (node != NULL); i++, node = node->next)
			//printf("%d ",node->x);
		for (int i = 0; i < size(); i++)
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
	int sum = 0, count = 0;///initialize vrb count = 0
	while (node != NULL) { ///add null
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