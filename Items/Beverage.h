#ifndef CPPASSIGNMENTONE_BEVERAGE_H
#define CPPASSIGNMENTONE_BEVERAGE_H


class Beverage : public Item {
public:
    float abv;
    float volume;
    bool isAlcoholic();
    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_BEVERAGE_H
