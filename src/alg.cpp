// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
   int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i+1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    if (count != 0)
        return count;
    return 0;
}
int countPairs2(int *arr, int len, int value) {
   int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] <= value) {
            for (int j = len - 1; j > i; j--) {
                if (arr[i] + arr[j] == value)
                    ++count;
            }
        }
    }
    if (count != 0)
        return count;
    return 0;
}
int countPairs3(int *arr, int len, int value) {
   int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int low = i;
        int top = len;
        while (low < top-1) {
            int mid = (low + top) / 2;
            if (arr[i] + arr[mid] == value) {
                ++count;
                int j = mid + 1;
                while (arr[i] + arr[j] == value && j < top) {
                    ++count;
                    ++j;
                }
                j = mid - 1;
                while (arr[i] + arr[j] == value && j > low) {
                    ++count;
                    --j;
                }
                break;
            }
            if (arr[i] + arr[mid] < value)
                low = mid;
            if (arr[i] + arr[mid] > value)
                top = mid;
        }
    }
    if (count != 0)
        return count;
    return 0;
}
