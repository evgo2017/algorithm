/*
 * @Author: evgo 
 * @Date: 2018-06-10 14:08:36 
 * @Last Modified by: evgo
 * @Last Modified time: 2018-06-10 17:14:08
 * @Email: evgo2017@qq.com 
 * @Github: evgo2017 
 * @Blog: http://evgo2017.com
 */
#include <iostream>
using namespace std;

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
    string s1, s2;
    int k;
    cin>>s1>>s2>>k;
    s1 = " " + s1;    
    s2 = " " + s2;    
    
    int len1 = s1.length(),
        len2 = s2.length(，
        val[len1][len2] = {0};

    for(int i=1; i<len1; i++) {
        val[i][0] = k * i;
    }
    for (int j=1; j<len2; j++) {
        val[0][j] = k * j;
    }
    for(int i=1; i<len1; i++) {
        for (int j=1; j<len2; j++) {
            val[i][j] = dist(s1[i], s2[j]);
        }
    }

    for (int i = 1; i <= len1; i ++) {
        for (int j = 1; j <= len2; j ++) {
            val[i][j] = min(val[i-1][j]+k, val[i][j-1]+k, val[i-1][j-1]+dist(s1[i],s2[j]));
        }
    } 

    cout<<val[len1-1][len2-1];
    return 0;
}