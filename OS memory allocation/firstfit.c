#include <stdio.h>  
  
#define MEMORY_SIZE 1000  
#define BLOCK_SIZE 20  
  
int memory[MEMORY_SIZE];  
  
void initialize_memory() {  
    int i;  
    for (i = 0; i < MEMORY_SIZE; i += BLOCK_SIZE) {  
        memory[i] = BLOCK_SIZE;  
    }  
}  
  
void print_memory() {  
    int i;  
    for (i = 0; i < MEMORY_SIZE; i += BLOCK_SIZE) {  
        printf("%d ", memory[i]);  
    }  
    printf("\n");  
}  
  
void allocate_memory(int process_id, int size) {  
    int i;  
    for (i = 0; i < MEMORY_SIZE; i += BLOCK_SIZE) {  
        if (memory[i] >= size) {  
            printf("Process %d allocated block %d of size %d\n", process_id, i/BLOCK_SIZE, size);  
            memory[i] -= size;  
            if (memory[i] == 0) {  
                printf("Block %d freed\n", i/BLOCK_SIZE);  
            }  
            break;  
        }  
    }  
    if (i == MEMORY_SIZE) {  
        printf("Process %d is waiting for memory\n", process_id);  
    }  
}  
  
void release_memory(int process_id, int block_id) {  
    int i = block_id * BLOCK_SIZE;  
    int size = BLOCK_SIZE;  
    while (memory[i] == 0) {  
        i -= BLOCK_SIZE;  
        size += BLOCK_SIZE;  
    }  
    printf("Block %d of size %d freed by process %d\n", i/BLOCK_SIZE, size, process_id);  
    memory[i] += size;  
}  
  
int main() {  
    initialize_memory();  
    allocate_memory(1, 50);  
    allocate_memory(2, 100);  
    allocate_memory(3, 30);  
    print_memory();  
    release_memory(2, 2);  
    print_memory();  
    allocate_memory(4, 25);  
    print_memory();  
    return 0;  
}