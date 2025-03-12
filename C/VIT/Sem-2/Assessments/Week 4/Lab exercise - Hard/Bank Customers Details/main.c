#include <stdio.h> 
#include <string.h> 
struct A{int a; char b[50]; char c[50]; char d[15]; double e; double f; double g;}; 
int main(){
    int h,i,j,k;
    scanf("%d",&h);
    struct A l[h];
    for(i=0;i<h;i++){
        scanf("%d %s %s %s %lf",&l[i].a,l[i].b,l[i].c,l[i].d,&l[i].e);
        l[i].f=0;l[i].g=0;}scanf("%d",&j);if(j==1){scanf("%d",&k);
        for(i=0;i<h;i++){
            if(l[i].a==k){
                printf("%d %s %s %s %.2lf %.2lf %.2lf\n",l[i].a,l[i].b,l[i].c,l[i].d,l[i].e,l[i].f,l[i].e);
                break;
                
            }
            
        }
            
        }else if(j==2){
            scanf("%d",&k);
            for(i=0;i<h;i++){
                if(l[i].a==k){
                    printf("Amount Deposited Successfully!\n");
                    break;
                    
                }
                
            }
            
        }else if(j==3){
            scanf("%d %lf",&k,&l[0].f);
            for(i=0;i<h;i++){
                if(l[i].a==k){
                    if(l[i].e-l[0].f>=1000){
                        l[i].e-=l[0].f;
                        l[i].g+=l[0].f;
                        printf("Amount Withdrawn Successfully!\n");
                    }else{
                        printf("Minimum Balance of Rs.1000 should be maintained\n");
                        
                    }break;
                    
                }
                
            }
            
        }else if(j==4){
            printf("Account No.    Customer Name            Address        Date of Birth  Deposit         Withdrawal      Balance        \n");
            for(i=0;i<h;i++){
                printf("%-15d%-25s%-15s%-15s%.2lf        %.2lf        %.2lf        \n",l[i].a,l[i].b,l[i].c,l[i].d,l[i].e,l[i].g,l[i].e);
                
            }
            
        }return 0;
    
}
                
                
                