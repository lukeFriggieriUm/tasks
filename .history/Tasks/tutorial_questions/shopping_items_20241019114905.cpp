

class item{
    public:
        virtual void display(){};
        virtual void persist(std::ofstream& out) const = 0;
}