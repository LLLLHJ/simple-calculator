#include "calc.h"
void Conversion_expression(char* str_input, char* str_output) {
	SqStack operator;
	operator.top = -1;
	int n = 0;
	int i = 0;
	char e;
	int flag = 0;
	int _minus_flag = 1;//_minus_flag = 0表示-为负号， = 1 表示- 为减号
	char now_char;
	char pre_char;
	while (str_input[i] != '\0' && str_input[i] != '\n') {
		if (str_input[i] == ' ') continue;


		//遇到‘-’判断为负号还是减号
		now_char = str_input[i];
		if (now_char == '-')
		{
			if (n == 0) _minus_flag = 0;
			else if (pre_char == '(' || pre_char == '+' || pre_char == '-' ||
				pre_char == '*' || pre_char == '/'
				|| pre_char == '^' || pre_char == '@') {
				_minus_flag = 0;
			}
			else {
				_minus_flag = 1;
			}
		}



		if ((str_input[i] >= '0' && str_input[i] <= '9') || str_input[i] == '.' ||
			(str_input[i] == '-' && _minus_flag == 0)) {
			str_output[n] = str_input[i];
			pre_char = str_input[i];
			i++;
			n++;
			flag = 1;
		}
		else if (str_input[i] == '(' || str_input[i] == ')' || str_input[i] == '+'
			|| (str_input[i] == '-' && _minus_flag == 1) || str_input[i] == '*' || str_input[i] == '/'
			|| str_input[i] == '^' || str_input[i] == '@') {
			//每个数字后面添加空格进行分割
			if (flag == 1) {
				str_output[n] = ' ';
				n++;
				flag = 0;
			}
			//对运算符进行判断和输出
			if (operator.top == -1) {
				Push_char(&operator, str_input[i]);
				pre_char = str_input[i];
				i++;
			}
			else if (str_input[i] == '(') {
				Push_char(&operator, str_input[i]);
				pre_char = str_input[i];
				i++;
			}
			else if (str_input[i] == ')') {

				while (1) {
					Pop_char(&operator,&e);
					if (e == '(') break;
					str_output[n] = e;
					n++;
					str_output[n] = ' ';
					n++;

				}
				pre_char = str_input[i];
				i++;
			}
			else {
				if (str_input[i] == '@') {
					Push_char(&operator, str_input[i]);
					pre_char = str_input[i];
					i++;
				}
				else if (str_input[i] == '^') {
					while (1) {
						if (operator.data[operator.top] == '@') {
							Pop_char(&operator, &e);
							str_output[n] = e;
							n++;
							str_output[n] = ' ';
							n++;
						}
						else {
							Push_char(&operator, str_input[i]);
							break;
						}
					}
					pre_char = str_input[i];
					i++;
				}
				else if (str_input[i] == '*' || str_input[i] == '/') {
					while (1) {
						if (operator.data[operator.top] == '^' || operator.data[operator.top] == '@') {
							Pop_char(&operator, &e);
							str_output[n] = e;
							n++;
							str_output[n] = ' ';
							n++;
						}
						else {
							Push_char(&operator, str_input[i]);
							break;
						}
					}
					pre_char = str_input[i];
					i++;
				}
				else if (str_input[i] == '-' || str_input[i] == '+') {
					while (1) {
						if (operator.data[operator.top] == '^' || operator.data[operator.top] == '@'
							|| operator.data[operator.top] == '*' || operator.data[operator.top] == '/'
							|| operator.data[operator.top] == '-' || operator.data[operator.top] == '+') {
							Pop_char(&operator, &e);
							str_output[n] = e;
							n++;
							str_output[n] = ' ';
							n++;
						}
						else {
							Push_char(&operator, str_input[i]);
							break;
						}

					}
					pre_char = str_input[i];
					i++;
				}
			}

		}

	}

	while (operator.top != -1) {
		if (flag == 1) {
			str_output[n] = ' ';
			n++;
			flag = 0;
		}
		Pop_char(&operator,&e);
		str_output[n] = e;
		n++;
		str_output[n] = ' ';
		n++;
	}
	return;
}
double calc_expression(char* str_output) {
	doubleSqStack number;
	double ans;
	int count;
	int j = 0;
	number.top = -1;
	while (str_output[j] != '\0') {
		if (str_output[j] == ' ') {
			j++;
			continue;
		}
		if ((str_output[j] >= '0' && str_output[j] <= '9') ||
			(str_output[j] == '-' && str_output[j + 1] >= '0' && str_output[j + 1] <= '9')) {
			sscanf(str_output + j, "%lf%n", &ans, &count);
			Push_double(&number, ans);
			j += count;
		}
		else if (str_output[j] == '+') {
			double num1, num2;
			Pop_double(&number, &num1);
			Pop_double(&number, &num2);
			Push_double(&number, add(num2, num1));
			j++;
		}
		else if (str_output[j] == '-' && str_output[j + 1] == ' ') {
			double num1, num2;
			Pop_double(&number, &num1);
			Pop_double(&number, &num2);
			Push_double(&number, minus(num2, num1));
			j++;
		}
		else if (str_output[j] == '*') {
			double num1, num2;
			Pop_double(&number, &num1);
			Pop_double(&number, &num2);
			Push_double(&number, multiply(num2, num1));
			j++;
		}
		else if (str_output[j] == '/') {
			double num1, num2;
			Pop_double(&number, &num1);
			Pop_double(&number, &num2);
			Push_double(&number, divide(num2, num1));
			j++;
		}
		else if (str_output[j] == '^') {
			double num1, num2;
			Pop_double(&number, &num1);
			Pop_double(&number, &num2);
			Push_double(&number, Pow(num2, (int)num1));
			j++;
		}
		else if (str_output[j] == '@') {
			double num1;
			Pop_double(&number, &num1);
			Push_double(&number, sqrt(num1));
			j++;
		}
	}
	Pop_double(&number, &ans);
	return ans;
}
