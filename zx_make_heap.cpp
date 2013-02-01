/*
 * zx的建堆算法+测试程序
 *
 * 效率应该比传统算法要低一些，不过测试程序证明算法是没错的。
 *
 * author Zx
 * version 1.0
 */

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;

//使__first到__last区间内的值成为一个堆
template<typename _RandomAccessIterator>
void zx_make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last) {

	if (__last - __first < 2)
		return;

	queue<_RandomAccessIterator> __q; //当前迭代进行上浮操作的节点队列
	set<_RandomAccessIterator> __s; //下一次迭代需要操作的节点集合

	//初始化第一次迭代操作的节点队列
	//为从__last开始往前的所有叶子节点（没有左子节点的节点）
	for (_RandomAccessIterator __iter = __last - 1; (__iter - __first) * 2 + 1
			+ __first >= __last; __iter--) {
		__q.push(__iter);
	}

	//开始迭代
	//每次迭代实际操作的是当前节点的父节点
	while (!__q.empty()) {

		while (!__q.empty()) {
			//当前进行上浮操作的节点
			_RandomAccessIterator __iter = __q.front();
			__q.pop();
			//当前节点的父节点
			_RandomAccessIterator __parent = ((__iter - __first) - 1) / 2
					+ __first;

			//父节点成为下一次需要操作的节点
			if (__parent != __iter)
				__s.insert(__parent);

			if (*__parent > *__iter) {
				_RandomAccessIterator __left, __right;
				//按照我试卷上的写法，这里还有以下两步：
				//上浮，子节点与父节点的值交换
				//swap(*__iter, *__parent);
				//__parent = __iter;
				//但可以去掉

				//父节点的值交换后下沉
				while (true) {
					__left = (__parent - __first) * 2 + 1 + __first;
					__right = (__parent - __first) * 2 + 2 + __first;
					if (__left >= __last)
						break;
					if (__right < __last && *__right < *__left && *__parent
							> *__right) {
						swap(*__parent, *__right);
						__parent = __right;
					} else {
						if (*__parent > *__left) {
							swap(*__parent, *__left);
							__parent = __left;
						} else {
							break;
						}
					}
				}
			}
		}

		//准备下一次迭代操作的节点队列
		while (!__s.empty()) {
			_RandomAccessIterator __iter = *__s.begin();
			__q.push(__iter);
			__s.erase(__s.begin());
		}

	}

}

//以下是测试程序
int main() {
	srand((unsigned int) time(NULL));
	vector<int> a;
	const int LENGTH = 1000000;

	//插入1000000个数
	for (int i = 0; i < LENGTH; i++)
		a.push_back(rand());

	//用本人的算法使该vector内容成为一个堆
	zx_make_heap(a.begin(), a.end());

	//验证是否所有父节点都比子节点小
	for (int i = 0; i < LENGTH; i++) {
		int left = (i << 1) + 1;
		if (left >= LENGTH)
			break;
		assert(a[i]<=a[left]);
		int right = left + 1;
		if (right >= LENGTH)
			break;
		assert(a[i]<=a[right]);
	}

	//如果编译器支持c++0x，可以使用c++0x中STL的标准方法测试是否为堆
	//对于G++ 4.3以上版本 使用-std=c++0x参数即可。
#ifdef __GXX_EXPERIMENTAL_CXX0X__
	greater_equal<int> int_greater_equal;
	assert(is_heap(a.begin(), a.end(),int_greater_equal));
#endif

	printf("Test passed!\n");
	return 0;
}
