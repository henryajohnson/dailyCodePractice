#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;


struct node{
    int k;
    int frequency;
};

bool compareNode(node n1, node n2){
	if(n1.frequency < n2.frequency){
		return true;
	}else if(n1.frequency == n2.frequency){
		if(n1.k > n2.k){
			return true;
		}
	}
	return false;
}

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int, int> map;
    	for(int i=0; i< nums.size(); i++){
    		map[nums[i]] ++;
    	} 
    	vector<node> nodeVec;
    	for (auto& x: map) {
    		node newnode;
    		newnode.k = x.first;
    		newnode.frequency = x.second;
    		nodeVec.push_back(newnode);
    	}
    	make_heap(nodeVec.begin(), nodeVec.end(), compareNode);
    	vector<int> outputNumbers;
    	for(int i=0; i<k && nodeVec.size()>0; i++){
    		outputNumbers.push_back(nodeVec.front().k);
    		pop_heap(nodeVec.begin(), nodeVec.end(), compareNode);
    		nodeVec.pop_back();
    	}
        return outputNumbers;
    }
};

int main(){
	cout << "-- Testing -- " << endl;
	int builder[] = {1,1,1,2,2,3,3,3,3,4,5,5};
	vector<int> myvec (builder, builder + sizeof(builder) / sizeof(int) );
	Solution mysolution;
	vector<int> results = mysolution.topKFrequent(myvec, 5);
	cout << "Final output: "<< endl;
	for(int i=0; i<results.size(); i++){
		cout << results[i] << " ";
	}
	cout << endl << endl;
	return 0;
}
