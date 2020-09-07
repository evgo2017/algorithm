/*
 * @Author: evgo 
 * @Date: 2018-06-10 19:26:59 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 21:23:04
 * @Email: evgo2017@qq.com
 * @Github: evgo2017
 * @Blog: http://evgo2017.com
 */

/*两路归并*/

#include <iostream>
#include <algorithm>
#define n 5
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int data[n] = {4,2,5,7,9};
    sort(data, data+n); 

    int j = 0;
    for(int i=0; i<n-2; i++) { 
        data[i+1] += data[i] - 1;

        j = i+1;
        while(data[j]>data[j+1]) {
            swap(data[j], data[j+1]);
            j++; 
        }
    }
    data[n-1] += data[n-2] - 1;

    cout<<data[n-1];
    return 0;
}