#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream> 
#include <vector>

//only 12 red cubes, 13 green cubes, and 14 blue cubes


int dice_counter(std::string s);
std::vector<std::string> split(std::string s, char delim);
int get_id(std::string s);

//Game 1: 13 green, 3 red; 4 red, 9 green, 4 blue; 9 green, 10 red, 2 blue

int main(int argc, char** argv)
{
    std::fstream input;
    input.open("data.txt", std::ios::in);
    std::string line;
    int power_sum = 0;


    std::vector<std::string> colon_split, semi_game_split;

    if (input.is_open()) {
        while (std::getline(input, line)) {
            colon_split = split(line, ':');
            power_sum += dice_counter(colon_split[1]);

        }
    }
    input.close();

    std::cout << power_sum;
}

int dice_counter(std::string string)
{
    std::vector<std::string> dice_colors, n_dice;
    std::vector<std::string> semi_game_split;
    
    int green = 0;
    int red = 0;
    int blue = 0;

    semi_game_split = split(string, ';');

    for (auto single_roll : semi_game_split)
    {
        dice_colors = split(single_roll, ',');

        for (auto i : dice_colors)
        {
            n_dice = split(i, ' ');
            if (n_dice[2].compare("green") == 0)
            {
                if (atoi(n_dice[1].c_str()) > green) green = atoi(n_dice[1].c_str());

            }
            if (n_dice[2].compare("red") == 0)
            {
                if (atoi(n_dice[1].c_str()) > red) red = atoi(n_dice[1].c_str());
            }
            if (n_dice[2].compare("blue") == 0)
            {
                if (atoi(n_dice[1].c_str()) > blue) blue = atoi(n_dice[1].c_str());
            }
        }

    }

    return green*red*blue;
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
