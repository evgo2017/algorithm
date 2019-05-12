/*
 * @Author: evgo 
 * @Date: 2018-06-09 11:01:02 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 11:17:06
 * @Email: evgo2017@qq.com
 * @Github: evgo2017
 */

/* 磁带最优问题
题目：设有n 个程序{1,2,…, n }要存放在长度为L的磁带上。程序i存放在磁带上的长度是Li， 1<= i<= n。这n 个程序的读取概率分别是p1,p2,...,pn,且pi+p2+...+pn = 1。如果将这n 个程序按 i1,i2,....,in 的次序存放，则读取程序ir 所需的时间tr=c*(Pi1*Li2+Pi2*Li2+...+Pir*Lir)。这n 个程序的平均读取 时间为t1+t2+...+tn。 磁带最优存储问题要求确定这n 个程序在磁带上的一个存储次序，使平均读取时间达到 最小。试设计一个解此问题的算法,并分析算法的正确性和计算复杂性。 编程任务： 对于给定的n个程序存放在磁带上的长度和读取概率，编程计算n个程序的最优存储方 案。
*/

/*
    疑问：使平均读取时间达到最小。是读取n个程序的总时间，还是读取这n个程序中每个程序的时间？
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//交换数据
template <class T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = x;
}
//打印数组
void printData(double data[][4], int n){
    for(int i=0;i<n;i++) {
        for(int j=0;j<4;j++) {
            cout<<data[i][j]<<" ";
        }  
        cout<<endl;
    }
    cout<<endl;
}

//采用贪心算法
int main(){
    /****************读取文件****************/
    ifstream fin("input.txt");

    /****************读取行数，新建数组存储************/
    /* 数值示例 5 */
    int n;
    fin>>n; 
    
    /****************读取数据,存入数组***************/
    /*数据结构：
    长度、概率（开始是概率值）、读取时间（单个程序）、序号（输入时第几个程序）
    */
    double data[n][4] = {0}, sumP = 0;
    /*数组结构示例
    71 872 0 0
    46 452 0 1
    9 265 0 2
    73 120 0 3
    35 87 0 4
    */
    string s;
    for(int i=0;i<n;i++) {
        fin>>data[i][0]; //长度值
        fin>>data[i][1]; //概率值
        data[i][3] = i; //第几个程序
        sumP += data[i][1]; //总概率
    }
    fin.close();//关闭文件
    printData(data,n);

    /****************开始计算****************/
    /*数组结构示例
    71 0.485523 34.4722 0 
    46 0.25167 11.5768 1 
    9 0.14755 1.32795 2 
    73 0.0668151 4.87751 3 
    35 0.048441 1.69543 4 
    */
    for(int i=0;i<n;i++) {
        data[i][1] = data[i][1]/sumP; //概率值切换为概率
        data[i][2] = data[i][0] * data[i][1]; //单个程序读取时间，长度与概率的乘积
    }
    printData(data,n);

    
    /****************冒泡排序（排序方法可以优化）****************/
    /*数组结构示例
    9 0.14755 1.32795 2 
    35 0.048441 1.69543 4 
    73 0.0668151 4.87751 3 
    46 0.25167 11.5768 1 
    71 0.485523 34.4722 0
    */
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(data[i][2]>data[j][2]) {
                swap(data[i], data[j]);
            }
        }
    }
    printData(data,n);

    /****************获取读取所有程序的时间****************/
    double time = 0;
    for(int i = 0;i < n; i++) {  
        /*示例：5*1.32795+4*1.69543+3*4.87751+2*11.5768+1*34.4722*/
        time += (n-i)*data[i][2];
    }  
    /* 示例:85.6798 */
    cout<<time<<endl;

    /****************写入文件****************/
    ofstream fout("ouput.txt");
    if(fout.is_open()) {
        fout<<time<<endl;
        fout.close();
    }

    return 0;
}