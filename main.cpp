#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
//check1
using namespace std;


//starting the project

// 14 classes ban chuki




//-------------Done--------------
//Runtime polymorphism using base class pointers
//Authentication done
//Task Assingment
//Min 3 level of inheritance (We just have to assign special tasks to users)



//-------------In Progress------------
//Activity Logs (AUDIT LOGOING)
//Time To Live
//Messages System                                                              ----->Review Statment once again 
//Tasks can be assigned priority levels: High, Medium, Low.
//Encryption Key for Decrypting Private Messages, Intended Users functionality
//Info



//-------------To Do------------
//Task Deligation
//Employee Performance (points) System
//Global Notification System
//ADD USER (HIRE NEW Subordinates)
//Special Tasks for each position to justify hierarchical levels



//------------Bouns------------
//Digital signatures for task approvals (hash of username + timestamp)
//Cycle detection in task delegation chains
//Encrypted binary log file.
// GUI-style dashboard using ASCII art and box formatting

//------------------------------------------------------------------------------------------------------



//check for the overloaded setsent_to(); //commented out, causing runtime error

//added new data member points in paidworkers class int points and bool login


/*Did some changes in inheritance of the user classes : PaidWorkers -> Junior -> Employee -> Manager -> Director -> Executive
iska matlab ke mimimum 3 inheritance levels wali condtion meet hogai
iss se koi as such farq nai pardhta but requirement thi
technically agar Junior hai to woh Employee ke functions ko access nai kar sake ga by any means because it is a Parent class, parent ko apne childclass members ka access nai hotta
but child class ko parent ke all protected data members ka access hotta 
Employee inherited Junior,
Manager inherited Employee,
and so on till the Executive*/



//still have to think about the unique ID system

//User files i.e. executive.txt, data writing format : ID|Name|Position|Password|Salary|points

//Policy Engine now Inherits Activity Logs

//------------------------------------------------------------------------------------------------------


