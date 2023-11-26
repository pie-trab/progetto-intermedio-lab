class Date
{
public:
    Date() {}

    void add_month(int n);
};

Date& operator+(const Date& a, const Date& b);
bool operator<(const Date& a, const Date& b);
bool operator>(const Date& a, const Date& b);
