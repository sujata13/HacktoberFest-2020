public class CocktailSort
{

    public static void cocktailSort(Integer[] inputArrays,
                                    Integer n)
    {
        Boolean swapped = Boolean.TRUE;
        Integer start = 0;
        Integer end = inputArrays.length;

        while (swapped) {
            swapped = Boolean.FALSE;

            for (int i = start; i < end - 1; ++i) {
                if (inputArrays[i] > inputArrays[i + 1]) {
                    int temp = inputArrays[i];
                    inputArrays[i] = inputArrays[i + 1];
                    inputArrays[i + 1] = temp;
                    swapped = Boolean.TRUE;
                }
            }

            if (!swapped) {
                break;
            }

            swapped = Boolean.FALSE;
            end--;

            for (int i = end - 1; i >= start; i--) {
                if (inputArrays[i] > inputArrays[i + 1]) {
                    int temp = inputArrays[i];
                    inputArrays[i] = inputArrays[i + 1];
                    inputArrays[i + 1] = temp;
                    swapped = Boolean.TRUE;
                }
            }

            start++;
        }
    }

}