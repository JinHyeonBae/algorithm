#include <iostream>

using namespace std;
int enterCount = 0;
char quotes = 34;

void repeat(int n) {

	if (n == 0) {
		for (int i = n; i < enterCount; i++) {
			cout << "____";
		}
		
		cout << quotes <<"����Լ��� ������?" << quotes<< "\n";
		for (int i = n; i < enterCount; i++) {
			cout << "____";
		}
		cout << quotes << "����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����"<< quotes << "\n";
		for (int i = n; i < enterCount; i++) {
			cout << "____";
		}
		cout << "��� �亯�Ͽ���.\n";
	}
	else {
		for (int i = 0; i < enterCount; i++) {
			cout << "____";
		}
		cout << quotes << "����Լ��� ������?" << quotes << "\n";
		for (int i = 0; i < enterCount; i++) {
			cout << "____";
		}
		cout << quotes <<"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < enterCount; i++) {
			cout << "____";
		}
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < enterCount; i++) {
			cout << "____";
		}
		cout<<"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������." <<quotes<< '\n';
		enterCount++;
		repeat(n - 1);
		
		for (int i = n; i < enterCount; i++) {
			cout << "____";
		}
		cout << "��� �亯�Ͽ���. \n";
	}	
}

int main() {

	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������. \n";
	repeat(n);

	return 0;
}