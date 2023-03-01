#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../pizza.h"

#define TOLERANCE 0.0001


bool within_tolerance(double expected, double result) {
    return fabs(expected - result) < TOLERANCE;
}

void print_pizza(struct pizza pizza) {
    printf("%u inch pizza for $%.2lf", pizza.size, pizza.price);
}


void test_circle_area(double radii[], size_t size, FILE* input_file) {

    for(size_t i = 0; i < size; i++) {
        double expected;
        fread(&expected, sizeof(expected), 1, input_file);
        double result = circle_area(radii[i]);

        if(!within_tolerance(expected, result)) {
            printf("\nERROR: Tested circle_area() with radius %lf. Expected %lf, got %lf\n", radii[i], expected, result);
            exit(1);
        }
    }
}


void test_price_per_square_inch(struct pizza pizzas[], size_t size, FILE* input_file) {

    for(size_t i = 0; i < size; i++) {
        double expected;
        fread(&expected, sizeof(expected), 1, input_file);
        double result = price_per_square_inch(pizzas[i]);

        if(!within_tolerance(expected, result)) {
            printf("\nERROR: price_per_square_inch() with a ");
            print_pizza(pizzas[i]);
            printf(". Expected %lf, got %lf\n", expected, result);
            exit(1);
        }
    }
}


void test_best_pizza_value(struct pizza pizzas[], size_t size, FILE* input_file) {
    struct pizza expected;
    fread(&expected, sizeof(expected), 1, input_file);
    struct pizza result = best_value_pizza(pizzas, size);

    if(expected.size != result.size
       || !within_tolerance(expected.price, result.price)) {

        printf("\nERROR: Test was run with an array containing the following pizzas:\n");
        for(size_t i = 0; i < size; i++) {
            print_pizza(pizzas[i]);
            printf("\n");
        }

        printf("Expected the ");
        print_pizza(expected);
        printf(" to be the best value. Instead it was a ");
        print_pizza(result);
        printf("\n");
        exit(1);
    }
}


int main() {
    FILE* input_circle;
    input_circle = fopen("tests/circle-area-tests", "rb");
    FILE* input_price_per_square;
    input_price_per_square = fopen("tests/price-per-square-tests", "rb");
    FILE* input_best_value;
    input_best_value = fopen("tests/best-pizza-value-tests", "rb");

    assert(input_circle != NULL);
    printf("Testing circle_area()... ");
    double radii[] = {0.0, 0.1, 6, 8, 12, 7.5};
    test_circle_area(radii, 6, input_circle);
    printf("PASSED!\n");

    printf("Testing price_per_square_inch()... ");
    struct pizza three_pizzas[] = {
        {6, 4.99},
        {12, 8.99},
        {16, 19.99}
    };

    struct pizza one_pizza[] = {
        {12, 9.99}
    };

    struct pizza four_pizzas[] = {
        {100, 89.99},
        {3, 25.99},
        {50, 100},
        {20, 300.50}
    };

    struct pizza five_pizzas[] = {
        {100, 89.99},
        {3, 25.99},
        {50, 100},
        {20, 300.50},
        {1024, 128.50}
    };
        
    
    test_price_per_square_inch(three_pizzas, 3, input_price_per_square);
    test_price_per_square_inch(one_pizza, 1, input_price_per_square);
    test_price_per_square_inch(four_pizzas, 4, input_price_per_square);
    test_price_per_square_inch(five_pizzas, 5, input_price_per_square);
    printf("PASSED!\n");

    printf("Testing best_pizza_value()... ");
    test_best_pizza_value(three_pizzas, 3, input_best_value);
    test_best_pizza_value(one_pizza, 1, input_best_value);
    test_best_pizza_value(four_pizzas, 4, input_best_value);
    test_best_pizza_value(five_pizzas, 5, input_best_value);
    printf("PASSED!\n");

    fclose(input_circle);
    fclose(input_price_per_square);
    fclose(input_best_value);

    return 0;
}
