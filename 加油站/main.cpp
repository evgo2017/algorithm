/*
 * @Author: evgo 
 * @Date: 2018-06-10 21:32:29 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 22:41:31
 * @Email: evgo2017@qq.com
 * @Github: evgo2017
 * @Blog: http://evgo2017.com
 */

/* 加油站 */

#include <iostream>
#include <fstream>
using namespace std;

//采用贪心算法
int main(){
    ifstream fin("input.txt");
    int n,k，num = 0; 
    fin>>n; 
    fin>>k; 

    int data[k+1] = {0};
    for(int i=0; i<k+1; i++) {
        fin>>data[i];
        if(data[i]>n) {
            cout<<"No Solution!"<<endl; 
            return 0;
        }
    }
    
    for(int i=0; i<k+1; i++) {
        if(n>data[i]) {  
            n -= data[i];
        } else { 
            n = 5 - data[i];
            num++;
        }
    }
    
    cout<<num<<endl;
    return 0;
}