
void merge( int input[], int l, int mid, int r){
    int n1 = mid -l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
	
    for(int i =0;i<n1;i++){
        a[i]=input[l+i];
    }
    for(int i =0;i<n2;i++){
        b[i]=input[mid+i+1];
    }
    int i =0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){ 
        input[k]=a[i];
        k++;i++;
        }
        else{
            input[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        input[k]=a[i];
        k++;i++;
    }
    while(i<n2){
        input[k]=b[j];
        k++;j++;
    }
}

void mergeSort1(int input[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort1(input, l, mid);
        mergeSort1(input, mid +1, r);

        merge(input, l, mid , r);
    }
}

void mergeSort(int input[], int length){
    mergeSort1(input,0, (length-1));
}
