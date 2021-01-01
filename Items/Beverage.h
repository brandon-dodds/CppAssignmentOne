#ifndef CPPASSIGNMENTONE_BEVERAGE_H
#define CPPASSIGNMENTONE_BEVERAGE_H


class Beverage : public Item {
public:
    Beverage(const std::string &name, float price, int calories, int volume, float abv);

    float abv;
    int volume;

    bool isAlcoholic();

    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_BEVERAGE_H
