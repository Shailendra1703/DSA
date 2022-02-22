
{
    for (int i = 1; i < n; i++)
        printf("%d ", H[i]);
    printf("\n\n");
}
int main()
{
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int n = sizeof(H) / sizeof(H[0]);
    for (int i = 2; i < n; i++)
        insert(H, i);

    printf("Created Heap\n");
    printHeap(H, n);

   for(int i = 1 ; i<n ; i++)
        delete (H, n-i);
    
     printf("Sorted Heap\n");
    printHeap(H, n);

    return 0;
}