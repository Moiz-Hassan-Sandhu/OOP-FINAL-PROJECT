#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//starting the project

class PolicyEngine{
    private:
    PaidWorkers* pw;
    int accessLevel;
    string position;
    

    public:
    PolicyEngine(PaidWorkers* p){
        pw = p;
        if(pw->getPosition() == "Junior"){
            accessLevel = 1;
        }
        else if(pw->getPosition() == "Employee"){
            accessLevel = 2;
        }
        else if(pw->getPosition() == "Manager"){
            accessLevel = 3;
        }
        else if(pw->getPosition() == "Director"){
            accessLevel = 4;
        }
        else if(pw->getPosition() == "Executive"){
            accessLevel = 5;
        }
        else{
            cout<<"Invalid Position"<<endl;
        }
    }

    bool can_Assign_Task(PaidWorkers p){
       PolicyEngine pe(&p);
       if(pe.accessLevel <= accessLevel){
            return true;
        }
        else{
            cout<<"You do not have permission to assign task to this user"<<endl;
            return false;
        }
        pe.~pe(); 
    } // ????? what if this can_Assign_Task() ends like return value statment tak puch jata, scope ending pe toh object auto delete ho jata na?

};
class task{

};
class PaidWorkers{
    protected:
    int ID;
    string name;
    string position;
    string password;
    float salary;
    task* t;
    bool new_messages;

    public:
    virtual void print() = 0;//making this an abstarct class we donot need an object of this class
    void setID(int id){
        ID = id;
    }
    void setName(string n){
        name = n;
    }
    void setPosition(string p){
        position = p;
    }
    void setPassword(string p){
        password = p;
    }
    void setSalary(float s){
        salary = s;
    }
    void setTask(task* tsk){
        t = tsk;
    }
    void setNewMessages(bool n){
        new_messages = n;
    }
    int getID(){
        return ID;
    }
    string getName(){
        return name;
    }
    string getPassword(){
        return password;
    }
    string getPosition(){
        return position;
    }
    float getSalary(){
        return salary;
    }
    task* getTask(){
        return t;
    }
    bool getNewMessages(){
        return new_messages;
    }
    
    

};

class Junior: public PaidWorkers{
    public:
    Junior(){
        ID=0;
        name="";
        position="Junior";
        password="";
        salary=1000.0;
        t=nullptr;
        new_messages=0;

    }
    Junior(int id,string n,string pass){
        ID=id;
        name=n;
        position="Junior";
        password=pass;
        salary=1000.0;
        t=nullptr;
        new_messages=0;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

    

};









class Authentication{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        int usercount;
        string name;
        string password;
        string OTP;
        
    public:
        bool login(string name, string password)
        {
            if(userExists(name))
            {
                
            }
            else
            {
                cout<<endl
                    <<"User Doesn't Exist"<<endl
                    <<"Please Register User"<<endl;
                return 0;       
            }
        }
        bool userExists(string name)
        {

        }
        string hashedpassword()
        {
            string password;
            int ci; //current index
            char ch;
            while (cin.get(ch))
            {
                if(ch == '\n')
                {
                    break;
                }
                else if(ch == '')

            }
            
            
            return password;
            //inputs the password from the user by keeping it hashed on console and returns the original password typed by the user.
        }
};


int main()
{
    cout<<endl<<endl<<"compiled sucessfully!"<<endl<<endl;
    int choice1;
    cout<<"#===========================================#"<<endl
        <<"#          Welcome To OFFICE PORTAL         #"<<endl
        <<"#===========================================#"<<endl
        <<"#          Press 1 to Login                 #"<<endl
        <<"#===========================================#"<<endl<<endl;
    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            string name;
            Authentication auth;
            cout<<"Enter your Username: ";
            cin>>name;
            cout<<endl
                <<"Enter your Password: ";
            string pass = auth.hashedpassword();
            auth.login(name, pass);
            
            
        }
    }
    
}