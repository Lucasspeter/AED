


typedef struct {
    int fila[10000];
    int inicio;
    int fim;
} RecentCounter;


RecentCounter* recentCounterCreate() {

    RecentCounter* obj = malloc(sizeof(RecentCounter));

    obj->inicio = 0;
    obj->fim = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->fila[obj->fim++] = t;

    while(obj->fila[obj->inicio] < t - 3000) {
        obj->inicio++;
    }

    return obj->fim - obj->inicio;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/