vector<int> mergeSortedArray(int N, vector<vector<int>> arr){
    vector<int> res; //result Array
    queue<vector<int>> q(N); //priority Queue
    vector<int> idx(N); // vector to keep track the index of individual array
    int count = 0;    
    //putting all the array's first element
    for(int i = 0; i < N; i++){
        if(idx[i] < arr[i].size())
            q.insert({arr[i][idx[i]],i});
        else count++;
    }
    
    //now every iteration we are picking one elemnet for the right place and if one array reached the end increment count
    while(count < N - 1){        
            vetor<int> front = q.front();
            q.pop();
            res.push_back(front[0]);
            int index = front[1];
            idx[index] += 1;
            if(idx[index] < arr[idx].size()){
                q.insert({arr[idx[index]], index});
            } else {
                count++;
            } 
    }
    
    //find the last array having some element left and copy rest to the res vector
    int leftOne;
    for(int i = 0; i < N; i++){
        if(idx[i] < arr[i].size()){
            leftOne = i;
            break;
        }
    }
    
    for(int i = idx[leftOne]; i < arr[leftOne].size(); i++){
        res.push_back(arr[leftOne][i]);
    }
    
    return res;
}
