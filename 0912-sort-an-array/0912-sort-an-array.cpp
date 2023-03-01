class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
    void heapsort(vector<int> &nums){
        
        int size = nums.size();
        
        for(int i=size/2-1;i>=0;i--){
            heapify(nums,size,i);
        }
        for(int i=size-1;i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }
    void heapify(vector<int> &nums,int size, int index){
        int parent = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && nums[parent]<nums[left]){
            parent = left;
        }
        if(right<size && nums[parent]<nums[right]){
            parent = right;
        }
        if(parent!=index){
            swap(nums[parent],nums[index]);
            heapify(nums,size,parent);
        }
    }
};