单链表，关键点是顺序、进位。

**效率：**

内存消耗一般为 38.3MB，打败 97%。发现执行用时不太稳，感觉和网速有很大关系，一般在 130ms~140ms，打败 50%，好一些就到 108 ms，打败 97%。

**代码：**

① 头结点单独配置，不要写在循环里面。虽然会重复些代码，但是内存消耗提升了一大截（约 2.5 MB）；

② 一次和若大于 10，则减去 10 而不是取余数，内存消耗会低一些。

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let val = (l1 ? l1.val : 0) + (l2 ? l2.val : 0)
  let carry = 0
  if (val > 9) {
    val -= 10
    carry = 1
  }
  let goal = new ListNode(val)
  let handGoal = goal
  let hand1 = l1.next
  let hand2 = l2.next
  while (hand1 || hand2 || carry !== 0) {
    let val = carry + (hand1 ? hand1.val : 0) + (hand2 ? hand2.val : 0)
    if (val > 9) {
      val -= 10
      carry = 1
    } else {
      carry = 0
    }
    handGoal.next = new ListNode(val)
    handGoal = handGoal.next
    if (hand1) hand1 = hand1.next
    if (hand2) hand2 = hand2.next
  }
  return goal
};
```

查看题解时找到的方法，使用递归，代码量和内存消耗极少（38.1MB），自己做了一些修改：

[Javascript：两数对位相加，超过 10 向前进位（其实就是算术模拟）](https://leetcode-cn.com/problems/add-two-numbers/solution/javascriptliang-shu-dui-wei-xiang-jia-chao-guo-10-/)

```javascript
var addTwoNumbers = function(l1, l2, carry = 0, end = { val: 0, next: null }) {
  let val =  l1.val + l2.val + carry
  if (val > 9) {
    val -= 10
    carry = 1
  } else {
    carry = 0
  }
  return {
    val,
    next: (l1.next || l2.next || carry)
     ? addTwoNumbers(l1.next || end, l2.next || end, carry, end)
     : null
  }
};
```
