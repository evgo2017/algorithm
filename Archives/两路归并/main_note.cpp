/*
 * @Author: evgo 
 * @Date: 2018-06-10 19:26:59 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 21:23:04
 * @Email: evenIfAlsoGo@gmail.com 
 * @Github: evenIfAlsoGo
 * @Blog: http://evgo2017.com 
 */

/* 题目：
给定 k 个排好序的序列 s1,s2,...,sk， 用 2 路合并算法将这 k 个序列合并成一个序列。 
假设所采用的 2 路合并算法合并 2 个长度为 m 和 n 的序列需要 m+n-1次比较。 
设计一个算法确定 2 路合并次序， 使所需的总比较次数最少。`

目的：比较次数最少
*/

#include <iostream>
#include <algorithm>
#define n 5
using namespace std;

// void printArr(int data[]) {
//     for(int i=0; i<n; i++)  {
//         cout<<data[i]<<" ";
//     }
//     cout<<endl;
// }

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

//采用贪心算法，每次选用最小的序列进行合并
int main() {
    int data[n] = {4,2,5,7,9};
    sort(data, data+n); //将数组从小到大排列

    int j = 0; 
    //一共比较 n-2 次，因为比较 n-1次时，j+1的值会越界，为了避免Bug，最后一项另外赋值
    for(int i=0; i<n-2; i++) { 
        data[i+1] += data[i] - 1;
        
        j = i+1; //作为游标，判断相加后的数，是否大于它后面的数，如果大则进行排序
        while(data[j]>data[j+1]) {
            swap(data[j], data[j+1]);
            j++; 
        }
    }
    //修正最后一项，它前面的数加上它本身就是最少次数了
    data[n-1] += data[n-2] - 1;

    cout<<data[n-1];
    return 0;
}