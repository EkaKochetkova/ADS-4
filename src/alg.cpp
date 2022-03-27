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
   return count;
}
int countPairs2(int *arr, int len, int value) {
   int count = 0;
   int i = 0;
   int j = len-1;
   while (i<j) {
      if (arr[i] + arr[j] == value) {
         ++count;
         if (arr[i + 1] + arr[j] == value) {
            ++i;
         } else {
            --j;
         }
      } else if (arr[i] + arr[j] > value) {
         --j;
      } else if(arr[i] + arr[j] < value) {
         ++i;
      }
   }
   return count;
}
int countPairs3(int *arr, int len, int value) {
   int val = 0;
   int count = 0;
   for (int k=0; k < len/2+1; ++k) {
      int low = k;
      int top = len - 1;
      val = value - arr[k];
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
        return count;
}
