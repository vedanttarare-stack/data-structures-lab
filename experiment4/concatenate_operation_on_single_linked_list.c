struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
     NODE temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = x;
    temp->next = NULL;
    return temp;
    
    
    
}

NODE addNode(NODE first, int x) {
     NODE temp = createNode(x);

    if(first == NULL) {
        return temp;
    }

    NODE current = first;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = temp;
    return first;
    
    
    
    
    
    
}

NODE concatenate(NODE t1, NODE t2) {
    if(t1 == NULL)
        return t2;

    if(t2 == NULL)
        return t1;

    NODE current = t1;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = t2;
    return t1;
    
    
    
}

void displayList(NODE first) {
     NODE temp = first;

    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");


    
    
    
    
}
