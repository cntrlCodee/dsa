#include<iostream>
#include<fstream>
using namespace std;

class seq_file
{
private:
	struct
	{
		int rn;
		char nm[10];
        char div[5];
        char addr[30];
	} s;
	
public:
	void create();
	void display();
    void search();
    void dlt();
    void update();
	
};
int main()
{
seq_file f;
f.create();
f.display();
f.search();
f.update();
f.display();
f.dlt();
f.display();
}
void seq_file::create()
{
	ofstream outfile;
	int ans;
	outfile.open("stud_data",ios::out | ios::binary);
	do
	{
		cout<<"enter roll no,name,division and address";
		cin>>s.rn>>s.nm>>s.div>>s.addr;
		outfile.write((char*)&s,sizeof(s));
		cout<<"want to add more";
		cin>>ans;
		
	}while(ans==1);	
	outfile.close();
}

void seq_file::display()
{
	ifstream infile;
	int ans;
	infile.open("stud_data",ios::in | ios::binary);
	while(infile)
	{
		infile.read((char*)&s,sizeof(s));
		cout<<"\n"<<s.rn;
		cout<<"\t"<<s.nm;
        cout<<"\t"<<s.div;
        cout<<"\t"<<s.addr;
		
	}
	infile.close();
}
void seq_file::search()
{
    ifstream f;
    int key;
    int flag=0;
    cout<<"enter key to search";
    cin>>key;
    f.open("stud_data",ios::in | ios::binary);
    // f.seekg(0, ios::beg);
    while(f)
    {
        if (s.rn==key)
        {
            //cout<<"student found";
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        cout<<"student not present";
    }
    else{
        cout<<"student present";
        cout<<s.rn<<s.nm<<s.div<<s.addr;
    }
    f.close();
}

void seq_file::dlt()
{
    fstream f1;
    fstream f2;
    int key;
    cout<<"enter key to delete";
    cin>>key;
    f1.open("stud_data",ios::in |ios::out | ios::binary);
    f2.open("temp_data",ios::in |ios::out | ios::binary);
    f1.seekg(0, ios::beg);
    f2.seekg(0, ios::beg);
    while(f1)
    {
        f1.read((char*)&s,sizeof(s));
        if(s.rn!=key)
        {
            f2.write((char*)&s,sizeof(s));

        }

    }
    f1.close();
    f2.close();
    remove("stud_data");
    rename("temp_data","stud_daat");

}
void seq_file::update()
{
    fstream f;
    int key;
    cout<<"enter key to update";
    cin>>key;
    f.open("stud_data",ios::in | ios::out |ios::binary);
    f.seekg(0,ios::beg);
    while(f)
    {
        if(s.rn==key)
        {
            cout<<"enter new roll no";
            cin>>s.rn;
            f.write((char*)&s,sizeof(s));
            break;

        }
        f.read((char*)&s,sizeof(s));

    }
    f.close();
    
}