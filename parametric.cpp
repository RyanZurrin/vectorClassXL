#include "vect.h"
#include "vect3D.h"
using namespace std;
 
struct myVector{
    int x, y, z;
} v1, v2;
 
void input2dPoints(){
    printf("Enter p1:");
    scanf("%d %d", &v1.x, &v1.y);
    printf("Enter p2:");
    scanf("%d %d", &v2.x, &v2.y);
}
 
void input3dPoints(){
    printf("Enter p1:");
    scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
    printf("Enter p2:");
    scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
}
 
struct myVector calculateParallelVector(int choice){
    if(choice == 1)
        return {v2.x - v1.x, v2.y - v1.y};
    else{
        return {v2.x - v1.x, v2.y - v1.y, v2.z - v1.z};
    }
};
 
void printParametricAndVectorForm(int point, struct myVector mv, struct myVector parallelVector){
        printf("Taking point p%d(%d, %d) on the line L we get parametric equation:\n", point, mv.x, mv.y);
        printf("L: x = %d + %dt, y = %d + %dt\n",  mv.x, parallelVector.x, mv.y, parallelVector.y);
        printf("\n");
        printf("Vector form:\n");
        printf("<x, y> = <%d, %d> + t <%d, %d>\n",  mv.x, mv.y, parallelVector.x, parallelVector.y);
        printf("\n\n");
}
 
//@Override
void printParametricAndVectorForm(int point, struct myVector mv, struct myVector parallelVector, int dimension){
        printf("Taking point p%d(%d, %d, %d) on the line L we get parametric equation:\n", point, mv.x, mv.y, mv.z);
        printf("L: x = %d + %dt, y = %d + %dt, z = %d + %dt\n",  mv.x, parallelVector.x, mv.y, parallelVector.y, mv.z, parallelVector.z);
        printf("\n");
        printf("Vector form:\n");
        printf("<x, y, z> = <%d, %d, %d> + t <%d, %d, %d>\n",  mv.x, mv.y, mv.z, parallelVector.x, parallelVector.y, parallelVector.z);
        printf("\n\n");
}
 /*
int main(){
    int choice;
    struct myVector parallelVector;
 
    printf("1. Two Dimensional.\n");
    printf("2. Three Dimensional.\n");
    printf("\nChoice: ");
    scanf("%d", &choice);
    printf("\n");
 
    switch(choice){
    case 1:
        input2dPoints();
 
        printf("\n");
        parallelVector = calculateParallelVector(choice);
        printf("Parallel vector -> p1p2 to the line L is: <%d, %d>\n", parallelVector.x, parallelVector.y);
        printf("\n\n");
 
        printParametricAndVectorForm(1, v1, parallelVector);
        printParametricAndVectorForm(2, v2, parallelVector);
 
        break;
 
    case 2:
        input3dPoints();
 
        printf("\n");
        parallelVector = calculateParallelVector(choice);
        printf("Parallel vector -> p1p2 to the line L is: <%d, %d, %d>\n", parallelVector.x, parallelVector.y, parallelVector.z);
        printf("\n\n");
 
        printParametricAndVectorForm(1, v1, parallelVector, 3);
        printParametricAndVectorForm(2, v2, parallelVector, 3);
 
        break;
 
    default:
        printf("Wrong input.\n");
    }
 
    return 0;
  }
  */
