/*
 * @Author: evgo 
 * @Date: 2018-06-10 14:08:36 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 17:14:08
 * @Email: evgo2017@qq.com 
 * @Github: evgo2017 
 * @Blog: http://evgo2017.com
 */

/* 字符串扩展距离 */

#include <iostream>
using namespace std;

//返回字符a与b的ASCII码的差的绝对值，也就是字符距离
int dist(char a, char b) {
    return abs(a-b);     
}
int min(int x, int y, int z){
    if(x<y) {
        return x<z?x:z;
    }
    return y<z?y:z;
}
int main() {
    /**************输入字符串，K值********************/
    string s1, s2; //字符串A B
    int k;  //定值k
    //示例：cmc snmn 2
    cin>>s1>>s2>>k;
    
    /*******此处在字符串开头添加一个空格，便于遍历********/
    s1 = " " + s1;    
    s2 = " " + s2;    
    
    int len1 = s1.length(), //4
        len2 = s2.length(), //5
        val[len1][len2] = {0}; //存储各个数据的数组
        
    /********************数组赋值********************/
    /* 示例：
    0  2  4  6  8
    2 16 11 10 11
    4  6  1  0  1
    6 16 11 10 11
    */
    //设置第一行，val[0][0] 之前已经定义为0了，没必要重新赋值
    for(int i=1; i<len1; i++) {
        val[i][0] = k * i;
    }
    //设置第一列，同理
    for (int j=1; j<len2; j++) {
        val[0][j] = k * j;
    }
    //设置内部值，各个字符距离
    for(int i=1; i<len1; i++) {
        for (int j=1; j<len2; j++) {
            val[i][j] = dist(s1[i], s2[j]);
        }
    }
    
    /*****************数组遍历，更新数据*******************/
    /* 示例：
    0 2 4 6 8
    2 4 6 8 10
    4 6 5 6 8
    6 8 7 8 10
    */
    for (int i = 1; i <= len1; i ++) { //3
        for (int j = 1; j <= len2; j ++) { //4
            val[i][j] = min(val[i-1][j]+k, val[i][j-1]+k, val[i-1][j-1]+dist(s1[i],s2[j]));
        }
    } 

    /********************输出结果********************/
    // 示例：10
    cout<<val[len1-1][len2-1];

    // //打印数组
    // for(int i = 0; i < len1; i++) {
    //     for (int j = 0; j < len2; j++) {
    //         cout<<val[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}