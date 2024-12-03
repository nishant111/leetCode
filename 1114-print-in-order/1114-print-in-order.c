typedef struct {
    // User defined data may be declared here.
    int state;
} Foo;

void printFirst();
void printSecond();
void printThird();

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond= PTHREAD_COND_INITIALIZER;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    obj->state = 1;
    // Initialize user defined data here.
    
    return obj;
}

void* first(void* obj) {
    pthread_mutex_lock(&m);
    
    (((Foo*)obj)->state)++;
    printf("%d", ((Foo*)obj)->state); 
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    
    pthread_mutex_unlock(&m);
    pthread_cond_broadcast(&cond);
    return NULL;
}

void* second(void* obj) {
    pthread_mutex_lock(&m);
    while( ((Foo*)obj)->state != 2){
        //printf("state seen in second is %d", ((Foo*)obj)->state); 
        pthread_cond_wait( &cond, &m );
    }
    (((Foo*)obj)->state)++;
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pthread_mutex_unlock(&m);
    pthread_cond_broadcast(&cond);
    return NULL;
}

void* third(void* obj) {
     pthread_mutex_lock(&m);
    while( ((Foo*)obj)->state != 3){
        pthread_cond_wait( &cond, &m );
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&m);
    
    return NULL;
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
    
}