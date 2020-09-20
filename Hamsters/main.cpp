#include <vector>
#include <algorithm>
#include <functional>

enum color {
    BLACK = 10,
    GREY = 5,
    WHITE = 8,
    BROWN = 4
};
std::vector<color> ALL_COLORS = {color::BROWN, color::GREY, color::WHITE, color::BLACK};

enum fur_type {
    GOOD = 10,
    BAD = 1,
    MID = 5,
    VERY_GOOD = 15
};
std::vector<fur_type> ALL_FURS = {fur_type::BAD, fur_type::MID, fur_type::GOOD, fur_type::VERY_GOOD};


class Hamster {
    int age;
    int max_age = 36;
    int height;
    int max_height = 15;
    int weight;
    int max_weight = 50;
    double rating = 0;
    color clr;
    color best_color = BLACK;
    fur_type fur;
    fur_type best_fur = VERY_GOOD;
public:
    Hamster(int a, int h, int w, color c, fur_type f) {
        this->age = a;
        this->height = h;
        this->weight = w;
        this->clr = c;
        this->fur = f;
        this->rating = get_rating();
    }
    Hamster() {
        this->age = rand() % max_age + 1;
        this->height = rand() % (max_height - 2) + 1;
        this->weight = rand() % (max_weight - 5) + 1;
        this->clr = ALL_COLORS[rand() % ALL_COLORS.size()];
        this->fur = ALL_FURS[rand() % ALL_FURS.size()];
        this->rating = get_rating();
    }
private:
    double get_rating() {
        double age_rating = double(max_age + 1 - age) / max_age;
        double height_rating = double(height) / max_height;
        double weight_rating = double(weight) / max_weight;
        double color_rating = double(clr) / best_color;
        double fur_rating = double(fur) / best_fur;
        return age_rating * height_rating * weight_rating * color_rating * fur_rating;
    }

    friend bool operator>(const Hamster& a, const Hamster& b) {
        return a.rating > b.rating;
    }

};

int main() {
    std::vector<Hamster> hamsters(100);
    sort(hamsters.begin(), hamsters.end(), std::greater<Hamster>());
    return 0;
}
