void show()
{
    float s=0.0;
    cout<<"\n\tItem\tWeight\tCost\tSelected";
    for(int i=1;i<9;i++)
        printf("\n\t%d\t%d\t%d\t%d",i+1,weight[i],profit[i],x[i]);
    printf("\n\n The Sack now holds following items : ");
    for(int i=1;i<9;i++){
        if(x[i]==1)
        {
            cout<<i+1<<"     ";
            s +=  profit[i] *  x[i];
        }
    }
    printf("\n Maximum Profit: %f ",s);
}
/*Arrange the item based on high profit per Unit*/
float kwf4(int k,int weightSoFar,int profitSoFar)
{
    float b = profitSoFar;
    float c = weightSoFar;
    for(int i=k+1;i<=n;i++)
    {
        c = c+weight[i];
        if( c < capacity)
            b = b +profit[i];
        else
            return (b+(1-(c-capacity)/ weight[i])*profit[i]);
    }
    return b;
}
void knapsack(int k,int profitSoFar,int weightSoFar)
{
    if(weightSoFar+weight[k] <= capacity)
    {
        y[k] = 1;
        if(k < no_items)
            knapsack(k+1,profitSoFar+profit[k],weightSoFar+weight[k]);
        if(((profitSoFar+profit[k]) > maxProfit) && ( k == no_items))
        {
            maxProfit = profitSoFar+profit[k];
            maxWeight = weightSoFar+weight[k];
            for(int j=1;j<=k;j++)
                x[j] = y[j];
        }
    }
    if(kwf4(profitSoFar,weightSoFar,k) >= maxProfit)
    {
        y[k] = 0;
        if( k < no_items)
            knapsack(k+1,profitSoFar,weightSoFar);
        if((profitSoFar > maxProfit) && (k == no_items))
        {
            maxProfit = profitSoFar;
            maxWeight = weightSoFar;
            for(int j=1;j<=k;j++)
                x[j] = y[j];
        }
    }
}