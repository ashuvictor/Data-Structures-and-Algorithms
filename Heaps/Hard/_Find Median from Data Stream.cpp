The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
    }
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};




class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() and minheap.empty())
        {
            maxheap.push(num);
        }
        else{
            if(maxheap.top()<num)
            {
                minheap.push(num);
            }
            else
            {
                maxheap.push(num);
            }
        }
        
        // now balance it after inserting
           int n=maxheap.size();
        int m=minheap.size();
         if(n-m==2 or n-m==-2)
        {
            if(n>m){
                int element=maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else{
                int element=minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
        
    }
    
    double findMedian() {
        //2 cases are there even elements and odd elements
        //and if they are not balanced ,then balance them
        int n=maxheap.size();
        int m=minheap.size();
       
        if((n+m)%2==0)
            return ((double)maxheap.top()+(double)minheap.top())/2.0;
        if(n>m)
            return maxheap.top()*1.0;
        else
            return minheap.top()*1.0;
    }
};