class task {
    string task_name;
    string task_description;
    string task_status;
    string task_assigned_by;
    string task_assigned_to;
    int TTL_time;
    public:
    task(){
        task_name="";
        task_description="";
        task_status="";
        task_assigned_by="";
        task_assigned_to="";
        TTL_time=0;
    }
    task(string name,string description,string status,string assigned_by,string assigned_to,int TTL){
        task_name=name;
        task_description=description;
        task_status=status;
        task_assigned_by=assigned_by;
        task_assigned_to=assigned_to;
        TTL_time=TTL;
    }
    void setTaskName(string name){
        task_name=name;
    }
    void setTaskDescription(string description){
        task_description=description;
    }
    void setTaskStatus(string status){
        task_status=status;
    }
    void setTaskAssignedBy(string assigned_by){
        task_assigned_by=assigned_by;
    }
    void setTaskAssignedTo(string assigned_to){
        task_assigned_to=assigned_to;
    }
    void setTTLTime(int TTL){
        TTL_time=TTL;
    }
    string getTaskName(){
        return task_name;
    }
    string getTaskDescription(){
        return task_description;
    }
    string getTaskStatus(){
        return task_status;
    }
    string getTaskAssignedBy(){
        return task_assigned_by;
    }
    string getTaskAssignedTo(){
        return task_assigned_to;
    }
    int getTTLTime(){
        return TTL_time;
    }
    void printTask(){
        cout<<"Task Name: "<<task_name<<endl
            <<"Task Description: "<<task_description<<endl
            <<"Task Status: "<<task_status<<endl
            <<"Task Assigned By: "<<task_assigned_by<<endl
            <<"Task Assigned To: "<<task_assigned_to<<endl
            <<"TTL Time: "<<TTL_time<<endl;
    }
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
        int points; //Employee points added New Data member
        bool login; //Login as data member to check on the run time in main menus if the user is logged in or not

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
        void setPoints(int p){
            points = p;
        }
        int getPoints(){
            return points;
        }
        void setLogin(bool l){
            login = l;
        }
        bool getLogin(){
            return login;
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
        points=0;
        login=false;

    }
    Junior(int id,string n,string pass){
        ID=id;
        name=n;
        position="Junior";
        password=pass;
        salary=1000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};

class Employee: public Junior{
    public:
    Employee(){
        ID=0;
        name="";
        position="Employee";
        password="";
        salary=2000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;

    }
    Employee(int id,string n,string pass){
        ID=id;
        name=n;
        position="Employee";
        password=pass;
        salary=2000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};
class Manager: public Employee{
    public:
    Manager(){
        ID=0;
        name="";
        position="Manager";
        password="";
        salary=3000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;

    }
    Manager(int id,string n,string pass){
        ID=id;
        name=n;
        position="Manager";
        password=pass;
        salary=3000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};

class Director: public Manager{
    public:
    Director(){
        ID=0;
        name="";
        position="Director";
        password="";
        salary=4000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }
    Director(int id,string n,string pass){
        ID=id;
        name=n;
        position="Director";
        password=pass;
        salary=4000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};
class Executive: public Director {
    public:
    Executive(){
        ID=0;
        name="";
        position="Executive";
        password="";
        salary=5000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;

    }
    Executive(int id,string n,string pass){
        ID=id;
        name=n;
        position="Executive";
        password=pass;
        salary=5000.0;
        t=nullptr;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};

class ActivityLog{
    protected:
        int countLogs;
        string* logs;
    public:
        ActivityLog(){
            countLogs = 0;
            logs = NULL;
        }
        void readSinginLogs()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                countLogs = 0;
            }
            ifstream in;
            in.open("./signinlogs.txt", ios::in);
            if (!in)
            {
                cout<<endl<<endl
                    <<"Error Counting singin Logs!"<<endl<<endl;
                return;
            }
            string line;
            while(in>>line)
            {
                countLogs++;
            }
            in.close();
            logs = new string [countLogs];
            int i = 0;
            in.open("./signinlogs.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            while(in>>line)
            {
                logs[i] = line;
                i++;
            }
            in.close();
            return;
        }
        void displaySinginLogs()
        {
            readSinginLogs();
            for(int i = 0; i < countLogs; i++)
            {
                cout<<logs[i]<<endl;
            }
        }
    
};



class Messages{
    protected:
        string message;
        string sender;
        string receiver;
        string type;
        bool isRead;
    public:
        Messages(string m, string s, string r){
            message = m;
            sender = s;
            receiver = r;
            isRead = false;
        }
        void setMessage(string m){
            message = m;
        }
        void setSender(string s){
            sender = s;
        }
        void setReceiver(string r){
            receiver = r;
        }
        void setIsRead(bool r){
            isRead = r;
        }
        string getMessage(){
            return message;
        }
        string getSender(){
            return sender;
        }
        string getReceiver(){
            return receiver;
        }
        bool getIsRead(){
            return isRead;
        }
};
class INFO:public Messages{

    public:
        INFO(string m, string s, string r):Messages(m,s,r){
            message = m;
            sender = s;
            receiver = r;
            type = "INFO";
            isRead = false;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }

};

class PRIVATE:public Messages{
    private:
    string encrypted_message;
    string decrypted_message;
    int sent_to;
    char caesarShift(char c, int shift) {
        if (isupper(c))
            return char((c - 'A' + shift + 260) % 26 + 'A');
        if (islower(c))
            return char((c - 'a' + shift + 260) % 26 + 'a');
        return c;
    }
    void encryptMessage() {
        int key = sent_to % 10;           // last digit of sent_to
        encrypted_message.clear();
        for (char c : message)
            encrypted_message += caesarShift(c, +key);
    }

