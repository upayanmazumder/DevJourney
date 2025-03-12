#include<stdio.h>
union ObjectProperties{
    double mass;
    double force;
};
int main(){
    union ObjectProperties obj;
    double acceleration;
    scanf("%lf",&obj.mass);
    scanf("%lf",&acceleration);
    obj.force=obj.mass*acceleration;
    printf("The force is: %.2lf N\n",obj.force);
    if (acceleration>0)
        printf("Constant acceleration\n");
    else if (acceleration<0)
        printf("Decelerating\n");
    else
        printf("At rest\n");
    return 0;
}

