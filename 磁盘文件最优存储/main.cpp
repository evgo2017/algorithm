/*
 * @Author: evgo 
 * @Date: 2018-06-10 11:35:18 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 13:21:46
 * @Email: evgo2017@qq.com
 * @Github: evgo2017
 */

/* 磁盘文件最优问题*/

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
void printData(double data[][2], int n){
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
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
    概率（开始是概率值）、序号（输入时第几个程序）
    */
    double data[n][2] = {0}, sumP = 0;
    /*数组结构示例
    33 0 
    55 1 
    22 2 
    11 3 
    9 4
    */
    string s;
    for(int i=0;i<n;i++) {
        fin>>data[i][0]; //概率值
        data[i][1] = i; //第几个程序
        sumP += data[i][0]; //总概率
    }
    fin.close();//关闭文件
    printData(data,n);

    /****************开始计算****************/
    /*数组结构示例
    0.253846 0 
    0.423077 1 
    0.169231 2 
    0.0846154 3 
    0.0692308 4
    */
    for(int i=0;i<n;i++) {
        data[i][0] = data[i][0]/sumP; //概率值切换为概率
    }
    printData(data,n);

    
    /****************冒泡排序（排序方法可以优化）****************/
    /*数组结构示例
    0.0692308 4 
    0.0846154 3 
    0.169231 2 
    0.253846 0 
    0.423077 1
    */
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(data[i][0]>data[j][0]) {
                swap(data[i], data[j]);
            }
        }
    }
    printData(data,n);

    /****************磁道位置****************/
    double result[n][2] = {0};
    /*数据示例,两个值偏大的存在左边,当总数为偶数个,对右边的数值存放有修正
    id         0         1        2        3         4
    data   0.0692308 0.0846154 0.169231 0.253846 0.423077
    result 0.0846154 0.253846  0.423077 0.169231 0.0692308
    */
    /* k = 2 */
    int k = (int)(n-1)/2; //数组中间,存放概率最大的值,如果是偶数个,则向下取整

   /****************结果数组右边位置****************/
   /*  0 1 2 3 4 5 一共6个数,偶数,需要额外处理第一个值
        result[i][0] = data[n-1-2*m][0](m=0,1,2...)
        result[2][0] = data[5][0] 
        result[3][0] = data[3][0]
        result[4][0] = data[1][0]
        result[5][0] = data[0][0]

        0 1 2 3 4 一共5个数,奇数
        result[i][0] = data[n-1-2*m][0](m=0,1,2...)
        result[2][0] = data[4][0] 
        result[3][0] = data[2][0]
        result[4][0] = data[0][0]
    */
    for(int i=k; i<n-1; i++) {  //注意这个n-1
        result[i][0] = data[n-1-2*(i-k)][0];
        result[i][1] = data[n-1-2*(i-k)][1];
    }
    //修正最后一个值,无论是奇数还是偶数个,结果数组内最后一个都存放的是概率最小的那个值
    result[n-1][0] = data[0][0];
    result[n-1][1] = data[0][1];

    /****************结果数组左边边位置****************/
    for(int i=k-1; i>-1; i--) {
        /*  result[k-1][0] = data[n-2*m][0](m=1,2,3..)
            result[1][0] = data[3][0] 
            result[0][0] = data[1][0]
        */
        /*  当n为偶数时,左边的数值无影响
            result[k-1][0] = data[n-2*m][0](m=1,2,3..)
            result[1][0] = data[4][0] 
            result[0][0] = data[2][0]
        */
        result[i][0] = data[n-2*(k-i)][0];
        result[i][1] = data[n-2*(k-i)][1];
    }
    printData(result,n);

    /****************获取读取所有程序的时间****************/
    double time = 0;
    for(int i = 0;i < n-1; i++) {  
        for(int j=i+1; j<n; j++) {
            time += result[i][0]*result[j][0]*(j-i);
        }
    }  
    /* 示例:0.547396 */
    cout<<time<<endl;

    /****************写入文件****************/
    ofstream fout("ouput.txt");
    if(fout.is_open()) {
        fout<<time<<endl;
        fout.close();
    }

    return 0;
}