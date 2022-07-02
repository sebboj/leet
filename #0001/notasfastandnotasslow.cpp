class Solution {//O(nlogn) lots of lines my hands hurt
public:
    
    void merge(vector<int>& bums, vector<int>& bemp, int l, int r, int rEnd){
        int lEnd = r - 1;
        int pos = l;
        int len = rEnd - l + 1;

        while(l <= lEnd and r <= rEnd){
            if(min(bums[l], bums[r]) == bums[l]){
                bemp[pos] = bums[l];
                pos++;
                l++;
            }
            else{
                bemp[pos] = bums[r];
                pos++;
                r++;
            }
        }

        while(l <= lEnd){
            bemp[pos] = bums[l];
            pos++;
            l++;
        }

        while(r <= rEnd){
            bemp[pos] = bums[r];
            pos++;
            r++;
        }

        for(int i = 0; i < len; i++){
            bums[rEnd] = bemp[rEnd];
            rEnd--;
        }
    }

    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right){
        if(left < right){
            int center = (left + right) / 2;
            mergeSort(nums, temp, left, center);
            mergeSort(nums, temp, center + 1, right);
            merge(nums, temp, left, center + 1, right);
        }
    }

    int binarySearch(vector<int>& wector, int goal){
        int l = 0, r = wector.size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(wector[mid] < goal)
                l = mid + 1;
            else if(wector[mid] > goal)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }
    
    vector<int> find(int a, int b, vector<int>& nums){
        vector<int> solution;
        solution.clear();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == a){
                solution.push_back(i);
                break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == b && i != solution[0]){
                solution.push_back(i);
                break;
            }
        }
        return solution;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        int size = nums.size();
        temp.assign(size, 0);

        vector<int> sol;
        
        if(size == 2){
            sol.clear();
            sol.push_back(0);
            sol.push_back(1);
        }
        
        else{
            vector<int> sorted;
            for(int i = 0; i < size; i++){
                sorted.push_back(nums[i]);
            }

            mergeSort(sorted, temp, 0, size-1);

            for(int i = 0; i < size; i++){
                sol.clear();
                sol.push_back(i);
                int other = binarySearch(sorted, target-sorted[i]);
                if(other > 0){
                    sol.push_back(other);
                    break;
                }
            }

            sol = find(sorted[sol[0]], sorted[sol[1]], nums);
        }
        
        return sol;
    }
    
};
