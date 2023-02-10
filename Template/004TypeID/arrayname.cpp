
#include <iostream>

int main()
{

    // double d;
    // double* p2;

    int x[3]={1,2,3}; //type int[3];

    // address of array of x
    // int (*p3)[3]= &x; // address of array of x
    // int *p4 =x ; // p4 is not address

    int n1 =10;
    int n2 = n1;
    double d1 =.34;
    double d2 =d1;

    int x1[3]={1,2,3};
    int (*p1)[3]=&x;
    // int x2[3]=x1; // ? array is not initilized by..
    // 배열의 이름은 첫번째 요소의 주소로 암시적 형변환함. 
    int *p2 =x1; // 요소를 가르킴.
    printf("%p,%p\n",p1,p1+1); //12
    printf("%p,%p\n",p2,p2+1); //4
    (*p1)[0]=10;
    (*p2); // array index of ss


}