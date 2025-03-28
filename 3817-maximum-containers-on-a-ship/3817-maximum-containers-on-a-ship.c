int maxContainers(int n, int w, int maxWeight) {
    int maxContainerShip = maxWeight / w;
    if (maxContainerShip < n*n) return maxContainerShip;
    return n*n;
}