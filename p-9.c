//Leaky Bucket 
Leaky_Bucket.c


#include <stdio.h>

int main()
{
    int bucket_size, output_rate;
    int incoming, remaining = 0;
    int time, sent, dropped;

    printf("Enter bucket capacity: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter number of time intervals: ");
    scanf("%d", &time);

    for (int i = 1; i <= time; i++)
    {
        printf("\nEnter incoming packets at time %d: ", i);
        scanf("%d", &incoming);

        if (remaining + incoming > bucket_size)
        {
            dropped = remaining + incoming - bucket_size;
        }
        else
        {
            dropped = 0;
        }

        remaining += incoming - dropped;

        sent = (remaining < output_rate) ? remaining : output_rate;

        remaining -= sent;

        printf("Packets sent: %d\n", sent);
        printf("Packets dropped: %d\n", dropped);
        printf("Packets remaining: %d\n", remaining);
    }

    return 0;
}

//TOKEN BUCKET 

Token_Bucket.c


#include <stdio.h>

int main()
{
    int bucket_size, token_rate;
    int tokens = 0;
    int packets, time;

    printf("Enter bucket capacity: ");
    scanf("%d", &bucket_size);

    printf("Enter token generation rate: ");
    scanf("%d", &token_rate);

    printf("Enter number of time intervals: ");
    scanf("%d", &time);

    for (int i = 1; i <= time; i++)
    {
        // Generate tokens
        tokens += token_rate;

        if (tokens > bucket_size)
        {
            tokens = bucket_size;
        }

        printf("\nEnter packets to send at time %d: ", i);
        scanf("%d", &packets);

        // Check token availability
        if (packets <= tokens)
        {
            printf("Packets sent: %d\n", packets);
            tokens -= packets;
        }
        else
        {
            printf("Packets sent: %d\n", tokens);
            printf("Packets waiting/dropped: %d\n",
                   packets - tokens);

            tokens = 0;
        }

        printf("Remaining tokens: %d\n", tokens);
    }

    return 0;
}
