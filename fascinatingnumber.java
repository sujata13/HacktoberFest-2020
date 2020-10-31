import java.io.*;
class fascinating
{
    public static void main()throws IOException
    {int n=0,n1=0,n2=0;
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("enter the number");
        n=Integer.parseInt(in.readLine());
        n1=n*2;
        n2=n*3;
        int i=0;
        int num[]=new int [100];
        for(int t=n;t>0;t/=10)
        {
            num[i]=t%10;
            i++;
        }
        for(int t=n1;t>0;t/=10)
        {
            num[i]=t%10;
            i++;
        }
        for(int t=n2;t>0;t/=10)
        {
            num[i]=t%10;
            i++;
        }
        int flag=1;
        for(int j=1;j<=9;j++)
        {
            int ctr=0;
            for(int k=0;k<9;k++)
            {
                if(j==num[k])
                {
                    ctr++;
                }
            }

            if(ctr>1)
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            System.out.println("fascinating number");
        }
        else
        {
            System.out.println("not");
        }
    }
}
