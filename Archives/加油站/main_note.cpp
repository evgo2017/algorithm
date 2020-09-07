/*
 * @Author: evgo 
 * @Date: 2018-06-10 21:32:29 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 22:42:06
 * @Email: evgo2017@qq..com 
 * @Github: evgo2017 
 * @Blog: http://evgo2017.com
 */

/* 
一辆汽车加满油后可行驶 n 公里。
旅途中有若干个加油站。
设计一个有效算法，指出应在哪些加油站停靠加油，使沿途加油次数最少。
对于给定的 n 和 k 个加油站位置，计算最少加油次数。
*/

#include <iostream>
#include <fstream>
using namespace std;

//采用贪心算法
int main(){
    /****************读取文件****************/
    ifstream fin("input.txt");

    /****************读取行数，新建数组存储************/
    int n,k; 
    /*示例， n = 5, k =3 */
    fin>>n; //加满油后可行驶 n 公里
    fin>>k; //旅途中有 k 个加油站
    
    /****************读取数据,存入数组***************/
    /*示例， data[3+1] = data[4] = {2,5,4,2} */
    int data[k+1] = {0}; //第 k 个加油站与第 k-1 个加油站之间的距离
    /*  第 0 个加油站表示出发地，汽车已加满油。第 k+1 个加油站表示目的地。 */

    for(int i=0; i<k+1; i++) {
        fin>>data[i];
        if(data[i]>n) {
            cout<<"No Solution!"<<endl; //如果某一站路之间的距离比加满油还远，自然无法到达
            return 0;
        }
    }
    
    //因为只要大于 n 值就直接返回了，所以以下过程中，data[]内的都小于或等于n值。
    int num = 0; //加油次数
    for(int i=0; i<k+1; i++) {
        if(n>data[i]) {  //如果油量比此段距离大，就直接减去
            n -= data[i];
        } else { //如果油量不比此段距离大，则加满油，再减去此段距离，加油次数+1
            n = 5 - data[i];
            num++;
        }
    }

    cout<<num<<endl;
    return 0;
}