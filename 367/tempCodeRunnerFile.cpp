for (int i = start; i <= sum; i + K)
    {
        findCombinations(N, K, R, currentCombination, 0, i);
    }