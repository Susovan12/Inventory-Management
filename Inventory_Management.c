#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product structure
typedef struct {
    int id;
    char name[50];
    int stock;
    double price;
} Product;

// Array of products
Product products[MAX_PRODUCTS];

// Current number of products
int numProducts = 0;

// Function to add a new product
void addProduct() {
    Product p;
    p.id = numProducts + 1;

    printf("Enter product name: ");
    scanf("%s", p.name);

    printf("Enter stock: ");
    scanf("%d", &p.stock);

    printf("Enter price: ");
    scanf("%lf", &p.price);

    products[numProducts] = p;
    numProducts++;

    printf("Product added successfully.\n");
}

// Function to sell a product
void sellProduct() {
    int id;
    int quantity;

    printf("Enter product ID: ");
    scanf("%d", &id);

    if (id > numProducts || id < 1) {
        printf("Invalid product ID.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity > products[id-1].stock) {
        printf("Not enough stock.\n");
        return;
    }

    products[id-1].stock -= quantity;

    printf("Total price: %.2lf\n", products[id-1].price * quantity);
    printf("Product sold successfully.\n");
}

// Function to generate a report
void generateReport() {
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Stock", "Price");

    for (int i = 0; i < numProducts; i++) {
        printf("%-5d %-20s %-10d $%.2lf\n", products[i].id, products[i].name, products[i].stock, products[i].price);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Sell product\n");
        printf("3. Generate report\n");
        printf("4. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                sellProduct();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(1);

    return 0;
}