// The solution of knapsack problem using greedy method
// The code written by Hocine Abderrahmene
// you can test the code in replit in this link: https://replit.com/@Abderrahmanehocine/knapsack-probelm-greedy-method?v=1

#include <stdio.h>

void knapsack_solution(int m, int *profit, int *weight, int size){
    int used[size];
    int cur_weight, item;
    float total_profit = 0;
    int i;
    for (i = 0; i < size; ++i)
        used[i] = 0;

    cur_weight = m;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < size; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) profit[i] / weight[i] > (float) profit[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += profit[item];
        if (cur_weight >= 0)
            printf("Added object %d (%d , %dKg) completely in the bag. Space left: %d Kg.\n", item + 1, profit[item], weight[item], cur_weight);
        else
        {
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d , %dKg) of object %d in the bag.\n", item_percent, profit[item], weight[item], item + 1);
            total_profit -= profit[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * profit[item];
        }
    }

    printf("Filled the bag with objects worth %.2f \n", total_profit);
}


int main(){
    int number_of_objects, max_weight;
    // scan the capacity number of the bag
    printf("Enter the max weight: ");
    scanf("%d",&max_weight);
    
    // scan the number of items
    printf("Enter number of objects: ");
    scanf("%d",&number_of_objects);
    
    int profit[number_of_objects];
    int weight[number_of_objects];
    printf("\n\nEnter the profit and the weight of each object: \n\n");
    
    // scan the profit and the weight of each item
    int i;
    for(i=0 ; i<number_of_objects ; i++){
        printf("Object number %d:\n",i+1);
        printf("Profit: ");
        scanf("%d",&profit[i]);
        printf("Weight: ");
        scanf("%d",&weight[i]);
        printf("\n");
    }
    
    knapsack_solution(max_weight, profit, weight, number_of_objects);
    return 0;
}
