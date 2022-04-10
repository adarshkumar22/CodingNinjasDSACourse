int binarySearch(int input[], int size, int element) {

 int start = 0;
   int end = size-1;
   while(start<=end) {
      int mid = (start+end)/2;
      if( input[mid] == element) {
         return mid;
      } else if( element < input[mid] ) {
         end = mid-1;
      } else {
         start = mid+1;
      }
   }
   return -1;
}