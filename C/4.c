#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *s1 = nums1;
    int *s2 = nums2;
    int *newnums = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    if (!newnums)
    {
        exit(-1);
    }
    int size = 0;
    int i = 0, j = 0;

    // 合并两个有序数组
    while (i < nums1Size && j < nums2Size)
    {
        if (s1[i] < s2[j])
        {
            newnums[size++] = s1[i++];
        }
        else
        {
            newnums[size++] = s2[j++];
        }
    }
    // 处理 nums1 剩余元素
    while (i < nums1Size)
    {
        newnums[size++] = s1[i++];
    }
    // 处理 nums2 剩余元素
    while (j < nums2Size)
    {
        newnums[size++] = s2[j++];
    }
    double ret;
    if (size % 2 != 0)
    {
        ret = newnums[size / 2];
    }
    else
    {
        // 因为下标是从零开始的，下标为9实际上是10个数 10/2 = 5  (10/2) -1 = 4
        //  0 1 2 3 4 5 6 7 8 9      刚好4 5 在中间
        ret = (newnums[size / 2 - 1] + newnums[size / 2]) / 2.0;
    }

    // 释放动态分配的内存
    free(newnums);

    return ret;
}