#include<bits/stdc++.h>
using namespace std;

void knapsack(int n, float weight[], float price[], float capacity)
{
   float x[20], total_price = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
   {
      x[i] = 0.0;
   }

   for (i = 0; i < n; i++)
   {
      if (weight[i] > u)
         break;
      else
      {
         x[i] = 1.0;
         total_price = total_price + price[i];
         u = u - weight[i];
         if(u < 1)
            break;
      }
   }

   if (i < n)
   {
      x[i] = u / weight[i];
   }

   total_price = total_price + (x[i] * price[i]);

   printf("\nThe final portion of each product is: ");

   for (i = 0; i < n; i++)
   {
      printf("%f\t", x[i]);
   }

   printf("\n\nFinal Price after conducting minimum loss is: %f BDT\n\n", total_price);

}

int main()
{
   float weight[20], price[20], capacity;
   int number, i, j;
   float ratio[20], temp;

   printf("                             WELCOME TO AMAZON\n\n\n");
   printf("Proceeding to checkout......\n\n");
   printf("Please insert your total number of selected products: ");
   scanf("%d",&number);

   printf("\nEnter the weights and prices of each product: \n");
   for (i = 0; i < number; i++)
   {
      scanf("%f %f", &weight[i], &price[i]);
   }

   printf("\nProceeding to user information......\n");
   for (i = 0; i < number; i++)
   {
      printf("\nProduct-%d: Weight: %f Kg  Price: %f BDT\n", i+1, weight[i], price[i]);
   }

   printf("\nEnter the maximum weight capacity of your country's airport: ");
   scanf("%f", &capacity);

   for (i = 0; i < number; i++) {
      ratio[i] = price[i] / weight[i];
   }

   for (i = 0; i < number; i++)
    {
      for (j = i + 1; j < number; j++)
      {
         if (ratio[i] < ratio[j])
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = price[j];
            price[j] = price[i];
            price[i] = temp;
         }
      }
   }

   knapsack(number, weight, price, capacity);
   return(0);
}
