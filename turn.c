Enter file contents here
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void reverse_str(char *left,char *right)
{
	assert(left != NULL);
	assert(right != NULL);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void turn_left(char *arr1,int n)
{
	reverse_str(arr1,(arr1 + strlen(arr1)-1));
	reverse_str(arr1,(arr1 + strlen(arr1)-1-n));
	reverse_str((arr1 + strlen(arr1)-n),(arr1 + strlen(arr1)-1));
}

int check_turn(char *arr1,char *arr2)
{
	int i = 0;
	int len = strlen(arr1);
	assert(arr1 != NULL);

	if(strlen(arr1) == strlen(arr2))
	{
		for(i=1; i<=len; i++)
		{
			turn_left(arr1,1);
			if(strcmp(arr1,arr2)==0)
			{
				return 1;
			}

		}
		return 0;
	}
	else
	{
		return 0;
	}

}
int main()
{
	char arr1[] = "AABCD";
	char arr2[] = "AABCD";

	printf("%d",check_turn(arr1,arr2));	

	system("pause");
	return 0;
}