    public:
        PRIVATE(string m, string s, string r):Messages(m,s,r)
        {
            type = "PRIVATE";
            isRead = false;
        }
        void setSentTo(int id) {
            sent_to = id;
            encryptMessage();
        }
        void saveToFile(const string& filename = "private_messages.txt") {
            ofstream out(filename, ios::app);      // open in append mode
            if (!out) {
                cerr << "Error opening " << filename << " for writing\n";
                return;
            }
            // Format: sender|receiver|sent_to|encrypted_message\n
            out << sender << '|'<< receiver << '|'<< sent_to << '|'<< encrypted_message<< '\n';
            out.close();
        }


      
        void markAsRead(){
            isRead = true;
        }
        // void setSentTo(int s){
        //     sent_to = s;
        // }
        int getSentTo(){
            return sent_to;
        }
};

class ALERT:public Messages{
    public:
        ALERT(string m, string s, string r):Messages(m,s,r){
            message = m;
            sender = s;
            receiver = r;
            type = "ALERT";
            isRead = false;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }
};
class PolicyEngine : public ActivityLog{
    private:
    int n_users;
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

    int getAccessLevel(){
        return accessLevel;
    }
    string getPosition(){
        return position;
    }

    bool Assign_Task(PaidWorkers* p){
       PolicyEngine pe(p);
       if(pe.accessLevel <= accessLevel){
            cout<<"You have permission to assign task to this user"<<endl;
            task* t = new task;
            cout<<"Enter Task Name: ";
            string name;
            getline(cin, name);
            t->setTaskName(name);
            cout<<"Enter Task Description: ";
            string description;
            getline(cin, description);
            t->setTaskDescription(description);
            t->setTaskStatus("Assigned");
            t->setTaskAssignedBy(pw->getName());
            t->setTaskAssignedTo(p->getName());
            cout<<"Enter TTL Time: ";
            int TTL;
            // I will  start working here for the TTL Assingment ( EXPIREIE DATE )
            cin>>TTL;
            t->setTTLTime(TTL);
            p->setTask(t);
            cout<<"Task Assigned Successfully"<<endl;
            cout<<"\n\n===========Task Details============ "<<endl;
            t->printTask();
            cout<<"===================================="<<endl;
            p->setTask(t);

            return true;
        }
        else{
            cout<<"You do not have permission to assign task to this user"<<endl;
            return false;
        }
    }

    bool can_send_info(PaidWorkers *p){
        PolicyEngine pe(p);
        if(pe.accessLevel < accessLevel){
             cout<<"\nYou have permission to send information to all "<<p->getPosition()<<endl;

             cout<<"\nEnter the Information: ";
                string info_message;
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, info_message);
             INFO* info=new INFO(info_message,pw->getPosition(),p->getPosition());
             //writing the info message to the file
                ofstream out("Info.txt",ios::app);
                if(!out){
                    cout<<"Error opening file"<<endl;
                    return false;
                }
                out<<info->getSender()<<"|"<<info->getReceiver()<<"|"<<info->getMessage()<<"|"<<info->getIsRead()<<endl;    
                out.close();
                cout<<"Information sent successfully!"<<endl;
             return true;
         }
         else{
             cout<<"You do not have permission to send information to the following workers"<<endl;
             return false;
         }
    }

};

class Authentication{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        //user.txt is only read and write by authentication class and noting else
        int usercount;
        int attempts;
        PaidWorkers* users;
        int OTP;
        long long otptime;
        
        public:
        Authentication(){
            usercount = 0;
            users = NULL;
            OTP = 0;
            attempts = 0;
            otptime = 0;
        }
        
