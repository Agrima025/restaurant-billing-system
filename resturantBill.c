
#include <stdio.h>

// Function declarations
void displaymenu();
int getInput();
float getPrice(int item);
void customerInfo();
void addItem(int item);
void bill();

// Customer structure
struct Customer
{
    int id;
    char name[50];
};

struct Customer c;
int customerCount = 100;

// Bill structure
struct Bill
{
    int item, qty;
    float price, total;
};

struct Bill b[50];
int count = 0;

// Main function
int main()
{
    int choice;

    customerInfo();

    while (1)
    {
        displaymenu();

        printf("Enter item number: ");
        choice = getInput();

        if (choice < 1 || choice > 5)
        {
            printf("Invalid choice!\n");
            printf("Enter a number from 1 to 5.\n");
            continue;
        }

        if (choice == 5)
            break;

        addItem(choice);
    }

    if (count > 0)
        bill();
    else
        printf("No items ordered!\n");

    printf("Thank you for visiting Nib's Cafe!\n");

    return 0;
}

// Customer information
void customerInfo()
{
    c.id = customerCount++;

    printf("\n===== Customer Information =====\n");
    printf("Customer ID: %d\n", c.id);

    printf("Enter customer name: ");
    scanf(" %49[^\n]", c.name);

    printf("Customer information saved!\n");
}

// Display menu
void displaymenu()
{
    printf("\n===== Nib's Cafe =====\n");
    printf("1. Burger - Rs. 60\n");
    printf("2. Pizza - Rs. 100\n");
    printf("3. Sandwich - Rs. 40\n");
    printf("4. Coffee - Rs. 30\n");
    printf("5. Final Bill\n");
}

// Input validation
int getInput()
{
    int n, ch;

    while (scanf("%d", &n) != 1)
    {
        printf("Invalid input!\n");
        printf("Enter a number: ");

        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch != ' ' && ch != '\t' && ch != '\r')
        {
            printf("Invalid input!\n");
            printf("Enter a number: ");

            while ((ch = getchar()) != '\n' && ch != EOF);

            return getInput();
        }
    }

    return n;
}

// Return item price
float getPrice(int item)
{
    if (item == 1)
        return 60;
    else if (item == 2)
        return 100;
    else if (item == 3)
        return 40;
    else
        return 30;
}

// Add item to order
void addItem(int item)
{
    int qty;

    if (count >= 50)
    {
        printf("Order limit reached!\n");
        return;
    }

    printf("Enter quantity (1-50): ");
    qty = getInput();

    while (qty < 1 || qty > 50)
    {
        printf("Invalid quantity!\n");
        printf("Enter quantity between 1 and 50: ");
        qty = getInput();
    }

    b[count].item = item;
    b[count].qty = qty;
    b[count].price = getPrice(item);
    b[count].total = b[count].price * qty;

    count++;

    printf("Item added successfully!\n");
}

// Print final bill
void bill()
{
    int i;
    float sub = 0, gst, total;

    printf("\n===== Final Bill =====\n");

    printf("Customer ID: %d\n", c.id);
    printf("Customer Name: %s\n", c.name);

    printf("-----------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("Item %d | Qty: %d | Total: Rs. %.2f\n",
               b[i].item, b[i].qty, b[i].total);

        sub += b[i].total;
    }

    gst = sub * 0.05;
    total = sub + gst;

    printf("-----------------------------\n");
    printf("Subtotal: Rs. %.2f\n", sub);
    printf("GST (5%%): Rs. %.2f\n", gst);
    printf("Final Bill: Rs. %.2f\n", total);
    printf("-----------------------------\n");
}
