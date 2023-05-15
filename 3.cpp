#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int arr[MAX_SIZE];

typedef struct alfa *alfaptr;

struct alfa {
    long long x;
    alfaptr next;
};

alfaptr rear = NULL, front = NULL;

void push(int x) {
    alfaptr node;
    node = (alfaptr)malloc(sizeof(struct alfa));
    node->x = x;
    node->next = NULL; // Initialize next pointer to NULL

    if (!front)
        front = node;
    else {
        rear->next = node;
    }
    rear = node; // Update rear pointer
}

void pop() {
    if (!front)
        printf("ERROR1\n");
    else {
        alfaptr node = front;
        front = front->next;
        free(node);
    }
}

void search(int x) {
    alfaptr node = front;
    int counter = 0;
    while (node) {
        if (node->x == x) {
            printf("%d\n", counter);
            return;
        }
        node = node->next;
        counter++;
    }
    printf("ERROR2\n");
}

void rpop() { // pop last element
    alfaptr node = front;
    alfaptr prev = NULL;

    if (!front) {
        printf("ERROR1\n");
        return;
    }

    while (node->next) {
        prev = node;
        node = node->next;
    }

    if (prev)
        prev->next = NULL;
    else
        front = NULL;

    rear = prev; // Update rear pointer

    free(node);
}

void set() {
    alfaptr node = front;
    int i = 0;

    while (i < MAX_SIZE && node) {
        arr[i] = node->x;
        node = node->next;
        i++;
    }
}

int size() {
    alfaptr node = front;
    int count = 0;

    while (node) {
        count++;
        node = node->next;
    }
    return count;
}

void show() {
    if (!front) {
        for (int i = 0; i < MAX_SIZE; i++)
            printf("%d ", arr[i]);
    } else {
        printf("ERROR3\n");
    }
}

int average() {
    alfaptr node = front;
    int sum = 0, count = 0;

    while (node) {
        sum += node->x;
        count++;
        node = node->next;
    }

    return count > 0 ? sum / count : 0; // Check for division by zero
}

int main() {
    int cmd;
    long long int x;

    while (1) {
        scanf("%d", &cmd);

        switch (cmd) {
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
                printf("%d\n", size());
                break;
            case 10:
                exit(0);
        }
    }

    return 0;
}
