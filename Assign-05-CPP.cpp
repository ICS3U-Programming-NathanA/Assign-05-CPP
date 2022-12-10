// Copyright (c) 2022 Nathan All rights reserved.
//
// Created by: Nathan
// Date: Dec 8, 2022
// This program calculates the surface area of a cylinder,
// the circumference and area of the circles on the top and bottom

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// Function to calculate the area of the circles
float areaCalculate(float radius) {
    // Declare area as a float
    float area;
    // Area of a circle formula
    area = M_PI * pow(radius, 2);
    // return area to main()
    return area;
}

// Function to calculate the circumference of the circles
float circumferenceCalculate(float radius) {
    // Declare circumference as a float
    float circumference;
    // Circumference of a circle formula
    circumference = 2 * M_PI * radius;
    // return circumference to main()
    return circumference;
}

// Function to calculate the surface area of the cylinder
float surfaceAreaCalculate(float radius, float height) {
    // delcare surfaceArea as a float
    float surfaceArea;
    // surfaceArea of a circle formula
    surfaceArea = 2 * M_PI * radius * height + 2 * M_PI * pow(radius, 2);
    // return surfaceArea to main()
    return surfaceArea;
}
int main() {
    // Declaring userRadius, userHeight, surfaceArea,
    // circumference, area to floats
    float userRadius, userHeight, surfaceArea, circumference, area;
    // Declaring userRadiusStr, userHeightStr, playAgain, userUnits to strings
    std::string userRadiusStr, userHeightStr, playAgain, userUnits;
    // Do while statement for the user to be able to restart the program
    do {
        // Gets userRadiusStr from the user
        std::cout << "Enter the radius of the cylinder: ";
        std::cin >> userRadiusStr;
        // Gets userHeightStr from the user
        std::cout << "Enter the height of the cylinder: ";
        std::cin >> userHeightStr;
        // Gets userUnits from the user
        std::cout << "Enter the units: ";
        std::cin >> userUnits;

        // A try catch to to catch any invalid inputs
        try {
            userRadius = std::stof(userRadiusStr);
            userHeight = std::stof(userHeightStr);
            // If they entered a number less than 0
            if (userRadius > 0 && userHeight > 0) {
                // Call circumferenceCalculate(userRadius)
                circumference = circumferenceCalculate(userRadius);
                // Call areaCalculate(userRadius)
                area = areaCalculate(userRadius);
                // Call surfaceAreaCalculate(userRadius, userHeight)
                surfaceArea = surfaceAreaCalculate(userRadius, userHeight);
                // Display the the surface area, area and circumference
                std::cout << std::fixed <<
                std::setprecision(2) << std::setfill('0')
                << "The surface area is " << surfaceArea
                << " " << userUnits << "²" << "\n";
                std::cout << std::fixed
                << std::setprecision(2) << std::setfill('0')
                << "The circumference of the circle is " << circumference
                << " " << userUnits << "\n";
                std::cout << std::fixed
                << std::setprecision(2) << std::setfill('0')
                << "The area of the circle is " << area
                << " " << userUnits << "²" << "\n";
            } else {
                std::cout << "Enter a number greater than 0\n";
            }
            // Ask the user if they want to enter two new numbers
            std::cout << "Do you want to input two new numbers?(y or n): ";
            std::cin >> playAgain;
            // set playAgain to uppercase
            std::transform(playAgain.begin(), playAgain.end(),
                           playAgain.begin(), ::toupper);
        } catch (std::invalid_argument) {
            std::cout
            << "You must enter a number for both inputs."
            << std::endl;
    }while (playAgain == "Y" || playAgain == "YES");
}
