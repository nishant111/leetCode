
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond= PTHREAD_COND_INITIALIZER;

typedef struct {
    int n;
    int turn;
} FooBar;

void printFoo();
void printBar();

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    obj->turn=1;
    return obj;
}

void* foo(void* obj) {
    
    
    for (int i = 0; i < ((FooBar*)obj)->n; i++) {
        
         pthread_mutex_lock( &m );
        
        while( ((FooBar*)obj)->turn!=1 ){
            pthread_cond_wait( &cond, &m );
        }
        ((FooBar*)obj)->turn = 2;
        
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        
        pthread_mutex_unlock( &m );
        pthread_cond_signal( &cond );
    }
    return NULL;
}

void* bar(void* obj) {
    
    for (int i = 0; i < ((FooBar*)obj)->n; i++) {
        
        pthread_mutex_lock( &m );
        
        while( ((FooBar*)obj)->turn!=2){
            pthread_cond_wait( &cond, &m );
        }
        ((FooBar*)obj)->turn = 1;
        
       
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        
        pthread_mutex_unlock( &m );
        pthread_cond_signal( &cond );
    }
    return NULL;
}

void fooBarFree(FooBar* obj) {
    free(obj);
}