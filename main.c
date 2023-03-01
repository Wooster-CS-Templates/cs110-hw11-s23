#include <stdio.h>

#include "pizza.h"

int main() {
    size_t pizza_count;

    printf("How many pizzas are you going to enter? ");

    scanf("%zu", &pizza_count);

    struct pizza pizzas[pizza_count];

    for(size_t i = 0; i < pizza_count; i++) {
        printf("Enter the size in inches for pizza %zu: ", i + 1);
        scanf("%u", &pizzas[i].size);
        printf("Enter the price for pizza %zu: ", i + 1);
        scanf("%lf", &pizzas[i].price);
    }

    struct pizza best_value = best_value_pizza(pizzas, pizza_count);

    printf("The best value is the %u inch pizza for $%.2lf\n", best_value.size,
           best_value.price);

    return 0;
}