        string hashedPassword(string& password)
        {
            string hashed;
            for(int i = 0; i < password.length(); i++)
            {
                char original = password[i];
                int convert = (original * (i + 1) + 31) % 94 + 33;      //keep it under the range of printable charachters
                if(convert == 124)
                {
                    convert = 125; //when hashing fall on | it will assign charchter next to | which is {
                }

                hashed += static_cast<char>(convert); //type cast the int type assci value to the actual charachter and add to the string 
            }
            return hashed;
        }
        void readuser(string pos)
        {
            if(usercount != 0)
            {
                delete [] users;
                usercount = 0;
            }
            
            ifstream in;
            int id = 0;
            int points = 0;
            double salary = 0;
            string position;
            string name;
            string password;
            string filename = "./" + pos + ".txt";

            if(pos == "Executive")
            {
                attempts++;
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Executive [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Director")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Director [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Manager")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Manager [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Employee")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Employee [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Junior")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Junior [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else
            {
                cout<<endl<<endl
                    <<"Invalid Position!"<<endl<<endl;
                mainMenu();
            }
        }
        int userExists(string name, string pos)
        {
            readuser(pos);
            for(int i = 0; i < usercount; i++)
            {
                if(users[i].getName() == name)
                {
                    return i;
                }
            }           
            return -1;
        }
        
        bool OTP_TIME()
        {
            ifstream in("./OTP.txt");
            int inOTP;
            long long inTime;   //  to store the int form of current time
            in >> inOTP;
            in.ignore(1);
            in >> inTime;
            in.close();

            // if more than 15 seconds have passed, expire it
            return (difftime(time(0), inTime) <= 15.0);   //using a difftime() function from the predefined ctime library
        }

        void otpGenerator()
        {
            srand(time(0));
            OTP = 100000 + rand() % 900000;
            otptime = time(0);

            ofstream out;
            out.open("./OTP.txt", ios::out);
            if(!out)
            {
                cout<<endl<<endl
                    <<"Error opening OTP file"<<endl<<endl;
                mainMenu();
            }

            out<< OTP << "|" << otptime << endl;
            out.close();
        }


        PaidWorkers& login(string pos)  //string to check position
        {
            bool login = false;
            string iname, ipassword;    //input name and input password
            cout<<"Enter your Username: ";
            cin>>iname;
            int index = userExists(iname, pos);
            while(1)
            {
                if(attempts>3)
                {
                    cout<<endl<<endl
                        <<"Too many attempts"<<endl
                        <<"Please try again later"<<endl;
                        attempts = 0;
                        login = false;
                        break;
                }

                if(index != -1)
                {
                    cout<<endl
                    <<"Enter your Password: ";
                    cin>>ipassword;
                    ipassword = hashedPassword(ipassword);
                    if(users[index].getPassword() == ipassword)
                    {
                        int otp = 0;
                        otpGenerator();
                        cout<<"Enter the OTP: ";
                        cin>>otp;

                        if (!OTP_TIME()) {
                            cout << "\n\nOTP Expired\nLogin Failed\n";
                            remove("./OTP.txt");
                            login = false;
                            break;
                        }

                        if(OTP == otp)
                        {
                            remove("./OTP.txt");
                            attempts = 1;
                            cout<<"Login Success"<<endl;
                            login = true;
                            break;
                        }
                        else
                        {
                            cout<<endl<<endl
                                <<"OTP Incorrect"<<endl<<endl
                                <<"Login Failed"<<endl<<endl;
                            remove("./OTP.txt");
                            login = false;
                            break;
                        }
                    }
                    else
                    {
                        cout<<endl<<endl
                            <<"Password Incorrect"<<endl<<endl
                            <<"Please try again"<<endl<<endl;
                        attempts++;
                    }
                }
                else
                {
                    cout<<endl<<endl
                    <<"User Doesn't Exist"<<endl
                    <<"Please Register User"<<endl;
                    login = false;
                    break;
                }
            }
            if(login == true)
            {
                users[index].setLogin(true);
                return users[index];
            }
            else
            {
                mainMenu();
            }
            return users[index];
        }
        ~Authentication()
        {
            if(users != NULL)
            {
                delete[] users;
                users = NULL;
            }
        }
};

void mainMenu();
void ExecutiveMenu(PaidWorkers* user);
void DirectorMenu(PaidWorkers* user);
void ManagerMenu(PaidWorkers* user);
void EmployeeMenu(PaidWorkers* user);
void JuniorMenu(PaidWorkers* user);

void show_Message_menu(PaidWorkers * pw);






//-----------------------------------Code Execution start from here--------------------------------
int main()
{
    mainMenu();
}

void mainMenu()
{
    int choice1;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Welcome To OFFICE PORTAL         #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to Login as Executive    #"<<endl
    <<"                              #          Press 2 to Login as Director     #"<<endl
    <<"                              #          Press 3 to Login as Manager      #"<<endl
    <<"                              #          Press 4 to Login as Employee     #"<<endl
    <<"                              #          Press 5 to Login as Junior       #"<<endl
    <<"                              #          Press 6 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Executive");
            if(pw->getLogin() == true)
            {
                ExecutiveMenu(pw);
            }
            break;
        }
        case 2:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Director");
            if(pw->getLogin() == true)
            {
                DirectorMenu(pw);
            }
            break;
        }
        case 3:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Manager");
            if(pw->getLogin() == true)
            {
                ManagerMenu(pw);
            }
            break;
        }
        case 4:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Employee");
            if(pw->getLogin() == true)
            {
                EmployeeMenu(pw);
            }
            break;
        }
        case 5:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Junior");
            if(pw->getLogin() == true)
            {
                JuniorMenu(pw);
            }
            break;
        }
        case 6:
        {
            cout<<endl
                <<"Have a Good Day!"<<endl<<endl<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            mainMenu();
        }
    }
}

