//
//  retail company.c
//  retail company
//
//  Created by Kirolos Esmat on 5/23/20.
//  Copyright © 2020 Kirolos Esmat. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int choose(int);
float data(void);
float add(void);
float delete(void);
float branchs_total(void);
float percentage(void);
float peak_sales(void);
float sales_of_month(void);
float sales_of_branch(void);
float backup(void);

int num,branch_numbers;
float total;
int months[12]={1,2,3,4,5,6,7,8,9,10,11,12};
float **sales,**sort;

int main(){
    choose(num);
    while (num!=0) {
        
        if (num==1){
            data();
            choose(num);
        }
        if (num==2){
            add();
            choose(num);
        }
        if (num==3){
            delete();
            choose(num);
        }
        if (num==4){
            branchs_total();
            choose(num);
        }
        if (num==5){
            percentage();
            choose(num);
        }
        if (num==6){
            peak_sales();
            choose(num);
        }
        if (num==7){
            sales_of_month();
            choose(num);
        }
        if (num==8){
            sales_of_branch();
            choose(num);
        }
        else{
            printf("Error! choose from 0-8\n");
            choose(num);
        }
    }
    if (num==0)
    {
        free(sales);
        free(sort);
        printf("Done...\n");
    }
    return 0;
}

int choose(){
       printf("1. Enter sales data.\n");
       printf("2. Add a record for a new branch.\n");
       printf("3. Delete record of an existing branch.\n");
       printf("4. Calculate total sales.\n");
       printf("5. Calculate percentage share of each branch.\n");
       printf("6. Determine the month of the peak sales.\n");
       printf("7. Display sales of a specific month.\n");
       printf("8. Display sales of a specific branch.\n");
       printf("0. Done.\n");
       printf("------------------------------------------------------------------\n");
       printf("Please choose number:\n");
       scanf("%d",&num);
    return num;
}

float data(){
    int i,j,k;
    
    sales = malloc(branch_numbers*sizeof(float*));
    
    printf("Enter number of branches:\n");
    scanf("%d",&branch_numbers);
        
    for(i=0;i<branch_numbers;i++)
    {
        sales[i]=malloc(12*sizeof(float*));
        printf("Sales for branch %d:\n",i+1);
        for(j=0;j<12;j++)
        {
            printf("\tSales for month %d: ",j+1);
            scanf("%f",&sales[i][j]);
        }
        printf("\n");
    }
    
    for(k=0;k<12;k++)
    {
        printf("%d\t",months[k]);
    }
    printf("\n");
    for(i=0;i<branch_numbers;i++)
    {
        printf("Branche %d:\n",i+1);
        for(j=0;j<12;j++)
        {
            printf("%.2f\n",sales[i][j]);
        }
        printf("\n");
        printf("------------------------------------------------------------------\n");
    }
    backup();
    return branch_numbers;
}

float add(){
    int i,j,k,branch;
    branch=branch_numbers;
    
    sales = realloc(sales,1*sizeof(float*));
    printf("Branch %d:\n",branch_numbers+1);
    
    for(i=0;i<12;i++)
    {
        printf("\tSales for month %d: ",i+1);
        scanf("%f",&sales[branch_numbers-1][i]);
    }
    printf("\n");
    printf("------------------------------------------------------------------\n");
    for(k=0;k<12;k++)
    {
        printf("%d\t",months[k]);
    }
    printf("\n");
    branch++;
    for(i=0;i<branch;i++)
    {
        printf("Branche %d:\n",i+1);
        for(j=0;j<12;j++)
        {
            printf("%f\n",sales[i][j]);
        }
        printf("\n");
        printf("------------------------------------------------------------------\n");
    }
    return 0;
}

float delete(){
    int branch,i,j,k;
    branch=branch_numbers;
    branch--;
    
    for(k=0;k<12;k++)
    {
        printf("%d\t",months[k]);
    }
    printf("\n");
    for(i=0;i<branch;i++)
    {
        printf("Branche %d:\n",i+1);
        for(j=0;j<12;j++)
        {
            printf("%f\n",sales[i][j]);
        }
        printf("\n");
        printf("------------------------------------------------------------------\n");
    }
    return 0;
}

