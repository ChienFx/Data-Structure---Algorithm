struct MinMax{
   int Min,Max;
}

MinMax FindMinMax(int[] array, int start, int end) {
   MinMax  min_max;
   int index;
   int n = end - start + 1;//n: the number of elements to be sorted, assuming n>0
   if ( n%2 != 0 ){// if n is odd

     min_max.Min = array[start];
     min_max.Max = array[start];

     index = start + 1;
   }
   else{// n is even
     if ( array[start] < array[start+1] ){
       min_max.Min = array[start];
       min_max.Max = array[start+1];
     }
     else{
       min_max.Min = array[start+1];
       min_max.Max = array[start];
     }
     index = start + 2;
   }

   int big, small;
   for ( int i = index; i < n-1; i = i+2 ){
      if ( array[i] < array[i+1] ){ //one comparison
        small = array[i];
        big = array[i+1];
      }
      else{
        small = array[i+1];
        big = array[i];
      }
      if ( min_max.Min > small ){ //one comparison
        min_max.Min = small;
      }
      if ( min_max.Max < big ){ //one comparison
        min_max.Max = big;
      }
   }

   return min_max;
}