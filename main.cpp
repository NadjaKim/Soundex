#include <iostream>
#include <string>

std::string change_massive(size_t size, std::string data) {
	for (size_t j = 0; j < size; j++) {
		for (size_t i = 1; i < static_cast<size_t>(size - 1); i++) {
			if (data[i] == '*' && data[i + 1] != '*') {
				char temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
	}
	while (data[size - 1] == '*') {
		data.pop_back();
		size--;
	}
	return data;
}

std::string put_zero(size_t size, std::string data) {
	for (size_t i = size; i < 4; i++) {
		data.push_back('0');
	}
	return data;
}

std::string cut_massive(size_t size, std::string data) {
	while (size > 4) {
		data.pop_back();
		size--;
	}
	return data;
}

int main() {
	std::string data;
	std::getline(std::cin, data);
	size_t i = 1, size = data.size();
	while (i < size) {
		int symbol = static_cast<int>(data[i]); //a, e, h, i, o, u, w, y
		if (symbol == 'a' || symbol == 'e' || symbol == 'h' || symbol == 'i')
			data[i] = '*';
		else if (symbol == 'o' || symbol == 'u' || symbol == 'w' || symbol == 'y')
			data[i] = '*';
		else if (symbol == 'b' || symbol == 'f' || symbol == 'p' || symbol == 'v')
			data[i] = '1';
		else if (symbol == 'c' || symbol == 'g' || symbol == 'j' || symbol == 'k') //c, g, j, k, q, s, x, z
			data[i] = '2';
		else if (symbol == 'q' || symbol == 's' || symbol == 'x' || symbol == 'z')
			data[i] = '2';
		else if (symbol == 'd' || symbol == 't') //d, t
			data[i] = '3';
		else if (symbol == 'l')
			data[i] = '4';
		else if (symbol == 'm' || symbol == 'n') // m n
			data[i] = '5';
		else if (symbol == 'r')
			data[i] = '6';
		i++;
	}
	data = change_massive(size, data);
	size = data.size();
	size_t counter = 1;
	for (i = 1; i < size; i++) {
		if (data[i] == data[i - 1])
			counter++;
		if (data[i] != data[i - 1] && counter > 1) {
			size_t k = i - 1;
			while (counter > 1) {
				data[k] = '*';
				k--;
				counter--;
			}
		}
		if ((i == size - 1) && (counter > 1)) {
			size_t k = i - 1;
			while (counter > 1) {
				data[k] = '*';
				k--;
				counter--;
			}
		}
	}
	data = change_massive(size, data);
	size = data.size();
	if (size < 4)
		data = put_zero(size, data);
	else if (size > 4)
		data = cut_massive(size, data);
	std::cout << data;
	return 0;
}