//Dynamic Memory Allocation(DMA), Static Memory Allocation(SMA)
//DMA - Memory Allocation at run time
//SMA - Memory Allocation at compile time
#include <stdio.h>

int main()
{
    int a, b;
    puts("Enter the value of a and b:");
    scanf("%d %d", &a, &b);
    printf("a =%d, b =%d", a, b);
    return 0;
}

//at compile time, the memory allocated to the program will be fixed ie 4 bytes to a, and 4 bytes to b. This is SMA.
//DMA is allocated at run time, and this can be modified according to programming needs
//The issue with SMA is that there is possibility of wastage of memory. For example, if I declare a variable int arr[5], this
//means that arr is allocated (5x4) bytes of memory. If we input just two integers instead of 5, then (3x4) bytes of memory go to waste
//or if at runtime you want to enter 7 values instead this will not be possible as arr will only have 20 bytes of storage.
//In SMA, memory cannot be freed at runtime. The memory cannot be reused.

//DMA
//In DMA, memory can be allocated and deallocated at runtime
//To do this, we have four functions:
//malloc(), calloc(), realloc(), free()
//Whenever we allocate memory dynamically, we allocate memory from heap.
//Heap is an unordered region of dynamically allocated memory. Heap is used for data whose size or lifetime cannot
//be determined at compile time.
//When using DMA, you must use pointers. This is an important application of pointers.
//Once your program is done, and you have used DMA, you MUST free memory.