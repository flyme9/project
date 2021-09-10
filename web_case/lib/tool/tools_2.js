/**
 * 获取随机数
 * @param {Number} start 
 * @param {Number} end 
 * @returns Number
 */
function randomNum(start, end) {
	var max = Math.max(start, end);
	var min = Math.min(start, end);
	return Math.floor(Math.random() * (max - min + 1) + min);
}

/**
 * 获取随机颜色
 * @param {Boolean} type 
 * @returns String
 */
function randomColor(type) {
	if (!type) {
		var colorRGB = `rgb(${randomNum(0, 255)},${randomNum(0, 255)},${randomNum(0, 255)})`
		return colorRGB;
	}
	var str = '#'
	for (var j = 0; j < 3; j++) {
		var color = randomNum(0, 255).toString(16);
		if (color.length === 1) {
			color = '0' + color;
		}
		str += color;
	}
	return str;
}

/**
 * 解析查询字符串
 * @param {String} str 
 * @returns Object
 */
function parseQueryString(str) {
	var obj = {}
	if (str) {
		//将获取到的多个字符串进行分离
		var tmp = str.slice(1).split('&');
		tmp.forEach(function(item) {
			//将每个key 和 value进行分离
			var temp = item.split('=');
			//分离后存入对象中
			obj[temp[0]] = temp[1];
		})
	}
	return obj;
}

/**
 * 计算时间差值
 * @param {Date} time1 
 * @param {Date} time2 
 * @returns Object
 */
function getTimeDifference(time1, time2) {
	var remainTime = Math.round(Math.abs(time1.getTime() - time2.getTime())) / 1000;
	var day = parseInt(remainTime / (60 * 60 * 24));
	var hours = parseInt(remainTime % (60 * 60 * 24) / (60 * 60));
	var min = parseInt(remainTime % (60 * 60) / 60);
	var sec = parseInt(remainTime % 60);
	return {
		day: day,
		hours: hours,
		min: min,
		sec: sec
	}
}

/**
 * 倒计时输出到页面
 */
function countDown() {
	var cur = new Date();
	var diff = getTimeDifference(cur, target);
	if (diff.day < 10) diff.day = '0' + diff.day
	if (diff.hours < 10) diff.hours = '0' + diff.hours
	if (diff.min < 10) diff.min = '0' + diff.min
	if (diff.sec < 10) diff.sec = '0' + diff.sec
	daybox.innerText = diff.day;
	hoursbox.innerText = diff.hours;
	minbox.innerText = diff.min;
	secbox.innerText = diff.sec;
}

/**
 * 获取元素样式兼容写法
 * @param { ELEMENT } ele 
 * @param { String } style 
 * @returns { String }
 */
function getStyle(ele, style) {
	if ('getComputedStyle' in window) {
		//标准浏览器
		return window.getComputedStyle(ele)[style]
	} else {
		//IE低版本
		return ele.currentStyle[style]
	}
}

/**
 * 浏览器事件绑定兼容处理
 * @param {Element} ele 事件源
 * @param {String} type 事件类型
 * @param {Function} handler 事件执行函数
 */
function on(ele, type, handler) {
	//检查ele参数合理性
	if (!ele || ele.nodeType !== 1) throw new Error('ele事件源传递不正确');
	//事件绑定兼容处理
	if (ele.addEventListener) {
		//标准浏览器
		ele.addEventListener(type, handler)
	} else if (ele.attachEvent) {
		//IE低版本
		ele.attachEvent('on' + type, handler)
	} else {
		//原始浏览器
		ele['on' + type] = handler
	}
}

/**
 * 浏览器事件解绑兼容处理
 * @param {Element} ele 事件源
 * @param {String} type 事件类型
 * @param {Function} handler 事件执行函数
 */
function off(ele, type, handler) {
	if (!ele || ele.nodeType !== 1) throw new Error('ele事件源传递不正确');
	if (ele.addEventListener) {
		//标准浏览器
		ele.removeEventListener(type, handler)
	} else if (ele.attachEvent) {
		//IE低版本
		ele.detachEvent('on' + type, handler)
	} else {
		//原始浏览器
		ele['on' + type] = null
	}
}

/**
 * 多样式运动函数
 * @param {Element} ele 运动的元素
 * @param {Object} target 运动的属性
 * @param {Function} [fn=()=>{}] 结束后的回调函数
 */
function move(ele, target, fn = () => {}) {
	//计数器，用于判断是否完全结束
	let count = 0;
	for (let key in target) {
		// 当为opacity 时，先进行扩大 
		if (key === 'opacity') target[key] *= 100
		//开启一个定时器+1
		count++
		let timer = setInterval(() => {
			//获取元素样式值
			let current = key === 'opacity' ? getStyle(ele, 'opacity') * 100 : parseInt(getStyle(ele, key))
			//计算每一次移动的距离
			let distance = (target[key] - current) / 10
			//样式值大于 0 时，向上取整，小于0时向下取整
			distance = distance > 0 ? Math.ceil(distance) : Math.floor(distance)
			if (current === target[key]) {
				//到达目标位置结束运动函数
				clearInterval(timer)
				//关闭一个定时器-1
				count--
				if (!count) {
					fn()
				}
			} else {
				//未到达目标样式值继续运动
				ele.style[key] = key === 'opacity' ? (current + distance) / 100 : current + distance + 'px'
			}
		}, 15)
	}
}

/**
 * 设置 cookie
 * 
 */
function setCookie(key, value, expires, path) {
	let str = key + '=' + value
	if (expires) {
		let time = new Date()
		time.setTime(time.getTime() - 1000 * 60 * 60 * 8 + expires * 1000)
		str += '; expires=' + time
	}
	if (path) {
		str += '; path=' + path
	}
	document.cookie = str
}
/**
 * 获取cookie值
 * 
 */
function getCookie(key) {
	let tmp = document.cookie.split('; ')

	let o = key ? '' : {}

	tmp.forEach(function(item) {
		let t = item.split('=')
		if (key) {
			if (t[0] === key) {
				o = t[1]
			} else {
				o[t[0]] = t[1]
			}
		}
	})
	return o
}
/**
 * 删除cookie
 */
function delCookie(key) {
	setCookie(key, ' ', -1)
}
