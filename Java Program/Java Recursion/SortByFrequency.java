
import java.io.*;
import java.lang.*;
import java.util.*;
class SortByFrequency {
    public static List<Integer> sortBasedOnFrequencyAndValue(List<Integer> list) {
    Map<Integer, Integer> map = new HashMap<>();

    for (int i = 0; i < list.size(); i++) {
      map.put(list.get(i), map.getOrDefault(list.get(i), 0) + 1);
    }

    Collections.sort(list, (n1, n2) -> {
      int freq1 = map.get(n1);
      int freq2 = map.get(n2);

      if (freq1 != freq2) {
        return freq2 - freq1;
      }

      return n1 - n2;
    });

    return list;
  }
	public static void main (String[] args) {
	    int a[]={1,3,2,6,3,3,2,6,1,1,2,6,0,0,0,0,5,5,5,5,5};
	    Integer[] arr = new Integer[a.length];
        int i = 0;
        for (int value : a) {
        arr[i++] = Integer.valueOf(value);
         }
         
	   List<Integer> list = Arrays.asList(arr);
       List<Integer>ans=SsortBasedOnFrequencyAndValue(list);
     
	    
	}
}
