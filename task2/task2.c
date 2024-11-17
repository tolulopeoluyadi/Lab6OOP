#include <stdio.h>
#include <stdlib.h>

/* Declare your functions */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

/* Main function */
int main(void) {
    int a = 6, b = 3;
    int option;

    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};

    while (1) {
        // Prompt user for input
        printf("Operand 'a': %d | Operand 'b': %d\n", a, b);
        printf("Specify the operation to perform (0: add | 1: subtract | 2: multiply | 3: divide | 4: exit): ");
        scanf("%d", &option);

        // Exit the program if the option is 4
        if (option == 4) {
            printf("Exiting program.\n");
            break;
        }

        // Perform the operation using the function pointer
        if (option >= 0 && option <= 3) {
            int result = operations[option](a, b);
            printf("Result: %d\n", result);
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

/* Define your functions */
int add(int a, int b) { 
    printf("Adding 'a' and 'b'\n"); 
    return a + b; 
}

int subtract(int a, int b) { 
    printf("Subtracting 'b' from 'a'\n"); 
    return a - b; 
}

int multiply(int a, int b) { 
    printf("Multiplying 'a' and 'b'\n"); 
    return a * b; 
}

int divide(int a, int b) { 
    if (b != 0) {
        printf("Dividing 'a' by 'b'\n");
        return a / b; 
    } else {
        printf("Error: Division by zero\n");
        return 0; 
    }
}
