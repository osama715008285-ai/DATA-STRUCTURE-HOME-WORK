#include <stdio.h>

// Insertion Algorithm
// 1. Begin
// 2. Initialize counter I = SIZE
// 3. Expand SIZE = SIZE + 1
// 4. While I >= POSITION, do steps 5 and 6
// 5. Shift: DATA[I+1] = DATA[I]
// 6. Decrease counter: I = I - 1
// 7. Insert: DATA[POSITION] = NEW_VAL
// 8. End

int insertItem(int DATA[], int SIZE, int POSITION, int NEW_VAL) {
    int I = SIZE;
    SIZE = SIZE + 1;
    
    while (I >= POSITION) {
        DATA[I + 1] = DATA[I];
        I = I - 1;
    }
    
    DATA[POSITION] = NEW_VAL;
    return SIZE;
}

// Deletion Algorithm
// 1. Begin
// 2. Store target: REMOVED_VAL = DATA[POSITION]
// 3. Loop from J = POSITION to SIZE - 2
// 4. Shift left: DATA[J] = DATA[J+1]
// 5. Reduce SIZE = SIZE - 1
// 6. End

int deleteItem(int DATA[], int SIZE, int POSITION) {
    int REMOVED_VAL = DATA[POSITION];
    
    for (int J = POSITION; J < SIZE - 1; J++) {
        DATA[J] = DATA[J + 1];
    }
    
    printf("Element %d deleted from index %d\n", REMOVED_VAL, POSITION);
    return SIZE - 1;
}

// Search Algorithm
// 1. Begin
// 2. Iterate from K = 0 to SIZE - 1
// 3. If DATA[K] matches TARGET then return K
// 4. If end of loop reached, return -1
// 5. End

int findItem(int DATA[], int SIZE, int TARGET) {
    for (int K = 0; K < SIZE; K++) {
        if (DATA[K] == TARGET) {
            return K;
        }
    }
    return -1;
}

int main() {
    int DATA[100] = {10, 20, 30, 40, 50};
    int SIZE = 5;
    
    printf("Initial Array: ");
    for(int i=0; i<SIZE; i++) printf("%d ", DATA[i]);
    printf("\n");
    
    // Testing Insert
    SIZE = insertItem(DATA, SIZE, 2, 99);
    printf("After Inserting 99: ");
    for(int i=0; i<SIZE; i++) printf("%d ", DATA[i]);
    printf("\n");
    
    // Testing Search
    int loc = findItem(DATA, SIZE, 99);
    if(loc != -1) 
        printf("Value 99 found at index %d\n", loc);
    
    // Testing Delete
    SIZE = deleteItem(DATA, SIZE, 2);
    printf("Final Array: ");
    for(int i=0; i<SIZE; i++) printf("%d ", DATA[i]);
    printf("\n");
    
    return 0;
}
