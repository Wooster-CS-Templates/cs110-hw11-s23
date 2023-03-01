#ifndef PIZZA_H
#define PIZZA_H


#include <math.h>    // provides M_PI
#include <stdlib.h>  // provides size_t


/**
 * This structure stores the price and size of a pizza. The price is in
 * dollars, and the size is the diameter of the pizza in inches.
 */
struct pizza {
    unsigned int size;
    double price;
};


/**
 * Finds the approximate area of a circle with the given radius.
 *
 * Paramters:
 *     radius - the radius of the circle
 *
 * Returns:
 *    the approximate area of the circle
 */
double circle_area(double radius);


/**
 * Given a struct pizza, finds the price per square inch of the pizza.
 *
 * Parameters:
 *     pizza - a structure containing the size and price of the pizza
 *
 * Returns:
 *     the price of the pizza per square inch
 */
double price_per_square_inch(struct pizza pizza);


/**
 * Given an array of struct pizzas, return the details for the pizza with the
 * lowest price per square inch.
 *
 * Parameters:
 *   pizzas - the array of pizza details to consider
 *   size - the number of elements in pizzas, must be greater than 0
 *
 * Returns:
 *   A pizza_details struct containing the details of the pizza with the best
 *   value
 */
struct pizza best_value_pizza(struct pizza pizzas[], size_t size);


#endif

