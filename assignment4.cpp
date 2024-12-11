#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14

// Function to calculate the volume of a cylinder
float cylinderVolume(float radius, float height) {
    return PI * radius * radius * height;
}

// Function to display the result of the cylinder volume calculation
void displayCylinderVolume(float radius, float height) {
    float volume = cylinderVolume(radius, height);
    cout << "The volume of the cylinder is: " << volume << " cm^3" << endl;
}

// Function to calculate the volume of a cone
float coneVolume(float radius, float height) {
    return (PI * radius * radius * height) / 3;
}

// Function to display the result of the cone volume calculation
void displayConeVolume(float radius, float height) {
    float volume = coneVolume(radius, height);
    cout << "The volume of the cone is: " << volume << " cm^3" << endl;
}

// Function to calculate the perimeter of a triangle
float trianglePerimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
}

// Function to display the result of the triangle perimeter calculation
void displayTrianglePerimeter(float side1, float side2, float side3) {
    float perimeter = trianglePerimeter(side1, side2, side3);
    cout << "The perimeter of the triangle is: " << perimeter << " cm" << endl;
}

// Function to calculate the perimeter of a rectangle
float rectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

// Function to display the result of the rectangle perimeter calculation
void displayRectanglePerimeter(float length, float width) {
    float perimeter = rectanglePerimeter(length, width);
    cout << "The perimeter of the rectangle is: " << perimeter << " cm" << endl;
}

// Function to find the largest of three numbers
float largestOfThree(float num1, float num2, float num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}

// Function to display the largest of three numbers
void displayLargestOfThree(float num1, float num2, float num3) {
    float largest = largestOfThree(num1, num2, num3);
    cout << "The largest number is: " << largest << endl;
}

int main() {
    int choice;
    float length, width, radius, height, side1, side2, side3, num1, num2, num3;

    do {
        system("cls");
        cout << "+";
        cout << setw(33) << setfill('=') << "+\n";
        cout << "|          ASSIGNMENT 4         |" << endl;
        cout << "+";
        cout << setw(33) << setfill('=') << "+\n";
        cout << "PLEASE CHOOSE A MENU OPTION: " << endl;
        cout << "1. Calculate the volume of a cylinder" << endl;
        cout << "2. Calculate the volume of a cone" << endl;
        cout << "3. Calculate the perimeter of a triangle" << endl;
        cout << "4. Calculate the perimeter of a rectangle" << endl;
        cout << "5. Find the largest of three numbers" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
            case 1:
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "|         CYLINDER VOLUME         |" << endl;
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "Enter the radius of the cylinder: ";
                cin >> radius;
                cout << "Enter the height of the cylinder: ";
                cin >> height;
                displayCylinderVolume(radius, height);
                system("pause");
                break;

            case 2:
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "|          CONE VOLUME            |" << endl;
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "Enter the radius of the cone: ";
                cin >> radius;
                cout << "Enter the height of the cone: ";
                cin >> height;
                displayConeVolume(radius, height);
                system("pause");
                break;

            case 3:
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "|       TRIANGLE PERIMETER         |" << endl;
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "Enter the length of side 1: ";
                cin >> side1;
                cout << "Enter the length of side 2: ";
                cin >> side2;
                cout << "Enter the length of side 3: ";
                cin >> side3;
                displayTrianglePerimeter(side1, side2, side3);
                system("pause");
                break;

            case 4:
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "|       RECTANGLE PERIMETER        |" << endl;
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "Enter the length: ";
                cin >> length;
                cout << "Enter the width: ";
                cin >> width;
                displayRectanglePerimeter(length, width);
                system("pause");
                break;

            case 5:
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "|       LARGEST OF THREE NUMBERS   |" << endl;
                cout << "+";
                cout << setw(33) << setfill('=') << "+\n";
                cout << "Enter the first number: ";
                cin >> num1;
                cout << "Enter the second number: ";
                cin >> num2;
                cout << "Enter the third number: ";
                cin >> num3;
                displayLargestOfThree(num1, num2, num3);
                system("pause");
                break;

            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
                break;
        }
    } while (choice != 6);

    return 0;
}
