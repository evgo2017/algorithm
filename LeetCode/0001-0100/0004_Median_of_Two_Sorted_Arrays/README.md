#### [4. 寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

> 注意！是有序数组

解法一：最简单的思路，但时间复杂度未达要求，也有其他思路但有些繁琐就不贴了

```javascript
var findMedianSortedArrays = function(nums1, nums2) {
  let nums = [...nums1, ...nums2].sort((a, b) => a - b)
  const len = nums.length
  return len % 2 === 0
    ? (nums[len/2] + nums[len/2 - 1])/2
    : nums[(len - 1)/2]
}
```

解法二：待补充。

[二分查找定位短数组的“边界线”](<https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/he-bing-yi-hou-zhao-gui-bing-guo-cheng-zhong-zhao-/> )

```

```

