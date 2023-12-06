#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream> 
#include <vector>

//only 12 red cubes, 13 green cubes, and 14 blue cubes


bool roll_validator(std::string s);
std::vector<std::string> split(std::string s, char delim);
int get_id(std::string s);

//Game 1: 13 green, 3 red; 4 red, 9 green, 4 blue; 9 green, 10 red, 2 blue

int main(int argc, char** argv)
{
	std::fstream input;
	input.open("data.txt", std::ios::in);
    std::string line;
    int id_sum = 0;
    bool check = true;

    std::vector<std::string> colon_split, semi_game_split;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            colon_split = split(line, ':');
            semi_game_split = split(colon_split[1], ';');
           
            for (auto single_roll : semi_game_split)
            {
                if (!roll_validator(single_roll)) check = false;
            }
            if(check) id_sum += get_id(colon_split[0]);
            check = true;
        }
    }
    input.close();

    std::cout << id_sum;
}

bool roll_validator(std::string string)
{
    std::vector<std::string> dice_colors, n_dice;
    dice_colors = split(string, ',');

    for (auto i : dice_colors)
    {
        n_dice = split(i, ' ');
        if (n_dice[2].compare("green") == 0)
        {
            if (atoi(n_dice[1].c_str()) > 13) return false;
        }
        if (n_dice[2].compare("red") == 0)
        {
            if (atoi(n_dice[1].c_str()) > 12) return false;
        }
        if (n_dice[2].compare("blue") == 0)
        {
            if (atoi(n_dice[1].c_str()) > 14) return false;
        }
    }

    return true;
}

std::vector<std::string> split(std::string s, char delim)
{
    std::vector<std::string> result;
    std::string item;
    std::stringstream ss(s);

    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

int get_id(std::string s)
{
    std::vector<std::string> game_details;

    game_details = split(s, ' ');

    return atoi(game_details[1].c_str());
}
