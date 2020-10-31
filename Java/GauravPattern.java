class Pattern13
{
    public static void main(String args[])
    {
        int x = 0;int i = 1;
        while(i<=4)
        {
            int j = 1;
            while(j<=i)
            {
                System.out.print(x);
                x++;
                j++;
            }
            System.out.println();
            i++;
        }
        int y = 5;int k = 3;
        while(k>0)
        {
            int l = 1;
            while(l<=k)
            {
                 System.out.print(y);
                 y--;
                 l++;
                }
                System.out.println();
                k--;
            }
        }
    }
                
