//#include "../geek.h"
//
//void bucketSort(int* arr, int len) {
//    const int max = len;
//    const int b = 10;
//
//    int buckets[b][max+1];
//    for (int i = 0; i < b; ++i) {
//        buckets[i][max] = 0;
//    }
//
//    for (int digit = 1; digit < 1000000000; digit*=10) {
//        for (int i = 0; i < max; ++i) {
//            int d = (arr[i] / digit) % b;
//
////            int counter = buckets[d][max];
////            buckets[d][counter] = arr[i];
////            counter++;
////            buckets[d][max] = counter;
//
//            buckets[d][buckets[d][max]++] = arr[i];
//        }
//        int idx = 0;
//        for (int i = 0; i < b; ++i) {
//            for (int j = 0; j < buckets[i][max]; ++j) {
//                arr[idx++] = buckets[i][j];
//            }
//            buckets[i][max] = 0;
//        }
//    }
//}
//
//void bucketTest() {
//    const int SZ = 30;
//    int arr[SZ];
//    fillIntRandom(arr, SZ, 100);
//    printIntArray(arr, SZ, 3);
//    bucketSort(arr, SZ);
//    printIntArray(arr, SZ, 3);
//}
