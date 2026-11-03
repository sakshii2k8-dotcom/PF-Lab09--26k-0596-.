#include <stdio.h>

double calculateItemTotal(double price, int quantity);
double calculateSubtotal(double total1, double total2);
double calculateDiscount(double subtotal);
double calculateFinalTotal(double subtotal, double discount);
int findHigherPrice(double price1, double price2);

int main() {
    double price1, price2;
    int quantity1, quantity2;
    double total1, total2, subtotal, discount, finalTotal;
    int higher;

    printf("Enter price of item 1: ");
    scanf("%lf", &price1);

    printf("Enter quantity of item 1: ");
    scanf("%d", &quantity1);

    printf("Enter price of item 2: ");
    scanf("%lf", &price2);

    printf("Enter quantity of item 2: ");
    scanf("%d", &quantity2);

    if (price1 < 0 || price2 < 0 || quantity1 < 0 || quantity2 < 0) {
        printf("\nInvalid input! Price and quantity cannot be negative.\n");
        return 0;
    }

    total1 = calculateItemTotal(price1, quantity1);
    total2 = calculateItemTotal(price2, quantity2);

    subtotal = calculateSubtotal(total1, total2);
    discount = calculateDiscount(subtotal);
    finalTotal = calculateFinalTotal(subtotal, discount);

    higher = findHigherPrice(price1, price2);

    printf("\n========== CUSTOMER RECEIPT ==========\n");

    printf("\nItem 1 Unit Price: Rs. %.2f", price1);
    printf("\nItem 1 Quantity: %d", quantity1);
    printf("\nItem 1 Total: Rs. %.2f\n", total1);

    printf("\nItem 2 Unit Price: Rs. %.2f", price2);
    printf("\nItem 2 Quantity: %d", quantity2);
    printf("\nItem 2 Total: Rs. %.2f\n", total2);

    printf("\nSubtotal: Rs. %.2f", subtotal);
    printf("\nDiscount: Rs. %.2f", discount);
    printf("\nFinal Amount: Rs. %.2f\n", finalTotal);

    if (higher == 1) {
        printf("\nItem 1 has the higher unit price.\n");
    } 
    else if (higher == 2) {
        printf("\nItem 2 has the higher unit price.\n");
    } 
    else {
        printf("\nBoth items have equal unit prices.\n");
    }

    printf("\n=======================================\n");

    return 0;
}

double calculateItemTotal(double price, int quantity) {
    return price * quantity;
}

double calculateSubtotal(double total1, double total2) {
    return total1 + total2;
}

double calculateDiscount(double subtotal) {
    if (subtotal > 1000) {
        return subtotal * 0.10;
    }

    return 0;
}

double calculateFinalTotal(double subtotal, double discount) {
    return subtotal - discount;
}

int findHigherPrice(double price1, double price2) {
    if (price1 > price2) {
        return 1;
    } 
    else if (price2 > price1) {
        return 2;
    } 
    else {
        return 0;
    }
}
