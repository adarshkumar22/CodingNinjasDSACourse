int pivot(int a[], int si, int ei)
{
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if (a[si] > a[i])
        {
            count++;
        }
    }
    int p = count + si;
    std::swap(a[si], a[p]);
    int i = si, j = ei;
    while (i < p && j > p)
    {
        if (a[i] < a[p])
        {
            i++;
        }
        else if (a[j] >= a[p])
        {
            j--;
        }
        else
        {
            std::swap(a[i], a[j]);
            i++;j--;
        }
    }
    return p;
}

void quickSort_helper(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int p = pivot(a, si, ei);
    quickSort_helper(a, si, p - 1);
    quickSort_helper(a, p + 1, ei);
}

void quickSort(int input[], int size)
{
    quickSort_helper(input, 0, size - 1);
}
// void swap(int arr[], int i , int j){
//     int temp = arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp; 
// }

// int partition(int arr[], int l, int r){
//     int pivot= arr[r];
//     int i = l-1;
//     for(int j =l;j<r;j++){
//         ifint pivot(int a[], int si, int ei)
{
    int count = 0;
    for (int i = si; i <= ei; i++)
    {
        if (a[si] > a[i])
        {
            count++;
        }
    }
    int p = count + si;
    std::swap(a[si], a[p]);
    int i = si, j = ei;
    while (i < p && j > p)
    {
        if (a[i] < a[p])
        {
            i++;
        }
        else if (a[j] >= a[p])
        {
            j--;
        }
        else
        {
            std::swap(a[i], a[j]);
            i++;j--;
        }
    }
    return p;
}

void quickSort_helper(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int p = pivot(a, si, ei);
    quickSort_helper(a, si, p - 1);
    quickSort_helper(a, p + 1, ei);
}

void quickSort(int input[], int size)
{
    quickSort_helper(input, 0, size - 1);
}
// void swap(int arr[], int i , int j){
//     int temp = arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp; 
// }

// int partition(int arr[], int l, int r){
//     int pivot= arr[r];
//     int i = l-1;
//     for(int j =l;j<r;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr, i,j);
//         }
//     }
//     swap(arr, i+1, r);
//     return i+1;
// }

// void quickSort1(int arr[],int l, int r){
//     if(l<=r){
//         int pi = partition(arr, l ,r);
//         quickSort1(arr, l, pi-1);
//         quickSort1(arr, pi+1, r);
//     }
// }
// void quickSort(int arr[], int size){
//     quickSort1(arr, 0,size-1);
// }(arr[j]<pivot){
//             i++;
//             swap(arr, i,j);
//         }
//     }
//     swap(arr, i+1, r);
//     return i+1;
// }

// void quickSort1(int arr[],int l, int r){
//     if(l<=r){
//         int pi = partition(arr, l ,r);
//         quickSort1(arr, l, pi-1);
//         quickSort1(arr, pi+1, r);
//     }
// }
// void quickSort(int arr[], int size){
//     quickSort1(arr, 0,size-1);
// }