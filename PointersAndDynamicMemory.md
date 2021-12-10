# Pointers and Dynamic Memory

## Ressource: 
**Stack vs Heap** : 
https://www.youtube.com/watch?v=_8-ht2AKyH4 

## Memory

Application's memory can be divided into 4 segments:
- Heap
- Stack
- Static/Global
- Code(Text)


The memory set aside for **Stack, Static/Global and Code** does not grow while l'application is running.

### Code 
It saves instructions.

### Static/Global

### Stack
For each method, stack-frame is created. 
During the compilation, the program reserves memory space.
The actual allocation of the stack space happens during runtime. It follows the rule:
- When a function is called, the function and its local variables get pushed into the stack.
- When a function finishes, the function an the local varaibles get poped out of the stack.
If the function calls run beyond the reserved memory of the stack, **overflow** happens. Example, bad recursion.


Limitation: 
- To allocate a large array, we need to know the size of the array at the compile time.

### Heap
- also called **Free Store** or **Dynamic Memory**
- Dynamic memory, its size can varie while l'application is running.
- This is different of "Heap Data Structure"
- In C:
    - malloc
    ```
    int main()
    {
        int a; //goes on stack
        int *p; //goes on stack
        //malloc allocates 4 bytes of memory in the heap, it return a pointer containing the address of the memory in the heap, this address is saved in the stack with the variable 'p'
        p = (int*)malloc(sizeof(int));
        //Dereference the pointer varaible p to set the value of memory in the heap
        *p = 10; 
        //Once we are done with the ressource at the 'p' address in the heap, free the memory
        free(p);

        //allocate another 4 bytes of memory in the heap, return a pointer pointing to an int value, store the address of the heap memory in the 'p' variable in the stack
        p = (int*)malloc(sizeof(int));
        free(p);

        //allocate an int array of 20 elements in the heap: malloc reserves 20 * 4 bytes continous memory in the heap. 'p' contains the starting address of the array.
        p = (int*)malloc(sizeof(20*sizeof(int)))

        //assign variable for the first element of the int array
        *p = 3;
        //It is equivalent to:
        p[0] = 3;

        //assign variable for the second element of the int array
        *(p+1) = 5;
        //It is equivalent to:
        p[1] = 5;
        
    }
    ```
    On failure, `malloc` returns a null pointer: `nullptr`. It can be used for error handling
    - calloc
    - realloc
    - free
- In C++: 
    - new 
    - delete
    ```
    int main()
    {
        int a; //goes on stack
        int *p;
        // 'new' allocates 4 bytes of memory in the heap, returns the pointer pointing to the address of the allocated memory in the heap
        p = new int;
        // assign the value of the heap memory at the address 'p' using dereferencing
        *p = 10; 
        // free the memory at address 'p'
        delete p;

        //allocate 20*4 bytes of continuous memory in the heap, store the beginning address of the block of memory in the variable 'p'
        p = new int[20];
        // free the block of 20*4 bytes of memory
        delete[] p;

    }
    ```
    
The only way to use memory on the heap, is through reference!


More example of `malloc`:
```
#include <stdio.h>   
#include <stdlib.h> 
 
int main(void) 
{
    int *p1 = malloc(4*sizeof(int));  // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[4])); // same, naming the type directly
    int *p3 = malloc(4*sizeof *p3);   // same, without repeating the type name
 
    if(p1) {
        for(int n=0; n<4; ++n) // populate the array
            p1[n] = n*n;
        for(int n=0; n<4; ++n) // print it back out
            printf("p1[%d] == %d\n", n, p1[n]);
    }
 
    free(p1);
    free(p2);
    free(p3);
}
```