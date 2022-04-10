void printSubsetHelper(int input[],int startIndex,int  size, int output[],int oSize){
    if(startIndex == size){
        for(int i =0;i<oSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }

    int smallOutput[40], smalloSize = 0 ;
    printSubsetHelper(input, startIndex+1, size, output, oSize);

    int i ;
    for(i = 0 ;i<oSize;i++){
        smallOutput[i]=output[i];
    }
    smallOutput[i]=input[startIndex];
    printSubsetHelper(input, startIndex+1, size, smallOutput, oSize+1);
}

void printSubsetsOfArray(int input[], int size){
    int output[1000];
    printSubsetHelper(input,0, size, output, 0);
}
