//快排（由大到小）,参数：需要排序的数组，按照哪个属性的值来排序
function quickSort(arr, attr) {
	//如果数组<=1,则直接返回
    if(arr.length <= 1) {
    	return arr
    }

    let left = [], //左边的数组，比标准值大
    	right = [], //右边的数组，比标准值小
    	center = [], //中间的数组，等于标准值，有等于标准值的情况
    	standard = arr[Math.floor(arr.length/2)] //选取数组的中间位作为标准值

   for(let i = 0, len = arr.length; i < len; i++) {
		let current = arr[i], 
			cs = parseInt(current[attr]), 
			ss = parseInt(standard[attr])
		//	将分数转化为 Int 类型再比较，否则有时候会出现大小错误！！
        // 如果需要由小到大的排列，则将 current 推入的数组互换即可
    	if(cs > ss) {
    		left.push(current)
    	} else if (cs < ss) {
    		right.push(current)
    	} else {
    		center.push(current)
    	}
    }

    left = quickSort(left, attr)
    right = quickSort(right, attr)

    return left.concat(center.concat(right))
} 