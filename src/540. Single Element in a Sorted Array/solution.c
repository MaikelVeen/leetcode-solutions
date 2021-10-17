int singleNonDuplicate(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        printf("m: %d l:%d r:%d \n", middle, left, right);

        if (middle % 2 == 1)
            middle--;

        if (nums[middle] == nums[middle + 1])
        {
            left = middle + 2;
        }
        else
        {
            right = middle;
        }
    }

    return nums[left];
}

int main()
{
    int nums[] = {1, 1, 2, 2, 4, 4, 5, 5, 9};

    printf("%d", singleNonDuplicate(nums, 9));
}