/*2015.12.29*/
#include <iostream>  
#include <vector>  
#include <map>  
using namespace std;
//��������  
struct node{
	int num;//�����ֵ  
	int degree;//������ȣ���ʾ��ǰλ�����״ι�ϣλ�õ�ƫ��ֵ������ͻ����  
	vector<int> next;//��̽��  
};
int main() {
	int N;
	cin >> N;
	map<int, int> map;
	int count = 0;
	vector<node> a(N);
	for (int i = 0; i<N; i++){//������0��N-1  
		cin >> a[i].num;
		if (a[i].num >= 0){
			count++;//��Ч���ĸ����������������  
			if (a[i].num%N == i){//һ�����У����Ϊ0  
				a[i].degree = 0;
				map[a[i].num] = i;//��ֵΪkey���Զ��������У�����ֱ���ҵ���Сֵ,λ��Ϊvalue  
			}
			else{
				a[i].degree = ((i + N) - a[i].num%N) % N;//���״�hash��ƫ��ֵ��������̽��Ĵ���  
				int k = a[i].degree;
				while (k){
					a[(i - k + N) % N].next.push_back(i);//�ý��push������ǰ������next����  
					k--;
				}
			}
		}
	}
	while (!map.empty()){//map�д洢�������Ϊ0�Ľ��  
		auto it = map.begin();
		cout << it->first << (--count ? " " : "");//first�ǽ����ֵ��second�ǽ�����  
		for (auto index = a[it->second].next.begin(); index != a[it->second].next.end(); index++){
			a[*index].degree--;//���к�̽ڵ���ȼ�1  
			if (a[*index].degree == 0)
				map[a[*index].num] = *index;
		}
		map.erase(it);
	}
	printf("\n");
	system("pause");
	return 0;
}
