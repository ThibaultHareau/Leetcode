long long repairCars(int* ranks, int ranksSize, int cars) {
    long maximum_rank = 0;
    for (int i=0;i<ranksSize;i++){if (ranks[i]>maximum_rank) {maximum_rank = ranks[i];}}
    long mini = cars/ranksSize;
    long maxi = ((long) maximum_rank) * (1+(cars/ranksSize))*(1+(cars/ranksSize));
    long fixed;
    long minutes;
    while(mini != maxi){
        minutes = (mini+maxi)/2;
        fixed = 0;
        for(int i=0;i<ranksSize;i++){
            fixed += sqrt(minutes/ranks[i]);
            if (fixed>cars){
                maxi = minutes;
                break;
            }
        }
        if (fixed<cars){
            mini = minutes+1;
        }
        if (fixed == cars){
            maxi = minutes;
        }
    }
    return maxi;
}