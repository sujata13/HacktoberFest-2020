import java.util.*;
class PrintJob
{
    int job[];
    int newjob;
    int capacity;
    int front;
    int rear;
    PrintJob()
    {
        capacity=20;
        front=-1;
        rear=-1;
        createjob();
    }
    void createjob()
    {
        job= new int[capacity];
    }
    void addjob()
    {
        Scanner  in =new Scanner(System.in);
        System.out.println("Enter a new Job");
        newjob=in.nextInt();
        if(rear== capacity-1)
        System.out.println("PrintJob is full,cannot add more ");
        else
        {
            if(front==-1&&rear==-1)
            {
                front=0;
                rear=0;
            }
            else
            rear=rear+1;
            job[rear]=newjob;
        }
    }
    void removejob()
    {
        int v;
        if(rear==-1&&front==-1)
        System.out.println("PrintJob is empty");
        else
        {
            v=job[front];
            System.out.println("PrintJob removes\t"+v);
            if(front== rear)
            {
                front=-1;
                rear=-1;
            }
            else
            front=front+1;
        }
    }
}

        
