#ifndef CPPASSIGNMENTONE_BEVERAGE_H
#define CPPASSIGNMENTONE_BEVERAGE_H


class Beverage : public Item {
private:
    float abv;
    int volume;
public:
    Beverage(const std::string &name, float price, int calories, int volume, float abv);
    bool isAlcoholic();
    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_BEVERAGE_H