float branchs_total(){
    int i,j ;
    float sum ,save[12];

    for(i = 0; i < branch_numbers; i++)
    {
        sum = 0.0;
        for(j = 0; j < 12; j++)
        {
            sum += sales[i][j];
        }
        save[i]=sum;
    }

    for(i = 0; i < branch_numbers; i++)
       {
           total += save[i];
       }
    
    printf("------------------------------------------------------------------\n");
    printf("Total Company Sales = %.2f $\n",total);
    printf("------------------------------------------------------------------\n");
    total=0;
    return 0;
}

float percentage(){
    int i,j;
    float percent,final,sum,save[12];
    
    for(i = 0; i < branch_numbers; i++)
    {
        sum = 0;
        for(j = 0; j < 12; j++)
        {
            sum += sales[i][j];
        }
        save[i]=sum;
    }

    for(i = 0; i < branch_numbers; i++)
       {
           total += save[i];
       }
    
    for(i=0;i<branch_numbers;i++)
    {
        printf("------------------------------------------------------------------\n");
        printf("branch %d: ",i+1);
        percent=0;
        final=0;
        for(j=0;j<12;j++)
        {
        percent += sales[i][j];
        }
        final = percent/total*100;
        printf("%.1f %%\n",final);
        printf("------------------------------------------------------------------\n");
        total=0;
    }
    
    return 0;
}

float peak_sales(){
    int i,j,m = 0;
    float k,peak = 0.0,save[12];
    
    for(i=0;i<12;i++)
    {

        for(j=0;j<branch_numbers;j++)
        {
            peak+=sales[j][i];
        }
        save[i]=peak;
        peak=0;
    }
    k=save[0];
    for(i=1;i<12;i++)
    {
        if(save[i]>k)
        {
            k=save[i];
            m=i;
        }
    }
    
    printf("------------------------------------------------------------------\n");
    printf("Month %d has the peak sales of %.1f\n",m+1,k);
    printf("------------------------------------------------------------------\n");
    return 0;
}

float sales_of_month(){
    int n,i,j;
    float arr[branch_numbers],swap;

    printf("Input :\n");
    scanf("%d",&n);
    printf("Month %d sales :\n",n);
    for (i=0;i<branch_numbers;i++){
        arr[i]=sales[i][(n-1)];
    }
    
    for (i=0;i<branch_numbers-1;i++){
        for(j=0;j<(branch_numbers-1-i);j++)
        {
            if (arr[j]<arr[j+1])
            {
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    
    for( j = 0 ; j < branch_numbers; j++)
    {
        printf("Branch: %.1f\n",arr[j]);
    }
    printf("\n");
    printf("------------------------------------------------------------------\n");
    return 0;
}

float sales_of_branch(){
    int i,j,m;
    float swap;
    
    printf("Input :\n");
    scanf("%d",&m);
    printf("Bransh %d sales :\n",m);
   
    for(i = 0 ; i < 12; i++)
    {
        for(j = i + 1; j < 12; j++)
        {
            if(sort[m-1][i] < sort[m-1][j])
            {
                swap = sort[m-1][i];
                sort[m-1][i] = sort[m-1][j];
                sort[m-1][j] = swap;
            }
        }
    }
    printf("\n");
    
    for( j = 0 ; j < 12; j++)
    {
        printf("Month: %.1f\n",sort[m-1][j]);
    }
    printf("\n");
    printf("------------------------------------------------------------------\n");
    return 0;
}

float backup(){
    int i,j;
    sort = malloc(branch_numbers*sizeof(float*));
    
    for (i=0 ; i < 12 ; i++)
    {
        sort[i] = malloc(12*sizeof(float*));
    }
    
    for (i=0 ; i < branch_numbers ; i++)
    {
        for (j=0 ; j < 12 ; j++)
        {
            sort[i][j]=sales[i][j];
        }
    }
    return 0;
}
