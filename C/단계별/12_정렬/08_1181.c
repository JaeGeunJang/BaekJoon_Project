/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000)
둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다.
주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int len;
	char str[51];
}words;

int compare(const void *a, const void *b) {
	words real_a = *(words*)a;
	words real_b = *(words*)b;
	int len_a = strlen(real_a.str);
	int len_b = strlen(real_b.str);
	if (len_a != len_b)
		return (len_a - len_b);
	return strcmp(real_a.str, real_b.str);
}

int main()
{
	words* word;
	words tmp;
	int flag = 0, real_n = 0;
	char strtmp[51] = {0};
	int n, i, j;
	scanf("%d", &n);
	word = (words*)malloc(sizeof(words) * n);
	for (i = 0;i < n;i++)
	{
		scanf("%s", strtmp);
		for (j = 0;j < i;j++) {
			if (strcmp(word[j].str, strtmp) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			strcpy(word[real_n].str, strtmp);
			word[real_n].len = strlen(strtmp);
			real_n++;
		}
		flag = 0;
	}
	qsort(word, real_n, sizeof(words), compare);
	for (i = 0;i < real_n;i++) printf("%s\n", word[i].str);
	free(word);
	return 0;
}
