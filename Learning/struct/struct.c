#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char studentID[4];
  char studentName[129];
  float avgMark;
} Student;

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int *array;
} Data;

void printStd(Student *std){
  printf("Student ID: %s\n", std->studentID);
  printf("Student ID: %s\n", std->studentName);
  printf("Student ID: %.3f\n", std->avgMark);
}

void printfPoint(Point *points){
  for (int i = 0; i < 10; i++){
    printf("p%d = (%d, %d)\n", i, points[i].x,
                                  points[i].y);
  }
}

int main() {
  Student myStudent = {"123", "Minh", 9.5};
  
  Student *myStudentPtr = &myStudent;
  printStd(myStudentPtr);
  
  Point points[10];
  for (int i = 0; i < 10; i++){
    points[i].x = i;
    points[i].y = 10-i;
  }

  // printfPoint(points);
 
  Data x; // x represent as Data class
  Data y; 
  // data save into *array pointer of x & y. Not x & y itself
  x.array = malloc(sizeof(int*) *5); // allocating space for 5 integers
  y.array = malloc(sizeof(int*) * 5);

  for (int i = 0; i < 5; i++){
    x.array[i] = i;
    y.array[i] = i+1;
  }

  // modify value  
  y.array[0] = 100;

  for (int i = 0; i < 5; i++){
    printf("x[%d] = %d; ", i, x.array[i]);
    printf("y[%d] = %d\n", i, y.array[i]);
    // printf("\n");
  }
 

  return 0;
}