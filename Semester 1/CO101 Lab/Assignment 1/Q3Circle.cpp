#include <stdio.h>

int main()
{
	float radius, diameter, circumference, area;
	printf("Enter radius of circle: ");
	scanf_s("%f", &radius);
	diameter = 2 * radius;
	circumference = 2 * 3.14159 * radius;
	area = 3.14159 * radius * radius;
	printf("Diameter of circle = %f\n", diameter);
	printf("Circumference of circle = %f\n", circumference);
	printf("Area of circle = %f", area);
	return 0;
}