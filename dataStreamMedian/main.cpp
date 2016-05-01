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
		if (nums[i] < median) {//nums[i]�� ��λ��medianС,��nums[i]��������maxHeap.
			maxHeap.push(nums[i]);//maxHeapÿʱÿ�̴洢��С��nums[i]���Ѷ�Ϊ��һ���������ֵ,��maxHeap.
		} else {//nums[i] ���� ��λ��medianС,�� -nums[i]������С��minHeap.
			minHeap.push(-nums[i]);//minHeapÿʱÿ�̴洢�ϴ��-nums[i],maxHeapÿʱÿ�̴洢�ϴ��nums[i]���Ѷ�Ϊ��һ��������Сֵ,��minHeap.����
		}//��Ϊ������������,-nums[i]���Ų�,������С����

		if (maxHeap.size() > minHeap.size()) {//����maxHeapԪ�ظ��� ���� ��С��minHeap
			minHeap.push(-median);//��Ԫ�ظ����ٵ�minHeap���󣿣�
			median = maxHeap.top();//���maxHeap�Ѷ�Ԫ��
			maxHeap.pop();//�Ƴ�maxHeap�Ѷ�Ԫ��
		} else if (maxHeap.size() + 1 < minHeap.size()) {//����maxHeapԪ�ظ���+1 ���� ��С��minHeap(����2)
			maxHeap.push(median);//��Ԫ�ظ����ٵ�maxHeap���󣿣�
			median = -minHeap.top();//��ΪminHeap����ѹ���minHeap.push(-nums[i]);//���minHeap�Ѷ�Ԫ��
			minHeap.pop();//�Ƴ�maxHeap�Ѷ�Ԫ��
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