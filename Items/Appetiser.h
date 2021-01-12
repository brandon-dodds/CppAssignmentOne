#ifndef CPPASSIGNMENTONE_APPETISER_H
#define CPPASSIGNMENTONE_APPETISER_H


class Appetiser : public Item {
private:
    std::string shareable;
    std::string twoForOne;
public:
    Appetiser(std::string name, float price, int calories, std::string shareable, std::string twoForOne);
    std::string toString() override;

    std::string getTwoForOne();
};


#endif //CPPASSIGNMENTONE_APPETISER_H
