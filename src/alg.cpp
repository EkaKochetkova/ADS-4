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
   int val = 0;
   int count = 0;
   for (int i=0; i < len/2+1; ++i) {
       int low = i;
       int top = len;
       val = value - arr[i];
       while (low <= top) {
           int mid = (top + low) / 2;
           if (arr[mid] == val) {
               int i = mid + 1;
               int j = mid - 1;
               ++count;
                while (arr[i] == val || arr[j] == val) {
                   if (arr[i] == val) {
                       count += 1;
                       i += 1;
                   }
                   if (arr[j] == val) {
                       count += 1;
                       j -= 1;
                   }                 
               }
                break;
           }
           if (arr[mid] < val) {
               low = mid + 1;
           }
           if (arr[mid] > val) {
               top = mid - 1;
           }
       }
   }
   if (count != 0)
       return count;
   return 0; 
}