void ExecutiveMenu(PaidWorkers* pw)
{
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Executive Menu                   #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View Messages        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 3 to Add New           #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {   
            show_Message_menu(pw);
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ExecutiveMenu(pw);
        }
    }
}
void DirectorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Director Menu                    #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to see messages          #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Send Message          #"<<endl
    <<"                              #          Press 5 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            show_Message_menu(pw);
            
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            DirectorMenu(pw);
        }
    }
}
void ManagerMenu(PaidWorkers* pw){
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Manager Menu                     #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ManagerMenu(pw);
        }
    }
}

void EmployeeMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Employee Menu                    #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            EmployeeMenu(pw);
        }
    }
}
void JuniorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Junior Menu                      #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            JuniorMenu(pw);
        }
    }
}


void show_Message_menu(PaidWorkers * pw)
{
    cout<<endl<<endl<<endl;
    cout
    <<"                              #===============================================#"<<endl
    <<"                              #               Message Menu                    #"<<endl
    <<"                              #===============================================#"<<endl
    <<"                              #          Press 1 to send INFO                 #"<<endl
    <<"                              #          Press 2 to send a private message    #"<<endl
    <<"                              #          Press 3 to send an Alert             #"<<endl
    <<"                              #          Press 4 to view Info                 #"<<endl
    <<"                              #          Press 5 to view private Message      #"<<endl
    <<"                              #          Press 6 to Exit                      #"<<endl
    <<"                              #===============================================#"<<endl<<endl<<endl;

    int choice1;
    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            PolicyEngine pe(pw);
            cout<<"Which class of pleople you want to send message to?"<<endl
                <<"Press 1 for Junior"<<endl
                <<"Press 2 for Employee"<<endl
                <<"Press 3 for Manager"<<endl
                <<"Press 4 for Director"<<endl
                <<"Press 5 for Executive"<<endl;
            int choice2;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<"Sending message to Junior"<<endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<"Sending message to Employee"<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<"Sending message to Manager"<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<"Sending message to Director"<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<"Sending message to Executive"<<endl;
                p = new Executive;
            }
            else
            {
                cout<<"Invalid Option"<<endl<<endl<<endl;
                show_Message_menu(pw);
            }

            if(pe.can_send_info(p) == true)
            {
                cout<<"Message Sent Successfully!"<<endl;
            }
            else
            {
                cout<<"Message Sending Failed!"<<endl;
            }
            
            break;
        }
        case 2:
        {
            cout<<"-------------Returning to main menu-------------"<<endl<<endl;
            mainMenu();
            break;
        }
        case 3:
        {
            cout<<endl
                <<"Have a Good Day!"<<endl<<endl<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            mainMenu();
        }
    }
}