//
//
// Login and sign-up System (using files)
//
//


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define	FILE_NAME "Sign-up and login.txt"
#define	FILE_SIZE 200

bool first_page();
std::string second_page(std::istream& infile, std::ostream& outfile, std::string data_file[], int& count);
std::string third_page(std::string data_file[], int count);

void sign_up(std::string& username, std::string& password);
bool login(std::string data_file[], int count);
bool input_checker(std::string user_answer);
void input_saved_data(std::istream& stream, std::string data_file[], int& count);
void output_New_data(std::ostream& output_stream, std::string data_file[],
	std::string username, std::string password, int &count);
void data_back_text(std::ostream& output_stream, std::string data_file[], int& count);
void print(std::string string);

int main()
{
	std::string user_answer;
	std::string exit_answer = "N";
	std::string username;
	std::string password;
	std::string data_file[FILE_SIZE];
	int count = 0;

	std::ifstream infile;
	std::ofstream outfile;

	infile.open(FILE_NAME);
	input_saved_data(infile, data_file, count);
	outfile.open(FILE_NAME);
	data_back_text(outfile, data_file, count);

	do
	{
		if (first_page())
		{
			exit_answer = second_page(infile, outfile, data_file, count);
		}
		else
		{
			exit_answer = third_page(data_file, count);
		}

	} while (!input_checker(exit_answer));
}

bool first_page()
{
	std::string user_answer;

	print(" ****************************************** ");
	print(" Welcome to the Login and sign - up System ");
	print(" ****************************************** ");

	print("Is this your first time using 'login and sign-up program': Y/N: ");
	std::cin >> user_answer;

	return input_checker(user_answer);
}

std::string second_page(std::istream& infile, std::ostream& outfile, std::string data_file[], int &count)
{
	std::string username;
	std::string password;
	std::string exit_answer;
	std::string user_answer;

	print("Do you want to sign-up for this system: Y/N: ");
	std::cin >> user_answer;

	if (input_checker(user_answer))
	{
		sign_up(username, password);
		output_New_data(outfile, data_file,
			username, password, count);
		print("You are signed-up!");
		print("Do you want to login: Y/N: ");
		std::cin >> exit_answer;

		if (input_checker(exit_answer))
		{
			if (login(data_file, count))
			{
				print("you are loged in to your account! ");
				print("Looks like this is the end!");
			}
			else
			{
				print("Sorry your password 'or' username was wrong!");
			}
		}
	}
	print("Do you want to exit the program: Y/N: ");
	std::cin >> exit_answer;

	return exit_answer;
}

std::string third_page(std::string data_file[], int count)
{
	std::string username;
	std::string password;
	std::string user_answer;

	print("Do you want to login: Y/N: ");
	std::cin >> user_answer;

	if (input_checker(user_answer))
	{
		if (login(data_file, count))
		{
			print("you are loged in to your account! ");
			print("Looks like this is the end!");
		}
		else
		{
			print("Sorry your password 'or' username was wrong!");
		}
	}
	print("Do you want to exit the program: Y/N: ");
	std::cin >> user_answer;

	return user_answer;
}


void print(std::string string)
{
	std::cout << string << std::endl;
}

void sign_up(std::string& username, std::string& password)
{
	print("Please Type a Username: ");
	std::cin >> username;
	print("Please Type a password: ");
	std::cin >> password;
}

bool login(std::string data_file[], int count)
{
	std::string username;
	std::string password;
	std::string username_and_password;
	print("Please Type your Username: ");
	std::cin >> username;
	print("Please Type your password: ");
	std::cin >> password;

	for (int i = 0; i < count; i++)
	{
		username_and_password = data_file[i];
		if (username + " " + password == username_and_password)
		{
			return true;
		}
	}
	return false;
}

bool input_checker(std::string user_answer)
{
	do
	{
		if ((user_answer == "Y") || (user_answer == "y"))
		{
			return true;
		}
		else if ((user_answer == "N") || (user_answer == "n"))
		{
			return false;
		}
		else
		{
			print("please Type 'Y' for Yes, 'N' for NO: ");
			std::cin >> user_answer;
		}
	} while ((user_answer == "Y") || (user_answer == "N"));
}
void input_saved_data(std::istream& stream, std::string data_file[], int &count)
{
	std::string save_username;
	std::string save_password;
	std::string saved_data;

	int i = 0;
	while (!stream.eof()){

		stream >> save_username >> save_password;
		saved_data = save_username + " " + save_password;
		data_file[i] = saved_data;
		count++;
		i++;
	}
}
void output_New_data(std::ostream& output_stream, std::string data_file[],
	std::string username, std::string password, int &count)
{
	data_file[count] = username + " " + password;
	count++;
	output_stream << username << " " << password << std::endl;
}
void data_back_text(std::ostream& output_stream, std::string data_file[], int& count)
{
	for(int i = 0; i < count-1; i++)
		output_stream << data_file[i] << std::endl;
}