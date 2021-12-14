#include <iostream>   // std::cout

int main() {

	int p, budget, hotel_count, able_week; //������, ����, ȣ�� ��, ������ ��
	int hotel_price[19], personnel;
	bool target_hotel[19] = {0,}; // ������ ���ǿ� �����ϴ� ȣ��

	
	std::cin >> p >> budget >> hotel_count >> able_week;
	std::cout << "ht_c :" << hotel_count << '\n';

	for (int i = 1; i <= hotel_count; i++) {
		std::cin >> hotel_price[i];
		for (int j = 1; j <= able_week; j++) {

			std::cin >> personnel;

			if (personnel >= p)
				target_hotel[i] = true;

		}
	}

	//������ ���ϱ�
	int min_hotel_price = 1000000;
	for (int i = 1; i <= hotel_count; i++) {
		
		//����� �´� ���
		if (target_hotel[i]) {
			int ht_price = hotel_price[i] * p;
			//������ ���ϱ�
			if (ht_price < min_hotel_price)
				min_hotel_price = ht_price;
		}
	}

	if (min_hotel_price <= budget)
		std::cout << min_hotel_price;
	else
		std::cout << "stay home";


}