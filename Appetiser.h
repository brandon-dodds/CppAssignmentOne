#ifndef CPPASSIGNMENTONE_APPETISER_H
#define CPPASSIGNMENTONE_APPETISER_H


class Appetiser : public Item {
public:
    std::string shareable;
    std::string twoForOne;
    std::string toString() override;
};


#endif //CPPASSIGNMENTONE_APPETISER_H
