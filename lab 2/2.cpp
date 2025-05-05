//Program to calculate area of square, rectangle, cube and cuboid using classes.
#include <cstdio>
#include <cstdlib>

class Shape {
private:
    float length, width, height;

public:
    // Constructor
    Shape() {
        length = width = height = 0;
    }

    // Setter methods
    void setLength(float l) { 
length = l; 
}
    void setWidth(float w) {
 width = w; 
}
    void setHeight(float h) {
 height = h; 
}

    // Function to calculate the area of a square
    float calculateSquareArea() {
        return length * length;
    }

    // Function to calculate the area of a cube 
    float calculateCubeArea() {
        return 6 * length * length;  // 6 faces of the cube
    }

    // Function to calculate the area of a rectangle
    float calculateRectangleArea() {
        return length * width;
    }

    // Function to calculate the area of a cuboid
    float calculateCuboidArea() {
        return 2 * (length * width + width * height + height * length);
    }
};

int main() {
    Shape* shape = (Shape*)malloc(sizeof(Shape));  // Dynamically allocate memory for the Shape object
    if (shape == nullptr) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    char choice;
    while (true) {
        printf("\nMenu:\n");
        printf("a) Square\n");
        printf("b) Cube\n");
        printf("c) Rectangle\n");
        printf("d) Cuboid\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                float side;
                printf("Enter the side of the square: ");
                scanf("%f", &side);
                shape->setLength(side);
                printf("Area of the square: %.2f\n", shape->calculateSquareArea());
                break;
            }
            case 'b': {
                float side;
                printf("Enter the side of the cube: ");
                scanf("%f", &side);
                shape->setLength(side);
                printf("Surface area of the cube: %.2f\n", shape->calculateCubeArea());
                break;
            }
            case 'c': {
                float length, width;
                printf("Enter the length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                shape->setLength(length);
                shape->setWidth(width);
                printf("Area of the rectangle: %.2f\n", shape->calculateRectangleArea());
                break;
            }
            case 'd': {
                float length, width, height;
                printf("Enter the length, width, and height of the cuboid: ");
                scanf("%f %f %f", &length, &width, &height);
                shape->setLength(length);
                shape->setWidth(width);
                shape->setHeight(height);
                printf("Surface area of the cuboid: %.2f\n", shape->calculateCuboidArea());
                break;
            }
            case 'e':
                free(shape);  // Free dynamically allocated memory
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

