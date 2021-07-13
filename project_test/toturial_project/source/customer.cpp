#include "customer.h"

void customer::byAProduct(mystring ID)
{
    sqlhandle data;
    row dataslect;
    int quantity;
    data.selectbyID("supermaket", "GOODSTB1st", ID, &dataslect);
    if (dataslect.quantity == 0 || dataslect.ID == "")
    {
        cout << "Sorry, this product is not available now" << endl;
    }
    else
    {
        this->beBought[this->numberofboughtProduct].ID = dataslect.ID;
        this->beBought[this->numberofboughtProduct].name = dataslect.name;
        cout << "input quantity want to buy" << endl;
        cin >> quantity;
        if (quantity > dataslect.quantity)
        {
            cout << "the quantity is too high, reduce it please" << endl;
        }
        else
        {
            this->beBought[this->numberofboughtProduct].quantity = quantity;
            this->beBought[this->numberofboughtProduct].price = dataslect.price;
            this->numberofboughtProduct += 1;
        }
    }
}
personinfor customer::getCustomerInfor(mystring ID)
{
    this->selectbyID("person","person",ID,&this->customerInfor);
    return this->customerInfor;
}
void customer::showCustomerInfor() const
{
    cout << "ID:\t\t"<<this->customerInfor.ID<<endl;
    cout << "Name:\t\t"<<this->customerInfor.fistname<<endl;
    cout << "Lase name:\t"<<this->customerInfor.lastname<<endl;
    cout << "Address:\t"<<this->customerInfor.address<<endl;
    cout << "Phone num:\t"<<this->customerInfor.cellNumber<<endl;
}
void customer::priceofAproduct(selectProduct &proname)
{
    double ret;
    int promo=proname.promote;
    int price =proname.price;
    int quantity=proname.quantity;
    proname.money=(1-promo/100)*price*quantity;
}
void customer::makeBill()
{
    fstream tmp;
    tmp.open("tmp.txt",ios::out);
    int numberPro =this->numberofboughtProduct;
    tmp << "ID:\t\t"<<this->customerInfor.ID<<endl;
    tmp << "Name:\t\t"<<this->customerInfor.fistname<<endl;
    tmp << "Lase name:\t"<<this->customerInfor.lastname<<endl;
    tmp << "Address:\t"<<this->customerInfor.address<<endl;
    tmp << "Phone num:\t"<<this->customerInfor.cellNumber<<endl;
    tmp << "-----------------------------------"<<endl;
    tmp << "ID\t\tProductName\tPrice\t\t\tPromote\t\tQty\tMoney"<<endl;

    double sum=0;
    for(int i=0; i<numberPro; i++)
    {
        this->priceofAproduct(this->beBought[i]);
        tmp<<beBought[i].ID<<"\t"<<beBought[i].name<<"\t"<<beBought[i].price<<"\t\t\t"<<
        beBought[i].promote<<"\t\t"<<beBought[i].quantity<<"\t"<<beBought[i].money<<endl;
        sum+=beBought[i].money;
    }
    tmp << "total\t\t\t\t\t\t\t\t\t\t"<<sum<<endl;
    
    tmp.close();
    this->hasbill=1;
}
void customer::viewBill()
{
    if(!this->hasbill)
    {
        this->makeBill();
    }
    fstream tmp;
    tmp.open("tmp.txt",ios::in);
    if(tmp.fail()) cout <<"view bill error, please try again"<<endl;
    else
    {
        string data;
        cout <<"\n\n\n";
        while(getline(tmp,data))
        {
            cout << data<<endl;
        }
    }
    
    
}
void customer::byProduct()
{
    int checkAccont;
    cout << "welcome to HHH shop plese make sure that your information is clear in our shop" << endl;
    cout << "if you have information please press 1 to check" << endl;
    cout << "or press 0 to make new form, thanks!" << endl;
    cin >> checkAccont;
    mystring IDinput;
    if (checkAccont == 1)
    {
        cout << "please input your ID" << endl;
        cin >> IDinput;
        int ret = this->showinformation("person", "person", IDinput);

        if (ret != 1)
        {
            cout << "There are no account with ID=" << IDinput << endl;
            cout << "Please input your information again" << endl;
            this->inputInfor();
            this->checkLeastID("person","person",&this->customerInfor);
            this->customerID=this->customerInfor.ID;
        }
        else
        {
            this->customerID = IDinput;
            this->getCustomerInfor(this->customerID);
        }
    }
    else
    {
        this->inputInfor();
        this->checkLeastID("person","person",&this->customerInfor);
        this->customerID=this->customerInfor.ID;
    }

    cout << "please input the Product ID what you want to buy" << endl;
    cout << "to complete your bill plese press 0" << endl;
    mystring productID;
    int keeponornot = 1;
    do
    {
        cout << "Product ID" << endl;
        cin >> productID;
        this->byAProduct(productID);
        cout << "Keep on buying" << endl;
        cin >> keeponornot;

    } while (keeponornot == 1);
}
