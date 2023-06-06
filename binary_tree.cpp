// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
class bst{
    public:
    struct node
    {
        int data;
        node *lc;
        node *rc;
    }*root;
    bst()
    {
        root=NULL;
    }
    void create()
    {
        node *temp,*curr;
        int ans;
        do
        {
        temp=new node;
        temp->lc=NULL;
        temp->rc=NULL;
        cout<<"enter data";
        cin>>temp->data;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            curr=root;
            while(curr!=NULL)
            {
                if (temp->data < curr->data)
                {
                    if(curr->lc==NULL)
                    {
                        curr->lc=temp;
                        break;
                    }
                    curr=curr->lc;
                }
                else if(temp->data > curr->data)
                {
                    if(curr->rc==NULL)
                    {
                        curr=curr->rc;
                        break;
                    }
                    curr=curr->rc;
                }
            }
        }
        cout<<"want to add one more(0,1)";
        cin>>ans;
    }while(ans==1);
    }
    
    // display
    
    void rec_inorder(node *t)
    {
        if (t!=NULL)
        {
            
            rec_inorder(t->lc);
            cout<<t->data;
            rec_inorder(t->rc);
        }
    }
    
    // search
    
    void search()
    
    {
        int key;
        bool found=false;
        if (root==NULL)
        {
            cout<<"tree is empty";
        }
        else
        {
        cout<<"enter key to search";
        cin>>key;
        if(root->data==key)
        {
            cout<<"data found";
            found=1;
        }
        else{
        node *temp=root;
        while(temp!=NULL)
        {
        if(temp->data==key)
        {
            cout<<"data found";
            found=true; 
            break ;
        }
        else if(temp->data < key)
        {
            temp=temp->rc;
        }
        else{
            temp=temp->lc;
        }
    }
    
    if (!found)
    {
        cout<<"data not found";
    }
    }
    }
    }
    
    // longestpath
    int longestpath(node *t)
    {
        if(t==NULL)
        {
            return 0;
        }
        int leftdepth=longestpath(t->lc);
        int rightdepth=longestpath(t->rc);
        return max(leftdepth,rightdepth)+1;
    }
    
    //find minimum
    int findmin(node *t)
    {
        if(t==NULL)
        {
            return 0;
        }
        while(t->lc!=NULL)
        {
            t=t->lc;
        }
        return t->data;
    }
    
    //swap pointers
    
    void swappointers(node *t)
    {
        if(t==NULL)
        {
            return;
        }
        node *temp=t->lc;
        t->lc=t->rc;
        t->rc=temp;
        
        swappointers(t->lc);
        swappointers(t->rc);
    }
};

int main()
{
    bst obj;
    int x;
    while(1)
    {
        cout<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.search"<<endl;
        cout<<"4.longestpath"<<endl;
        cout<<"5.find minimum"<<endl;
        cout<<"6.swappointers"<<endl;
        cout<<"7.exit"<<endl;
        
        cout<<"enter your choice";
        cin>>x;
        switch(x)
        {
            case 1:
                {obj.create();
                break;
                }
            case 2:
                {obj.rec_inorder(obj.root);
                break;}
            case 3:
                {obj.search();
                break;}
            case 4:
                {int l=obj.longestpath(obj.root);
                cout<<l;
                break;}
            case 5:
                {int m=obj.findmin(obj.root);
                cout<<m;
                break;}
            case 6:
            {
                obj.swappointers(obj.root);
                obj.rec_inorder(obj.root);
                break;
            }
            case 7:
                exit(0);
            default:
                cout<<"enter valid choice";
        }
    }
}