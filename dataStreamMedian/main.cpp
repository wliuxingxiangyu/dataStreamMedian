#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> medianII(vector<int> &nums) {
	vector<int> result;
	if (nums.size() == 0) {
		return result;
	}

	int median = nums[0];
	priority_queue<int> maxHeap, minHeap;

	result.push_back(median);
	int len=nums.size();
	for (int i = 1; i < len; i++) {
		if (nums[i] < median) {//nums[i]比 中位数median小,则nums[i]插入最大堆maxHeap.
			maxHeap.push(nums[i]);//maxHeap每时每刻存储较小的nums[i]，堆顶为这一半数的最大值,即maxHeap.
		} else {//nums[i] 不比 中位数median小,则 -nums[i]插入最小堆minHeap.
			minHeap.push(-nums[i]);//minHeap每时每刻存储较大的-nums[i],maxHeap每时每刻存储较大的nums[i]，堆顶为这一半数的最小值,即minHeap.？？
		}//因为本来堆是最大堆,-nums[i]反着插,就是最小堆了

		if (maxHeap.size() > minHeap.size()) {//最大堆maxHeap元素个数 多于 最小堆minHeap
			minHeap.push(-median);//将元素个数少的minHeap增大？？
			median = maxHeap.top();//获得maxHeap堆顶元素
			maxHeap.pop();//移出maxHeap堆顶元素
		} else if (maxHeap.size() + 1 < minHeap.size()) {//最大堆maxHeap元素个数+1 少于 最小堆minHeap(即大2)
			maxHeap.push(median);//将元素个数少的maxHeap增大？？
			median = -minHeap.top();//因为minHeap就是压入的minHeap.push(-nums[i]);//获得minHeap堆顶元素
			minHeap.pop();//移出maxHeap堆顶元素
		}

		result.push_back(median);
	}

	return result;
}
int main(){
	int arr[]={4, 5, 1, 3, 2, 6, 0};
	int len=sizeof(arr)/sizeof(arr[0]);
	vector<int> nums(arr,arr+len);
	medianII(nums);
	system("pause");
	 return 0;
}