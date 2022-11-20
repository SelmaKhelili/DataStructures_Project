#include"useraccount.h"
#ifndef BSTUSERS_H
#define BSTUSERS_H
#include<iostream>
using std::cout;
template <typename Comparable, typename user>
 class BinarySearchTree
 {
   public:
 	BinarySearchTree()
    : root{ nullptr }{}//constructor
 	 BinarySearchTree( const BinarySearchTree & rhs )//Copy constructor 
     : root{ nullptr }
 {
 	root = clone( rhs.root );
 }
 	BinarySearchTree( BinarySearchTree && rhs )//Move constructor
    {
        root = std::move( rhs.root );
        rhs.root=nullptr;
    }
 	~BinarySearchTree( )
 {
 	makeEmpty();
 }//distructor
 	const Comparable & findMin() const
    {
        return  findMin(root)->ID;
    }
    user retreive(const Comparable &id)
    {
       return retreive(id,root);
    }
    
    const Comparable & findMax( ) const
    {
        return findMax(root)->ID;
    }
    bool contains( const Comparable & x ) const
    {
        return contains(x,root);
    }

    bool isEmpty( ) const
    {
        return root==nullptr;
    }

	void makeEmpty()
    {
        makeEmpty(root);
    }
    void insert( const user & account ,const Comparable & id)
    {
        insert(account,id,root);
    }
    void insert( user && account ,Comparable && id)
    {
        insert( std::move( account ),std::move(id),root );
    }
    void remove(const Comparable & id)
    {
        remove(id,root);
    }
	BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        root = clone( rhs.root );
        return *this;
    }
	BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        root = std::move( rhs.root );
        rhs.root=nullptr;
    }
    void printTree( ostream & out = cout ) const
     {
 	if( isEmpty( ) )
 		out << "Empty tree" << endl;
 	else
 		printTree( root, out );
 }

  private:
 	struct BinaryNode
 	{
		Comparable ID;
 		user User;
 		BinaryNode *left;
 		BinaryNode *right;

	BinaryNode( const user& account,const Comparable& id, BinaryNode *lt, BinaryNode *rt )
	   : user{ account },ID{id}, left{ lt }, right{ rt } { }
 		BinaryNode( user&& account,Comparable&& id, BinaryNode *lt, BinaryNode *rt )
 		   : user{ std::move( account ) }, left{ lt }, right{ rt } { }
 	};

	BinaryNode *root;

BinaryNode * clone( BinaryNode *t ) const
{
	if( t == nullptr )
    return nullptr;
	else
	    return new BinaryNode{ t->User,t->ID, clone( t->left ), clone( t->right ) };
   }

 	void insert( const user& u,const Comparable& x, BinaryNode * & t )
     {
 	if( t == nullptr )
 	    t = new BinaryNode{ u,x, nullptr, nullptr };
	else if( x < t->ID )
 	         insert( u,x, t->left );
 	     else if( x > t->ID)
 		      insert(u,x, t->right );
 		  else
 			; // Duplicate; do nothing
 }
    void insert( user&& u,Comparable&& x, BinaryNode * & t )
     {
 	if( t == nullptr )
 	    t = new BinaryNode{ std::move( u ), std::move( x ), nullptr, nullptr };  
                 // std::move is exactly equivalent to a static_cast to an rvalue reference type
 	else if( x< t->ID)
 		 insert( std::move( u),std::move( x ), t->left );
 	     else if( x> t->ID )
	      insert( std::move( u),std::move( x ), t->right );
		  else
 			; // Duplicate; do nothing
 }
user retreive(Comparable iD,BinaryNode *t)
{
    if(t== nullptr)
     return;
    else if(iD< t->ID)
     return retreive(ID,t->left);
    else if(iD> t->ID)
     return retreive(iD,t->right);
    else
      return t->User;
}
    void remove( const Comparable & x, BinaryNode * & t )
     {
 	if( t == nullptr )
	    return; // Item not found; do nothing
	if( x < t->ID)
 	    remove( x, t->left );
 	else if( t->ID< x )
 		 remove( x, t->right );
 	     else if( t->left != nullptr && t->right != nullptr ) // Two children
 		  {
 		      t->User=findMin( t->right )->User;
			  t->ID=findMin( t->right )->ID;
	 	      remove( t->ID, t->right );
 		  }
		  else
 		  {
		      BinaryNode *oldNode = t;
 		      t = ( t->left != nullptr ) ? t->left : t->right;
 		      delete oldNode;
 		   }
 }
 	BinaryNode * findMin( BinaryNode *t ) const
     {
 	if( t == nullptr )
 		return nullptr;
	if( t->left == nullptr )
 		return t;
 	return findMin( t->left );
 }

	BinaryNode * findMax( BinaryNode *t ) const
     {
 	if( t != nullptr )
 	      while( t->right != nullptr )
 		  t = t->right;
 	return t;
 }
 	bool contains( const Comparable & x, BinaryNode *t ) const
     {
 	if( t == nullptr )
  		 		return false;
 	else if( x < t->ID)
         return contains( x, t->left );    
 else if( t->ID < x )		
         return contains( x, t->right );	
   else	
    	return true; // Match
    }
 	void makeEmpty( BinaryNode * & t )
     {
 	if( t != nullptr )
 	{
 	    makeEmpty( t->left );
	    makeEmpty( t->right );
 	    delete t;
	}
 	t = nullptr;
}

void printTree( BinaryNode *t, ostream & out ) const
 {
 	if( t != nullptr )
 	{
 		printTree( t->left, out );
 		out <<t->User<< endl;
	printTree( t->right, out );
	}
 }
 };
#endif