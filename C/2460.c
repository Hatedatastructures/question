#include <stdio.h>
#include <stdlib.h>

void inbuilt_swap(int *num_a, int *num_b)
{
    int exchange_object = *num_a;
    *num_a = *num_b;
    *num_b = exchange_object;
}
int *applyOperations(int *nums, int numsSize, int *returnSize)
{
    if (nums == NULL)
    {
        return NULL;
    }
    for (int traverse_size = 0; traverse_size < numsSize; traverse_size++)
    {
        if (traverse_size + 1 > numsSize - 1)
        {
            break;
        }
        if (nums[traverse_size] == nums[traverse_size + 1])
        {
            nums[traverse_size] = nums[traverse_size] * 2;
            nums[traverse_size + 1] = 0;
        }
    }
    for (int tweaks_size = 0; tweaks_size < numsSize; tweaks_size++)
    {
        if (nums[tweaks_size] == 0)
        {
            for (int get_size = tweaks_size; get_size < numsSize; get_size++)
            {
                if (nums[get_size] != 0)
                {
                    inbuilt_swap(&nums[tweaks_size], &nums[get_size]);
                    break;
                }
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}

int main()
{
    int test[] = {847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272};
    int test_size = sizeof(test) / sizeof(test[0]);
    int return_size = 0;
    int *ret = applyOperations(test, test_size, &return_size);
    for (int i = 0; i < return_size; i++)
    {
        printf("%d ", ret[i]);
    }
    return 0;
}