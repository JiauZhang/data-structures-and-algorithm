/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

template <typename Dtype>
class HeapSort {
public:
	HeapSort() {}
	~HeapSort() {}
	
	static void sort(Dtype *data, int length);
private:
	static void heapify(Dtype *tree, int n, int i); 
	static void build_heap(Dtype *data, int length);
	static void do_sort(Dtype *data, int length);
};

template <typename Dtype>
void HeapSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	//heapify(data, length, 0);
	//build_heap(data, length);
	do_sort(data, length);
}

template <typename Dtype>
void HeapSort<Dtype>::heapify(Dtype *tree, int n, int i)
{
	if (i >= n)
		return;
	
	int max = i;
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	
	if (c1 < n && tree[max] < tree[c1])
		max = c1;
	if (c2 < n && tree[max] < tree[c2])
		max = c2;
		
	if (max != i) {
		Dtype temp = tree[i];
		tree[i] = tree[max];
		tree[max] = temp;
		
		heapify(tree, n, max);
	}
}

template <typename Dtype>
void HeapSort<Dtype>::build_heap(Dtype *data, int length)
{
	int last_node = length - 1;
	int parent = (last_node - 2) / 2;
	for (int i=parent; i>=0; i--) {
		heapify(data, length, i);
	}
}

template <typename Dtype>
void HeapSort<Dtype>::do_sort(Dtype *data, int length)
{
	build_heap(data, length);
	for (int i = length-1; i>=0; i--) {
		Dtype temp = data[i];
		data[i] = data[0];
		data[0] = temp;
		heapify(data, i, 0);
	}
}
