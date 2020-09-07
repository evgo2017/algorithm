#### [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

运行时间过长：

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  let works = [s]
  let result = s[0]
  while (works.length > 0) {
    const work = works.shift()
    if (isPalindrome(work)[0]) {
      result = work
      break
    } else {
      const left = work.substring(0, work.length -1)
      const right = work.substring(1)
      if (hasSameChar(left)) works.push(left)
      if (hasSameChar(right)) works.push(right)
    }
  }
  function hasSameChar (s) {
    const map = new Map()
    const len = s.length 
    for(let i = len - 1; i >= 0; i--) {
      const exist = map.get(s[i])
      if (exist) {
        map.set(s[i], exist + 1)
      } else {
        map.set(s[i], 1) 
      }
    }
    const arr = [...map]
    let result = arr.some((ch, index) => {
      return ch[1] > 1
    })
    return result
  }
  function isPalindrome (s) {
    const mid = (s.length - 1 ) / 2
    for(let i = mid; i > 0; i--) {
      if (s[mid - i] !== s[mid + i]) return [false, i]
    }
    return [true, 0]
  }
  return result
};
```

