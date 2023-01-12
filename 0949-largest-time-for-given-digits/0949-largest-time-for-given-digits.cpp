class Solution {
public:
	string largestTimeFromDigits(vector<int>& arr) {
		string ans = "";
		sort(arr.begin(),arr.end());
		do
		{
			if((arr[0]==2 && arr[1]<=3 || arr[0]<2) && arr[2]<=5)
			{
                string temp;
                temp.push_back(arr[0]+'0');
                temp.push_back(arr[1]+'0');
                temp.push_back(':');
                temp.push_back(arr[2]+'0');
                temp.push_back(arr[3]+'0');
				if(temp > ans){
                    ans = temp;
                }
			}       
		}while(next_permutation(arr.begin(),arr.end()));
		return ans;
	}
};