#include "OrgChart.hpp"

using namespace std;

namespace ariel
{
    OrgChart::iterator::iterator(Node ptr)//: pointer_to_current_chart(ptr){}
    { 
        this->pointer_to_current_chart=ptr;
    }
    string& OrgChart::iterator::operator*() const
    {
        
        return this->pointer_to_current_chart->name;
    }
    string* OrgChart::iterator::operator->() const
    {
       
        return &(this->pointer_to_current_chart->name);
    }
    OrgChart::iterator& OrgChart::iterator::operator++()//++i
    {
       
        
            this->pointer_to_current_chart=this->pointer_to_current_chart->next;     
    

        return *this;
    }
    OrgChart::iterator OrgChart::iterator::operator++(int)
    {
        iterator temp(this->pointer_to_current_chart);
         this->pointer_to_current_chart=this->pointer_to_current_chart->next;  
        
    

        return temp;
    }
    bool OrgChart::iterator::operator==(const OrgChart::iterator& iter) const
    {
        return this->pointer_to_current_chart==iter.pointer_to_current_chart;
    }
    bool OrgChart::iterator::operator!=(const OrgChart::iterator& iter) const
    {

        return this->pointer_to_current_chart!=iter.pointer_to_current_chart;
    }
    int OrgChart::iterator::size() const
    {
        return this->pointer_to_current_chart->name.size();
            }
    ostream& operator<<(ostream& output, const  OrgChart::iterator &iterator)
    {
        return output;
    }
    // //revese iterator
    //    OrgChart::iterator_preorder::iterator_preorder(struct node *ptr)//: pointer_to_current_chart(ptr){}
    // {    
    //     for (unsigned long i = ptr->sons.size()-1; i >= 0; i--)
    //     {
    //         this->tree.push(ptr->sons.at(i));
    //     }
        
             
    //     this->pointer_to_current_chart = ptr;
    // }
    // string& OrgChart::iterator_preorder::operator*() const
    // {
    //     return this->pointer_to_current_chart->name;
    // }
    // string* OrgChart::iterator_preorder::operator->() const
    // {
       
    //     return &(this->pointer_to_current_chart->name);
    // }
    // OrgChart::iterator_preorder& OrgChart::iterator_preorder::operator++()//++i
    // {
    //     Node n=this->tree.top();
    //     for (unsigned long i = n->sons.size()-1; i >= 0; i++)
    //     {
    //         this->tree.push(n->sons.at(i));
    //     }
    //     this->pointer_to_current_chart=n;
    //     this->tree.pop();
        
        

    //     return *this;
    // }
    // OrgChart::iterator_preorder OrgChart::iterator_preorder::operator++(int)
    // {
    //     iterator_preorder temp(this->pointer_to_current_chart);
    //     Node n=this->tree.top();
    //     for (unsigned long i = n->sons.size()-1; i >= 0; i--)
    //     {
    //         this->tree.push(n->sons.at(i));
    //     }
    //     this->pointer_to_current_chart=n;
    //     this->tree.pop();
    //     return temp;
    // }
    // bool OrgChart::iterator_preorder::operator==(const OrgChart::iterator_preorder& iter) const
    // {
    //     return this->pointer_to_current_chart==iter.pointer_to_current_chart;
    // }
    // bool OrgChart::iterator_preorder::operator!=(const OrgChart::iterator_preorder& iter) const
    // {
    //     return this->pointer_to_current_chart!=iter.pointer_to_current_chart;
    // }
    // int OrgChart::iterator_preorder::size() const
    // {
    //     return this->pointer_to_current_chart->name.size();
    //         }
    // ostream& operator<<(ostream& output, const  OrgChart::iterator_preorder &iterator)
    // {
    //     return output;
    // }
    // //iterator reverse
    //    OrgChart::iterator_reverse::iterator_reverse(struct node *ptr)//: pointer_to_current_chart(ptr){}
    // {    
    //     Node n=ptr->parent;
    //     while (n->parent !=nullptr)
    //     {
    //         n=n->parent;
    //     }
    //      Q.push(n);
    //      while (!(Q.empty()))
    //      {
    //          n=Q.front();
    //          Q.pop();
    //          S.push(n);
    //          for (unsigned long i = n->sons.size()-1; i >=0; i--)
    //          {
    //              Q.push(n->sons.at(i));
    //          }
             
    //      }
         
        
        
             
    //     this->pointer_to_current_chart = ptr;
    // }
    // string& OrgChart::iterator_reverse::operator*() const
    // {
    //     return this->pointer_to_current_chart->name;
    // }
    // string* OrgChart::iterator_reverse::operator->() const
    // {
       
    //     return &(this->pointer_to_current_chart->name);
    // }
    // OrgChart::iterator_reverse& OrgChart::iterator_reverse::operator++()//++i
    // {
    //     Node n=S.top();
    //     this->pointer_to_current_chart=n;
    //     this->S.pop();
        
        

    //     return *this;
    // }
    // OrgChart::iterator_reverse OrgChart::iterator_reverse::operator++(int)
    // {
    //     iterator_reverse temp(this->pointer_to_current_chart);
    //     Node n=S.top();
    //     this->pointer_to_current_chart=n;
    //     this->S.pop();
       
    //     return temp;
    // }
    // bool OrgChart::iterator_reverse::operator==(const OrgChart::iterator_reverse& iter) const
    // {
    //     return this->pointer_to_current_chart==iter.pointer_to_current_chart;
    // }
    // bool OrgChart::iterator_reverse::operator!=(const OrgChart::iterator_reverse& iter) const
    // {
    //     return this->pointer_to_current_chart!=iter.pointer_to_current_chart;
    // }
    // int OrgChart::iterator_reverse::size() const
    // {
    //     return this->pointer_to_current_chart->name.size();
    //         }
    // ostream& operator<<(ostream& output, const  OrgChart::iterator_reverse &iterator)
    // {
    //     return output;
    // }

    
}