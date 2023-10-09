class OrderCounter {
public:
    static OrderCounter& getInstance() 
    {
        static OrderCounter instance;
        return instance;
    }

    int getNextOrderID() 
    {

        // Solo ordenes de 1 a 99
        if (orderID == 99)
        {
            orderID = 0;
        }

        return ++orderID;
    }

private:
    OrderCounter() : orderID(0) {}
    OrderCounter(const OrderCounter&) = delete;
    OrderCounter& operator=(const OrderCounter&) = delete;

    int orderID;
};
