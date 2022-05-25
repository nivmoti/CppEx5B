#pragma once

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;


namespace ariel{
    
    
      class OrgChart
    {
        
    
    typedef struct node {
  
    string name;  
    vector<node*> sons;
    node* next;
      
   
      
    // Keeps track of the parent node
     node* parent;
      node(){
          name="";
          parent=nullptr;
          next=nullptr;
      }
}*Node;
     
         

	private:
      Node root;
      vector<Node> tree;
      queue<Node> Q;
      stack <Node> S; 
      
    public:
       OrgChart();
        ~OrgChart()=default;
        OrgChart(OrgChart& OrgChart)=default;
        OrgChart(OrgChart&& OrgChart)=default;
        OrgChart & operator= (OrgChart &&) =default;
        OrgChart& operator = (const OrgChart& orgchart)=default;
        OrgChart& add_root(string const &newRoot);
        OrgChart& add_sub(string const &from, string const &to);
        friend std::ostream& operator<<(ostream& output, const OrgChart &org);
        string treePrint(Node n) const;
        
        class iterator
        {
            
        private:
        public:
             
             Node pointer_to_current_chart;
             iterator(Node ptr =nullptr);
             ~iterator()=default;
             iterator(iterator& OrgChart)=default;
            iterator(iterator&& OrgChart)=default;
            iterator & operator= (iterator &&) =default;
            iterator& operator = (const iterator& orgchart)=default;
            string& operator*() const;
            string* operator->() const;
            iterator& operator++();
            iterator operator++(int);
		
           bool operator==(const iterator& iter) const;
           bool operator!=(const iterator& iter) const;
		   int size() const;
		   friend std::ostream& operator<<(std::ostream& output, const iterator& iterator);

        };
        // class iterator_reverse
        // {
            
        // private:
        //     stack <Node> S; 
        //     queue <Node> Q;
        // public:
        //      Node pointer_to_current_chart;
        //      iterator_reverse(Node ptr =nullptr);
        //      ~iterator_reverse(){

        //      }
        //     string& operator*() const;
        //     string* operator->() const;
        //     iterator_reverse& operator++();
        //     iterator_reverse operator++(int);
		
        //    bool operator==(const iterator_reverse& iter) const;
        //    bool operator!=(const iterator_reverse& iter) const;
		//    int size() const;
		//    friend std::ostream& operator<<(std::ostream& output, const iterator_reverse& iterator);

        // };
        // class iterator_preorder
        // {
            
        // private:
        //     stack<Node> tree;
        // public:
        //      Node pointer_to_current_chart;
        //      iterator_preorder(Node ptr =nullptr);
        //      ~iterator_preorder(){

        //      }
        //     string& operator*() const;
        //     string* operator->() const;
        //     iterator_preorder& operator++();
        //     iterator_preorder operator++(int);
		
        //    bool operator==(const iterator_preorder& iter) const;
        //    bool operator!=(const iterator_preorder& iter) const;
		//    int size() const;
		//    friend std::ostream& operator<<(std::ostream& output, const iterator_preorder& iterator);

        // };
        
         iterator begin();
	
	     iterator end();

        iterator begin_level_order();
         iterator end_level_order();
        iterator begin_reverse_order();
        iterator reverse_order();
        iterator begin_preorder();
        iterator end_preorder();
         void MakeLevelorder();
         void MakeLevelorderR();
         void MakePreorder(Node n);
         bool search(string const &from);
        
        
    };
    
    

}