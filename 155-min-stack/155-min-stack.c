


typedef struct {
    int *arr;
    int top;
    int min;
    int size;
    
} MinStack;


void findMin(MinStack *stack)
{
    int newMin= INT_MAX;
    int topLocal = stack->top - 1; //dont consider the element being popped.
    for(int i = 0;i<=topLocal;i++)
    {
        if(stack->arr[i] <= newMin)
        {
            newMin = stack->arr[i];
            //printf("\nnew min is %d", newMin);
            //stack->min = newMin;
            //return;
        }
    }
    printf("\nnew min is %d", newMin);
    stack->min = newMin;
}

MinStack* minStackCreate() {
    MinStack *stack = malloc(sizeof(MinStack));
    stack->arr = malloc(1000 * sizeof(int));
    stack->size = 1000;
    stack->top = -1;
    stack->min = INT_MAX;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if(obj->top == obj->size-1)
    {
        // need to resize
        obj->arr=realloc(obj->arr, (obj->size) * (10 * sizeof(int))); //memory leaks if realloc fails.
        obj->size = obj->size*10;
    }
    obj->top+=1;
    obj->arr[obj->top] = val;
    //obj->top+=1;
    if(val < obj->min)
    {
        obj->min = val;   
    }
}

void minStackPop(MinStack* obj) {
    if(obj->arr[obj->top] == obj->min)
    {
        //find new min
        findMin(obj);
    }
    obj->arr[obj->top--]=-111;
    //obj->top-=1;
}

int minStackTop(MinStack* obj) {
    return (obj->arr[obj->top]);
}

int minStackGetMin(MinStack* obj) {
    return(obj->min);
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/