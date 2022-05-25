#include "OrgChart.hpp"

using namespace std;

namespace ariel
{
    OrgChart::OrgChart() 
    {
        this->root=nullptr;
    }

    OrgChart& OrgChart::add_root(string const &newRoot)
    {
        if(this->root==nullptr)
        {
     
        this->root=new node();
        root->name=newRoot;
        root->parent=nullptr;
        root->sons={};
        }
        else{
            this->root->name=newRoot;
        }
        this->MakeLevelorder();
        return *this;
        
    }
    void OrgChart::MakeLevelorder(){
        this->tree.clear();
        this->Q.push(this->root);
        while(!(Q.empty()))
        {
            Node n=Q.front();
            tree.push_back(n);
            if(!(n->sons.empty())){
            for ( unsigned long i = 0; i < n->sons.size(); i++)
            {
               Q.push(n->sons.at(i));
            }
            }
            
            Q.pop();
        }
        node* n=new node();
         n->name="end";
         n->parent=nullptr;
         tree.push_back(n);
        for (unsigned long i = 0; i < this->tree.size()-1; i++)
        {
            this->tree.at(i)->next=this->tree.at(i+1);
        }
        

    }
    bool OrgChart::search(string const &from){
        Node n=nullptr;
        for (unsigned long i = 0; i < tree.size(); i++)
        {
            n=tree.at(i);
            if(n->name==from){
                return true;
            }
        }
        return false;
        
        
    
        

        
    }

    OrgChart& OrgChart::add_sub(string const &from, string const &to)
    {
        if(this->root==nullptr){throw std::out_of_range("there is no root");}
        if(!(this->search(from))){
        throw std::out_of_range("there is no person");
        }
        for (unsigned long i = 0; i < tree.size(); i++)
        {
            if(this->tree.at(i)->name==from){
                node* n=new node();
                n->name=to;
                n->parent=this->tree.at(i);
                this->tree.at(i)->sons.push_back(n);
            }
        }
        this->MakeLevelorder();
        



        return (*this);
    
    }
    void OrgChart::MakePreorder(Node n){
        tree.push_back(n);
        if(n->sons.empty()){
            return;
        }
        for(const auto &it : n->sons)
            {
                this->MakePreorder(it);
            }

        

    }
    void OrgChart::MakeLevelorderR(){
       
        
        
        Q.push(this->root);
         while (!(Q.empty()))
         {
             Node n=Q.front();
             
             S.push(n);
             
             if(!(n->sons.empty())){
                 for (vector<Node>::reverse_iterator i = n->sons.rbegin(); 
                      i != n->sons.rend(); ++i ) { 
                          Q.push((*i));
                     } 
             }
             Q.pop();
             
         }
         tree.clear();
         while (!(S.empty()))
         {
             Node n=S.top();
             tree.push_back(n);
             S.pop();
             

         }
         node* n=new node();
         n->name="end";
         n->parent=nullptr;
         tree.push_back(n);
         for (unsigned long i = 0; i < this->tree.size()-1; i++)
        {
            this->tree.at(i)->next=this->tree.at(i+1);
            
        }
         
         
    }
    string OrgChart::treePrint(Node n) const{
        string tr=n->name;
        if(!(n->sons.empty())){
            tr+='\n';
            for(const auto &it : n->sons)
            {
                tr+=this->treePrint(it)+"      ";
            }

        }
        return tr;

    }
    
    ostream& operator<<(ostream& output, const OrgChart &org)
    {
        string hey=org.treePrint(org.root);
        output<<hey;
        return output;
    }

    OrgChart::iterator OrgChart::begin_level_order()
    {
        
        if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        
        this->MakeLevelorder();
        iterator temp{this->root};
        return temp;
    }

    OrgChart::iterator OrgChart::end_level_order()
    {
        if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        
        iterator temp(tree.at(tree.size()-1));
        
        return temp;
    }

     OrgChart::iterator OrgChart::begin_reverse_order()
    {
        if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
         this->MakeLevelorderR();
        iterator temp(tree.at(0));
        return temp;
    }

     OrgChart::iterator OrgChart::reverse_order()
    {
        if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
         iterator temp(tree.at(tree.size()-1));
        return temp;
    }

    OrgChart::iterator OrgChart::begin_preorder()
    {
        if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        tree.clear();
        this->MakePreorder(this->root);
        node* n=new node();
         n->name="end";
         n->parent=nullptr;
         tree.push_back(n);
        for (unsigned long i = 0; i < this->tree.size()-1; i++)
        {
            this->tree.at(i)->next=this->tree.at(i+1);
        }
        iterator temp{this->root};
        return temp;
    }

     OrgChart::iterator OrgChart::end_preorder()
    {
         if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        iterator temp(tree.at(tree.size()-1));
        return temp;
    }

    OrgChart::iterator OrgChart::begin()
    {
         if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        
        this->MakeLevelorder();
        iterator temp{this->root};
        return temp;
    }
     OrgChart::iterator OrgChart::end()
    {
       
       if (this->root==nullptr)
        {
            throw std::out_of_range("there is no root");
        }
        
        iterator temp(tree.at(tree.size()-1));
        
        return temp;
    }
}