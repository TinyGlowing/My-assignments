#include<iostream>
using namespace std;
class node {
private:
	int k;
	int exp;
	node* next;
public:
	node(int a=0,int b=0):k(a),exp(b),next(nullptr){}
	friend class Linklist;
};

class Linklist {
private:
	node* head;
	void insert(int k, int exp) {               //插入新的项
		if (k == 0) return;
		node* newnode = new node(k, exp);
		node* cur = head;
		node* pre = nullptr;
		while (cur!=nullptr && cur->exp > exp) {   //遍历到对应项
			pre = cur;
			cur = cur->next;
		}
		if (cur!=nullptr && cur->exp == exp) {    //合并同类项，为零时删除
			cur->k += k;
			delete newnode;
			if (cur->k == 0) {
				if (pre == nullptr)
					head = cur->next;        //如果是第一项，删除后头指针指向第二项
				else
					pre->next = cur->next;
				delete cur;
			}
			return;                        //合并后结束函数，避免再插入
		}
		if (pre == nullptr)
			head = newnode;
		else
			pre->next = newnode;
		newnode->next = cur;
	}
public:
	Linklist():head(nullptr){}
	~Linklist() {
		node* cur = head;
		while (cur != nullptr) {
			node* temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = NULL;
	}
	void input() {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k, e;
			cin >> k >> e;
			insert(k, e);
		}
	}
	Linklist add(const Linklist& p) {
		Linklist result;
		node* cur = head;
		while (cur != nullptr) {
			result.insert(cur->k, cur->exp);
			cur = cur->next;
		}
		cur = p.head;
		while (cur != nullptr) {
			result.insert(cur->k, cur->exp);
			cur = cur->next;
		}
		return result;
	}
	void print() {
		if (head == nullptr){
			cout << "0 0 0" << endl;
			return;
	    }
		int count = 0;
		node* cur = head;
		while (cur != nullptr) {
			count++;
			cur = cur->next;
		}
		cout << count<<" ";
		cur = head;
		while (cur != nullptr) {
			cout << cur->k << " " << cur->exp << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main() {
	Linklist a, b;
	a.input();
	b.input();
	Linklist sum = a.add(b);
	sum.print();
	return 0;
}