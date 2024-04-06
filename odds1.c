#include <stdio.h>
#include <stdlib.h>
int count_of_odds(int *arr, int len)
{
int count = 0;
for(int i=0; i<len;i++){
    if(arr[i]%2 != 0){
        count++;
    }
}

return count;

}
int main()
{
int line_num = 1;

while(line_num < 3 || line_num <=10){
puts("Enter the values of the array:");
int len;
scanf("%d", &len);
int nums[len];
for(int i=0; i<len;i++){
    scanf("%d", &nums[i]);
}
int count = count_of_odds(nums, len);
printf("%d\n", count);
line_num++;
}
}