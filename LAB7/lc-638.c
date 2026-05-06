int shoppingOffers(int* price, int priceSize, int** special,
                   int specialSize, int* specialColSize,
                   int* needs, int needsSize) {

    int minCost = 0;

    // direct buy
    for (int i = 0; i < needsSize; i++)
        minCost += needs[i] * price[i];

    for (int i = 0; i < specialSize; i++) {

        int newNeeds[10];
        int valid = 1;
        int normalCost = 0;

        // check validity + compute normal price
        for (int j = 0; j < needsSize; j++) {
            if (special[i][j] > needs[j]) {
                valid = 0;
                break;
            }
            newNeeds[j] = needs[j] - special[i][j];
            normalCost += special[i][j] * price[j];
        }

        if (!valid || special[i][needsSize] >= normalCost)
            continue;

        int cost = special[i][needsSize] +
                   shoppingOffers(price, priceSize, special,
                                  specialSize, specialColSize,
                                  newNeeds, needsSize);

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}
