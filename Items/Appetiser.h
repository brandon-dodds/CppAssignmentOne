#ifndef CPPASSIGNMENTONE_APPETISER_H
#define CPPASSIGNMENTONE_APPETISER_H


class Appetiser : public Item {
public:
    Appetiser(std::string name, float price, int calories, std::string shareable, std::string twoForOne);

    std::string shareable;
    std::string twoForOne;
    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_APPETISER_H
