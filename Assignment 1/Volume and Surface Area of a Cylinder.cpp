/*#include <iostream>
#include <cmath>  // For M_PI constant
using namespace std;

int main() {
    double radius, height, volume, surface_area;

    // Get radius and height from user
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;

    // Calculate the volume of the cylinder
    volume = M_PI * pow(radius, 2) * height;

    // Calculate the surface area of the cylinder
    surface_area = 2 * M_PI * radius * (radius + height);

    // Output the results
    cout << "Volume of the cylinder: " << volume << endl;
    cout << "Surface area of the cylinder: " << surface_area << endl;

    return 0;
}
